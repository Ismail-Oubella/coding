const result = document.querySelector("span");
const push = document.querySelector("#button");
const numberOne =document.querySelector("#number1")
const numberTwo = document.querySelector("#number2")

let one;
let two;

push.addEventListener("click", () => {

    one = numberOne.value;
    two = numberTwo.value;

    let sum = (one + two);
    result.textContent = sum;
})
