extends MenuNode

@export var TreeNode:Tree = $Tree:
	set(_tree_node):
		TreeNode = _tree_node
		_tree_node.item_activated.connect(Selected)
		_tree_node.item_edited.connect(Edit)

enum MenuPageEnum {StartMenu, OptionMenu}
var MenuPage:MenuPageEnum

var OptionItem:Dictionary = {
	"WindowMode" : {
		"Mode" : TreeItem.CELL_MODE_RANGE,
		"Text" : "FullScreen,Windowed",
	},
	"EnableShadow" : {
		"Mode" : TreeItem.CELL_MODE_CHECK,
	},
	"GameVolume" : {
		"Mode" : TreeItem.CELL_MODE_RANGE,
		"Range" : {
			"Min" : 0,
			"Max" : 100,
			"Step" : 1
		},
	}
}

func Command(_argument:String) -> void:
	match _argument:
		"Archive":
			DrawOptionPage()
		"Option":
			DrawOptionPage()

func Selected(_item:TreeItem) -> void:
	pass

func Edit(_item:TreeItem) -> void:
	pass

func DrawArchivePage() -> void:
	TreeNode.set_hide_root(true)
	var root:TreeItem = TreeNode.create_item()
	

func DrawOptionPage() -> void:
	TreeNode.set_hide_root(true)
	TreeNode.set_columns(2)
	var root:TreeItem = TreeNode.create_item()
	
	for _title in OptionItem:
		var item:TreeItem = TreeNode.create_item(root)
		var argument:Dictionary = OptionItem[_title]
		item.set_text(0, _title)
		item.set_cell_mode(1, argument["Mode"])
		item.set_editable(1, true)
		if argument.has("Text"):
			item.set_text(1, argument["Text"])
		if argument.has("Range"):
			var range:Dictionary = argument["Range"]
			item.set_range_config(1, range["Min"], range["Max"], range["Step"])

func SetOptionValue(_title:StringName) -> void:
	pass


func _ready() -> void:
	MenuRootNode.ShowMenuNode("SecondMenu", "Option")
