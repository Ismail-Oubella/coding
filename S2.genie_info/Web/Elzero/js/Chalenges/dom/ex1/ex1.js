const methodOne = document.querySelector(".element");
console.log(`MethodOne: ${methodOne}`);

const methodTwo = document.querySelector("#elzero");
console.log(`MethodTwo: ${methodTwo}`);

const methodThree = document.querySelector("div");
console.log(`MethodThree: ${methodThree}`);

const methodFour = document.querySelector(".element[name = 'js']");
console.log(`MethodFour: ${methodFour}`);

const methodFive = document.querySelectorAll(".element[name = 'js']");
console.log(`MethodFive: ${methodFive[0]}`);

const methodSix = document.querySelectorAll(".element[name = 'js']");
console.log(`MethodSix: ${methodSix[0]}`);

const methodSeven = document.querySelectorAll(".element[name = 'js']");
console.log(`MethodSeven: ${methodSeven[0]}`);

const methodNine = document.querySelectorAll(".element[name = 'js']");
console.log(`MethodNine: ${methodNine[0]}`);

const methodTen = document.getElementById("elzero");
console.log(`MethodTen: ${methodTen}`);

const methodEleven = document.getElementsByClassName("element");
console.log(`MethodEleven: ${methodEleven}`);

const methodTwelve = document.getElementsByName("div");
console.log(`MethodTwelve: ${methodTwelve}`);

const methodthirteen = document.getElementsByTagName("div");
console.log(`Methodthirteen: ${methodthirteen}`);
