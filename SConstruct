import os

path = "hammer/"

def find_cpp_files(directory):
    cpp_files = []
    for root, _, files in os.walk(directory):
        for file in files:
            if file.endswith(".cpp"):
                cpp_files.append(os.path.join(path + root, file))
    return cpp_files

sources = find_cpp_files('.')

Return('sources') # type: ignore
