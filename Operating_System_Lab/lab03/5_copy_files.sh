#!/bin/bash
# Script to copy files of given extension to a target folder

echo -n "Enter file extension (without dot): "
read ext
echo -n "Enter destination folder: "
read dest

mkdir -p "$dest"

find . -maxdepth 1 -type f -name "*.$ext" -exec cp {} "$dest" \;
echo "Files copied to $dest."
