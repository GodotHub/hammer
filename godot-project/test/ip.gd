#@tool
extends EditorInspectorPlugin


func _can_handle(object):
	# We support all objects in this example.
	return true

func _parse_begin(object: Object):
	if object is OptionButton:
		var test = Button.new()
		test.text = "test"
		add_custom_control(test)
