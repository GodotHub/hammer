@tool
extends Node
class_name Test


@export var InteractionDistance:float = 10:
	set(_interaction_distance):
		InteractionDistance = _interaction_distance
		InteractionDistanceFunction()

func InteractionDistanceFunction():
	print(InteractionDistance)

func _ready() -> void:
	InteractionDistance = 5


@export var energy = 0:
	set(value):
		energy = value
		update_configuration_warnings()

func _get_configuration_warnings():
	if energy < 0:
		return ["Energy 必须大于等于 0。"]
	else:
		return []