function solution(n, arr1, arr2) {
    var answer = [];
    
    for (let i = 0; i < n; i++){
        let arr_temp = [];
        let str = "";
        for (let j = 0; j < n; j++){
            arr_temp.push((arr1[i] % 2) + (arr2[i] % 2));
            arr1[i] = Math.floor(arr1[i] / 2);
            arr2[i] = Math.floor(arr2[i] / 2);
        }
        for (let k = 0; k < n; k++){
            let num = arr_temp.pop();
            if (num >= 1)
                str = str + '#';
            else
                str = str + ' ';
        }
        answer.push(str);
    }
    
    return answer;
}