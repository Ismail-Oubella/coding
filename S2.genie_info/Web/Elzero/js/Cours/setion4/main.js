    //?  – Comparison Operators

//* Comparison Operators
//* - == Equal
//* - != Not Equal
//* 
//* - === Identical
//* - !== Not Identical
//* 
//* - > Larger Than
//* - >= Larger Than Or Equal
//* 
//* - < Smaller Than
//* - <= Smaller Than Or Equal


console.log(10 == "10" ); //* True
console.log(10 === "10" ); //* False Campare Value && Type

console.log(10 != "10"); //* False
console.log(10 === "10" ); //* False Campare Value && Type
console.log(10 !== "10" ); //* True


console.log("************************************************************")
console.log("################################")

    //?  – Logical Operators

//* Logical Operators
//* - ! Not
//* - && And
//* - || Or

console.log(!true); //* False
console.log(!(10 == "10"));

console.log(10 == "10" && 10 > 8 && 10 >= 50) //* False

console.log(10 == "10" || 10 > 80 || 10 > 50) //* True

console.log("************************************************************")

    //?  – If Condition

//* Control Flow
//* - if
//* - else if
//* - else
//* 
//* if (Condition) {
//*  Block Of Code
  

var price = 100;
var discount = false;
var discountAmount = 30;
var country = "Egypt";

if (discount == true) { price -= discountAmount; }
else if (country == "India") { price -= 40; }
else {price -= 5}
console.log(price);

console.log("************************************************************")


    //?  – Nested If Condition

var price = 100;
var discount = false;
var discountAmount = 30;
var country = "Egypt";
var student = true;

if (discount === true) {

    price -= discountAmount;

}   else if (country === "Egypt") {

    if (student === true) {

    price -= discountAmount + 30;

    } else {

    price -= discountAmount + 10;

    }

} else {

  price -= 10;

}

console.log(price);

console.log("************************************************************")

  //?  – Conditional ternary Operator

let theName = "Mona";
let theGender = "Female";
let theAge = 30;

if (theGender === "Male") {
  console.log("Mr");
} else {
  console.log("Mrs");
}

//* Condition ? If True : Id False

theGender === "Male" ? console.log("Mr") : console.log("Mrs");
let result = theGender === "Male" ? "Mr" : "Mrs";

console.log(result);

console.log(theGender === "Male" ? "Mr" : "Mrs")
console.log(`Hello ${theGender === "Male" ? "Mr" : "Ms"} ${theName}!`);

theAge < 20 ? console.log(20) : theAge > 20 && theAge < 60 ? console.log("20 -> 60") : theAge > 60 ? console.log("Larger than 60") : console.log("Unknown");

console.log("************************************************************")

  //?    – Nullish Coalescing Operator

//*  
//*  Logical Or ||
//*  -- Null + Undefined + Any Falsy Value
//*  Nullish Coalescing Operator ??
//*  -- Null + Undefined

console.log(Boolean(100)) //* true
console.log(Boolean(0)) //* => false
console.log(Boolean(-100)) //* true
console.log(Boolean("")) //* => false
console.log(Boolean(null)) //* => false

let price = null;

console.log(`The price is $${price || 200}`);

//*The nullish coalescing (??) operator is a logical operator that returns its right-hand side operand when its left-hand side operand is null or undefined, and otherwise returns its left-hand side operand.

console.log(`The price is ${price ?? 200}`);

console.log("************************************************************")

  //?    – Switch Statement

//* Same type && same value


//*  Switch Statement
//*  switch(expression) {
//*    Case 1:
//*      // Code Block
//*      break;
//*    Case 2:
//*      // Code Block
//*      break;
//*    Default:
//*      // Code Block
//*  }
//*  - Default Ordering
//*  - Multiple Match
//*  - ===

let day = 0;

switch (day) {
  case 0: console.log("Monday"); break;
  case 1: console.log("Tuesday"); break;
  case 2: console.log("Wednesday"); break;
  default : console.log("unknown Day"); break;
}