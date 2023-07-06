#     #?q1

# echo -e "Those Are Your Parameters : ";

# for j in $@
# do 
# echo "$j"

# done 

    #?q2
# echo "Give A Number To Indicates The Type "
# read number

# if [ $(($number % 2)) -eq 0 ]
# then 
#   echo "$number is even!"
# else 
#   echo "$number is odd!"
# fi

    #?q3

# echo "Give A Year : "
# read year;

# if [ $(($year % 400)) -eq 0 ] || [ $(($year % 4)) -eq 0 ]  && [ $(($year % 100)) -ne 0 ]
# then 
# echo "$year is a leap year."
# else 
# echo "$year is not a leap year."
# fi

    #?q4

# a=`find -name "*.txt"`

# for i in $a
# do
#   cat $i
# done

    #?q5

# file=$1;
# if [ -d $file ]
#     then   
#     echo "those Are files in Your Rep : "
#     files=`find -type d`
#     for i in $files 
#     do
#     echo "$i"
#     done
# else 
#     echo "This is not a rep !"
# fi

    #?q6



	#?q7

# echo "Give Name Of A file In Personal Repo"
# read file
# path=$(find ~/ -name $file)
# if [ -n "$path" ]
# then 
# ls -l "$path"
# else
# echo "There Is No File Named $file"
# fi

	#?q8

# echo "Give A Number (By Seconds) To Be Converted To Minutes "
# read time
# if [ $time -lt 60 ]
# then 
# Minutes=0
# Seconds="$time"
# else
# Minutes=$(("$time"/60))
# Seconds=$(($"time"%60))
# fi
# echo "Time is $Minutes min $Seconds sec"

	#?q9

# note=$1

# if [ "$note" -le 20 -a "$note" -ge 0 ]
# then
#     if [ "$note" -lt 10 ]
#     then 
#     echo "travail insuffisant"
#     elif [ "$note" -lt 12 ]
#     then
#     echo "Passable"
#     elif [ "$note" -lt 14 ]
#     then
#     echo "Assez bien"
#     elif [ "$note" -lt 16 ]
#     then
#     echo "bien"
#     elif [ "$note" -le 20]
#     then
#     echo "Tres Bien"
#     fi
# else
# echo "le nombre saisi ne correspond pas à une note"
# fi

	#?q10

# file=$1

# if [ -f "$file" ]
# then
# echo "Le nombre de lignes est : `wc -l $file`"
# else
# echo "there is no such file "
# fi

	#?q11

# numbers="$@"

# if [ $# -lt 3 ]
# then
# echo "There Is No enough Numbers To Be Compered"
# else
#     max=$1
#     for i in $numbers
#     do
#         if [ "$i" -gt "$max" ]
#         then
#         max="$i"
#         fi
#     done
#     echo "Max is : "$max" "
# fi

