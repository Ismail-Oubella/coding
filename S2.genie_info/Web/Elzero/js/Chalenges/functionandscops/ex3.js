    //!    Currying Function Technique إقرأ عن
function checker(zName) {
  return function (status) {
    return function (salary) {
      return status === "Available"
        ? `${zName}, My Salary Is ${salary}`
        : `Iam Not Avaialble`;
    };
  };
}

console.log(checker("Osama")("Available")(4000)); // Osama, My Salary Is 4000
console.log(checker("Ahmed")("Not Available")()); // Iam Not Avaialble

let Checker = (zName) => {
  return (status) => {
    return (salary) => {
      return status === "Available" ? `${zName}, My Salary Is ${salary}`: `Iam Not Avaialble`;
    };
  };
};

console.log("*".repeat(60))

console.log(Checker("Osama")("Available")(4000)); // Osama, My Salary Is 4000
console.log(Checker("Ahmed")("Not Available")()); // Iam Not Avaialble