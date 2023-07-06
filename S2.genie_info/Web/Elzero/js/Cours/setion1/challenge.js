    //?  – Variables And Concatenation Challenge

let TheTitle = "Elzero", DescriptionContent = "Elzero Web shcool", TheDate = "25/10";

let Content = `
    <div>
        <h3>${TheTitle}</h3>
        <p>${DescriptionContent}</p>
        <span>${TheDate}</span>
    </div>
`;

for (let i = 0; i < 4; i++)
document.write(Content);