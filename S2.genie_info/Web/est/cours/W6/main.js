//! ECMA Script 6

//! arow functions

const a=(x,y)=>x+y;
console.log(a(3, 3));
console.log(`*****************************************************`);

//!
console.log();

let student = {
    name:"Ali",
    age : 20, 
}

console.log(student)

const { name, age } = student;
console.log(name);
console.log(age);
console.log(`*****************************************************`);

//!

console.log();

b = "first"
c = "last"
d = "date"

let Student = {
    [b + d]: "Jhon",
    [c + d]: "Doe",
    age: 20
}

console.log(Student)

console.log(Student[b + "date"]);
console.log(`*****************************************************`);

//! Closures
console.log();

function counter(init) {
    v = init;
    return function () {
        v++;
        console.log(v);
    }
}

function person(name, age, prof) { 
    secret = 0; //private attribute
    return function () {
        return {
            name,
            age,
            prof
        }
    }
}

let p = person("Ali", 20, "Software Engineer");
console.log(p);



let count = counter(0);
count(); count(); count(); count(); count(); count();

console.log(`*****************************************************`);


//!Curriying
console.log();

const prod2 = (a) => (b) => a * b;

console.log(prod2(3));
console.log(prod2(3)(5));


console.log(`*****************************************************`);

//! compose 
console.log();

const comp = (f, g) => (x) => f(g(x));
let somme = (n) => n + 1;

console.log(comp(somme, somme)(10));


console.log(`*****************************************************`);

//! Array
console.log();

//*map function

const arr = [1, 2, 3, 4, 5];
let ab = arr.map(
    (n)=>n*2
)
console.log(arr);
console.log(ab);

//*filter function

let pair = arr.filter((n) => n % 2 === 0);

console.log(pair);

//*reduce function

let reduce = arr.reduce((s, n) => s + n, 2); //! this is => 
    // s = 2; for (let n of arr){s=s+n;}
console.log(reduce);

console.log(`*****************************************************`);

//! references

console.log();

let abc = { val: 3 };
let def = abc;
let acc = { val: 3 };

console.log(abc === def);
console.log(abc === acc);

abc.val = 4;

console.log(abc.val);
console.log(def.val);
console.log(acc.val);

console.log(`*****************************************************`);

//! instanciation

console.log();

class Home {
    constructor(name, age) {
        this.name = name;
        this.age = age;
    }
    hi() {
        console.log(`Hi, my name is ${this.name}`);
    }
}

let h = new Home("Ali", 20);

h.hi();

class std extends Home {
    constructor(name, age, cne) { 
        super(name, age);
        this.cne = cne;
    }
    gethi() {
        console.log(`Hi, my name is ${this.name} and my cne is ${this.cne}`);
    }
}

console.log(`*****************************************************`);

let sd = new std("Ali", 20, 243334443);

sd.gethi();