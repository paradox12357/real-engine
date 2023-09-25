#pragma once
#include <string>
using std::string;
namespace resource {
	class ResourceManager {
	private:
	public:
		static void initializeResourceManager();
		static void shutdownResourceManager();
		static string getPath(string path);
	};
}