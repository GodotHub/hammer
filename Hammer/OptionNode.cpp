#include "OptionNode.h"

using namespace godot;

OptionNode::OptionNode(){
    setFOV(90);
    const Vector2i vec2i = Vector2i(1280, 720);
    setScreenSize(&vec2i);
    setScreenMode(FullScreen);
    setShadowEnable(true);

    serverAudio = memnew(AudioServer);
    setMainVolume(1);
    setGameVolume(1);
    setMusicVolume(1);
    setDialogVolume(1);
    setUIVolume(1);

    setMouseSensity(0.05);
}
OptionNode::~OptionNode(){
    memdelete(serverAudio);
}

void OptionNode::setVolume(int _index, const String *_name, float _volume){
    serverAudio->add_bus(_index);
    serverAudio->set_bus_name(_index, *_name);
    serverAudio->set_bus_volume_linear(_index, volumeMain);
}

void OptionNode::setFOV(int _fov){FOV = _fov;}
int OptionNode::getFOV() const {return FOV;}

void OptionNode::setScreenSize(const Vector2i *_size_screen){
    sizeScreen = *_size_screen;
    get_window()->set_size(sizeScreen);
}
Vector2i OptionNode::getScreenSize() const {return sizeScreen;}

void OptionNode::setScreenMode(ScreenMode _mode_screen){
    if (_mode_screen > ScreenModeMax || _mode_screen < 0){
        modeScreen = FullScreen;
    } else {
        modeScreen = _mode_screen;
    }
    Window::Mode mode;
    switch (modeScreen){
        case FullScreen:
            mode = Window::MODE_FULLSCREEN;
            break;
        case Exclusive:
            mode = Window::MODE_EXCLUSIVE_FULLSCREEN;
            break;
        case Window:
            mode = Window::MODE_WINDOWED;
            break;
        get_window()->set_mode(mode);
    }
}
OptionNode::ScreenMode OptionNode::getScreenMode() const {return modeScreen;}

void OptionNode::setShadowEnable(bool _enable_shadow){enableShadow = _enable_shadow;}
bool OptionNode::getShadowEnable() const {return enableShadow;}


void OptionNode::setMainVolume(float _volume_main){
    volumeMain = _volume_main;
    const String name = "Main";
    setVolume(0, &name, volumeMain);

}
float OptionNode::getMainVolume() const {return volumeMain;}

void OptionNode::setGameVolume(float _volume_game){
    volumeGame = _volume_game;
    const String name = "Main";
    setVolume(1, &name, volumeGame);
}
float OptionNode::getGameVolume() const {return volumeGame;}

void OptionNode::setMusicVolume(float _volume_music){
    volumeMusic = _volume_music;
    const String name = "Music";
    setVolume(2, &name, volumeMusic);
}
float OptionNode::getMusicVolume() const {return volumeUI;}

void OptionNode::setDialogVolume(float _volume_dialog){
    volumeDialog = _volume_dialog;
    const String name = "Dialog";
    setVolume(3, &name, volumeDialog);
}
float OptionNode::getDialogVolume() const {return volumeDialog;}

void OptionNode::setUIVolume(float _volume_ui){
    volumeUI = _volume_ui;
    const String name = "UI";
    setVolume(4, &name, volumeUI);
}
float OptionNode::getUIVolume() const {return volumeUI;}



void OptionNode::setMouseSensity(float _sensity_mouse){sensityMouse = _sensity_mouse;}
float OptionNode::getMouseSensity() const {return sensityMouse;}