#!/bin/bash

# Check if an argument is provided
if [ $# -ne 1 ]; then
    echo "Usage: ./valgrind.sh <arg>"
    exit 1
fi

# Get the argument
ARG=$1

# Run valgrind with the argument
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=leaks.log -s ./fractol "$ARG"

# Optional: Print the log file after execution
echo "Valgrind completed. Check leaks.log for details."