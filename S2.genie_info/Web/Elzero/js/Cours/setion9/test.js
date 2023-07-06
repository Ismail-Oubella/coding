let nums = [1, 2, 3, 4, 5, 6];

let add = nums.reduce(function (acc, current, index, arr) {
  console.log(`acc => ${acc}`);
  console.log(`current => ${current}`);
  console.log(`Current element index => ${index}`);
  console.log(`Array => ${arr}`);
  console.log(acc + current);
  console.log("#".repeat(30));
  return acc + current;
}, );