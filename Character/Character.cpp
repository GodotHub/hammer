#include "Character.h"

#include <godot_cpp/variant/callable.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>


using namespace godot;

void Character::_bind_methods() {
	ClassDB::bind_method(D_METHOD("getFileModel"), &Character::getFileModel);
	ClassDB::bind_method(D_METHOD("setFileModel", "fileModel"), &Character::setFileModel);
    ADD_PROPERTY(PropertyInfo(Variant::STRING, "fileModel", PROPERTY_HINT_FILE, "*.blend"), "setFileModel", "getFileModel");

	ClassDB::bind_method(D_METHOD("getRefShape"), &Character::getRefShape);
	ClassDB::bind_method(D_METHOD("setRefShape", "refShape"), &Character::setRefShape);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "refShape", PROPERTY_HINT_RESOURCE_TYPE, "Shape3D"), "setRefShape", "getRefShape");
	ClassDB::bind_method(D_METHOD("getPoseGroup"), &Character::getPoseGroup);
	ClassDB::bind_method(D_METHOD("setPoseGroup", "refPoseGroup"), &Character::setPoseGroup);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "refPoseGroup", PROPERTY_HINT_RESOURCE_TYPE, "PoseGroup"), "setPoseGroup", "getPoseGroup");

	ClassDB::bind_method(D_METHOD("getHeadFront"), &Character::getHeadFront);
	ClassDB::bind_method(D_METHOD("setHeadFront", "vecHeadFront"), &Character::setHeadFront);
    ADD_PROPERTY(PropertyInfo(Variant::VECTOR3, "vecHeadFront", PROPERTY_HINT_RANGE, "-360, 360, 0.1"), "setHeadFront", "getHeadFront");
	ClassDB::bind_method(D_METHOD("getBodyFront"), &Character::getBodyFront);
	ClassDB::bind_method(D_METHOD("setBodyFront", "vecBodyFront"), &Character::setBodyFront);
    ADD_PROPERTY(PropertyInfo(Variant::VECTOR3, "vecBodyFront", PROPERTY_HINT_RANGE, "-360, 360, 0.1"), "setBodyFront", "getBodyFront");


	ClassDB::bind_method(D_METHOD("initCharacter"), &Character::initCharacter);
}

Character::Character() {
	vecHeadFront = Vector3(0, 0, 0);
	vecBodyFront = Vector3(0, 0, 0);

	connect("ready", Callable(this, "initCharacter"));

	// nodeModel = memnew()
	nodeModel = nullptr;

	nodeCollision = memnew(CollisionShape3D);
	add_child(nodeCollision);
};

Character::~Character(){
	if (nodeCollision == nullptr){
		nodeCollision->queue_free();
	};
};

void Character::initCharacter(){
	
};


String Character::getFileModel() const {return fileModel;}
void Character::setFileModel(String _file_model){
	fileModel = _file_model;
	
	if (nodeModel != nullptr){
		nodeModel->queue_free();
		nodeModel = nullptr;
	}

	if (fileModel != String()) {
		Ref<PackedScene> scene = ResourceLoader::get_singleton()->load(fileModel);
		nodeModel = Object::cast_to<Node3D>(scene->instantiate());
		add_child(nodeModel);
	}
}

Ref<Shape3D> Character::getRefShape() const {return nodeCollision->get_shape();}
void Character::setRefShape(const Ref<Shape3D> &_shape){refShape = _shape;nodeCollision->set_shape(refShape);}
Ref<PoseGroup> Character::getPoseGroup() const {return refPoseGroup;}
void Character::setPoseGroup(const Ref<PoseGroup> &_pose_group){refPoseGroup = _pose_group;}

Vector3 Character::getHeadFront() const {return vecHeadFront;}
void Character::setHeadFront(const Vector3 &_front_head){vecHeadFront = _front_head;}
Vector3 Character::getBodyFront() const{return vecBodyFront;};
void Character::setBodyFront(const Vector3 &_body_front){vecBodyFront = _body_front;}