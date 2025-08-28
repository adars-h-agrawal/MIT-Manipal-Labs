#!/bin/bash
# Script to calculate gross salary

echo -n "Enter Basic Salary: "
read basic
echo -n "Enter TA: "
read ta

gross=$(echo "$basic + $ta + (0.10 * $basic)" | bc -l)
echo "Gross Salary: $gross"
