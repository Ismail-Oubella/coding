    //?  – Object – Introduction

//  *Object
//  *- Intro and What Is Object
//  *- Testing Window Object
//  *- Accessing Object

user = {
    //properties
    theName: "Ismail",
    theAge: 20,
    //Methods
    sayHello: () => `Hello, World!`,
};

console.log(user)
console.log(user.sayHello())

// console.log("*".repeat(60))

    //?  – Dot Notation vs Bracket Notation

//  *Object
//  *- Dig Deeper
//  *- Dot Notation vs Bracket Notation
//  *- Dynamic Property Name

let myVar = "country"

user = {
    theName: "Osama",
    "country of": "Egypt",
    country: "Morocco",
};

console.log(user.theName);
console.log(user["country of"]);
console.log(user["theName"]);
console.log(user[myVar]);

console.log("*".repeat(60))

    //?  – Nested Object And Advanced Examples

//  *Object
//  *- Nested Object And Trainings

user = {
    name: "Osama",
    age: 11,
    skills: ["HTML", "CSS", "Js"],
    available: false,
    addresses: {
        ksa: "Riyadh",
        egypt: {
            one: "Cairo",
            two : "Giza",
        },
    },
    checkAv: () => this.available === true ? `Free for work` : `Not Free`,
};

console.log(user)
console.log(user.checkAv())
console.log(user.addresses.egypt.one);
console.log(user["addresses"]["egypt"]["one"]);

console.log("*".repeat(60))

    //?  – Create Object With New Keyword

//  *Object
//  *- Create With New Keyword new Object();

let user = new Object({
    age : 20,
});
console.log(user)

user.age = 10;
user["name"] = "Ismail"

console.log(user)

user.sayHello = () => `Hello!`;

console.log(user.sayHello());

console.log("*".repeat(60))

    //?  – This Keyword

//  *Function this Keyword
//  *- this Introduction
//  *- this Inside Object Method
//  *--- When a function is called as a method of an object,
//  *--- its this is set to the object the method is called on.
//  *- Global Object
//  *- Test Variables With Window And This
//  *- Global Context
//  *- Function Context

//  *Search
//  *- Strict Mode

console.log(this) //* => Window

myVar = 100;

console.log(window.myVar);
console.log(this.myVar);

function sayHello() {
  console.log(this);
  return this;
}
sayHello();

console.log(sayHello() === window); //* => True

document.getElementById("cl").onclick = function () { console.log(this); };

user = {
  age: 38,
  ageInDays: function () {
    return this.age * 365;
  },
};

// console.log("*".repeat(60))

    //?  – Create Object With Create Method

//   *Object
//   *- Create Object With Create Method

let user = {
  age: 20,
  doubleAge: function () {
    return this.age * 2;
  },
};

console.log(user);
console.log(user.age);
console.log(user.doubleAge());

let obj = Object.create({});

console.log(obj)

obj.a = 100;

console.log(obj);

let copyObj = Object.create(user);

copyObj.age = 39;

console.log(copyObj);
console.log(copyObj.age);
console.log(copyObj.doubleAge());

console.log("*".repeat(60))

    //?  – Create Object With Assign Method

//   *Object
//   *- Create Object With Assign Method

let obj1 = {
  prop1: 1,
  meth1: function () {
    return this.prop1;
  },
};

let obj2 = {
  prop2: 2,
  meth2: function () {
    return this.prop2;
  },
};

let targetObject = {
  prop1: 100,
  prop3: 3,
};

let finalObject = Object.assign(targetObject, obj1, obj2);

finalObject.prop1 = 200;
finalObject.prop1 = 4;

console.log(finalObject);

let newObject = Object.assign({}, obj1, { prop5: 5, prop6: 6 });

console.log(newObject);
