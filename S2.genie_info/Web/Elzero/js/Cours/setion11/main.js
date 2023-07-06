//?  – What Is DOM ? And Select Elements

//   *DOM
//   *- What Is DOM
//   *- DOM Selectors
//   *--- Find Element By ID
//   *--- Find Element By Tag Name
//   *--- Find Element By Class Name
//   *--- Find Element By CSS Selectors
//   *--- Find Element By Collection
//   *------ title
//   *------ body
//   *------ images
//   *------ forms
//   *------ links

let myIdElement = document.getElementById("my-div");

let myTagElements = document.getElementsByTagName("p");

console.log(myIdElement);
console.log(myTagElements);
console.log(myTagElements[1]);
console.log(myTagElements);

myTagElements[1].innerHTML = "Test Js ";

let myClassElement = document.getElementsByClassName("my-span");

console.log(myClassElement);

let myQueryElement = document.querySelector(".special");

console.log(myQueryElement);

let myQueryAllElement = document.querySelectorAll(".my-span");

console.log(myQueryAllElement);

console.log(document.title);
console.log(document.body);
console.log(document.forms[0].one.value);
console.log(document.links[1].href);

console.log("*".repeat);

//?  – Get, Set Elements And Attributes

//  *DOM [Get / Set Elements Content And Attributes]
//  *- innerHTML
//  *- textContent
//  *- Change Attributes Directly
//  *- Change Attributes With Methods
//  *--- getAttribute
//  *--- setAttribute

//  *Search
//  *- innerText

let myElement = document.querySelector(".js");

console.log(myElement.innerHTML);
console.log(myElement.textContent);

myElement.innerHTML = "text from <span>main.js</span> file";
myElement.textContent = "text from <span>main.js</span> file";

document.images[0].src = "here";
document.images[0].alt = "alt";
document.images[0].title = "picture";
document.images[0].id = "picture";
document.images[0].className = "img";

let myLink = document.querySelector(".link");

console.log(myLink.getAttribute("href"));
console.log(myLink.getAttribute("class"));

myLink.setAttribute("href", "https//twitter.com");
myLink.setAttribute("title", "Link title");

console.log("*".repeat);

//?  – Check Attributes And Examples

/*
  DOM [Check Attributes]
  - Element.attributes
  - Element.hasAttribute
  - Element.hasAttributes
  - Element.removeAttribute
*/

console.log(document.getElementsByTagName("p")[0].attributes);

let myP = document.getElementsByTagName("p")[0];

if (myP.hasAttribute("data-src")) {
  if (myP.getAttribute("data-src") === "") {
    myP.removeAttribute("data-src");
  } else {
    myP.setAttribute("data-src", "New Value");
  }
} else {
  console.log(`Not Found`);
}

if (myP.hasAttributes()) {
  console.log(`Has Attributes`);
}

if (document.getElementsByTagName("div")[0].hasAttributes()) {
  console.log(`Has Attributes`);
} else {
  console.log(`Div Has No Attributes`);
}

console.log("*".repeat);

//?  – Create and Append Elements

/*
  DOM [Create Elements]
  - createElement
  - createComment
  - createTextNode
  - createAttribute
  - appendChild
*/

let myElement = document.createElement("div");
myElement.className = "product";
let myText = document.createTextNode("Product one");
let myComment = document.createComment("This Is Div");

let myAtt = document.createAttribute("data-custom");
myElement.setAttributeNode(myAtt);

myElement.setAttribute("data-test", "testing");

//append text to element
myElement.appendChild(myText);

//append comment to element

myElement.appendChild(myComment);

//append element to body

document.body.appendChild(myElement);

console.log(myElement);

console.log("*".repeat);

//?  – Product With Title And Description Practice

/*
  DOM [Create Elements]
  - Practice Product With Heading And Paragraph
*/

//todo : div class = product (h3(text, p(text))) * 100;

let myDiv = document.createElement("div");
myDiv.className = "product";

let heading = document.createElement("h2");
heading.textContent = "Heading Page";

myDiv.appendChild(heading);

let text = document.createElement("p");
let textContent = document.createTextNode("This Is The Text Of this Page");
text.appendChild(textContent);

myDiv.appendChild(text);

document.body.appendChild(myDiv);

console.log(myDiv);

console.log("*".repeat);

//?    – Deal With Children
/*
  DOM [Deal With Childrens]
  - children
  - childNodes
  - firstChild
  - lastChild
  - firstElementChild
  - lastElementChild
*/

let myElement = document.querySelector("div");

console.log(myElement);
console.log(myElement.children);
console.log(myElement.children[0]);
console.log(myElement.childNodes);
console.log(myElement.childNodes[0]);

console.log(myElement.firstChild);
console.log(myElement.lastChild);

console.log(myElement.firstElementChild);
console.log(myElement.lastElementChild);

console.log("*".repeat);

//?  – DOM Events

/*
  DOM [Events]
  - Use Events On HTML
  - Use Events On JS
  --- onclick
  --- oncontextmenu
  --- onmouseenter
  --- onmouseleave

  --- onload
  --- onscroll
  --- onresize

  --- onfocus
  --- onblur
  --- onsubmit
*/

let myButton = document.getElementById("btn");

myButton.onclick = () => console.log("Button Clicked!");

window.onscroll = () => console.log("So It seems That You're Scrolling!");

console.log("*".repeat);

//? validition

let userInput = document.querySelector("[name = 'username']");
let ageInput = document.querySelector("[name = 'age']");

document.forms[0].onsubmit = function (event) {
  let userValid = false;
  let ageValid = false;

  if (userInput.value !== "" && userInput.value.length <= 10) {
    userValid = true;
  }

  if (ageInput.value !== "") {
    ageValid = true;
  }

  if (userValid === false || ageValid === false) {
    event.preventDefault();
  }
};

document.links[0].onclick = function (event) {
  console.log(event);
  event.preventDefault();
};

console.log("*".repeat);

//? - click , focus, blur

let two = document.querySelector(".two");
let one = document.querySelector(".one");

window.onload = function () {
  two.focus();
};

one.onblur = function () {
  document.links[0].click();
};

console.log("*".repeat);

//? class list objects

let element = document.getElementById("my-div");

console.log(element);
console.log(element.classList);
console.log(typeof element.classList);

console.log(element.classList.contains("ismail"));
console.log(element.classList.contains("show"));

console.log(element.classList.item(0));
console.log(element.classList.item(3));

element.onclick = function () {
  element.classList.add("add-one", "add-two");
};

element.onclick = function () {
  element.classList.remove("one", "two");
};

element.onclick = function () {
  element.classList.toggle("oussama");
};

console.log("*".repeat);

//? css styling

let element = document.getElementById("my-div");
element.style.color = "red";
element.style.fontWeight = "bold";

element.style.cssText = "font-weight : bold; color : green ; opacity : 0.9";

element.style.removeProperty("color");
element.style.setProperty("font-size", "40px", "important");

//? Deal With Elements

/*
  DOM [Deal With Elements]
  - before [Element || String]
  - after [Element || String]
  - append [Element || String]
  - prepend [Element || String]
  - remove
*/

let element = document.getElementById("my-div");
console.log(element);
let createdPara = document.createElement("p");

element.after(createdPara);

element.append(" append ");
element.prepend(" prepend ");

element.remove();

//? Dom treversing

/*
  DOM [Traversing]
  - nextSibling
  - previousSibling
  - nextElementSibling
  - previousElementSibling
  - parentElement
*/

let span = document.querySelector(".two");

console.log(span.nextSibling);
console.log(span.nextElementSibling.remove());
console.log(span.previousSibling);
console.log(span.previousElementSibling.remove());

console.log(span.parentElement);

span.onclick = function () {
  span.parentElement.style.opacity = "0";
};

//? Dom Cloning

/*
  DOM [Cloning]
  - cloneNode(Deep)
*/

myP = document.querySelector("p").cloneNode(true);
let myDiv = document.querySelector("div");

myP.id = `${myP.id}-clone`;

// myDiv.append(myP);

//? addeventlistner

/*
  DOM [Add Event Listener]
  - addEventListener
  - Use Without On
  - Attach Multiple Events
  - Error Test

  Search
  - Capture & Bubbling JavaScript
  - removeEventListener
*/

let myP = document.querySelector("p");

// myP.onclick = one;

// // myP.onclick = function () {
// //   myP.remove();
// // }

function one() {
  console.log("Message from onclick One ");
}
function two() {
  console.log("Message from onclick two ");
}

window.onload = "ismail";

myP.addEventListener("click", function (event) {
  console.log("Message from onclick Event ");
});

myP.addEventListener("click", one);
myP.addEventListener("click", two);

myP.onclick = function () {
  let newPara = myP.cloneNode(true);
  document.body.appendChild(newPara);
  newPara.className = `clone`;
};

// let cloned = document.querySelector(".clone");
// cloned.onclick = function () {
//   console.log("im cloned");
// }

document.addEventListener("click", function (event) {
  if (event.target.className === `clone`) {
    console.log("im cloned");
  }
});
