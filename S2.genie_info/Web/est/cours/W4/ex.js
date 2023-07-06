// console.log('Hello World!');
// // console.log(process.argv);

// let a=process.argv[2];
// let b=process.argv[3];

// a=Number(a);
// b=Number(b);

// console.log(`la somme est ${a+b}`);

// a=2;
// b=3;

// let som=a+b;

// console.log(`Somme est ${som}`);

// // function fact (a){
// //     if (a==1 || a==0)
// //     {
// //         return 1;
// //     }
// //     return ((a-1)*fact(a-1));
// // }




// // console.log(`fact est ${fact(4)}`);

let c=process.argv[2];

c=Number(c);


function etoile(c){
    if(c==0) return;
    if(c>0){
        process.stdout.write('*');
    }
    etoile(c-1);
}

function all(a){
    if(a>1){
        all(a-1);
    }
    etoile(a);
    console.log();
}

all(c);



// nombre des nombre premiers < n 
calculer 

function nombrePremiers(n){
    let k;
    let m=0;
    for(let i=2 ; i<n ; i++){
        k=0;
        for(let j=2 ; j<=i/2 ; j++){
            if(i%j==0){
                k++;
            }
        }
        if(k==0){m++};
    }
    return m;
}

let c=process.argv[2];

c=Number(c);

console.log(`${nombrePremiers(c)}`);

function calcul(a){

}