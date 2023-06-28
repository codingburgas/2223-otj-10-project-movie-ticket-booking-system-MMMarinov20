const express = require("express");
const uuid = require("uuid");
const db = require("../db/db_config.js");
const bodyParser = require("body-parser");

const router = express.Router();
router.use(bodyParser.json());
module.exports = router;

router.get("/", (req, res) => {
  res.send("Hello World!");
});

router.get("/getTickets", (req, res) => {
  db.query("SELECT * FROM tickets", (err, result) => {
    if (err) throw err;
    res.send(result);
  });
});

router.post("/postTicket", (req, res) => {
  const id = uuid.v4();
  const { seat_number, movie_name, movie_time } = req.body;
  const purchase_date = new Date().toISOString().slice(0, 19).replace("T", " ");
  const sql = `INSERT INTO tickets (uuid, seat_number, movie_name, movie_time, purchase_date) VALUES ("${id}", "${seat_number}", "${movie_name}", "${movie_time}", "${purchase_date}")`;
  db.query(sql, (err, result) => {
    if (err) throw err;
    res.send("Ticket successfully purchased!");
  });
});
