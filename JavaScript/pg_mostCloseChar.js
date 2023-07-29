function solution(s) {
    var answer = [];
    let M = new Map();
    
    for (let i = 0; i < s.length; i++) {
        if (M.get(s[i])) {
            answer.push(i + 1 - M.get(s[i]));
            M.delete(s[i]);
            M.set(s[i], i + 1);
        }
        else {
            answer.push(-1);
            M.set(s[i], i + 1);
        }
    }
    
    return answer;
}