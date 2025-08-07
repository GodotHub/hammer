extends Area3D
class_name Trigger
## 侦测指定的行为

var Status:bool = false

@export var OrganList:Array[Organ]

func _physics_process(delta: float) -> void:
    pass
    


func TriggerLoop(_delta:float):
    for organ in OrganList:
        if organ.Reversal:
            organ.Status = !Status
        else:
            organ.Statuss = Status