const input = require("fs")
.readFileSync(process.platform === "linux" ? "dev/stdin" : "./input.txt")
.toString()
.trim()
.split("\n")

let str = "";

for (let i = 0; i < 15; i++) {
    for (let j = 0; j < 5; j++) {
        if (input[j].length <= i)
            continue;
        str += input[j][i];
    }
}

console.log(str);
