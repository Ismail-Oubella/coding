    //?  – Array Big Introduction

//* Arrays
//* - Create Arrays [Two Methods] new Array() + []
//* - Access Arrays Elements
//* - Nested Arrays
//* - Change Arrays Elements
//* - Check For Array Array.isArray(arr);

let myFriends = ['John', 'Mary', 'Jane', ["Alice", "Bob", "Charlie"]];

console.log(`Hello, ${myFriends[0]}`);
console.log(`Hello, ${myFriends[1][3]}`);
console.log(`Hello, ${myFriends[3]}`);
console.log(`Hello, ${myFriends[3][1][0]}`);

console.log(myFriends);
myFriends[1] = "Ali"
console.log(myFriends);

myFriends[3] = "Fatima";

console.log(myFriends);
console.log(typeof myFriends); //* => object
console.log(Array.isArray(myFriends)); //* => true

console.log("************************************************************")

    //?  – Using Length With Array

console.log(myFriends.length)
myFriends[myFriends.length] = "Jamal"

console.log(myFriends)
console.log(myFriends.length); 

myFriends.length = 3;
console.log(myFriends);

myFriends.length = 4;
console.log(myFriends);
//* the length of an array is the number of elements it contains, and it can be used to delete elements by decrese the length of the array like in the prev example

console.log("************************************************************")

    //?  – Add And Remove From Array

myFriends = ['John', 'Mary', 'Jane', "Alice", "Bob", "Charlie"];


//*  Arrays Methods [Adding And Removing]
//*  - unshift("", "") Add Element To The First
//*  - push("", "") Add Element To The End
//*  - shift() Remove First Element From Array
//*  - pop() Remove Last Element From Array

//* The unshift() method adds one or more elements to the beginning of an array and returns the new length of the array.

    console.log("################################")

console.log(myFriends);

myFriends.unshift("ismail", "ali");

console.log(myFriends);

//* The push() method adds one or more elements to the end of an array and returns the new length of the array.

    console.log("################################")


console.log(myFriends);

myFriends.push("Iman", "Samah");

console.log(myFriends);

//* The shift() method removes the first element from an array and returns that removed element. This method changes the length of the array.

    console.log("################################")


console.log(myFriends);

let firstName = myFriends.shift();

console.log(`First Name: ${firstName}`);

console.log(myFriends);

//* The pop() method removes the last element from an array and returns that element. This method changes the length of the array.

    console.log("################################")


console.log(myFriends);

let lastName = myFriends.pop();

console.log(`Last Name: ${lastName}`);

console.log(myFriends);

console.log("************************************************************")

    //?  – Searching Array


// * Arrays Methods [Search]
// * - indexOf(Search Element, From Index [Opt])
// * - lastIndexOf(Search Element, From Index [Opt])
// * - includes(valueToFind, fromIndex [Opt]) [ES7]

//* The indexOf() method returns the first index at which a given element can be found in the array, or -1 if it is not present.

myFriends = ['John', 'Mary', 'Jane', "Alice", "Bob", "Charlie"];

    console.log("################################")
    
console.log(myFriends);

console.log(myFriends.indexOf("Alice", 5)); // => -1

//* The lastIndexOf() method, given one argument: a substring to search for, searches the entire calling string, and returns the index of the last occurrence of the specified substring. Given a second argument: a number, the method returns the last occurrence of the specified substring at an index less than or equal to the specified number.

    console.log("################################")

console.log(myFriends); 
console.log(myFriends.lastIndexOf("Bob")); //* => 4

console.log(myFriends.lastIndexOf("Bob", -2)); //* => search for bob will start at index length-2

//* The includes() method determines whether an array includes a certain value among its entries, returning true or false as appropriate.

    console.log("################################")

console.log(myFriends);
console.log(myFriends.includes("Alice")); //* => true
console.log(myFriends.includes("Oussama")); //* => false

if (myFriends.includes("Ahmed") === false) {
    console.log("Not Found");
}

console.log("************************************************************")

    //?  -Sortting Array


//* Arrays Methods [Sort]
//* - sort(Function [Opt])
//* - reverse

//* The sort() method sorts the elements of an array in place and returns the reference to the same array, now sorted. The default sort order is ascending, built upon converting the elements into strings, then comparing their sequences of UTF-16 code units values.

    console.log("################################")


myFriends = [10, "Sayed", "Mohamed", "90", 9000, 100, 20, "10", -20, -10];

console.log(myFriends);
console.log(myFriends.sort())

//* The reverse() method reverses an array in place and returns the reference to the same array, the first array element now becoming the last, and the last array element becoming the first. In other words, elements order in the array will be turned towards the direction opposite to that previously stated.

    console.log("################################")
    

console.log(myFriends);
console.log(myFriends.reverse())

console.log("************************************************************")

    //?  – Slicing Array
 
//*   Arrays Methods [Slicing]
//*   - slice(Start [Opt], End [Opt] Not Including End)
//*   --- slice() => All Array
//*   --- If Start Is Undefined => 0
//*   --- Negative Count From End
//*   --- If End Is Undefined || > Indexes => Slice To The End Array.length
//*   --- Return New Array
//*   - splice(Start [Mand], DeleteCount [Opt] [0 No Remove], The Items To Add [Opt])
//*   --- If Negative => Start From The End
 

myFriends = ["Ahmed", "Sayed", "Ali", "Osama", "Gamal", "Ameer"];

//* The slice() method returns a shallow copy of a portion of an array into a new array object selected from start to end (end not included) where start and end represent the index of items in that array. The original array will not be modified.

    console.log("################################")


console.log(myFriends);
console.log(myFriends.slice());
console.log(myFriends.slice(1));
console.log(myFriends.slice(1, 3));
console.log(myFriends.slice(-3));
console.log(myFriends.slice(1, -2));
console.log(myFriends.slice(-4, -2));
console.log(myFriends);


//* The splice() method changes the contents of an array by removing or replacing existing elements and/or adding new elements in place. To access part of an array without modifying it, see slice(). 


    console.log("################################")



myFriends.splice(0, 0, "Sameer", "Samara");
console.log(myFriends);

console.log("************************************************************")

    //? – Joining Arrays


//* Arrays Methods [Joining]
//* - concat(array, array) => Return A New Array
//* - join(Separator)


myFriends = ["Ahmed", "Sayed", "Ali", "Osama", "Gamal", "Ameer"];
let myNewFriends = ["Samar", "Sameh"];
let schoolFriends = ["Haytham", "Shady"];

//* The concat() method is used to merge two or more arrays. This method does not change the existing arrays, but instead returns a new array.

    console.log("################################")


let allFriends = myFriends.concat(myNewFriends, schoolFriends, "Gameel", [1, 2]);

console.log(allFriends);

//* The join() method creates and returns a new string by concatenating all of the elements in an array (or an array-like object), separated by commas or a specified separator string. If the array has only one item, then that item will be returned without using the separator.

    console.log("################################")


console.log(allFriends.join());
console.log(allFriends.join(""));
console.log(allFriends.join(" @ "));
console.log(allFriends.join("|"));
console.log(allFriends.join("|").toUpperCase());