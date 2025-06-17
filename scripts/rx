#!/bin/bash

# Check if input.txt exists
if [ ! -f input.txt ]; then
  echo "Error: Input file 'input.txt' not found." >&2
  exit 1
fi

# Check if the language is specified (default to cpp)
LANGUAGE=${1:-cpp}

if [ "$LANGUAGE" = "cpp" ]; then
  # Check if a.cpp exists
  if [ ! -f a.cpp ]; then
    echo "Error: Source file 'a.cpp' not found." >&2
    exit 1
  fi

  # Compile the source file
  g++ -o a.exe -std=c++20 a.cpp

  # Execute the compiled program with input and output redirection
  ./a.exe < input.txt > output.txt

elif [ "$LANGUAGE" = "py" ]; then
  # Check if a.py exists
  if [ ! -f a.py ]; then
    echo "Error: Source file 'a.py' not found." >&2
    exit 1
  fi

  # Execute the Python script with input and output redirection
  python3 a.py < input.txt > output.txt

else
  echo "Error: Unsupported language '$LANGUAGE'. Use 'cpp' or 'py'." >&2
  exit 1
fi