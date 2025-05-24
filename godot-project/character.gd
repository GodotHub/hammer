@tool
extends CharacterBody3D

func _ready() -> void:
	AudioServer.add_bus()
