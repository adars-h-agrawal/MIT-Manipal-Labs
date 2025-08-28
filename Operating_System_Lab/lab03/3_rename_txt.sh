#!/bin/bash
# Script to change .txt extension to .text recursively

find . -type f -name "*.txt" | while read file; do
    newname="${file%.txt}.text"
    mv "$file" "$newname"
    echo "Renamed: $file -> $newname"
done
