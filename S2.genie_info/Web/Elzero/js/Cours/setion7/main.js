    //?  – Function Intro And Basic Usage

//* Function
//* - DRY => Don't Reapet yourself
//* - What Is Function ?
//* - User-Defined vs Built In
//* - Syntax + Basic Usage
//* - Example From Real Life
//* - Parameter + Argument
//* - Practical Example

function sayHello(userName) {
    console.log(`Hello, ${userName}!`)
}

sayHello("Ismail");

console.log("*".repeat(60));

    //?  – Function Advanced Examples

function sayHello(userName, age) {
  if (age < 20) {
    console.log(`App Is Note Settable For You!`);
  } else {
    console.log(`Hello, ${userName} Your age is ${age}`);
  }
}

sayHello("Oussama", 28);
sayHello("Mahmoud", 38);
sayHello("Sayed", 40);
sayHello("Ali", 18);

function generateYears(start, end, exclude) {
    for (let i = start; i <= end; i++){
        if (i == exclude) { continue; }
        console.log(i);
    }
}

generateYears(1982, 2023, 2020)

console.log("*".repeat(60))

//?  – Function Return Statement And Use Cases

//* Function
//* - Return
//* - Automatic Semicolon Insertion [No Line Terminator Allowed]
//* - Interrupting

function calc(num1, num2) {
  return num1 + num2;
}

let res = calc(10, 20);

console.log(res + 100);

    console.log("#".repeat(30))

function generate(start, end) {
  for (let i = start; i <= end; i++) {
      if (i == 15) { return 'Interruptting'; }
      console.log(i);
    }
}

generate(10, 30)

console.log("*".repeat(60))

    //?  – Function Default Parameters

//* Function
//* - Default Function Parameters is Undifined
//* - Function Parameters Default [Undefined]
//* - Old Strategies [Condition + Logical Or]
//* - ES6 Method

function sayHello(userName = "Unknown", age = "Unknown") {
  // if (age === undefined) { age = "Unknown" }
  // age = age || "Unknown";
  return `Hello, ${userName}!, Your Age Is ${age}`;
}

console.log(sayHello("Ismail", 20));
console.log(sayHello("Ismail"));
console.log(sayHello());

console.log("*".repeat(60))

    //?  – Function Rest Parameters

//* Function
//* - Rest Parameters
//* - Only One Allowed
//* - Must Be Last Element

function calc(...numbers) {
  let sum = 0;
  console.log(Array.isArray(numbers));
  for (let i = 0; i < numbers.length; i++) {
    console.log(numbers[i], sum);
    sum += numbers[i];
  }
  return `Final Result Is : ${sum}`;
}

console.log(calc(10, 20, 30, 50));

console.log("*".repeat(60))

    //? #062 – Function Ultimate Practice

//* Function Advanced Practice
//* - Parameters
//* - Default
//* - Rest
//* - Loop
//* - Condition

function showInfo(user = "Un", age = "Un", hRate = 0, show = "Yes", ...skills) {
  document.write(`<div>`);
  document.write(`<h2>Welcome, ${user}</h2>`);
  document.write(`<h2>Age : ${age}</h2>`);
  document.write(`<h2>Hour Rate : $${hRate}</h2>`);
  if (show === "Yes") {
    if (skills.length > 0) {
      document.write(`<p>${skills.join(", ")}</p>`);
    } else {
      document.write("<p>Skills : No Skills</p>");
    }
  } else {
    document.write("<p>Skills Is Hidden</p>");
  }
  document.write(`</div>`);
}

showInfo("Ismail", 20, 100, "No", "HTML", "CSS", "Js");