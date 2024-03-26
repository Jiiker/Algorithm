function check_str(s) {
  let stack = [];
  if (s.length % 2 === 1) {
    return false;
  }
  if (s[0] === ")" || s[0] === "}" || s[0] === "]") {
    return false;
  }

  for (let i = 0; i < s.length; i++) {
    if (s[i] === "(" || s[i] === "{" || s[i] === "[") {
      stack.push(s[i]);
    } else if (
      (stack.at(-1) === "(" && s[i] === ")") ||
      (stack.at(-1) === "{" && s[i] === "}") ||
      (stack.at(-1) === "[" && s[i] === "]")
    ) {
      stack.pop();
    } else {
      return false;
    }
  }

  return true;
}

function solution(s) {
  var answer = -1;
  let cnt = 0;

  for (let i = 0; i < s.length; i++) {
    let char = s[0];
    s = s.slice(1);
    s = s + char;

    if (check_str(s)) cnt++;
  }

  answer = cnt;

  return answer;
}
