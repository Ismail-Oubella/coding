const para = document.querySelector("p");
const div = document.querySelector(".our-element");

para.remove();

const start = document.createElement("div");
start.textContent = "Start";
start.className = "start";
start.setAttribute("title", "Start Element");
start.setAttribute("data-value", "Start");

div.before(start);

const End = document.createElement("div");
End.textContent = "End";
End.className = "End";
End.setAttribute("title", "End Element");
End.setAttribute("data-value", "End");

div.after(End);
