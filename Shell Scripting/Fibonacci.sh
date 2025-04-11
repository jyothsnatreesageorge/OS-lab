#!/bin/bash
echo "Enter the number of terms:"
read n
echo "Fibonacci Series"
if [ $n -eq 1 ]
then
   echo "0"
elif [ $n -eq 2 ]
then
   echo -e "0\n1"
else
   a=0
   b=1
   echo -e "$a\n$b"
   for ((i=2;i<n;i++))
   do
      c=$((a+b))
      echo $c
      a=$b
      b=$c
   done
fi
