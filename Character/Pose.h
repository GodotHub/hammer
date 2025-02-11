#ifndef POSE_H
#define POSE_H

#include <godot_cpp/classes/resource.hpp>

namespace godot{

class Pose : public Resource{
    GDCLASS(Pose, Resource)
private:
    String Name;
    float Height;
    float Speed;
    String Animation;

    void initPose(String _name, float _height, float _speed, String _animation);
public:
    Pose();
    Pose(Pose *_pose);
    Pose(String _name, float _height, float _speed, String _animation);

    String getName() const;
    void setName(String _name);

    float getHeight() const;
    void setHeight(float _height);

    float getSpeed() const;
    void setSpeed(float _speed);

    String getAnimation() const;
    void setAnimation(String _animation);


protected:
	static void _bind_methods();
};

}

#endif