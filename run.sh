#!/bin/bash

# 检查是否提供了源文件
if [ -z "$1" ]; then
  echo "Usage: $0 <source-file.cpp>"
  exit 1
fi

# 提取文件名（不带扩展名）
filename=$(basename -- "$1")
filename="${filename%.*}"

# 编译源文件
g++ -o /tmp/"$filename" "$1"
if [ $? -ne 0 ]; then
  echo "Compilation failed."
  exit 1
fi

# 运行生成的可执行文件
echo "Running $filename..."
./"$filename"
