extends Organ
class_name OrganPanel

@export var PanelNode:StaticBody3D

@export var PointNode:Marker3D

@export var MoveSpeed:float = 3
@export var RotateSpeed:float = 90



func OnLoop(_delta:float) -> void:
    if not PanelNode or not PointNode:
        return

    Move(_delta, PointNode.global_position)
    Rotate(_delta, PointNode.global_rotation_degrees)

    
func OffLoop(_delta:float) -> void:
    Move(_delta, global_position)
    Rotate(_delta, global_rotation)
    

func Move(_delta:float, _to:Vector3):
    PanelNode.global_position = PanelNode.global_position.move_toward(_to, MoveSpeed * _delta)

func Rotate(_delta:float, _to:Vector3):
    PanelNode.global_rotation_degrees = PanelNode.global_rotation_degrees.move_toward(_to, RotateSpeed * _delta)