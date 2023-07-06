let myArray = ["E", "l", "z", ["e", "r"], "o"];

let elzero = myArray.reduce((acc, current) => {
    if (!Array.isArray(current)) return `${acc}${current}`;
    else {
        let res = current.reduce((ac, ele) => {
            return `${ac}${ele}`;
        }, "")
        return `${acc}${res}`;
    }
}, "");

console.log(elzero)

// Elzero
