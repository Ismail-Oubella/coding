// let n=process.argv[2];

// n=Number(n);

// function fibo(n) {
//     if (n == 0) return 0;
//     if(n==1 || n==2) return 1;
//     return fibo(n-1) + fibo(n-2);
// }

// let result = fibo(n);

// console.log(` result is ${result} `);


// U1=1 U2=1 Un+2=Un+1+U1
// polymorphism ? generalisation ?

// let personne ={
//     nom : "John",
//     age : 30,
//     sayHi: function() {console.log(`Hi !!`);}
// }

// personne.sayHi();
// personne.age=20;
// personne.nom="Yahyawi";
// personne.pre="Ismail"

// console.log(personne);


// objets litterals 

//      function user(n,a,m) {
//          this.name=n;
//          this.age=a;
//          this.mail=m;
//          this.sayHi=function() {console.log(`Hi , i'm `+ this.name + ` I'm `+this.age+` years`);}
//      }

//      let user1=new user("John",30,"anpch@example.com");
//      let user2=new user("Yahyawi",20,"anpch@example.com");

//      user1.sayHi();
//      user2.sayHi();

// // To update  write "sudo apt install --only-upgrade code"
// //constructures d'objets

// prototype : js , class:c++,java; but it's not recommended to use it classes are better

//      function User(n, m) {
//          this.name = n;
//          this.personne = m;
//       }

//       function BR (){
//           console.log(`Hey my name is `);
//       }


//       User.prototype.pro1 = BR;


//       let u1 = new User("John", "Marry");

//       let u2 = new User("Yahyawi", "Boy");

//      u1.pro1 =


//     // correction 


// Classes 

//    class ligne {
//        constructor(name, height){
//            this.nom=name;
//            this.log=height;
//        }
   
//        taille (){
//            console.log(`Long de ${this.nom} est ${this.log}`);
//        }
//    }
   
//    l1= new ligne("Marry",10);
//    l2= new ligne("Boy",20);
   
   
//    l1.taille();
//    l2.taille();
   
//    console.log(l1)


// //heritage => generalisation de la classe

// class rectangle extends ligne{
//    constructor (x, width, height){
//        super(x,height); 
// }


// class persone {
//     constructor (nom, prenom){
//         this.name = nom;
//         this.pers=prenom;
//     }
//     tell (){
//         console.log(`Hey I'm ${this.name} ${this.pers}`);
//     }
// }

// class etu extends persone{
//     constructor (nom, prenom, CNE){
//         super(nom,prenom);
//         this.cne=CNE;
//     }

//     telletu (){
//         console.log(`Hey I'm ${this.name} ${this.pers} , I'm etu and my CNE is  ${this.cne}`);
//     }
// }

// let u1 = new etu("John", "Marry", 20);

// u1.telletu();


//  valeurs primitives

//  let name="John";

// //Objet string, Objet math, Objet date

// //! arrays 

// let arr = [1,"here",3,0.12,5,['maher',100]]; //* declaration

// console.log(arr[4]);

// for(let valeur of arr) {
//     console.log(valeur);
// }

// let persone = {
//     person : 'John',
//     age : 30,
//     sport : 'basketball',
//     cours : ['HTML', 'CSS', 'JavaScript'],
// }

// for (let valeur in persone) {
//     console.log(valeur);
// }