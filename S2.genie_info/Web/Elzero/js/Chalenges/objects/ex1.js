const objMethodOne = { property: "Method One" };

console.log(objMethodOne.property); // "Method One"

const objMethodTwo = new Object({
  property: "Method Two",
});

console.log(objMethodTwo.property); // "Method Two"

function ObjMethodThree() {
    this.property = "Method Three";
}

const objMethodThree = new ObjMethodThree();

console.log(objMethodThree.property); // "Method Three"

const objMethodFour = Object.create(objMethodOne)
objMethodFour.property = "Method Four";

console.log(objMethodFour.property); // "Method Four"
