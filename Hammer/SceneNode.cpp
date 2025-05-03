#include "SceneNode.h"

#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void SceneNode::_bind_methods(){
    // ClassDB::bind_method(D_METHOD("getSceneIndex"), &SceneNode::getSceneIndex);
	// ClassDB::bind_method(D_METHOD("setSceneIndex", "nowScene"), &SceneNode::setSceneIndex);
    // ADD_PROPERTY(PropertyInfo(Variant::INT, "nowScene"), "setSceneIndex", "getSceneIndex");

    

}

// int SceneNode::getNowScene(){return nowSceneIndex;}
// void SceneNode::setNowScene(int _now_scene){nowSceneIndex = _now_scene;}

SceneNode::SceneNode(){
    sceneIndex = 0;
    sceneNode = nullptr;
}

SceneNode::~SceneNode(){
    if (sceneNode != nullptr){
        sceneNode->queue_free();
    }
};

bool SceneNode::loadDirectory(const String *_directory, const String *_struct){
    const String DEFAULT_STRUCT = "struct.json";
    if (_struct == nullptr){_struct = &DEFAULT_STRUCT;}
    Ref<FileAccess> struct_file = FileAccess::open(*_directory + *_struct, FileAccess::ModeFlags::READ);
    if (!struct_file.is_valid()){return false;}
    
    String struct_text = struct_file->get_as_text();
    if (!struct_text){return false;}
    Dictionary struct_json = JSON::parse_string(struct_text);
    if (!struct_json){return false;}

    Array scene_list = struct_json["scene_list"];
    for (int i = 0; i < scene_list.size(); i++){
        Dictionary info_json = scene_list[i];
        const String name = info_json["name"];
        const String path = info_json["path"];
        bool unlock = info_json["unlock"];
        addScene(&name, &path, &unlock);
    }
    
    // String next_directory = struct_json[next_directory];
    nextDirectoryPath = struct_json["next_directory"];

    directoryPath = *_directory;
    return true;
}

bool SceneNode::loadScene(const String *_name){
    int index = getSceneIndex(_name);
    if (index == -1){return false;}
    SceneInfo scene_info = listScene[index];
    Ref<PackedScene> scene_packed = ResourceLoader::get_singleton()->load(scene_info.path);

    if (scene_packed.is_valid()){return false;}

    sceneNode->queue_free();
    sceneNode = scene_packed->instantiate();
    add_child(sceneNode);

    return true;
}
bool SceneNode::loadNextScene(){
    const SceneInfo *scene_info = &listScene[sceneIndex];
    const String name = scene_info->name;
    return loadScene(&name);
}

bool SceneNode::saveScene(const String *_name){
    if (savePath == ""){return false;}
    Ref<PackedScene> scene_packed = memnew(PackedScene);
    scene_packed->pack(sceneNode);
    Error status = ResourceSaver::get_singleton()->save(scene_packed, savePath + *_name);
    if (status != OK){return false;}
    return true;
}

int SceneNode::getSceneIndex(const String *_name){
    for (int i = 0; i < listScene.size(); i++){
        SceneInfo scene = listScene[i];
        if (scene.name == _name){return i;}
    }
    return -1;
}

bool SceneNode::addScene(const String *_name, const String *_path, bool _unlock){
    if (getSceneIndex(_name) != -1){return false;}
    SceneInfo scene_info = {*_name, *_path, _unlock};
    listScene.append(scene_info);
    return true;
}

bool SceneNode::setScene(const String *_name, const String *_path, const bool *_unlock){
    int index = getSceneIndex(_name);
    if (index == -1){return false;}
    SceneInfo *scene_info = &listScene.write[index];
    if (_path != nullptr){scene_info->path = *_path;}
    if (_unlock != nullptr){scene_info->unlock = _unlock;}
    return true;
}

bool SceneNode::setScenePath(const String *_name, const String *_path){return setScene(_name, _path, nullptr);}
bool SceneNode::setSceneUnlock(const String *_name, bool _unlock){return setScene(_name, nullptr, &_unlock);}

bool SceneNode::removeScene(const String *_name){
    int index = getSceneIndex(_name);
    if (index == -1){return false;}
    // Vector<Scene>::Iterator it = listScene.begin();
    // for (int i = 0; i < listScene.size(); i++){
    //     ++ it;
    // }
    // listScene.erase(it);
    listScene.remove_at(index);
    return true;
}

PackedStringArray SceneNode::getSceneList(){
    PackedStringArray list;
    for (int i = 0; i < listScene.size(); i++){
        SceneInfo scene = listScene[i];
        list.append(scene.name);
    }
    return list;
}


