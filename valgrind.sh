#!/bin/bash

# Get the argument
ARGS=$@

# Run valgrind with the argument
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=leaks.log -s ./fractol "$ARGS"

# Optional: Print the log file after execution
echo "Valgrind completed. Check leaks.log for details."