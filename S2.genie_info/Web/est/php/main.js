const name = document.querySelector("#name");
const age = document.querySelector("#age");
const add = document.querySelector("#add");
const list = document.querySelector("#list");

add.addEventListener("click", () => {
  let nameValue = name.value;
  let ageValue = age.value;
  const li = document.createElement("li");
  list.appendChild(li);
  li.textContent(nameValue, ageValue);
});
