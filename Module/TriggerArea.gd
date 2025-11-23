extends Trigger
class_name TriggerArea
## 区域检测触发器

var BodyList:Array[Node3D] # 成员列表

## 检测角色
@export var EnableCharacter:bool = true
## 检测物体
@export var EnableRigid:bool = true

func _ready() -> void:
	body_entered.connect(BodyEnter)
	body_exited.connect(BodyExit)

func _physics_process(_delta: float) -> void:
	TriggerLoop(_delta)

func TriggerLoop(_delta:float):
	if BodyList.size() > 0:
		Status = true
	else:
		Status = false

func BodyEnter(_body:Node3D) -> void:
	if EnableCharacter and _body is Character:
		BodyList.append(_body)
	elif EnableRigid and _body is RigidBody3D:
		BodyList.append(_body)

func BodyExit(_body:Node3D) -> void:
	if _body in BodyList:
		BodyList.erase(_body)
