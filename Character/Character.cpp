#include "Character.h"

#include <godot_cpp/core/class_db.hpp>


using namespace godot;

void Character::_bind_methods() {
	ClassDB::bind_method(D_METHOD("getRefShape"), &Character::getRefShape);
	ClassDB::bind_method(D_METHOD("setRefShape", "refShape"), &Character::setRefShape);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "refShape", PROPERTY_HINT_RESOURCE_TYPE, "Shape3D"), "setRefShape", "getRefShape");

	ClassDB::bind_method(D_METHOD("getPoseGroup"), &Character::getPoseGroup);
	ClassDB::bind_method(D_METHOD("setPoseGroup", "refPoseGroup"), &Character::setPoseGroup);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "refPoseGroup", PROPERTY_HINT_RESOURCE_TYPE, "Shape3D"), "setPoseGroup", "getPoseGroup");

	// ClassDB::bind_method(D_METHOD("getListPose"), &Character::getListPose);
	// ClassDB::bind_method(D_METHOD("setListPose", "listPose"), &Character::setListPose);
    // ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "listPose", PROPERTY_HINT_TYPE_STRING, String::num(Variant::OBJECT) + "/" + String::num(PROPERTY_HINT_RESOURCE_TYPE) + ":Pose"), "setListPose", "getListPose");
}

Character::Character() {nodeCollision = memnew(CollisionShape3D);add_child(nodeCollision);}
void Character::_process(double _delta) {}
Character::~Character(){nodeCollision->queue_free();}


Ref<Shape3D> Character::getRefShape() const {return nodeCollision->get_shape();}
void Character::setRefShape(Ref<Shape3D> _shape){refShape = _shape;nodeCollision->set_shape(refShape);}

Ref<PoseGroup> Character::getPoseGroup() const {return refPoseGroup;}
void Character::setPoseGroup(Ref<PoseGroup> _pose_group){refPoseGroup = _pose_group;}

// TypedArray<Pose> Character::getListPose() const{
// 	return listPose;
// };
// void Character::setListPose(TypedArray<Pose> _list){
// 	listPose = _list;
// };