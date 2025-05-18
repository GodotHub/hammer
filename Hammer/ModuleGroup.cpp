#include "ModuleGroup.h"

using namespace godot;

ModuleGroup::ModuleGroup(){
    
}

void ModuleGroup::setModuleList(const TypedArray<ModuleResource> *_list_Module){listModule = *_list_Module;};
TypedArray<ModuleResource> ModuleGroup::getModuleList() const{return listModule;};


void ModuleGroup::setNodeParent(Node *_node_parent){nodeParent = _node_parent;};
Node *ModuleGroup::getNodeParent() const {return nodeParent;};

void ModuleGroup::loop(float _delta){
    for (int i = 0; i < listModule.size(); i++){
        ModuleResource *module = Object::cast_to<ModuleResource>(listModule[i]);
        
        if (!module->getModuleEnable()){continue;}
        if (!module->getCheckPassed()){if (!module->selfCheck()){continue;}}

        module->loop(_delta);
    }
}

void ModuleGroup::physics(float _delta){
    for (int i = 0; i < listModule.size(); i++){
        ModuleResource *module = Object::cast_to<ModuleResource>(listModule[i]);
        
        if (!module->getModuleEnable()){continue;}
        if (!module->getCheckPassed()){if (!module->selfCheck()){continue;}}

        module->physics(_delta);
    }
}

void ModuleGroup::input(InputEvent *_input_event){
    for (int i = 0; i < listModule.size(); i++){
        ModuleResource *module = Object::cast_to<ModuleResource>(listModule[i]);
        
        if (!module->getModuleEnable()){continue;}
        if (!module->getCheckPassed()){if (!module->selfCheck()){continue;}}

        module->input(_input_event);
    }
}

bool ModuleGroup::addModule(ModuleResource* _module, int _index){
    String class_name = _module->get_class();
    for (int i = 0; i < listModule.size(); i++){
        ModuleResource *module = Object::cast_to<ModuleResource>(listModule[i]);
        if (module->get_class() == class_name){if (module->getModuleUnique()){return false;}}
    }
    listModule.append(_module);
    return true;
}

bool ModuleGroup::removeModule(int _index){
    if (_index > listModule.size()){return false;}
    listModule.remove_at(_index);
}

void ModuleGroup::_bind_methods(){

}