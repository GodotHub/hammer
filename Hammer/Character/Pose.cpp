#include "Pose.h"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void Pose::_bind_methods() {
	ClassDB::bind_method(D_METHOD("getName"), &Pose::getName);
	ClassDB::bind_method(D_METHOD("setName", "Name"), &Pose::setName);
    ADD_PROPERTY(PropertyInfo(Variant::STRING, "Name"), "setName", "getName");

	ClassDB::bind_method(D_METHOD("getHeight"), &Pose::getHeight);
	ClassDB::bind_method(D_METHOD("setHeight", "Height"), &Pose::setHeight);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "Height"), "setHeight", "getHeight");

	ClassDB::bind_method(D_METHOD("getSpeed"), &Pose::getSpeed);
	ClassDB::bind_method(D_METHOD("setSpeed", "Speed"), &Pose::setSpeed);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "Speed"), "setSpeed", "getSpeed");

	ClassDB::bind_method(D_METHOD("getAnimation"), &Pose::getAnimation);
	ClassDB::bind_method(D_METHOD("setAnimation", "Animation"), &Pose::setAnimation);
    ADD_PROPERTY(PropertyInfo(Variant::STRING, "Animation"), "setAnimation", "getAnimation");
}

Pose::Pose(){initPose("Name", 2.0, 3.0, "Animation");};
Pose::Pose(Pose *_pose){initPose(_pose->Name, _pose->Height, _pose->Speed, _pose->Animation);};
Pose::Pose(String _name, float _height, float _speed, String _animation){initPose(_name, _height, _speed, _name);};

void Pose::initPose(String _name, float _height, float _speed, String _animation){
	Name = _name;
	Height = _height;
	Speed = _speed;
	Animation = _animation;
};


String Pose::getName() const{return Name;};
void Pose::setName(String _name){Name = _name;};

float Pose::getHeight() const{return Height;};
void Pose::setHeight(float _height){Height = _height;};

float Pose::getSpeed() const{return Speed;};
void Pose::setSpeed(float _speed){Speed = _speed;};

String Pose::getAnimation() const{return Animation;};
void Pose::setAnimation(String _animation){Animation = _animation;};

