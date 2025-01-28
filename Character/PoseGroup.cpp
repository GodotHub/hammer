#include "PoseGroup.h"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void PoseGroup::_bind_methods() {
	ClassDB::bind_method(D_METHOD("getPoseGroup"), &PoseGroup::getPoseGroup);
	ClassDB::bind_method(D_METHOD("setPoseGroup", "Group"), &PoseGroup::setPoseGroup);
    ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "Group", PROPERTY_HINT_TYPE_STRING, String::num(Variant::OBJECT) + "/" + String::num(PROPERTY_HINT_RESOURCE_TYPE) + ":Pose"), "setPoseGroup", "getPoseGroup");
}

TypedArray<Pose> PoseGroup::getPoseGroup(){return Group;};
void PoseGroup::setPoseGroup(TypedArray<Pose> _group){Group = _group;};