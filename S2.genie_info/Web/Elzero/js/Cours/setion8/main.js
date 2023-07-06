    //?  – Anonymous Function And Practice

//* Function
//* - Anonymous Function
//* - Calling Named Function vs Anonymous Function
//* - Argument To Other Function
//* - Task Without Name
//* - SetTimeout

// function calc(num1, num2) {
//     return num1 + num2;
// }

let calculator = function (num1, num2) {
  return num1 + num2;
};

console.log(calculator(10, 20));

console.log("#".repeat(30));

document.getElementById("show").onclick = function () {
  console.log("Show");
};

    console.log("#".repeat(30));

setTimeout(function () {
  console.log("Good");
}, 2000);

console.log("*".repeat(60));

    //?  – Return Nested Function

//* Function
//* - Function Inside Function
//* - Return Function

    //*Exemeple One :

    console.log("#".repeat(30));
function sayMessage(fName, lName) {
    let message = "Hello";
    // Nested Function
    function concatMessage() {
        message = `${message}, ${fName} ${lName}`
    }

    concatMessage();
    return message;
}

console.log(sayMessage("Ismail", "Oubella"))

    //*Exemeple Two :

    console.log("#".repeat(30));
function sayMessage(fName, lName) {
    let message = "Hello";
    // Nested Function
    function concatMessage() {
        return `${message}, ${fName} ${lName}`
    }

    return concatMessage();
}

console.log(sayMessage("Ismail", "Oubella"))

    //*Exemeple Three :

    console.log("#".repeat(30));
function sayMessage(fName, lName) {

    let message = "Hello";
    // Nested Function

    function concatMessage() {

        function getFullName() {
            return `${fName} ${lName}`;
        }

        return `${message}, ${getFullName()}`
    }

    return concatMessage();
}

console.log(sayMessage("Ismail", "Oubella"))

console.log("*".repeat(60));

    //?  – Arrow Function Syntax

// //* Function
// //* - Arrow Function
// //* -- Regular vs Arrow [Param + No Param]
// //* -- Multiple Lines

// let print = function () { return 10; };

// let print =  _ => 10; //* () => _

// let print = (num) => num;

// let print = function (num1, num2) {
//     return num1 + num2;
// };

let print =(num1, num2) => num1 + num2;

console.log(print(100, 50));

console.log("*".repeat(60));

//?  – Scope – Global And Local

//* Scope
//* - Global And Local Scope

var a = 1;
let b = 2;

function showText() {
  var a = 10;
  let b = 20;
  console.log(`Function - From Local ${a}`);
  console.log(`Function - From Local ${b}`);
}

console.log(`From Global ${a}`);
console.log(`From Global ${b}`);

showText();

console.log("*".repeat(60));

    //?  – Scope – Block

//* Scope
//* - Block Scope [If, Switch, For]

var x = 10;
if (true) {
//   var x = 50;
//   console.log(`From Local ${x}`); //* From Local 50
  let x = 50;
  console.log(`From Local ${x}`); //* From Local 10
}

console.log(`From Global ${x}`) //* From Global 10

console.log("*".repeat(60));

    //?  – Scope – Lexical (Static)

//* Scope
//* - Lexical Scope

//* Search
//* - Execution Context
//* - Lexical Environment

// let a = 100;
function parent() {
  let a = 10;
  function chiled() {
    // let a = 20;
    console.log(`From Chiled : ${a}`);
    function grand() {
      let b = 199;
      console.log(`From Grand : ${a}`);
      console.log(`From Grand : ${b}`);
    }
      grand();
  }
  chiled();
}

parent();
