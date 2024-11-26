#!/bin/bash

if [ -z "$1" ]; then
  echo "Usage: $0 <source-file.cpp>"
  exit 1
fi

filename=$(basename -- "$1")
filename="${filename%.*}"

echo "Compiling $filename..."
g++ -o2 -o "/tmp/$filename" "$1"
if [ $? -ne 0 ]; then
  echo "Compilation failed."
  exit 1
fi

echo "Running $filename..."
"/tmp/$filename"
