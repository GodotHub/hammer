@tool
extends Character

@onready var vbox = $Panel/VBoxContainer

func uph():
	print(vbox.get_rect())

func _ready() -> void:
	print(vbox.get_rect())
	var node = Node.new()
	vbox.add_child(node, false, Node.INTERNAL_MODE_FRONT)
	#vbox.move_child(node, 0)

func _process(delta: float) -> void:
	var node = vbox.get_child(0)
	if node.name == "Label":
		
		#vbox.remove_child(node)
		node.queue_free()
		uph()
