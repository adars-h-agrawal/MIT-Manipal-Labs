#!/bin/bash
# Script to replace 'ex:' with 'Example:' if at start of line or after period

for file in *.txt; do
    sed -i -E 's/^ex:/Example:/; s/\.ex:/\.Example:/g' "$file"
    echo "Processed: $file"
done
