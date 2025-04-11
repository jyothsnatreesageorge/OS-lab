#!/bin/bash
echo "Enter filename"
read file
echo "Enter word"
read word
if [ ! -f $file ]
then
   echo "File not found"
else
   count=$(grep -o "$word" "$file" | wc -l)
   if [ $count -eq 0 ]
   then
      echo "Word not found in file"
   else
      echo "Word appeared $count times in file"
   fi
fi
