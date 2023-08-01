function solution(numbers) {
    var answer = [];
    let S = [];
    
    for (let i = 0; i < numbers.length; i++) {
        answer[i] = -1;
    }
    
    for (let i = 0; i < numbers.length; i++) {
        let num = numbers[i];
        
        while (S.length != 0) {
            let idx = S.pop();
            if (numbers[idx] < num) {
                answer[idx] = num;
            }
            else {
                S.push(idx);
                break;
            }
        }
        
        S.push(i);
    }
    
    
    return answer;
}