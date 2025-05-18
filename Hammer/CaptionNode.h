#ifndef CaptionNode_H
#define CaptionNode_H


#include <godot_cpp/classes/control.hpp>
#include <godot_cpp/classes/label.hpp>

#include <godot_cpp/classes/v_box_container.hpp>
#include <godot_cpp/classes/panel.hpp>

#include <godot_cpp/variant/color.hpp>
#include <godot_cpp/variant/typed_array.hpp>

namespace godot{

class CaptionNode : public Control{
    GDCLASS(CaptionNode, Control)
private:
    int stayTime;
    int maxLine;
    VBoxContainer * nodeContainer;
    Control * nodeBackground;

    void updateHeight();

protected:
	static void _bind_methods();
public:
    CaptionNode();
    ~CaptionNode();
    
    int countLine() const;

    void addCaption(const String *_content, const Color *_color = nullptr, const String *_source = nullptr);
    
    void removeCaption(int _index = -1);
};


}

#endif