#!/bin/bash
# Script to perform line, word, char count on a file

if [ $# -ne 2 ]; then
    echo "Usage: $0 option filename"
    echo "Options: -linecount  -wordcount  -charcount"
    exit 1
fi

opt=$1
file=$2

if [ ! -f "$file" ]; then
    echo "File not found!"
    exit 1
fi

case $opt in
    -linecount) echo "Line Count: $(wc -l < "$file")" ;;
    -wordcount) echo "Word Count: $(wc -w < "$file")" ;;
    -charcount) echo "Character Count: $(wc -c < "$file")" ;;
    *) echo "Invalid option" ;;
esac
