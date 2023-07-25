let str = "dfasd,dfasdf,xdff,dsafsade,rtertf,dsf";
let char = ',';

function ft_split(s, c) {
    let answer = [];
    let idx = 0;
    let str = "";

    while (idx < s.length){
        if (s[idx] != c){
            str = str + s[idx];
            idx++;
        }
        else{
            answer.push(str);
            str = "";
            idx++;
        }
    }
    answer.push(str);

    return answer;
}

console.log(ft_split(str,char));