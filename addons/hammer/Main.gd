extends Node
class_name ManageRoot
## 对游戏进行管理

@export var MenuRootNode:MenuNode:
	set(_menu_root_node):
		MenuRootNode = _menu_root_node
		_menu_root_node.ManageRootNode = self
		update_configuration_warnings()

@export var ArchiveData:Dictionary[StringName, String] = {
	"Archieve1": "res://Achieve/Archieve1",
	"Archieve2": "res://Achieve/Archieve2",
	"Archieve3": "res://Achieve/Archieve3",
}

@export var OptionData:Dictionary = {
	"WindowMode" : 0,
	"MasterVolume" : 100,
}


## 警告信息
func _get_configuration_warnings() -> PackedStringArray:
	var warning:PackedStringArray
	pass
	
	return warning

func _ready() -> void:
	pass
	#if not SceneNode:
		#ChangeScene(0)

### 场景管理
### 切换下一场景
#func NextScene() -> void:
	#ChangeScene(SceneIndex + 1)
#
### 更改场景
#func ChangeScene(_index:int) -> void:
	#SceneIndex = _index
	#var scene:Node = load(ScenePath[SceneIndex]).instantiate()
	#if SceneNode:
		#SceneNode.queue_free()
	#add_child(scene)
	#SceneNode = scene


# 
