function solution(s, skip, index) {
    const arr_alpha = Array.from({length : 24}, () => 1);
    answer = "";
    
    for (let i = 0; i < skip.length; i++){
        arr_alpha[skip[i].charCodeAt(0) - 'a'.charCodeAt(0)] = 0;
    }
    
    for (let i = 0; i < s.length; i++){
        let ascii_s = s[i].charCodeAt(0);
        for (let j = 0; j < index; j++){
            ascii_s++;
            
            if (ascii_s > 'z'.charCodeAt(0))
                ascii_s = 'a'.charCodeAt(0);
            
            if (arr_alpha[ascii_s - 'a'.charCodeAt(0)] == 0)
                j--;
        }
        answer = answer + String.fromCharCode(ascii_s);
    }
    
    return answer;
}