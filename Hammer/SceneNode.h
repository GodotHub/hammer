#ifndef SceneNode_H
#define SceneNode_H

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/classes/json.hpp>

#include <godot_cpp/classes/packed_scene.hpp>
#include <godot_cpp/classes/resource_loader.hpp>
#include <godot_cpp/classes/resource_saver.hpp>

#include <godot_cpp/classes/file_access.hpp>


namespace godot{

// json struct
// {
// "scene_list":[
//   {
//   "name":String
//   "path":String
//   "unlock":bool
//   }
// ]
// "next_directory":String
// "next_struct":String
// }

class SceneNode : public Node{
    GDCLASS(SceneNode, Node)    
private:
    struct SceneInfo
    {   
        String name;
        String path;
        bool unlock;
    };

    Vector<SceneInfo> listScene;

    Node *sceneNode;
    int sceneIndex;

    String savePath;
    String directoryPath;

    String nextDirectoryPath;
    String nextDirectoryStruct;


protected:
	static void _bind_methods();
public:

    SceneNode();
    ~SceneNode();

    int getNowScene();
    void setNowScene(int _now_scene);
    
    // Node getSceneNode();

    bool loadDirectory(const String *_directory, const String *_struct = nullptr);

    bool loadScene(const String *_name);
    bool loadNextScene();
    bool saveScene(const String *_name);

    int getSceneIndex(const String *_name);

    bool addScene(const String *_name, const String *_path, bool _unlock);
    bool setScene(const String *_name, const String *_path, const bool *_unlock);
    bool setScenePath(const String *_name, const String *_path);
    bool setSceneUnlock(const String *_name, bool _unlock);

    bool removeScene(const String *_name);
    
    PackedStringArray getSceneList();

};

}


#endif
