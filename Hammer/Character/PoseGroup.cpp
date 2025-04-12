#include "PoseGroup.h"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void PoseGroup::_bind_methods() {
	ClassDB::bind_method(D_METHOD("getPoseGroup"), &PoseGroup::getGroup);
	ClassDB::bind_method(D_METHOD("setPoseGroup", "Group"), &PoseGroup::setGroup);
    ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "Group", PROPERTY_HINT_TYPE_STRING, String::num(Variant::OBJECT) + "/" + String::num(PROPERTY_HINT_RESOURCE_TYPE) + ":Pose"), "setPoseGroup", "getPoseGroup");
	
	ClassDB::bind_method(D_METHOD("getItem", "_name"), &PoseGroup::getItem);
	
}	

TypedArray<Pose> PoseGroup::getGroup(){return Group;};
void PoseGroup::setGroup(TypedArray<Pose> _group){Group = _group;};

Ref<Pose> PoseGroup::getItem(String _name){
	for (int i = 0; i < Group.size(); i++){
		Ref<Pose> pose = Ref<Pose>(static_cast<Pose*>(Group[i].operator Object*()));
		if (pose->getName() == _name){return pose;};
	};
	return Ref<Pose>();
};