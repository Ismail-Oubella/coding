exercices du cours page 27
##############################################
question5
echo type est : `file $1`
##############################################
question 6
let "s = $1 + $2"
let "p = $1 * $2"
let "q = $1 / $2"
let "m = $1 % $2"
let "d = $1 - $2"

echo "la somme est : " $s
echo "la difference est : " $d
echo "le produit est : " $p
echo "le quotient est : " $q
echo "le modulo est : " $m
##############################################
question : reecrire le script de la page 28 avec if sans else
et avec echo une seule fois
a=inferieur
if [ $1 -ge $2 ]
then
	a=superieur
fi
echo " $1 est $a a $2"
##############################################
exemple boucle for
for cmpt in $@
do
	echo "le parametre est: $cmpt"
done
##############################################
question page 31
for rep in $@
do
	ls -l $rep
done

la boucle for page 31 affiche la 1ere colonne du fichier passwd,
la 1ere colonne contient les utilisateurs
##############################################
test du script while
read -p "entrer une chaine : " chaine
[ -z "$chaine" ]
do
	echo "vous n'avez rien entre, reessayer"
done
##############################################
test du script until
i=0
until [ $i -gt $1 ]
do
	echo $i
	let "i = $i + 1"
done


