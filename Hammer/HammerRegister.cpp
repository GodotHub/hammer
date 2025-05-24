#include "HammerRegister.h"

#include "SceneNode.h"
#include "CaptionNode.h"
#include "OptionNode.h"

#include "ModuleResource.h"
#include "ModuleGroup.h"

#include <gdextension_interface.h>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

using namespace godot;

void initialize_hammer_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
	
		return;
	}


	// GDREGISTER_CLASS(Character);
	// GDREGISTER_CLASS(Pose);
	// GDREGISTER_CLASS(PoseGroup);

	GDREGISTER_CLASS(SceneNode);
	GDREGISTER_CLASS(CaptionNode);
	GDREGISTER_CLASS(CaptionNode);

	GDREGISTER_CLASS(ModuleResource);
	GDREGISTER_CLASS(ModuleGroup);

}

void uninitialize_hammer_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
}

extern "C" {
GDExtensionBool GDE_EXPORT hammer_library_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, const GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization) {
	godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

	init_obj.register_initializer(initialize_hammer_module);
	init_obj.register_terminator(uninitialize_hammer_module);
	init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

	return init_obj.init();
}
}