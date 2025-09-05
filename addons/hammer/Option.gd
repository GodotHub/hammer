extends Control
class_name Option


## 鼠标灵敏度
@export var MouseSensitivity:float = 0.1


func Init() -> void:
	pass
	#var input:InputEventKey = InputEventKey.new()
	#for action in KeyboardMap:
		#var key:Key = OS.find_keycode_from_string(KeyboardMap[action])
		#input.physical_keycode = key
		#InputMap.add_action(action)
		#InputMap.action_add_event(action, input)

func UpdataKeyboardMap(_name:String, _key:Key) -> void:
	for event in InputMap.action_get_events(_name):
		if event is InputEventKey:
			event.
	#KeyboardMap[_name] = OS.get_keycode_string(_key)
	#InputMap.action_erase_event(_name, action_get_events)
	


func _ready() -> void:
	Init()
