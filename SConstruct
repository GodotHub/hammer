import os
import sys

EXPORT_PATH = "godot-project/hammer/"
HAMMER_PATH = "Hammer/"
NATURE_PATH = "Nature/"

env = SConscript("godot-cpp/SConstruct") # type: ignore

sources = Glob(HAMMER_PATH + "*.cpp")  # type: ignore
sources.append(Glob(HAMMER_PATH + "Character/*.cpp")) # type: ignore

if env["platform"] == "macos":
    library = env.SharedLibrary(
        target = EXPORT_PATH + "hammer.{}.{}.framework/libgdexample.{}.{}".format(
            env["platform"], env["target"], env["platform"], env["target"]
        ),
        source = sources,
    )
else:
    library = env.SharedLibrary(
        target = EXPORT_PATH + "hammer{}{}".format(env["suffix"], env["SHLIBSUFFIX"]),
        source = sources,
    )


Default(library)  # type: ignore