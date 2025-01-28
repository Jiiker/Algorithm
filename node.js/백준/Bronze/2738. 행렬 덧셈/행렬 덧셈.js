const input = require("fs")
.readFileSync(process.platform === "linux" ? "dev/stdin" : "./input.txt")
.toString()
.trim()
.split("\n")
.map(el => el.split(" ").map(Number));

for (let i = 1; i <= input[0][0]; i++) {
    for (let j = 0; j < input[0][1]; j++) {
        let sum = input[i][j] + input[i+input[0][0]][j];
        process.stdout.write(`${sum} `);
    }
    process.stdout.write("\n");
}