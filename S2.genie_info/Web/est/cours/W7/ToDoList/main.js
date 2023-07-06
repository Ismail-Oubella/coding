const submitAction = document.getElementById("submitAction");
const listTasks = document.getElementById("listTasks");
const myForm = document.getElementById("formTasks");

myForm.addEventListener("submit", addElement);

function addElement(event) {
    event.preventDefault();
    const input = document.getElementById("newTask").value;
    const newElem = document.createElement("li");
    newElem.innerHTML = input;

    const removeButton = document.createElement("button"); 
    removeButton.textContent = "Delete"; 
    removeButton.addEventListener("click", () => {
        listTasks.removeChild(newElem); 
    });
    newElem.appendChild(removeButton);  

    listTasks.appendChild(newElem);

    document.getElementById("newTask").value = "";
}
