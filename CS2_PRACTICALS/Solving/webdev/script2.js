const form = document.getElementById("register");
const tableBody = document.querySelector("#table tbody");

form.addEventListener("submit", function (event) {
    // Prevent the page from reloading
    event.preventDefault();

    // Get values from the form
    const name = form.elements["fullname"].value.trim();
    const studentClass = form.elements["class"].value.trim();
    const eventName = form.elements["event"].selectedOptions[0].text;
    const house = form.elements["house"].value;

    // Convert the house value into a readable name
    const houseName = house.charAt(0).toUpperCase() + house.slice(1) + " House";

    // Create a new table row
    const row = document.createElement("tr");

    // Create cells and fill them with the form data
    [name, studentClass, eventName, houseName].forEach(function (value) {
        const cell = document.createElement("td");
        cell.textContent = value;
        row.appendChild(cell);
    });

    // Add the row to the table
    tableBody.appendChild(row);

    // Clear the form for the next participant
    form.reset();
});
