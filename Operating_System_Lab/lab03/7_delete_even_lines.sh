#!/bin/bash
# Script to delete even-numbered lines from a file

echo -n "Enter filename: "
read fname

if [ -f "$fname" ]; then
    sed -i 'n;d' "$fname"
    echo "Even-numbered lines deleted from $fname."
else
    echo "File not found!"
fi
