let btn = document.getElementById("btn");
let target = document.getElementById("target");

btn.addEventListener("click", start);

function start() {
  target.addEventListener("mouseover", win);

  function win() {
    target.style.backgroundColor = "rgb(0, 255, 0)";
    btn.style.backgroundColor = "rgb(0, 255, 0)";
    clearInterval(timer);
  }

  let timer = setInterval(jump, 400);
  let counter = 0;

  function jump() {
    target.style.backgroundColor = "";
    btn.style.backgroundColor = "";

    let x = Math.floor(Math.random() * (1000 - 0 + 1) - 0);
    let y = Math.floor(Math.random() * (500 - 0 + 1) - 0);

    counter++;
    target.style.transform = `translate(${x}px, ${y}px)`;

    if (counter === 20) {
      target.style.backgroundColor = "rgb(255, 0, 0)";
      btn.style.backgroundColor = "rgb(255, 0, 0)";
      clearInterval(timer);
      target.removeEventListener("mouseover", win);
    }
  }
}
