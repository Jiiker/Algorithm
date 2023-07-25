function betweenInt(a, b)
{
    let count = 0;
    if (a % 1 != 0)
        a = parseInt(a)+1;
    b = parseInt(b)
    count = b - a + 1;
    return count;
}

function solution(r1, r2) {
    var answer = 0;
    const pow_r1 = Math.pow(r1, 2);
    const pow_r2 = Math.pow(r2, 2);
    
    for (let i = 1; i <= r2; i++){
        let pow_i = Math.pow(i, 2);
        let k1, k2;
        k1 = Math.sqrt(pow_r1 - pow_i);
        if (i > r1)
            k1 = 0;
        k2 = Math.sqrt(pow_r2 - pow_i);
        answer = answer + betweenInt(k1, k2);
    }
    
    return 4 * answer;
}