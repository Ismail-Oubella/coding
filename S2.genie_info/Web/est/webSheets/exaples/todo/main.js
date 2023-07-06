const task = document.querySelector("input");
const push = document.querySelector("#Submit");
const list = document.querySelector("#tasks");

push.addEventListener("click", (event) => {
  event.preventDefault();
    if (task.value !== "") {
  
        const newTask = document.createElement("li");
        newTask.textContent = task.value;
        list.appendChild(newTask);
        const remove = document.createElement("button");
        remove.textContent = "remove";
        newTask.appendChild(remove);
        remove.style.display = "inline";
        remove.addEventListener("click", (event) => {
            newTask.remove();
        });
    }
  task.value = "";
});
