#!/bin/bash
# Script to sort strings passed as command-line args

if [ $# -eq 0 ]; then
    echo "Usage: $0 string1 string2 ..."
    exit 1
fi

sort_strings() {
    for str in "$@"; do
        echo "$str"
    done | sort
}

echo "Unsorted:"
for arg in "$@"; do
    echo "$arg"
done

echo
echo "Sorted:"
sort_strings "$@"
