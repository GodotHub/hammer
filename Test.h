#ifndef TEST_H
#define TEST_H

#include <godot_cpp/classes/resource.hpp>

namespace godot{

class Test : public Resource {
    GDCLASS(Test, Resource)

private:
    Dictionary test = {};

    int id;
    String name;
    bool enable;

protected:
    static void _bind_methods();

public:
    bool _get(const StringName &p_property, Variant &r_value) const;
    bool _set(const StringName &p_property, const Variant &p_value);
    void _get_property_list(List<PropertyInfo> *p_list) const;


};

}

#endif