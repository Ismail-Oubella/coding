let myString = "EElllzzzzzzzeroo";

let Elzero = myString
  .split("")
    .filter((char, index, arr) => {
    //   console.log(
    //     `arr.indexOf(char): ${arr.indexOf(
    //       char
    //     )}, index: ${index}, char: ${char}, arr.indexOf(char) === index: ${
    //       arr.indexOf(char) === index
    //     }`
    //   );
    return arr.indexOf(char) === index;
  })
  .reduce((acc, curr) => {
    return acc + curr;
  }, "");

console.log(Elzero); // Elzero

let YourString = "eelllzzzzzzzeroo";


let elzero = YourString.split("").filter((char, index, arr) => {
    return arr.indexOf(char) === index;
}).reduce((acc, current) => {
    return acc + current;
}, "")

console.log(elzero); // Elzero
