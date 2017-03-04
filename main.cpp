#include <iostream>
#include <vector>
#include "pluginloading/PluginLoader.h"


int main() {


    const std::string endings[] = {"so", "dll"};// "so","dll"



    ysl::PluginLoader loader("plugMeIn/", new ysl::FileReader(), endings);


    loader.load();

    std::map<std::string, std::shared_ptr<IPlugin>> plugins = loader.getLoadedPlugins();

    std::cout << "Plugins loaded: " << plugins.size() << std::endl;


    for (const auto &pluginPair : plugins) {

        IPlugin &pl = *pluginPair.second.get();

        pl(true);

        std::cout << pluginPair.second.use_count() << std::endl;
        //pluginPair.second->onDisable();

        pl(false);

        std::cout << "name: " << *pluginPair.second.get() << std::endl;
    }

    return 0;
}