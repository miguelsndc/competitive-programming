import os
import shutil
import stat

bad_extensions = ['.prob', '.bin', '.exe', '.c.swp', '.in', '.out']
bad_dirs = ['.cph', 'build', 'Debug', "output"]
exclude = ['.vscode', '.git']

def remove_readonly(path):
    """Remove read-only permissions to allow deletion on Windows"""
    try:
        os.chmod(path, stat.S_IWRITE)
    except Exception:
        pass

def is_executable(file_path):
    """Check if a file is executable"""
    return os.access(file_path, os.X_OK)

for root, dirs, files in os.walk('.'):
    for f in exclude:
        if f in dirs:
            dirs.remove(f)
    
    for file in files:
        # Check for bad extensions OR executable files without specific extension
        if (file.endswith(tuple(bad_extensions)) or 
            (not file.endswith(tuple(bad_extensions)) and is_executable(os.path.join(root, file)))):
            path = os.path.join(root, file)
            if os.path.exists(path):
                try:
                    remove_readonly(path)
                    os.remove(path)
                except Exception as e:
                    print(f"Could not remove {path}: {e}")
    
    for dir in dirs:
        if dir.endswith(tuple(bad_dirs)):
            dir_path = os.path.join(root, dir)
            if os.path.exists(dir_path):
                try:
                    remove_readonly(dir_path)
                    shutil.rmtree(dir_path)
                except Exception as e:
                    print(f"Could not remove directory {dir_path}: {e}")