import os
import shutil

bad_extensions = ['.prob', '.bin', '.exe', '.c.swp', '.in', '.out']
bad_dirs = ['.cph', 'build', 'Debug', "output"]
exclude = ['.vscode', '.git']

for root, dirs, files in os.walk('.'):
    for f in exclude:
        if f in dirs:
            dirs.remove(f)

    for file in files:
        if file.endswith(tuple(bad_extensions)):
            path = os.path.join(root, file)
            if os.path.exists(path):
                os.remove(path)
    
    for dir in dirs:
        if dir.endswith(tuple(bad_dirs)):
            dir_path = os.path.join(root, dir)
            if os.path.exists(dir_path):
                shutil.rmtree(dir_path)


