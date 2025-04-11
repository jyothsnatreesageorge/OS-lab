$ cat pal.sh
#!/bin/bash
echo "Enter number 1"
read n1
echo "Enter number 2"
read n2
for (( i=$((n1+1));i<$n2;i++ ))
do
   temp=$i
   num=$i
   sum=0
   while [ $temp -gt 0 ];
   do
      rem=$((temp%10))
      sum=$((sum*10+rem))
      temp=$((temp/10))
   done
   if [ $sum -eq $num ]
   then
       echo "$num"
   fi
done
