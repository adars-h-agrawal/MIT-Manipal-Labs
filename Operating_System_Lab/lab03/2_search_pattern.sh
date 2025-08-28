#!/bin/bash
# Script to search for a pattern inside all files of a given directory

echo -n "Enter directory path: "
read folder
echo -n "Enter search pattern: "
read pattern

if [ -d "$folder" ]; then
    grep -rl "$pattern" "$folder"
else
    echo "Directory does not exist!"
fi
