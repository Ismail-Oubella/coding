//* var and let 

name = 'John Doe';

console.log(name);

var name = "mateldoe";

console.log(name);

//* self executed function

let f=function(){
    for(let i=0;i<10;i++){
        console.log(`Hello, World`)
    }
}

//* letteral object

let person ={
    name : "John Doe",
    age : 20,
    message : function(){
        console.log(`Hello ,my name is ${this.name} and I'm ${this.age}`);
    }
}

person.message();

//* constructor functions 

function std(name, age, id){
    this.name = name;
    this.age = age;
    this.id = id;
    this.message = function(){
        console.log(`Hello,my name is ${this.name} and I'm ${this.age}, I'm a student and my id is ${this.id}`);
    }
}


let std1= new std("Ismail",20,"D136481739");

std1.message();

//* Prototype

function user(name, job){
    this.name = name;
    this.job = job;
}

user.prototype.message = function(){
    console.log(`Got you !`);
}

let me= new user("Ismail", "Software Engineer");

me.message();


//* Classes 

class home{ 
    constructor(name, age, id){
        this.name = name;
        this.age = age;
        this.id = id;
    }
    hey (){
        console.log(`I'm ${thsi.name}`);
    }
}

class empl extends home{
    constructor(name, age, id, salary){
        super(name, age, id);
        this.salary = salary;
    }
    sal (){
        console.log(`I'm ${this.name} and my salary is ${this.salary}`);
    }
}

let emp= new empl("Ismail", 20, "D13648173", 10000);

emp.sal();
