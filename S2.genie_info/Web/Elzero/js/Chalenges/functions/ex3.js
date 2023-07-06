function ageInTime(theAge) {
    if (theAge > 100 || theAge < 10) console.log("Age Out Of Range");
    else {
        const Months = (theAge * 12);
        const days = (Months * 30);
        const hours = (days * 24);
        const minutes = (hours * 60);
        const seconds = (minutes * 60);
        console.log(`${Math.round(Months)} Months`);
        console.log(`${Math.round(hours)} Hours`);
        console.log(`${Math.round(minutes)} minutes`);
        console.log(`${Math.round(seconds)} seconds`);
    }
}

// Needed Output
ageInTime(110); // Age Out Of Range
ageInTime(38); // Months Example => 456 Months
