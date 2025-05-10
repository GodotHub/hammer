#include "CaptionNode.h"

using namespace godot;

CaptionNode::CaptionNode(){
    stayTime = 5;
    maxLine = 10;

    nodeContainer = memnew(VBoxContainer);
    nodeContainer->set_anchors_preset(PRESET_BOTTOM_WIDE);

    nodeBackground = memnew(Panel);
}
CaptionNode::~CaptionNode(){
    if (nodeContainer){nodeContainer->queue_free();}
}

void CaptionNode::updateHeight(){
    int line = countLine();
    nodeContainer->set_visible(line);
    nodeContainer->set_visible(line);

    if (line > maxLine){removeCaption();}
    Size2i size = nodeContainer->get_size();
    nodeBackground->set_size(size);
}

void CaptionNode::addCaption(const String *_content, const Color *_color, const String *_source){
    Label *label = memnew(Label);
    label->set_autowrap_mode(TextServer::AutowrapMode::AUTOWRAP_WORD_SMART);

    if (_source == nullptr){
        String source = String();
        _source = &source;
    }

    if (_color == nullptr){
        Color color = Color(1, 1, 1);
        _color = &color;
    }

    String text = *_source + *_content;

    label->set_text(*_source + *_content);
    label->set_modulate(*_color);

    nodeContainer->add_child(label, false, INTERNAL_MODE_FRONT);

    updateHeight();
}



void CaptionNode::removeCaption(int _index){
    Node *node = nodeContainer->get_child(_index);
    updateHeight();
}

int CaptionNode::countLine(){
    int count = 0;
    int node_number = nodeContainer->get_child_count();
    for (int i = 0; i < node_number; i++){
        Label *label = (Label *)nodeContainer->get_child(i);
        count += label->get_line_count();
    }
    return count;
}

