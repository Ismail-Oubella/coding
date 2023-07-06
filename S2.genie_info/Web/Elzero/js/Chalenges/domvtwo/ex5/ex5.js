const div = document.querySelector("div");
const span = document.querySelector("span");
const p = document.querySelector("p");
const article = document.querySelector("article");
const section = document.querySelector("section");

const table = [div, span, p, article, section];
table.forEach((element) => {
  element.addEventListener("click", (event) => {
    console.log(`This is ${event.target.tagName}`);
  });
});
