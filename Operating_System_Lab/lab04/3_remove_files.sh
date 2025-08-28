#!/bin/bash
# Script to remove files given as command-line arguments, asking before each delete

if [ $# -eq 0 ]; then
    echo "No files specified."
    exit 1
fi

for file in "$@"; do
    if [ -e "$file" ]; then
        echo -n "Remove $file? (y/n): "
        read ans
        if [ "$ans" = "y" ]; then
            rm -f "$file"
            echo "$file deleted."
        else
            echo "$file skipped."
        fi
    else
        echo "File not found: $file"
    fi
done
