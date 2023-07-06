//! Create Your Object One Here
function memberOne(name, age, country) {
  this.name = name;
  this.age = age;
  this.country = country;
  this.fullDetails = function () {
    console.log(
      `My Name Is ${this.name}, My Age Is ${this.age}, I Live in ${this.country}`
    );
  };
}

let user = new memberOne("Elzero", 38, "Egypt");

console.log(user.name); // Elzero
console.log(user.age); // 38
console.log(user.country); // Egypt
user.fullDetails();
// My Name Is Elzero, My Age Is 38, I Live in Egypt

console.log("*".repeat(60));

//! Create Your Object Two Here

const memberTwo = {
  name: "Elzero",
  age: 38,
  country: "Egypt",
  fullDetails: function () {
    console.log(
      `My Name Is ${this.name}, My Age Is ${this.age}, I Live in ${this.country}`
    );
  },
};

console.log(memberTwo.name); // Elzero
console.log(memberTwo.age); // 38
console.log(memberTwo.country); // Egypt
memberTwo.fullDetails();
// My Name Is Elzero, My Age Is 38, I Live in Egypt

console.log("*".repeat(60));

//! Create Your Object Three Here


const memberThree = Object.create(memberTwo);

console.log(memberThree.name); // Elzero
console.log(memberThree.age); // 38
console.log(memberThree.country); // Egypt
memberThree.fullDetails();
// My Name Is Elzero, My Age Is 38, I Live in

console.log("*".repeat(60));

//! Create Your Object Four Here


const memberFour = new Object({
  name: "Elzero",
  age: 38,
  country: "Egypt",
  fullDetails: function () {
    console.log(
      `My Name Is ${this.name}, My Age Is ${this.age}, I Live in ${this.country}`
    );
  },
});

console.log(memberFour.name); // Elzero
console.log(memberFour.age); // 38
console.log(memberFour.country); // Egypt
memberFour.fullDetails()
// My Name Is Elzero, My Age Is 38, I Live in Egypt
