const express = require('express');
const fs = require('fs');
const { exec } = require('child_process');
const app = express();
const port = 3000;

app.use(express.static(__dirname));

app.get('/run', (req, res) => {
    exec('app.exe', (error, stdout, stderr) => {
        if (error) {
            console.error(`Execution error: ${error}`);
            return res.status(500).send('Error running backend.');
        }
        fs.readFile('output.txt', 'utf8', (err, data) => {
            if (err) return res.status(500).send('Error reading output.');
            res.send(data);
        });
    });
});
app.listen(port, () => {
    console.log(`🚀 Server running at http://localhost:${port}`);
});