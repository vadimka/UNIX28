#!/bin/bash

Password=0

for ((i=0;i<10;i++))
do
	for ((j=0;j<10;j++))
  	do
		for ((k=0;k<10;k++))
   	 	do
			for ((l=0;l<10;l++))
			do
				Password=$i$j$k$l
        			7za e tex2html-test.tar.7z -p$Password -y >/dev/null
        			if [ $? -eq "0" ]
        			then
					echo "Password is $Password"
          				exit 0
        			else
					echo $Password
        			fi
			done
		done
	done
done
