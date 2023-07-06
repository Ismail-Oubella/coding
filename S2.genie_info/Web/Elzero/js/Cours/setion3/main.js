    //?  – String Methods Part 1

let theName = "John";
let theList = [1, 2, 3, 4, 5, 6];

console.log(theName);
console.log(theName[5]);

//* The charAt() method of a String instance returns a new string consisting of the single UTF-16 code unit located at the specified offset into the string.

    console.log("################################")


console.log(theName.charAt(3));

//* The length data property of a string contains the length of the string in UTF-16 code units.

    console.log("################################")


console.log(theName.length);

//* The trim() method removes whitespace from both ends of a string and returns a new string, without modifying the original string.

    console.log("################################")


let theString = "  Hello World  ";
console.log(theString.trim());

//*The toUpperCase() method returns the calling string value converted to uppercase (the value will be converted to a string if it isn't one).

    console.log("################################")


console.log(theString.toUpperCase());

//* The toLowerCase() method returns the calling string value converted to lowercase (the value will be converted to a string if it isn't one).

    console.log("################################")
    

console.log(theString.toLowerCase());

//* Chain Methods

console.log(theString.trim().charAt(2).toLowerCase());

console.log("************************************************************")

    




    //?  – String Methods Part 2

//* The indexOf() method returns the first index at which a given element can be found in the array, or -1 if it is not present, indexof(Value [Mand], Start [Opt] )

var siteName = "Elzero Web School";

console.log(siteName.indexOf("Web")); //* => 7
console.log(siteName.indexOf("Web", 9)); //* => -1

//*The lastIndexOf() method returns the last index at which a given element can be found in the array, or -1 if it is not present. The array is searched backwards, starting at fromIndex.

    console.log("################################")

console.log(siteName.lastIndexOf("ro")); //* => 4

//* The slice() method returns a shallow copy of a portion of an array into a new array object selected from start to end (end not included) where start and end represent the index of items in that array. The original array will not be modified.

    console.log("################################")


console.log(siteName.slice(7, 10)); //* => Web
console.log(siteName.slice(-5)); //* => chool
console.log(siteName.slice(-5, -3)); //* => ch

//* The repeat() method constructs and returns a new string which contains the specified number of copies of the string on which it was called, concatenated together.

    console.log("################################")


console.log(siteName.repeat(3)); 

//* he split() method takes a pattern and divides a String into an ordered list of substrings by searching for the pattern, puts these substrings into an array, and returns the array.

    console.log("################################")


console.log(siteName.split(" ")); //* => [ 'Elzero', 'Web', 'School' ]
console.log(siteName.split(" ", 2)); //* => [ 'Elzero', 'Web' ] , 2 is the number of parts to split the string on.

console.log("************************************************************")

    




    //? – String Methods Part 3

var siteName = "Elzero Web School";

//* The substring() method returns the part of the string from the start index up to and excluding the end index, or to the end of the string if no end index is supplied.

    console.log("************************************************************");


console.log(siteName.length);

console.log(siteName.substring(7, 10)); //* => Web
console.log(siteName.substring(10, 7)); //* => Web
console.log(siteName.substring(-5, 10)); //* => Elzero Web 0=> 10
console.log(siteName.substring(siteName.length - 1)); //* Last char => l
console.log(siteName.substring(siteName.length - 6)); //* Shcool
console.log(siteName.substring(siteName.length - 5, siteName.length - 3)); //* ch
 
//* The includes() method determines whether an array includes a certain value among its entries, returning true or false as appropriate, VarName.includes("Word", start position"Opt" default = 0)

    console.log("************************************************************");



console.log(siteName.includes("Web")) //* => true
console.log(siteName.includes("Web", 8)) //* => false

//* The startsWith() method determines whether a string begins with the characters of a specified string, returning true or false as appropriate.

    console.log("************************************************************");



console.log(siteName.startsWith("Elzero")) //* => true
console.log(siteName.startsWith("Elzero", 2)) //* => false
console.log(siteName.startsWith("zero", 2)) //* => true

// *The endsWith() method determines whether a string ends with the characters of a specified string, returning true or false as appropriate. 

    console.log("************************************************************");


console.log(siteName.endsWith("School")) //* => true
console.log(siteName.endsWith("ro", 6))

// TODO   String Methods
// TODO   - substring(Start [Mand], End [Opt] Not Including End)
// TODO   --- Start > End Will Swap
// TODO   --- Start < 0 It Start From 0
// TODO   --- Use Length To Get Last Character
// TODO   - substr(Start [Mand], Characters To Extract)
// TODO   --- Start >= Length = ""
// TODO   --- Negative Start From End
// TODO   - includes(Value [Mand], Start [Opt] Default 0) [ES6]
// TODO  - startsWith(Value [Mand], Start [Opt] Default 0) [ES6]
// TODO   - endsWith(Value [Mand], Length [Opt] Default Full Length) [ES6]

