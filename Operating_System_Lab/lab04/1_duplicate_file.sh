#!/bin/bash
# Script to make a duplicate copy of a specified file

if [ $# -ne 1 ]; then
    echo "Usage: $0 filename"
    exit 1
fi

file=$1

if [ -f "$file" ]; then
    cp "$file" "${file}_copy"
    echo "Duplicate created: ${file}_copy"
else
    echo "Error: File '$file' does not exist."
fi
