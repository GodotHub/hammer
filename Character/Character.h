#ifndef CHARACTER_H
#define CHARACTER_H

#include <godot_cpp/classes/character_body3d.hpp>

#include <godot_cpp/classes/collision_shape3d.hpp>
#include <godot_cpp/classes/capsule_shape3d.hpp>

namespace godot {

class Character : public CharacterBody3D {
	GDCLASS(Character, CharacterBody3D)

private:
	bool isPerforming;

	double Width;

	struct Pose
	{
		double Height;
		double Speed;
	};

	Pose Posture;

	Pose poseStand;
	Pose poseSquat;

	CollisionShape3D *collision;
	Shape3D *shape;
	
	Array poseList;

protected:
	static void _bind_methods();

public:
	Character();
	void _process(double delta) override;

	Shape3D *get_shape();
	void set_shape(Shape3D *new_shape);
};

}

#endif