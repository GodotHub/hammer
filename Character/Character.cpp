#include "Character.h"
#include <godot_cpp/core/class_db.hpp>


using namespace godot;

void Character::_bind_methods() {
	// ClassDB::bind_method(D_METHOD("get_amplitude"), &Character::get_amplitude);
	// ClassDB::bind_method(D_METHOD("set_amplitude", "p_amplitude"), &Character::set_amplitude);
	// ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "amplitude"), "set_amplitude", "get_amplitude");


	// ClassDB::bind_method(D_METHOD("get_speed"), &Character::get_speed);
	// ClassDB::bind_method(D_METHOD("set_speed", "p_speed"), &Character::set_speed);
	// ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "speed", PROPERTY_HINT_RANGE, "0,20,0.01"), "set_speed", "get_speed");

	ClassDB::bind_method(D_METHOD("get_shape"), &Character::get_shape);
	ClassDB::bind_method(D_METHOD("set_shape", "shape"), &Character::set_shape);
	ADD_PROPERTY(PropertyInfo(Shape3D, "shape"), "set_shape", "get_shape");

	


	// ADD_SIGNAL(MethodInfo("position_changed", PropertyInfo(Variant::OBJECT, "node"), PropertyInfo(Variant::VECTOR2, "new_pos")));
}

Character::Character() {
	Posture = poseStand;

	isPerforming = false;

	// 子节点创建
	collision = memnew(CollisionShape3D);
	collision->set_name("Collision");
	collision->set_shape(shape);
	add_child(collision);


}

void Character::_process(double delta) {
}




Shape3D *Character::get_shape(){return shape;}
void Character::set_shape(Shape3D *new_shape){shape = new_shape;}