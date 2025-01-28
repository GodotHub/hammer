#ifndef CHARACTER_H
#define CHARACTER_H

#include "PoseGroup.h"
#include <godot_cpp/classes/shape3d.hpp>
#include <godot_cpp/classes/character_body3d.hpp>
#include <godot_cpp/classes/collision_shape3d.hpp>
// #include <godot_cpp/classes/animation.hpp>

namespace godot {

class Character : public CharacterBody3D {
	GDCLASS(Character, CharacterBody3D)

private:

	CollisionShape3D *nodeCollision;
	// Animation * nodeAnimation;

	Ref<Shape3D> refShape;
	Ref<PoseGroup> refPoseGroup;
	
	// TypedArray<Pose> listPose;

protected:
	static void _bind_methods();
public:
	Character();
	void _process(double _delta) override;
	~Character();

	Ref<Shape3D> getRefShape() const;
	void setRefShape(Ref<Shape3D> _shape);

	Ref<PoseGroup> getPoseGroup() const;
	void setPoseGroup(Ref<PoseGroup> _pose_group);

	// TypedArray<Pose> getListPose() const;
	// void setListPose(TypedArray<Pose> _list);
};

}

#endif