# Hammer

强化Godot的3D部分，像起源引擎Hammer编辑器一样强大易用  

[English](https://github.com/godothub/hammer) &nbsp;&nbsp;&nbsp;&nbsp;[中文](https://github.com/godothub/hammer/blob/master/README.ZH.md)  

## 类开发
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
#!/usr/bin/env python
import os
import sys

env = SConscript("godot-cpp/SConstruct") # type: ignore


env.Append(CPPPATH=["hammer/"])
sources = Glob("hammer/**/*.cpp")

if env["platform"] == "macos":
    library = env.SharedLibrary(
        "demo/bin/libgdexample.{}.{}.framework/libgdexample.{}.{}".format(
            env["platform"], env["target"], env["platform"], env["target"]
        ),
        source=sources,
    )
else:
    library = env.SharedLibrary(
        "godot-project/hammer/libgdexample{}{}".format(env["suffix"], env["SHLIBSUFFIX"]),
        source=sources,
    )

Default(library) # type: ignore

```

在项目更目录下运行scons即可


