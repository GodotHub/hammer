#ifndef MoudelGroup_H
#define MoudelGroup_H

#include "ModuleResource.h"

#include <godot_cpp/classes/resource.hpp>

#include <godot_cpp/classes/input_event.hpp>
#include <godot_cpp/classes/node.hpp>

#include <godot_cpp/variant/typed_array.hpp>

namespace godot{

class ModuleGroup : public Resource{
    GDCLASS(ModuleGroup, Resource)
private:
    TypedArray<ModuleResource> listModule;
    Node * nodeParent;

protected:
	static void _bind_methods();
public:
    ModuleGroup();

    void setModuleList(const TypedArray<ModuleResource> *_list_Module);
    TypedArray<ModuleResource> getModuleList() const;

    bool addModule(ModuleResource* _module, int _index = -1);
    bool removeModule(int _index);

    void setNodeParent(Node *_node_parent);
    Node *getNodeParent() const;
    
    // 需要父节点调用以下函数
    
    void loop(float _delta);
    void physics(float _delta);
    void input(InputEvent *_input_event);



};

}


#endif