    ##! q1

# list=$@
# for i in $list
# do
#     mkdir "$i" && mkdir "$i"/TP
#     for j in $(seq 10)
#     do
#         mkdir "$i"/TP/TP"$j"
#     done
# done

# tree 
# for i in $list
# do
#     rm -r "$i"
# done


    ##! q2                                                                      

# echo "Give a number: "
# read number

# if [ $number -lt 0 ]
# then
#     echo "This Is your DESC Counter  : "
#     for i in $(seq 1 -1 $number)
#     do
#         echo $i >> numbers  
#     done
# else 
#     echo "This Is your ASC Counter  : "
#     for i in $(seq $number)
#     do
#         echo $i >> numbers
#     done
# fi

# cat numbers
# rm numbers
    ##! q3

# echo "Give an int number : "
# read num
# for i in $(seq 10)
# do
#     echo "$num * $i =   " $(($num*$i))
# done
    ##! q4

# echo "Give an int number"
# read num
# for i in $(seq 2 $(($num/2)))
# do
#     if [ $(($num%$i)) -eq 0 ]
#     then
#     echo "$num not Premier"
#         exit
#     fi
# done
#     echo "$num is Premier"

                    ##????
    ##! q5

number=$1
new=0
while [ $number -ne 0 ]
do
    int=$(($number%10))
    number=$(($number/10))
    new=$(($new*10 + $int))
done
echo $new



