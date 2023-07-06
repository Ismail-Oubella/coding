    ##! q1
# echo "donner un nomber entier"
# read number

# parfait(){
# sum=0

# for i in $(seq 1 $(($1 - 1)))
# do
# if [ $(($1 % $i)) -eq 0 ]
# then
# sum=$(($sum+$i))
# fi
# done

# if [ $sum -eq $1 -a $1 -ne 0 ]
# then 
# echo "$1 est parfait!"
# else
# echo "$1 n'est parfait!"
# fi
# }

# parfait $number;

    ##! q2

# echo "give an integer number"
# read number

# sumFunction(){
#     sum=0
#     for i in $(seq 1 $(($1-1)))
#     do 
#     sum=$(($sum + ( $i * $i )))
#     done
#     echo "sum is $sum"
# }

# sumFunction $number;

    ##! q3

# echo "give me a division operation (x / y):"
# read x y

# echo "give me the number of decimal places to round to:"
# read num


# # divRelle(){
# #     div=$(($1* (10**$3)))
# #     result=$(($div/$2))
# #     result=$(($result / (10**$3)))
# #     echo "result is: $result "       
# # }


# divRelle(){
#     result=$(($1/$2))
#     rest=$(($1-($2*$result)))
#     if [ $rest -ne 0 ]
#     then
#     div=$(($rest*(10**$3)))
#     resultFloat=$(($div/$2))
#     while [ $(($resultFloat%10)) -eq  0 ]
#     do
#     resultFloat=$(($resultFloat/10))
#     done
#     echo "result is: $result.$resultFloat"
#     exit
#     fi
#     echo "result is: $result"
# }

# divRelle $x $y $num

    ##! q4

# echo "give a number"
# read number

# nombersPremiers(){
#     if [ $1 -lt 2 ]
#     then
#         echo "No premiers numbers!"
#         exit
#     fi
#     for i in $(seq 1 $(($1-1)))
#     do
#         if [ $(est_premier $i) -eq 0 ]
#         then
#             echo "$i est premier"
#         fi
#     done
# }

# est_premier(){
#     k=0;
#     for i in $(seq $1)
#     do
#         if [ $(($1%$i)) -eq 0 ]
#         then
#             let "k=k+1"
#         fi
#     done
#     if [ $k -ne 2 ]
#     then
#         echo 1
#     else
#         echo 0
#     fi    
# }

# nombersPremiers $number

    ##! q5

file=$1

cut -d ":" -f 2 $file > markes
cut -d ":" -f 1 $file > names

paste -d ":" markes names > merged
sort -nr merged > sorted

cut -d ":" -f 1 sorted > markes 
cut -d ":" -f 2 sorted > names

paste -d ":" names markes > newone

cat $file
echo -e "\n----------------------------------------------------"

cat newone

rm  markes  merged  names  newone  sorted