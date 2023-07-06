//?  – Higher Order Functions – Map

//*   Higher Order Functions
//*   ---> is a function that accepts functions as parameters and/or returns a function.

//*   - Map
//*   --- method creates a new array
//*   --- populated with the results of calling a provided function on every element
//*   --- in the calling array.

//*   Syntax map(callBackFunction(Element, Index, Array) { }, thisArg)
//*   - Element => The current element being processed in the array.
//*   - Index => The index of the current element being processed in the array.
//*   - Array => The Current Array

//*   Notes
//*   - Map Return A New Array

//*   Examples
//*   - Anonymous Function
//*   - Named Function

let myNums = [1, 2, 3, 4, 5, 6];

let newArray = [];

for (let i = 0; i < myNums.length; i++){
    newArray.push(myNums[i]*2)
}

console.log(newArray)

//* Same Idea with Map

let addSelf = myNums.map(function (element, index, arr) {
    //console.log(`Current Element => ${element}`)
    //console.log(`Current Index => ${index}`);
    //console.log(`Array => ${arr}`);
    //console.log(`This => ${this}`);
    return element * 2;
}, 10)

addSelf = myNums.map((element) =>  element * 2);

console.log(addSelf);

function add(element) {
    return element * 2;
}

let addition = myNums.map(add);

console.log(addition);

console.log("*".repeat(60));

    //?  – Higher Order Functions – Map Practice

//* Map
//* - Swap Cases
//* - Inverted Numbers
//* - Ignore Boolean Value

let swappingCases = "elZERo";
let invertedNumbers = [1, -10, -20, 15, 100, -30];
ignoreNumbers = "Elz123er4o";

let sw = swappingCases
  .split("")
  .map(function (ele) {
    return ele === ele.toUpperCase() ? ele.toLowerCase() : ele.toUpperCase();
  })
  .join("");

console.log(sw);

let inv = invertedNumbers.map((element) => -element);

console.log(inv);

ign = ignoreNumbers.split("").map((element) => isNaN(parseInt(element)) ? element : "").join("");

console.log(ign)

console.log("*".repeat(60));

    // ?  – Higher Order Functions – Filter

//   *- Filter
//   *--- method creates a new array
//   *--- with all elements that pass the test implemented by the provided function.

//   *Syntax filter(callBackFunction(Element, Index, Array) { }, thisArg)
//   *- Element => The current element being processed in the array.
//   *- Index => The index of the current element being processed in the array.
//   *- Array => The Current Array

// Get Friends With Name Starts With A
let friends = ["Ahmed", "Sameh", "Sayed", "Asmaa", "Amgad", "Israa"];

// Get Even Numbers Only
let numbers = [11, 20, 2, 5, 17, 10];

// Test map vs Filter
let addMap = numbers.map((element) => element * 2);
console.log(addMap);

let addFilter = numbers.filter((element) => element * 2);
console.log(addFilter);

let filteredsFriends = friends.filter((element) => element.startsWith("A"));

console.log(filteredsFriends);

let evenNumbers = numbers.filter((element => element % 2 === 0));

console.log(evenNumbers);

console.log("*".repeat(60));

    //?  – Higher Order Functions – Filter Practice


// *Filter
// *- Filter Longest Word By Number


// Filter Words More Than 4 Characters
let sentence = "I Love Foood Code Too Playing Much";

let smallWords = sentence.split(" ").filter((element) => element.length <= 4).join(" ");

console.log(smallWords)

// Ignore Numbers
let ignoreNumbers = "Elz123er4o";

let ign = ignoreNumbers
  .split("")
  .filter(function (ele) {
    return isNaN(parseInt(ele));
  })
  .join("");

console.log(ign);

// Filter Strings + Multiply
let mix = "A13BS2ZX";

let mixed = mix.split("").filter((element) => !isNaN(parseInt(element))).map((element) => element * element).join("");
console.log(mixed);

console.log("*".repeat(60));

    //?  – Higher Order Functions – Reduce

//*- Reduce
//*--- method executes a reducer function on each element of the array,
//*--- resulting in a single output value.

//*Syntax
//*reduce(callBackFunc(Accumulator, Current Val, Current Index, Source Array) { }, initialValue)
//*- Accumulator => the accumulated value previously returned in the last invocation
//*- Current Val => The current element being processed in the array
//*- Index => The index of the current element being processed in the array.
//*---------- Starts from index 0 if an initialValue is provided.
//*---------- Otherwise, it starts from index 1.
//*- Array => The Current Array

let nums = [10, 20, 15, 30];

console.log(nums)

let add = nums.reduce(function(acc, current, index, arr){
    console.log(`acc => ${acc}`);
    console.log(`current => ${current}`);
    console.log(`Current element index => ${index}`);
    console.log(`Array => ${arr
    }`);
    console.log(acc + current);
    console.log("#".repeat(30));
    return acc + current;
}, 5)

console.log(add)

console.log("*".repeat(60));

    //?  – Higher Order Functions – Reduce Practice

// *Reduce
// *- Longest Word
// *- Remove Characters + Use Reduce

let theBiggest = ["Bla", "Propaganda", "Other", "AAA", "Battery", "Test", "Propaganda_Two"];

let check = theBiggest.reduce((acc, current)=> acc.length > current.length ? acc : current)

console.log(check)

let removeChars = ["E", "@", "@", "L", "Z", "@", "@", "E", "R", "@", "O"];

let elzero = removeChars.filter((element) => element !== "@").reduce((acc, current) => acc + current);

console.log(elzero)

console.log("*".repeat(60));

    //?  – Higher Order Functions – ForEach & Practice

// *- forEach
// *--- method executes a provided function once for each array element.

// *Syntax forEach(callBackFunction(Element, Index, Array) { }, thisArg)
// *- Element => The current element being processed in the array.
// *- Index => The index of the current element being processed in the array.
// *- Array - The Current Array

// *Note
// *- Doesnt Return Anything [Undefined]
// *- Break Will Not Break The Loop

let allLis = document.querySelectorAll("ul li");

let allDivs = document.querySelectorAll(".content div");

allLis.forEach(function (element) {
  element.onclick = function () {
    //remove active class from all elements
    allLis.forEach(function (element) {
      element.classList.remove("active");
    });
    // Add Active Class To This Element
    this.classList.add("active");
    //hide all divs
    allDivs.forEach(function (element) {
      element.style.display = "none";
    });
  };
});
