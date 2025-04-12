#ifndef CHARACTER_H
#define CHARACTER_H

#include "PoseGroup.h"
#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/shape3d.hpp>
#include <godot_cpp/classes/packed_scene.hpp>
#include <godot_cpp/classes/resource_loader.hpp>
#include <godot_cpp/classes/character_body3d.hpp>
#include <godot_cpp/classes/collision_shape3d.hpp>

namespace godot {

class Character : public CharacterBody3D {
	GDCLASS(Character, CharacterBody3D)

private:
	Node3D *nodeModel;
	CollisionShape3D *nodeCollision;

	String fileModel;

	Ref<Shape3D> refShape;
	Ref<PoseGroup> refPoseGroup;

	Vector3 vecHeadFront;
	Vector3 vecBodyFront;


protected:
	static void _bind_methods();
public:
	Character();
	~Character();

	void initCharacter();

	String getFileModel() const;
	void setFileModel(String _file_model);

	Ref<Shape3D> getRefShape() const;
	void setRefShape(const Ref<Shape3D> &_shape);
	Ref<PoseGroup> getPoseGroup() const;
	void setPoseGroup(const Ref<PoseGroup> &_pose_group);

	Vector3 getHeadFront() const;
	void setHeadFront(const Vector3 &_head_front);
	Vector3 getBodyFront() const;
	void setBodyFront(const Vector3 &_body_front);
};

}

#endif