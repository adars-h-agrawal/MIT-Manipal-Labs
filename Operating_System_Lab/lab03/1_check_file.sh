#!/bin/bash
# Script to check if a given file is a directory or a regular file

echo -n "Enter file/directory name: "
read fname

if [ -d "$fname" ]; then
    echo "$fname is a directory."
elif [ -f "$fname" ]; then
    echo "$fname is a regular file."
else
    echo "$fname does not exist."
fi
