#include "Pose.h"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void Pose::_bind_methods() {
	ClassDB::bind_method(D_METHOD("getAnimation"), &Pose::getAnimation);
	ClassDB::bind_method(D_METHOD("setAnimation", "Animation"), &Pose::setAnimation);
    ADD_PROPERTY(PropertyInfo(Variant::STRING, "Animation"), "setAnimation", "getAnimation");

	ClassDB::bind_method(D_METHOD("getHeight"), &Pose::getHeight);
	ClassDB::bind_method(D_METHOD("setHeight", "Height"), &Pose::setHeight);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "Height"), "setHeight", "getHeight");

	ClassDB::bind_method(D_METHOD("getSpeed"), &Pose::getSpeed);
	ClassDB::bind_method(D_METHOD("setSpeed", "Speed"), &Pose::setSpeed);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "Speed"), "setSpeed", "getSpeed");
}

Pose::Pose(){
	Height = 2.0;
	Speed = 3.0;
	Animation = "Animation";
};

float Pose::getHeight() const{return Height;};
void Pose::setHeight(float _height){Height = _height;};

float Pose::getSpeed() const{return Speed;};
void Pose::setSpeed(float _speed){Speed = _speed;};

String Pose::getAnimation() const{return Animation;};
void Pose::setAnimation(String _animation){Animation = _animation;};

