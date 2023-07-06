// //?  -Loop For And Concept Of Loop

// //* Loop
// //* - For
// //* for ([1] [2] [3]) {
// //*   // Block Of Code
// //* }

// for (let i = 0; i < 10; i++) {
//   console.log(i);
// }

// console.log("************************************************************");

//   //?  – Looping On Sequences

// let myFriends = [1, 2, "Osama", "Ahmed", 3, 4, "Sayed", 6, "Ali"];

// let onlyNames = [];

// for (let i = 0; i < myFriends.length; i++){
//   if (typeof myFriends[i] === "string") {
//     onlyNames.push(myFriends[i])
//   }
// }

// console.log(myFriends)
// console.log(onlyNames)

// console.log("*".repeat(60));

//   //?    – Nested Loops And Training’s

// let products = ["Keyboard", "Mouse", "Pen", "Pad", "Monitor"];

// let colors = ["Red", "Green", "Black"];

// let models = [2020, 2021];

// for (let i = 0; i < products.length; i++){
//   console.log("#".repeat(30))
//   console.log(`# ${products[i]}`)
//   console.log("#".repeat(30));
//   console.log("Colors : ")
//   for (let j = 0; j < colors.length; j++){
//     console.log(` -${colors[j]}`)
//   }
//   console.log("Models : ");
//   for (let k = 0; k < models.length; k++) {
//     console.log(` -${models[k]}`);
//   }
// }

// console.log("*".repeat(60));

// //?    – Loop Control – Continue, Break, Label

//  products = ["Keyboard", "Mouse", 20, 10, "Pen", 30, 100, "Pad", "Monitor"];

// let colors = ["Red", "Green", "Black"];

// for (let i = 0; i < products.length; i++) {
//   if (products[i] == "Pen") {
//     break;
//   }
//   console.log(products[i]);
// }

// //* The continue statement terminates execution of the statements in the current iteration of the current or labeled loop, and continues execution of the loop with the next iteration.

// console.log("#".repeat(30));

// for (let i = 0; i < products.length; i++) {
//   if (typeof products[i] === "number") {
//     continue;
//   }
//   console.log(products[i]);
// }

// //* The labeled statement can be used with break or continue statements. It is prefixing a statement with an identifier which you can refer to.

// console.log("#".repeat(30));

// mainLoop: for (let i = 0; i < products.length; i++) {
//   console.log(products[i]);
//   nestedLoop: for (let j = 0; j < colors.length; j++) {
//     console.log(`- ${colors[j]}`);
//     if (colors[j] === "Green") {
//       break mainLoop;
//     }
//   }
// }

// console.log("*".repeat(60))

//   //?    – Loop For Advanced Examples
// 
// products = ["Keyboard", "Mouse", "Pen", "Pad", "Monitor", "iPhone"];
// let i = 0;
// 
// for (;;) {
//   console.log(products[i]);
//   i++;
//   if (i === products.length) break;
// }
// 

// console.log("*".repeat(60))

//   //?    – Practice – Add Products To Page


// products = ["Keyboard", "Mouse", "Pen", "Pad", "Monitor", "iPhone"];
// colors = ["Red", "Green", "Blue"];
// let showCount = 2;

// document.write(`<h1>Show ${showCount} Products`)

// for (let i = 0; i < showCount; i++){
//   document.write(`<div>`);
//   document.write(`<h3>[${i+1}] ${products[i]}</h3>`);
//   for (let j = 0; j < colors.length; j++){
//     document.write(`<p>${colors[j]}</p>`)
//   }
//   document.write(`<p>${colors.join(" | ")}</p>`);

//   document.write(`</div>`);
// }

// console.log("*".repeat(60))

//   //?    – Loop – While

// products = ["Keyboard", "Mouse", "Pen", "Pad", "Monitor", "iPhone"];

// let index = 0;

// while (index < products.length) {
//   console.log(products[index]);
//   index += 1;
// }

// console.log("*".repeat(60))

//   //?    – Loop – Do, While

// products = ["Keyboard", "Mouse", "Pen", "Pad", "Monitor", "iPhone"];

// index = 0;

// do {
//   console.log(index);
//   index++;
// } while (false);

// console.log(index);

// console.log("*".repeat(60))
