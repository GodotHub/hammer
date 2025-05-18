#ifndef ModuleResource_H
#define ModuleResource_H

#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/classes/input_event.hpp>

#include <godot_cpp/classes/node.hpp>

namespace godot{

class ModuleResource : public Resource{
    GDCLASS(ModuleResource, Resource)
private:
    Node *nodeParent;
    bool checkPassed;

    bool enableModule;
    bool uniqueModule;


protected:
	static void _bind_methods();
public:
    ModuleResource();

    virtual bool selfCheck();
    bool getCheckPassed();

    virtual void init(){};
    virtual void loop(float _delta){};
    virtual void physics(float _delta){};
    virtual void input(InputEvent *_input_event){};

    void setModuleEnable(bool _enable);
    bool getModuleEnable() const;

    void setNodeParent(Node *_node_parent);
    Node *getNodeParent() const;

    void setModuleUnique(bool _unique_moudle);
    bool getModuleUnique() const;
    

};

}

#endif