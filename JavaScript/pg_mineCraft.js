function solution(picks, minerals) {
    var answer = 0;
    let arr = [];
    let idx = 0;
    const sum_picks = picks[0] + picks[1] + picks[2];

    for (let i = 0; i < sum_picks; i++) {
        let sum = 0;
        
        for (let j = 5 * i; j < 5 * i + 5; j++) {
            if (minerals[j] == 'diamond') {
                sum = sum + 100;
            }
            else if (minerals[j] == 'iron') {
                sum = sum + 10;
            }
            else if (minerals[j] == 'stone') {
                sum = sum + 1;
            }
            else {
                sum = sum;
            }
        }
        arr.push(sum);
    }
    
    arr.sort((a, b) => b - a);
    
    for (let pick = 0; pick < 3; pick++) {
        for (let num = 0; num < picks[pick]; num++) {
            let fatigue = 0;
            
            if (idx >= arr.length) {
                break;
            }
            
            if (pick == 0) {
                fatigue = fatigue + (1 * Math.floor(arr[idx] / 100));
                arr[idx] = arr[idx] % 100;
                fatigue = fatigue + (1 * Math.floor(arr[idx] / 10));
                arr[idx] = arr[idx] % 10;
                fatigue = fatigue + (1 * Math.floor(arr[idx]));
            }
            else if (pick == 1) {
                fatigue = fatigue + (5 * Math.floor(arr[idx] / 100));
                arr[idx] = arr[idx] % 100;
                fatigue = fatigue + (1 * Math.floor(arr[idx] / 10));
                arr[idx] = arr[idx] % 10;
                fatigue = fatigue + (1 * Math.floor(arr[idx]));
            }
            else {
                fatigue = fatigue + (25 * Math.floor(arr[idx] / 100));
                arr[idx] = arr[idx] % 100;
                fatigue = fatigue + (5 * Math.floor(arr[idx] / 10));
                arr[idx] = arr[idx] % 10;
                fatigue = fatigue + (1 * Math.floor(arr[idx]));
            }
            idx++;
            answer = answer + fatigue;
        }
        if (idx >= arr.length) {
            break;
        }
    }
    
    return answer;
}