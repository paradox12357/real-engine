#pragma once
#include <typeindex>
using std::type_index;
typedef long EntityID;
typedef std::type_index ComponentIndex;
namespace ecs {
	class ECSManager {
	private:
	public:
		template< typename T >
		T& Get(EntityID entity) {
			return GetAppropriateSparseSet<T>()[entity];
		}
		static void initializeECSManager();
		static void shutdownECSManager();
		static EntityID Create(const std::vector<std::type_index>& components);
		static void Drop(EntityID e);
		static void Destroy(EntityID e);
	};
}