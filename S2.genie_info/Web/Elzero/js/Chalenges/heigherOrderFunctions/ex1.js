let mix = [1, 2, 3, "E", 4, "l", "z", "e", "r", 5, "o"];

let Elzero = mix.reduce((acc, current) => {
    if (isNaN(current)) return acc + current;
    else return acc;
}, "")

let elzero = mix.map((element) => {
    return isNaN(element) ? element : "";
}).reduce((acc, current) => {
    return acc + current
}, "")


console.log(Elzero); // Elzero
console.log(elzero); // Elzero
