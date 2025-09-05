extends Node
class_name Scnene

@export_group("Describe")
## 说明器节点
@export var DescribeNode:Describe
## 说明器文件路径
@export var DescribePath:String

#@export_group("Player")
### 玩家节点
#@export var PlayerNode:Player
### 玩家文件路径
#@export var PlayerPath:String

@export_group("Scene")
## 用于场景管理与切换
@export var ScenePath:PackedStringArray;
## 当前场景序号
@export var SceneIndex:int:
	set(_scene_index):
		if _scene_index > 0 and _scene_index < ScenePath.size() - 1:
			SceneIndex = _scene_index
## 当前场景节点
@export var SceneNode:Node

## 初始换场景管理
func Init() -> void:
	if not DescribeNode:
		if DescribePath:
			var describe_node:Describe = load(DescribePath).instantiate()
			add_child(describe_node)
			DescribeNode = describe_node
		else:
			print("请配置DescribeNode")
			#return
	
	#if not PlayerNode:
		#if PlayerPath:
			#var player_node:Player = load(PlayerPath).instantiate()
			#add_child(player_node)
			#PlayerNode = player_node
		#else:
			#print("请配置PlayerNod")
	
	if not SceneNode:
		ChangeScene(0)

## 切换下一场景
func NextScene() -> void:
	ChangeScene(SceneIndex + 1)

## 更改场景
func ChangeScene(_index:int) -> void:
	SceneIndex = _index
	var scene:Node = load(ScenePath[SceneIndex]).instantiate()
	if SceneNode:
		SceneNode.queue_free()
	add_child(scene)
	SceneNode = scene

func _ready() -> void:
	Init()
