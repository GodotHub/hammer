#include "Character.h"

#include <godot_cpp/core/class_db.hpp>


using namespace godot;

void Character::_bind_methods() {
	ClassDB::bind_method(D_METHOD("getRefShape"), &Character::getRefShape);
	ClassDB::bind_method(D_METHOD("setRefShape", "refShape"), &Character::setRefShape);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "refShape", PROPERTY_HINT_RESOURCE_TYPE, "Shape3D"), "setShape", "getShape");

	// ClassDB::bind_method(D_METHOD("getRefShape"), &Character::getListPose);
	// ClassDB::bind_method(D_METHOD("setRefShape", "refShape"), &Character::setListPose);
    // ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "refShape", PROPERTY_HINT_RESOURCE_TYPE, "Shape3D"), "setShape", "getShape");
}

Character::Character() {nodeCollision = memnew(CollisionShape3D);add_child(nodeCollision);}
void Character::_process(double _delta) {}
Character::~Character(){nodeCollision->queue_free();}


Ref<Shape3D> Character::getRefShape() const {return nodeCollision->get_shape();}
void Character::setRefShape(Ref<Shape3D> _shape){refShape = _shape;nodeCollision->set_shape(refShape);}

TypedArray<Pose> Character::getListPose() const{
	return listPose;
};
void Character::setListPose(TypedArray<Pose> _list){
	listPose = _list;
};