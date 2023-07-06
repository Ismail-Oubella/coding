	#?q1

# table=("SE" "BD" "POO")
# for i in ${table[@]}
# do
#     for j in {1..10}
#     do
#     mkdir "$i" && mkdir "$i/tp"
#     mkdir "$i/tp/tp"$j""
#     done
# done

	#?q2

# echo "Give A Number : "
# read number
# if [ $number -lt 0 ]
# then
#     seq 1 -1 $number
# else
#     seq 1 $number
# fi


    #?q3

# echo "Give an Int number "
# read number

# for i in $(seq 1 10)
# do
#     echo "$number * $i = $(($number*$i))"
# done

	#?q4

# echo "Give Int number : "
# read number

# for i in $(seq 2 $(($number/2)))
# do
# if [ $(($i%2)) -eq 0 ]
# then
# echo "Not A Prime Number"
# exit 0
# fi
# done
# echo "Prime Number"

	#?q5

echo "Give number : "
read number
reverse=0
while [ $number -ne 0 ]
do
    int=$(($number%10))
    number=$(($number / 10))
    reverse=$(($reverse * 10 + $int))
done

echo $reverse