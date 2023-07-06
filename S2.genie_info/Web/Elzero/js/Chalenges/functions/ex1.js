function sayHello(theName, theGender) {
  let hi = "";
  if (theGender === "Male") {
    hi = "Mr ";
  } else if (theGender === "Female") {
    hi = "Miss ";
  }
  console.log(`"Hello ${hi}${theName}"`);
}

// Needed Output
sayHello("Osama", "Male"); // "Hello Mr Osama"
sayHello("Eman", "Female"); // "Hello Miss Eman"
sayHello("Sameh"); // "Hello Sameh"

// process.stdout.write("\r here");console.log("go");
