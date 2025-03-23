#include "Test.h"

using namespace godot;

void Test::_bind_methods() {
    // ClassDB::bind_method(D_METHOD("_get"), &Test::_get);
    // ClassDB::bind_method(D_METHOD("_set"), &Test::_set);
    // ClassDB::bind_method(D_METHOD("_get_property_list"), &Test::_get_property_list);
}

void Test::_get_property_list(List<PropertyInfo> *p_list) const {
    p_list->push_back(PropertyInfo(Variant::INT, "id"));
    p_list->push_back(PropertyInfo(Variant::STRING, "name"));
    p_list->push_back(PropertyInfo(Variant::BOOL, "enable"));
}


// 获取属性值
bool Test::_get(const StringName &p_property, Variant &r_value) const {
    if (p_property == StringName("id")) {
        r_value = id;
        return true;
    } else if (p_property == StringName("name")) {
        r_value = name;
        return true;
    } else if (p_property == StringName("enable")) {
        r_value = enable;
        return true;
    }
    return false;
}

// 设置属性值
bool Test::_set(const StringName &p_property, const Variant &p_value) {
    if (p_property == StringName("id")) {
        id = p_value;
        return true;
    } else if (p_property == StringName("name")) {
        name = p_value;
        return true;
    } else if (p_property == StringName("enable")) {
        enable = p_value;
        return true;
    }
    return false;
}