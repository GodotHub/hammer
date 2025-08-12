extends Node3D
class_name Organ
## 对被触发的Trigger作出反应

var Status:bool = false
var Reversal:bool = false

@export var TriggerList:Array[Trigger]


func _physics_process(_delta: float) -> void:
	OrganLoop(_delta)
	

func OrganLoop(_delta:float):
	OrganStatus()
	if Status:
		OnLoop(_delta)
	else:
		OffLoop(_delta)

func OrganStatus() -> void:
	for t in TriggerList:
		if !t.Status:
			Status = false
			return
	Status = true

## 开启状态主循环
## 重载此函数进行配置
func OnLoop(_delta:float) -> void:
	pass

## 关闭状态主循环
## 重载此函数进行配置
func OffLoop(_delta:float) -> void:
	pass
