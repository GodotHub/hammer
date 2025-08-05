extends CharacterBody3D
class_name Character

## 跳跃速度
@export var JUMP_SPEED:float = 5

@export_group("Gravity")
## 重力方向
@export var GRAVITY_DIR:Vector3 = Vector3.DOWN
## 重力加速度
@export var GRAVITY_ACC:float = 9.8

@export_group("Move")
@export_subgroup("Air")
## 空中速度
@export var AIR_SPEED:float = 1
## 空中加速度
@export var AIR_ACC:float = 0
@export_subgroup("Stand")
## 站立速度
@export var STAND_SPEED:float = 3
## 站立加速度
@export var STAND_ACC:float = 10
@export_subgroup("Squat")
## 下蹲速度
@export var SQUAT_SPEED:float = 2
## 下蹲加速度
@export var SQUAT_ACC:float = 5

var MoveDir:Vector3 = Vector3.ZERO ## 移动方向
var MoveSpeed:float = SQUAT_SPEED ## 移动速度
var MoveAcc:float = SQUAT_ACC ## 移动加速度

@export_group("Navigation")
## 导航目标
@export var TargetNode:Node3D
## 导航载体
@export var NavAgent:NavigationAgent3D

func _ready() -> void:
	NavAgent.target_position = TargetNode.global_position

func _physics_process(_delta: float) -> void:
	Navigation(_delta)


## 平滑移动
func SmoothMove(_delta:float) -> void:
	var move_vector:Vector3 = velocity.slide(global_basis.y)

	velocity -= (move_vector - MoveDir * MoveSpeed) * _delta * MoveAcc
	velocity += GRAVITY_ACC * GRAVITY_DIR * _delta

	move_and_slide()

## 导航
func Navigation(_delta:float) -> void:
	if TargetNode == null or NavAgent == null:
		return
	if NavAgent.is_navigation_finished():
		MoveSpeed = 0
		MoveAcc = 0
		return
	MoveSpeed = STAND_SPEED
	MoveAcc = STAND_ACC
	MoveDir = (NavAgent.get_next_path_position() - global_position).normalized()

	SmoothMove(_delta)
