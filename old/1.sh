#!/bin/sh

#编译 main1.c main2.c
g++ main1.c
mv a.out a1.out
g++ main2.c
mv a.out a2.out
g++ solved.c
mv a.out a3.out
g++ main4.c
mv a.out a4.out

ip="10.16."

while [ true ]
do

#(1) 生成mac1.txt
echo "#build mac1.txt" > mac1.txt
for((i=1;i<=16;i++));
do
    nmap -sP -PI -PT $ip$i.0/24 >> ./mac1.txt
done


#(2) 保存副本 mac1.txt ---> mac2.txt
mv ./mac1.txt ./mac2.txt


#(3) C语言处理mac2.txt ---> mac3.txt
echo "#build mac3.txt" > mac3.txt
./a1.out


#(3) 保存副本 mac3.txt ---> mac4.txt
mv ./mac3.txt ./mac4.txt

#(4) 
echo "#build acmer2.txt" > acmer2.txt
echo "#build acmer3.txt" > acmer3.txt
./a2.out

mv ./acmer2.txt ./acmer1.txt
mv ./acmer3.txt ./acmer4.txt

#(5)
./a3.out
mv ./name_solved.txt ./name_solved1.txt

#(6)
./a4.out

done

