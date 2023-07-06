let numsAndStrings = [1, 10, -10, -20, 5, "A", 3, "B", "C"];

let newArr = numsAndStrings.filter((element) => {
    return !isNaN(element);
}).map((element) => {
    return -element;
})

console.log(numsAndStrings)
console.log(newArr)

// [-1, -10, 10, 20, -5, -3]
