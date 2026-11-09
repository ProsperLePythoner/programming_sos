const form = document.getElementById("register");
const tableBody = document.querySelector("#table tbody");

form.addEventListener("submit", () => {
    event.preventDefault();

    const name = form.elements['fullname'].value.trim();
    const studentClass = form.elements['class'].value.trim();
    const eventName = form.elements['event'].value.trim();
    const house = form.elements['house'].value;
    const data = [name, studentClass, eventName, house];

    const row = document.createElement("tr");

    for (let i = 0; i < data.length; ++i) {
        const cell = document.createElement("td");
        cell.textContent = data[i];
        row.appendChild(cell);
    }

    tableBody.appendChild(row);

    form.reset();
});