echo "donner un nomber entier"
read number

parfait(){
sum=0

for i in $(seq 1 $(($1 - 1)))
do
if [ $(($1 % $i)) -eq 0 ]
then
sum=$(($sum+$i))
fi
done

if [ $sum -eq $1 -a $1 -ne 0 ]
then 
echo "$1 est parfait!"
else
echo "$1 n'est parfait!"
fi
}

parfait $number;