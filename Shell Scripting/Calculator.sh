#!/bin/bash
echo "MENU"
echo -e "1.ADD\n2.SUBTRACT\n3.MULTIPLY\n4.DIVIDE\n5.MODULUS\n"
ch='n'
while [ "$ch" == "n" ]
do
echo "Enter choice:"
read var
echo "Enter a:"
read a
echo "Enter b"
read b
case $var in
   1)c=$((a+b))
     echo "$c";;
   2)c=$((a-b))
     echo "$c";;
   3)c=$((a*b))
     echo "$c";;
   4)c=$((a/b))
     echo "$c";;
   5)c=$((a%b))
     echo "$c";;
   *)echo "Invalid Choice";;
esac
echo "Do you want to exit?(y/n)?"
read ch
done
