# Hammer

Enhance Godot's 3D capabilities, making it as powerful and user-friendly as the Hammer Editor from the Source Engine.

[English](https://github.com/godothub/hammer)&nbsp;&nbsp;&nbsp;&nbsp;[中文](https://github.com/godothub/hammer/blob/master/README.ZH.md)    

## Classes
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

## Build from Source

```
- hammer/
- godot-cpp/
- godot-project/
- SConstruct
```

Write the following content in `SConstruct`:

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

Run `scons` in the project root directory.