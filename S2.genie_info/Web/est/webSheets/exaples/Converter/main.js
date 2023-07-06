const celInput = document.querySelector("#Cel");
const fahInput = document.querySelector("#Fah");
const reset = document.querySelector(".reset");


let cel;
let fah;
celInput.addEventListener("input", () => {
  cel = celInput.value ? celInput.value : undefined;
  fah = cel ? 32 + (cel * 9) / 5 : undefined;

  fahInput.value = fah ? fah : "";
});

fahInput.addEventListener("input", () => {

  fah = fahInput.value ? fahInput.value : undefined;
  cel = fah ? ((fah - 32) * 5) / 9 : undefined;

  celInput.value = cel ? cel : "";
});

reset.addEventListener("click", () => {
  fahInput.value = "";
  celInput.value = "";
});