extends Node3D
class_name Tool

@export var Distance:float = 10

func SelfCheck() -> bool:
    return true

## 功能主循环
func ToolLoop(_delta:float, _parent,_ray:RayCast3D):
    pass

