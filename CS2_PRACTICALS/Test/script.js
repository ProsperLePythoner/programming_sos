const form = document.getElementById('register');

form.addEventListener('submit', () => {
    event.preventDefault();

    const firstName = document.getElementById('fname').value;
    const lastName = document.getElementById('lname').value;
    const email = document.getElementById('email').value;
    const password = document.getElementById('password').value;
    const confirmPassword = document.getElementById('confirm').value;
    const source = document.getElementById('source').value;
    const income = document.getElementById('income').value;

    const gender = [
        document.getElementById('male').value,
        document.getElementById('female').value
    ];
    const hobby = [
        document.getElementById('music').value,
        document.getElementById('sports').value,
        document.getElementById('travel').value,
        document.getElementById('movies').value,
    ];

    const age = document.getElementById('age').value;

    if (!firstName || !lastName || !email || !password || !age) {
        alert("Input fields cannot be empty!");
    }

    if (password !== confirmPassword) {
        alert("Passwords do not match!");
    }
});