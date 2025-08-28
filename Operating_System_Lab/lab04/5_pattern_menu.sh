#!/bin/bash
# Menu-driven script for searching/deleting patterns

if [ $# -lt 2 ]; then
    echo "Usage: $0 filename pattern1 [pattern2 ...]"
    exit 1
fi

file=$1
shift
patterns=("$@")

while true; do
    echo "----- MENU -----"
    echo "1. Search patterns"
    echo "2. Delete patterns from file"
    echo "3. Exit"
    read -p "Enter choice: " choice

    case $choice in
        1)
            for pat in "${patterns[@]}"; do
                echo "--- Lines containing '$pat' ---"
                grep --color=auto "$pat" "$file"
            done
            ;;
        2)
            for pat in "${patterns[@]}"; do
                sed -i "s/$pat//g" "$file"
                echo "Deleted occurrences of '$pat'."
            done
            ;;
        3) exit 0 ;;
        *) echo "Invalid choice." ;;
    esac
done
