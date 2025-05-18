#include "ModuleResource.h"

using namespace godot;

ModuleResource::ModuleResource(){checkPassed = false;}

bool ModuleResource::selfCheck(){return false;}
bool ModuleResource::getCheckPassed(){return checkPassed;}

void ModuleResource::setModuleEnable(bool _enable){enableModule = _enable;}
bool ModuleResource::getModuleEnable() const {return enableModule;}

void ModuleResource::setModuleUnique(bool _unique_moudle){uniqueModule = _unique_moudle;};
bool ModuleResource::getModuleUnique() const{return uniqueModule;};

void ModuleResource::_bind_methods(){
    
}