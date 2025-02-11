#ifndef POSE_GROUP_H
#define POSE_GROUP_H

#include "Pose.h"
#include "PoseGroup.h"
#include <godot_cpp/classes/resource.hpp>

namespace godot{

class PoseGroup : public Resource{
    GDCLASS(PoseGroup, Resource)
private:
    TypedArray<Pose> Group;
public:
    TypedArray<Pose> getGroup();
    void setGroup(TypedArray<Pose> _group);

    Ref<Pose> getItem(String _name);
protected:
	static void _bind_methods();
};

}

#endif