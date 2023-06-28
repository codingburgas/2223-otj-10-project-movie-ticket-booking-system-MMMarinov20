const mysql = require("mysql2");

const db = mysql.createConnection({
  host: "localhost",
  user: "root",
  password: "Maks123maks",
  database: "tickets",
});

db.connect((err) => {
  if (err) throw err;
  console.log("Connected to MySQL Server!");
});

module.exports = db;
