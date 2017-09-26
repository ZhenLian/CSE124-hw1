#!/bin/bash

if [ "$#" -ne 1 ]; then
  echo "Usage: $0 input-file.txt"
  exit 1
fi

if [ ! -f $1 ]; then
  echo "File $1 not found"
  exit 2
fi

num_lines=`wc -l < $1`
num_crlf=`grep -U $'\x0D' $1 | wc -l`

echo "Number of lines in the file: ${num_lines}"
echo "Number of lines ending in CRLF: ${num_crlf}"
