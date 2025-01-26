#ifndef POSE_H
#define POSE_H

#include <godot_cpp/classes/resource.hpp>

namespace godot{

class Pose : public Resource{
    GDCLASS(Pose, Resource)
private:
    float Height;
    float Speed;
    String Animation;
public:
    Pose();

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