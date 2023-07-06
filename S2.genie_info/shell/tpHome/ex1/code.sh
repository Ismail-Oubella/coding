    ##! q1

# for i in $@
# do
#     echo "$i"
# done 

    
    ##! q2

# if  [ $(($1 % 2)) -eq 0 ]
# then 
#     echo "$1 est pair"
# else
#     echo "$1 est impair"
# fi
    
    ##! q3
    
# if [ $(($1 % 400)) -eq 0 -o $(($1 % 4 )) -eq 0 -a $(($1 % 100)) -ne 0 ]
# then
#     echo "$1 est une anne Bissextile"
# else
#     echo "$1 n'est une anne Bissxtile"
# fi

    ##! q4
    
# file=`find . -name "*.txt"`

# for i in $file 
# do
# cat $i
# done

    ##! q5
    
# path=`find ~/ -name $1`
# if [ -e $path -a -d $path ]
# then
#     echo "Those are repos inside the parameter repo"
#     repos=`find $path -type d`
#     for i in $repos
#     do
#         echo $i
#     done
# else
#     echo "its not a repo"
# fi
    ##! q6


    ##! q7

# file=`find ~/ -name $1`

# if [ -n "$file" ]
# then
#     for i in $file 
#     do
#     ls -l "$i" 
#     done
# else
#     echo "No such file "
# fi

    ##! q8

# minutes=$(($1/60))
# secondes=$(($1%60))
# echo "$1 by second, has just converted int $minutes min: $secondes s"
    
    ##! q9

# if [ $1 -ge 0 -a $1 -le 20 ]
# then
#     if [ $1 -lt 10 ]
#     then
#         echo "Travail Insufisant"
#     elif [ $1 -lt 12 ]
#     then
#         echo "Passable"
#     elif [ $1 -lt 14 ]
#     then
#         echo "Assez Bien"
#     elif [ $1 -lt 16 ]
#     then
#         echo "Bien"
#     elif [ $1 -lt 20 ]
#     then 
#         echo "Tres Bien"
#     fi
# else
#     echo "Mark must be between 0 And 20"
# fi

    ##! q10

# if [ -f $1 ]
# then
#     echo "Rows Number is this file is " `wc -l $1`
# else
#     echo "This is not a file "
# fi

    ##! q11

# if [ $# -ge 3 ]
# then
#     max=$1
#     for i in $@
#     do
#         if [ $i -gt $max ]
#         then
#             max=$i
#         fi
#     done
#     echo "Max is $max"
# else
#     echo "You have to insert 3 parameters at least to make this code works"
# fi