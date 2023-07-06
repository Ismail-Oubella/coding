let myFriends = ["Ahmed", "Elham", "Osama", "Gamal"];
let num = 3;

// Method 1
console.log(myFriends.slice(0, num)); // ["Ahmed", "Elham", "Osama"];

// Method 2

let Remove = myFriends.splice(0, num);

console.log(`Remove = ${Remove} `); // ["Ahmed", "Elham", "Osama"];
console.log(`myFriends = ${myFriends} `); // ["Gamal"];
