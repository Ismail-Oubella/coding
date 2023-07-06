function multiply(...tab) {
  let number = tab.filter((element) => {
    return typeof element !== "string";
  });
    console.log(tab)
    console.log(number)
  let result = number.reduce((acc, current) => {
    console.log(`previousValue: ${acc}, currentValue: ${current}`);
    return parseInt(current * acc);
  }, 1);

  console.log(result);
}

multiply(10, 20); // 200
multiply("A", 10, 30); // 300
multiply(100.5, 10, "B"); // 1000
