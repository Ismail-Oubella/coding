    //?  – Arithmetic Operators

console.log(10 - "Number") //* => Nan Not a Number
console.log(typeof NaN) //* => Number

console.log(2 ** 4) //* exp 

let num = 1;
num++; //* Post Increment
++num; //* Pre Increment
console.log("************************************************************")
    //?  – Unary Plus And Negation Operators

//* + Unary Plus[returns number if its not a number]
//* - Unary Negation [returns number if its not a number + Negates It]

console.log(100)
console.log(+"100") 
console.log(+"-100")
console.log(+"Oussama") //*=> NaN
console.log(+"-100.9")
console.log(+"0xff") //* => 255
console.log(+true) //* => 1

    //
    console.log("################################")

console.log(100)
console.log(-"100") //* => -100 
console.log(-"-100") //* => 100
console.log(-"Oussama") //*=> NaN
console.log(-"-100.9")
console.log(-"0xff") //* => -255
console.log(-true) //* => -1

    //

console.log(Number("100"));
console.log("************************************************************")
    
    //?  – Type Coercion

var a = "10";
let b = 20;
let c = true;

console.log(a - b); //* => -10
console.log("" - 2); //* => -2
console.log("************************************************************")

    //?  – Assignment Operators

var a = 10;
a += 20;

console.log(a );
console.log("************************************************************")

    //?  –Number

console.log(1000000);
console.log(1_000_000); //* => 1000000 Syntactic sugar "_"
console.log(1e6);
console.log(10 ** 6);
console.log(Number.MAX_SAFE_INTEGER); //* => Max  : 9007199254740991
console.log(Number.MAX_VALUE); //* => Max Value in JS : 1.7976931348623157e+308

console.log("************************************************************")

    //?  – Number Methods

//* toString => (Number).toString() OR Number..toString()

console.log(1000000..toString());

//* toFixed => (Number).toFixed() OR Number..toFixed(N) The number of digits to appear after the decimal point;

    console.log("################################")


console.log(100.555555.toFixed(2));

//* The parseInt() function parses a string argument and returns an integer of the specified

    console.log("################################")


console.log(parseInt("100.555555"));

//* The parseFloat() function parses a string argument and returns a floating-point number of the specified

    console.log("################################")


console.log(parseFloat("100.555555"));

//*The Number.isInteger() static method determines whether the passed value is an integer.

    console.log("################################")


console.log(Number.isInteger("100"));
console.log(Number.isInteger(100.555555));
console.log(Number.isInteger(100));

//* The Number.isNaN() static method determines whether the passed value is NaN.

    console.log("################################")


console.log(Number.isNaN("Ismail"/10));
console.log(Number.isNaN(100.555555));

console.log("************************************************************")

    //?  – Math Object

//* The Math.round() static method returns the value of a number rounded to the nearest integer.

console.log(Math.round(99.2)); //* => 99
console.log(Math.round(99.5)); //* => 100
console.log(Math.round(99.9)); //* => 100

//* The Math.ceil() static method always rounds up and returns the smaller integer greater than or equal to a given number.

    console.log("################################")


console.log(Math.ceil(99.2)); //* => 100
console.log(Math.ceil(99.01)); //* => 100

//* The Math.floor() static method always rounds down and returns the smaller integer less than or equal

    console.log("################################")


console.log(Math.floor(99.2)); //* => 99
console.log(Math.floor(99.01)); //* => 99

//* The Math.max() static method returns the largest of the numbers given as input parameters, or -Infinity if there are no parameters.

    console.log("################################")


console.log(Math.max(100, 200, 3, 4));
console.log(Math.max());

//* The Math.min() static method returns the smallest of the numbers given as input parameters, or Infinity if there are no parameters.

    console.log("################################")


console.log(Math.min(100, 200, 3, 4));
console.log(Math.min());

//*The Math.pow() static method returns the value of a base raised to a power. That is

    console.log("################################")


console.log(Math.pow(2, 3)); //* => 8

//*he Math.random() static method returns a floating-point, pseudo-random number that's greater than or equal to 0 and less than 1, with approximately uniform distribution over that range 

    console.log("################################")


console.log(Math.random());

//* The Math.trunc() static method returns the integer part of a number by removing any fractional digits.

    console.log("################################")


console.log(Math.trunc(99.5)); //* => 99