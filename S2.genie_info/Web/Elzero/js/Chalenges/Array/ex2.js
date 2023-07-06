let friends = ["Ahmed", "Eman", "Osama", "Gamal"];

// Write Your Code Here

friends.pop();
friends.shift();

console.log(friends); // ["Eman", "Osama"]


//? ChatGpt answer 

friends = friends.slice(1, -1);
console.log(friends); // Output: ["Eman", "Osama"]

//! or 

friends.shift(); // Remove the first element ("Ahmed")
friends.pop();   // Remove the last element ("Gamal")
console.log(friends); // Output: ["Eman", "Osama"]
