    ##! q1

# fact=1
# for i in $(seq $1)
# do
#     fact=$(($fact * $i))
# done

# echo "Facoriel de $1 est: $fact"

    ##! q2


# if [ "$1" = "Lundi" ]
# then
#     echo "1"
# elif [ "$1" = "Mardi" ]
# then
#     echo "2"
# elif [ "$1" = "Mercredi" ]
# then
#     echo "3"
# elif [ "$1" = "Jeudi" ]
# then
#     echo "4"
# elif [ "$1" = "Vendredi" ]
# then
#     echo "5"
# elif [ "$1" = "Samedi" ]
# then
#     echo "6"
# elif [ "$1" = "Dimanche" ]
# then
#     echo "7"
# else
#     echo "0"
# fi



    #!q3

# echo "Enter the first number: "
# read num1
# echo "Enter the second number: "
# read num2

# while [ $num2 -ne 0 ]
# do
#   remainder=$((num1 % num2))
#   num1=$num2
#   num2=$remainder
# done

# echo "The GCD of the two numbers is: $num1"

    ##!q4

# function pathof(){
#     count=0
#     path=`find ~/ -name "$1"`
#     if [ -z $path ]
#     then
#         echo "no such file or directory"
#         exit
#     fi
#     file=`find "$path" -type f`
#     for i in $file
#     do
#         if [ -x $i ]
#         then
#             count=$(($count+1))
#         fi
#     done

#     echo "$count"
# }

# pathof $1


    ##!q5

function permute(){
    test=$1
    length=0
    while [ $test -ne 0 ]
    do
        test=$(($test/10))
        length=$(($length+1))
    done
    if [ $(($length%2)) -ne 0 ]
    then
    echo "inside impaie"
        newLeft=0
        power=$((10**($length/2)))
        left=$(($1/$power))
        right=$(($1%$power))
        center=$(($1/$power))
        echo $center
        center=$(($center%10))
        echo $center
                left=$(($1/$power - $center))

        echo$right$center$left
    else
        power=$((10**($length/2)))
        left=$(($1/$power))
        right=$(($1%$power))
    fi
        echo $right$left
}

permute $1


# function permute() {
#     test=$1
#     length=0
#     while [ $test -ne 0 ]
#     do
#         test=$((test/10))
#         length=$((length+1))
#     done
#     echo $((length/2))
#     reverse=$((test/10**(length/2)))
#     echo $reverse
# }

# permute $1
