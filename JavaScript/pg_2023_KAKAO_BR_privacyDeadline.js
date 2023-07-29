function solution(today, terms, privacies) {
    var answer = [];
    let temp_today = today.split('.');
    let todayInt = parseInt(temp_today[0]+temp_today[1]+temp_today[2]);
    let map_terms = new Map();
    
    for (let i = 0; i < terms.length; i++) {
        let temp = terms[i].split(' ');
        map_terms.set(temp[0], parseInt(temp[1]));
    }
    
    for (let i = 0; i < privacies.length; i++) {
        let temp = privacies[i].split(' ');
        let temp_day = temp[0].split('.');
        let dayInt = parseInt(temp_day[0]+temp_day[1]+temp_day[2]);
        let kind = map_terms.get(temp[1]);
        
        if (kind >= 12) {
            kind = 100 * Math.floor(kind / 12) + (kind % 12);
        }
        
        let deadline = dayInt + (kind * 100 - 1);
        
        if (deadline % 100 == 0) {
            deadline = deadline - 72;
        }
        
        if (Math.floor(deadline / 100) % 100 > 12) {
            deadline = deadline + 8800;
        }
        
        
        if (deadline < todayInt) {
            answer.push(i + 1);
        }
        
    }
    
    return answer;
}