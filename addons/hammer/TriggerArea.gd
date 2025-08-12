extends Trigger
class_name TriggerArea

var BodyList:Array[Node3D]

@export var EnableCharacter:bool = true
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