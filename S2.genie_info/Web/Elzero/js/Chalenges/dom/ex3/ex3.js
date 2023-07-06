const input = document.querySelector(".input");
const output = document.querySelector(".output");
const dollar = document.querySelector("input");

dollar.addEventListener("input", (event) => {
    input.textContent = dollar.value;
    output.textContent = (dollar.value * 15.6).toFixed(2);
})