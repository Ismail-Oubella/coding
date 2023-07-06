function specialMix(...data) {
  console.log(data);
  let number = data.reduce((acc, current) => {
    if (!isNaN(current)) return acc + current;
    else if (!isNaN(parseInt(current.slice(0, 2))))
      return acc + parseInt(current.slice(0, 2));
    else return acc;
  }, 0);
  if (isNaN(number)) return `All Is Strings`;
  else {
    return number;
  }
}

console.log(specialMix(10, 20, 30)); // 60
console.log("*".repeat(60));
console.log(specialMix("10Test", "Testing", "20Cool")); // 30
console.log("*".repeat(60));
console.log(specialMix("Testing", "10Testing", "40Cool")); // 50
console.log("*".repeat(60));
console.log(specialMix("Test", "Cool", "Test")); // All Is Strings
console.log("*".repeat(60));
