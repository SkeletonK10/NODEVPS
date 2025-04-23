#!/bin/bash

# Check if problem number is provided as an argument
if [ -z "$1" ]; then
  echo "Usage: $0 <problem_number>"
  exit 1
fi

if ! [[ "$1" =~ ^[0-9]+$ ]]; then
  echo "Error: Problem number must be a numeric value."
  exit 1
fi

PROBLEM_NUMBER=$1
LANGUAGE=${2:-cpp} # Default to cpp if no second argument is provided
SOURCE_FILE="a.${LANGUAGE}"
DEST_DIR="BOJ"
DEST_FILE="$DEST_DIR/$PROBLEM_NUMBER.${LANGUAGE}"

# Create destination directory if it doesn't exist
mkdir -p "$DEST_DIR"

# Copy the source file to the destination
cp "$SOURCE_FILE" "$DEST_FILE"

# Add, commit, and push changes to git
git add "$DEST_FILE"
git commit -m "BOJ $PROBLEM_NUMBER"

echo "Committed BOJ problem $PROBLEM_NUMBER to $DEST_FILE"
