#!/bin/bash
set -e

# Iterate over directories starting with 'ex0'
for dir in ex0*; do
    if [ -d "$dir" ]; then  # Check if it's a directory
        echo "Cleaning $dir"
        # Delete binary files
        find "$dir" -maxdepth 1 -type f -perm +u=x -delete
        # Delete object files
        find "$dir" -maxdepth 1 -type f -name "*.o" -delete
    fi
done
