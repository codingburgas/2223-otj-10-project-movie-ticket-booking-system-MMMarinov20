const express = require("express");
const app = express();
const api = require("./routes/api.js");
const cors = require("cors");

app.use(
  cors({
    origin: "http://localhost:3000",
    credentials: true,
  })
);

app.use("/api", api);

app.get("/", (req, res) => {
  res.send("Hello World!");
});

app.listen(3001, () => {
  console.log("Server is listening on port 3001");
});
