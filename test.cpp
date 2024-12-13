#include <iostream>
#include <string>
#include <vector>

class Component{
    public:
        virtual void Init()=0;
        virtual bool Process()=0;
        std::string name_;
        Component(){};
        Component(std::string name):name_(name){
            std::cout << "Component " << name_ << " created" << std::endl;
        };
};


class PerceptionComponent : public Component{
    public:
        void Init() override{
            std::cout << "PerceptionComponent Init" << std::endl;
        }
        bool Process() override{
            std::cout << "PerceptionComponent Process" << std::endl;
            return true;
        }
};

class RouteComponent : public Component{    
    public:
        void Init() override{
            std::cout << "RouteComponent Init" << std::endl;
        }
        bool Process() override{
            std::cout << "RouteComponent Process" << std::endl;
            return true;
        }
        RouteComponent(){
        };
};


int main(){
    std::vector<Component*> components = {new PerceptionComponent(), new RouteComponent()};
    for(Component* component : components){
        component->Init();
        component->Process();
    }
    return 0;
}
