//
// Created by yannick lamprecht on 24.02.17.
//



#include <iostream>
#include "plugin/IPlugin.h"

class TestPlugin : public virtual IPlugin{
public:
    TestPlugin(const std::string &name) : IPlugin(name) {
    }

private:
    void onEnable() override {

        std::cout << "Test onEnable" << getName() << std::endl;


    }

    void onDisable() override {
        std::cout << "Test onDisable" << getName() << std::endl;
    }


};