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
