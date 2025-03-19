# Check if input.txt exists
if [ ! -f input.txt ]; then
  echo "Error: Input file 'input.txt' not found." >&2
  exit 1
fi

# Check if a.cpp exists
if [ ! -f a.cpp ]; then
  echo "Error: Source file 'a.cpp' not found." >&2
  exit 1
fi

# Compile the source file
g++ -o a.exe -std=c++20 a.cpp

# Execute the compiled program with input and output redirection
./a.exe < input.txt > output.txt