const express = require("express");
const bodyParser = require("body-parser");
const fs = require("fs");
const { exec } = require("child_process");
const cors = require("cors");
const app = express();
app.use(cors());
app.use(bodyParser.json());
const PORT = 3000;
app.post("/search", (req, res) => {
    const searchId = req.body.id;
    fs.writeFileSync("search.txt", searchId);
    exec("app.exe", (error, stdout, stderr) => {
        if (error) {
            console.error("Execution error:", error);
            return res.status(500).send("Execution failed");
        }
        const result = fs.readFileSync("output.txt", "utf-8");
        res.send(result);
    });
});
app.listen(PORT, () => {
    console.log(`🚀 Server running at http://localhost:${PORT}`);
});