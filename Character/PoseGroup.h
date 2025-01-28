#ifndef POSE_GROUP_H
#define POSE_GROUP_H

#include "Pose.h"
#include <godot_cpp/classes/resource.hpp>

namespace godot{

class PoseGroup : public Resource{
    GDCLASS(PoseGroup, Resource)
private:
    TypedArray<Pose> Group;
public:
    TypedArray<Pose> getPoseGroup();
    void setPoseGroup(TypedArray<Pose> _group);
protected:
	static void _bind_methods();
};

}

#endif