extends Control
class_name MenuRoot
## 所有菜单的根节点

var ManageRootNode:ManageRoot

@export var MenuNodeList:Dictionary[String, MenuNode]:
	set(_menu_node_list):
		for _title in _menu_node_list:
			var menu:MenuNode = _menu_node_list[_title]
			menu.MenuRootNode = self
		MenuNodeList= _menu_node_list

		
## 显示指定 _title 的菜单
func ShowMenuNode(_title:String, _argument:String = "") -> void:
	var menu:MenuNode = MenuNodeList[_title]
	menu.Command(_argument)
	menu.Show()

## 显示指定 _title 的菜单
func HideMenuNode(_title:String) -> void:
	var menu:MenuNode = MenuNodeList[_title]
	if not menu.AlwaysOn:
		menu.Hide()

## 隐藏所有菜单
func HideAllMenu() -> void:
	for _title in MenuNodeList:
		HideMenuNode(_title)

#func _process(delta: float) -> void:
	#if Input.is_action_just_pressed("Esc"):
		#visible = not visible

func _ready() -> void:
	HideAllMenu()
	for _title in MenuNodeList:
		var menu:MenuNode = MenuNodeList[_title]
		if menu.AlwaysOn:
			ShowMenuNode(_title)
