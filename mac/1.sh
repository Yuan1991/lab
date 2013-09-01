#!/bin/sh

g++ format_mac.c
mv a.out format_mac.out

ip="10.16."

while [ true ]
do

echo "#build mac1.txt" > mac1.txt
for((i=1;i<=16;i++));
do
    nmap -sP -PI -PT $ip$i.0/24 >> ./mac1.txt
done


mv ./mac1.txt ./mac2.txt


echo "#build mac3.txt" > mac3.txt
./format_mac.out


mv ./mac3.txt ./mac4.txt
#sleep(300)
done

