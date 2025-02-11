# Hammer

强化Godot的3D部分，像起源引擎Hammer编辑器一样强大易用  

[English](https://github.com/godothub/hammer)&nbsp;&nbsp;&nbsp;&nbsp;[中文](https://github.com/godothub/hammer/blob/master/README.ZH.md)  

## 类
* [ ] Option
  * [ ] Keyboard
  * [ ] Mouse
  * [ ] Video
  * [ ] Audio
* [ ] NetWork
  * [ ] Multiple
  * [ ] TCP
* [ ] Character
  * [ ] Player
  * [ ] NPC
  * [x] Pose
  * [x] PoseGroup
* [ ] Interact
  * [ ] Trigger
  * [ ] Action
* [ ] Prop
* [ ] Chapter

## 自构建
```
- hammer/
- godot-cpp/
- godot-project/
- SConstruct
```

在 `SConstruct` 中编写如下内容

```
import os
import sys

path = "godot-project/hammer/"

env = SConscript("godot-cpp/SConstruct") # type: ignore

env.Append(CPPPATH=["hammer/"])
sources = Glob("hammer/Register.cpp")  # type: ignore
sources.append(Glob("hammer/Character/Character.cpp")) # type: ignore
sources.append(Glob("hammer/Character/Pose.cpp")) # type: ignore
sources.append(Glob("hammer/Character/PoseGroup.cpp")) # type: ignore

if env["platform"] == "macos":
    library = env.SharedLibrary(
        target = path + "hammer.{}.{}.framework/libgdexample.{}.{}".format(
            env["platform"], env["target"], env["platform"], env["target"]
        ),
        source = sources,
    )
else:
    library = env.SharedLibrary(
        target = "godot-project/hammer/hammer{}{}".format(env["suffix"], env["SHLIBSUFFIX"]),
        source = sources,
    )


Default(library)  # type: ignore
```

在项目更目录下运行scons即可


