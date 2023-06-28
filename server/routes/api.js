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

router.get("/tickets", (req, res) => {
  db.query("SELECT * FROM tickets", (err, result) => {
    if (err) throw err;
    res.send(result);
  });
});
