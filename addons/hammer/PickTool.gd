extends Tool
class_name PickTool

var PickObject:RigidBody3D

@export var ObjectPos:Marker3D

@export var OBJECT_ACC:float = 5000
@export var RELEASE_SPEED:float = 5

func SelfCheck() -> bool:
	if not ObjectPos:
		return false
	return true

## 功能主循环
func ToolLoop(_delta: float, _parent: Character, _ray: RayCast3D) -> void:
	if PickObject:
		PickObject.linear_velocity = (ObjectPos.global_position - PickObject.global_position) * _delta * OBJECT_ACC
	if Input.is_action_just_pressed("E"):
		if PickObject:
			var velocity_normal:Vector3 = PickObject.linear_velocity.normalized()
			var velocity_length:float = PickObject.linear_velocity.length()
			if velocity_length > RELEASE_SPEED:
				PickObject.linear_velocity = velocity_normal * RELEASE_SPEED


			_parent.ToolLock = false
			PickObject = null
		elif _ray.is_colliding():
			var object = _ray.get_collider()
			if object is RigidBody3D:
				_parent.ToolLock = true
				PickObject = _ray.get_collider()
