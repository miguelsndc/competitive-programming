#!/bin/bash

cpp_compiler="C:\\TDM-GCC-64\\bin\\g++.exe"
cpp_args=("-std=c++14" "-O2" "-Wall")

if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <path_to_cpp_file>"
    exit 1
fi

cpp_file="$1"

# Compile
executable_name=$(basename "$cpp_file" .cpp).exe
output_folder="executables"
mkdir -p "$output_folder"
"$cpp_compiler" "${cpp_args[@]}" "$cpp_file" -o "$output_folder/$executable_name"

# Run
if [ -f "$output_folder/$executable_name" ]; then
    echo "Executable built successfully: $output_folder/$executable_name"
    echo "Running the executable:"
    "$output_folder/$executable_name"
else
    echo "Error: Failed to build executable"
fi
