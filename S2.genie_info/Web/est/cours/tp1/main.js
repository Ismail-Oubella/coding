const students = [];

add.addEventListener("click", () => {
  let nameValue = name.value;
  let ageValue = age.value;
  if (nameValue && ageValue) {
    const student = { name: nameValue, age: ageValue };
    students.push(student);
    const li = document.createElement("li");
    li.textContent = `Name : ${nameValue}  Age : ${ageValue}`;
    list.appendChild(li);
    name.value = "";
    age.value = "";
    li.style.listStyle = "none";
  }
});
const submit = document.querySelector("#submit");

submit.addEventListener("click", () => {
  submit.type = "submit";
  form.submit();
});
