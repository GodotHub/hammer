#ifndef OptionNode_H
#define OptionNode_H

#include <godot_cpp/classes/control.hpp>
#include <godot_cpp/classes/window.hpp>
#include <godot_cpp/classes/audio_server.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

namespace godot{

class OptionNode : public Control{
    GDCLASS(OptionNode, Control)
private:
    // 视频
    int FOV;

    Vector2i sizeScreen;

    enum ScreenMode{
        FullScreen = 0,
        Exclusive = 1,
        Window = 2,
        ScreenModeMax = 3,
    };
    ScreenMode modeScreen;

    bool enableShadow;

    // 音频
    AudioServer *serverAudio;

    float volumeMain; // 0

    float volumeGame; // 1
    float volumeMusic; // 2
    float volumeDialog; // 3
    float volumeUI; // 4

    void setVolume(int _index, const String *_name, float _volume);

    // 操作
    float sensityMouse;


protected:
	static void _bind_methods();

public:
    OptionNode();
    ~OptionNode();

    void setFOV(int _fov);
    int getFOV() const;

    void setScreenSize(const Vector2i *_size_screen);
    Vector2i getScreenSize() const;

    void setScreenMode(ScreenMode _mode_screen);
    ScreenMode getScreenMode() const;

    void setShadowEnable(bool _enable_shadow);
    bool getShadowEnable() const;


    void setMainVolume(float _volume_main);
    float getMainVolume() const;
    void setMusicVolume(float _volume_music);
    float getMusicVolume() const;
    void setUIVolume(float _volume_ui);
    float getUIVolume() const;
    void setGameVolume(float _volume_game);
    float getGameVolume() const;
    void setDialogVolume(float _volume_dialog);
    float getDialogVolume() const;


    void setMouseSensity(float _sensity_mouse);
    float getMouseSensity() const;



};

}

#endif