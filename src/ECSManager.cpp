#include "types.h"

using namespace std;
using namespace ecs;
EntityID m_nextID = 0;
class SparseSetHolder {
public:
    // A virtual destructor, since subclasses need their destructors to run to free memory.
    virtual ~SparseSetHolder() = default;
    virtual bool Has(EntityID) const = 0;
    virtual void Drop(EntityID) = 0;
    virtual void Add(EntityID) = 0;
};
std::unordered_map< ComponentIndex, std::unique_ptr< SparseSetHolder > > m_components;
// Subclasses are templated on the component type they hold.
template< typename T > class SparseSet : public SparseSetHolder {
public:
    std::unordered_map< EntityID, T > data;
    bool Has(EntityID e) const override { return data.count(e) > 0; };
    void Drop(EntityID e) override { data.erase(e); };
    //void Add(EntityID e) override { data[e] = T; };
};
template< typename T >
std::unordered_map< EntityID, T >&
GetAppropriateSparseSet() {
    // Get the index for T's SparseSet
    const ComponentIndex index = std::type_index(typeid(T));
    // Create the actual sparse set if needed.
    if (m_components[index] == nullptr) m_components[index] = std::make_unique< SparseSet<T> >();
    // It's safe to cast the SparseSetHolder to its subclass and return the std::unordered_map< EntityID, T > inside.
    return static_cast<SparseSet<T>&>(*m_components[index]).data;
}
void ECSManager::initializeECSManager() {
	
}
void ECSManager::shutdownECSManager() {

}
EntityID ECSManager::Create(const std::vector<std::type_index>& components) {
	// Get the next available ID.
	const EntityID id = ++m_nextID;
	// Add the components to the entity.
	for (const auto& index : components) {
        m_components[index]->Add(id);
	}
	return id;
}
// Drop a component from an entity.
template< typename T >
void Drop(EntityID e) {
    GetAppropriateSparseSet<T>().erase(e);
}

// Destroy the entity by removing all components.
void Destroy(EntityID e) {
    for (const auto& [index, comps] : m_components) { comps->Drop(e); }
}

typedef std::function<void(EntityID)> ForEachCallback;
template<typename EntitiesThatHaveThisComponent, typename... AndAlsoTheseComponents>
void ForEach(const ForEachCallback& callback) {
    // Get a vector of ComponentIndex we can use with `m_components[ index ]->Has( entity )`.
    std::vector<ComponentIndex> also{ std::type_index(typeid(AndAlsoTheseComponents))... };
    // Iterate over entities in the first container. If the entity has all components in `also`, call `callback( entity )`.
    for (const auto& [entity, component] : GetAppropriateSparseSet<EntitiesThatHaveThisComponent>()) {
		bool hasAllComponents = true;
		for (const auto& index : also) {
			if (!m_components[index]->Has(entity)) {
				hasAllComponents = false;
				break;
			}
		}
		if (hasAllComponents) {
			callback(entity);
		}
	}
}
