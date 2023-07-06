function createSelectBox(startYear, endYear) {
  const select = document.createElement("select");
  for (let i = startYear; i <= endYear; i++) {
    const option = document.createElement("option");
    option.setAttribute("value", i);
    option.textContent = i;
    select.appendChild(option);
  }
  document.body.appendChild(select);
}

// Output
createSelectBox(2000, 2021);
