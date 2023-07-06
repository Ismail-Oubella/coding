    //?  – Variables Introduction

var user = "Ismail";
var age = 20;

    //?  – Identifiers Name Conventions And Rules

var userName; //*Naming in js is camelCase

    //?  -Var, Let, Const Compare

//* Var is the only that can be redeclared, Cannot access before declaration (undefined), Variable Scope Drama (var after declaration is added to Window && it can be accessible by window.nameOfVar)
//* Let cannot be redeclared, Cannot access before declaration (error), No Variable Scop Drama, 
//* Const cannot be redeclared, Cannot access before declaration (error), No Variable Scop Drama, 

const a = 1;
console.log(a);
// var a = 2;

    //?  – String Syntax And Character Escape Sequences

//* \ operator : Escape + Line continue

console.log(`Elzero \\Web \`School\``);
console.log("Elzero \
Web \
Shcool ");

console.log("Elzero Web \nSchool");

    //?  – Concatenation

let ab = "We love"
let b = "Js"; 

console.log(ab + " " + b);

    //?  – Template Literals (Template Strings)

let A = "We Love";
let B = "Js";
let C = "And";
let D = "Programming"; 

console.log(A, B,"\n",
    C, D);

console.log(`${A} ${B} 
    ${C} \  ${D}`);


