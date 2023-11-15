# 모의고사

### 문제 설명
수포자는 수학을 포기한 사람의 준말입니다. 수포자 삼인방은 모의고사에 수학 문제를 전부 찍으려 합니다. 수포자는 1번 문제부터 마지막 문제까지 다음과 같이 찍습니다.

1번 수포자가 찍는 방식: 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, ...

2번 수포자가 찍는 방식: 2, 1, 2, 3, 2, 4, 2, 5, 2, 1, 2, 3, 2, 4, 2, 5, ...

3번 수포자가 찍는 방식: 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, ...

1번 문제부터 마지막 문제까지의 정답이 순서대로 들은 배열 answers가 주어졌을 때, 가장 많은 문제를 맞힌 사람이 누구인지 배열에 담아 return 하도록 solution 함수를 작성해주세요.

### 제한 조건
* 시험은 최대 10,000 문제로 구성되어있습니다.
* 문제의 정답은 1, 2, 3, 4, 5중 하나입니다.
* 가장 높은 점수를 받은 사람이 여럿일 경우, return하는 값을 오름차순 정렬해주세요.

### 입출력 예
|answers|	return|
|:-----|:-----|
|[1,2,3,4,5]| [1]
|[1,3,2,4,2]| [1,2,3]

### 입출력 예 설명
입출력 예 #1

* 수포자 1은 모든 문제를 맞혔습니다.
* 수포자 2는 모든 문제를 틀렸습니다.
* 수포자 3은 모든 문제를 틀렸습니다.

따라서 가장 문제를 많이 맞힌 사람은 수포자 1입니다.

입출력 예 #2

* 모든 사람이 2문제씩을 맞췄습니다.

### 제출
```js
// 오답제출
function solution(answers) {
    let score = [0, 0, 0];
    let answer = [];
    let student_answer_sheet = [
        [1, 2, 3, 4, 5], 
        [2, 1, 2, 3, 2, 4, 2, 5], 
        [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]
    ]
    student_answer_sheet.forEach((sheet, idx) => {
        if(answers.length > sheet.length) {
            const tmp = [...sheet];
            const n = Math.floor(answers.length/sheet.length);
            for(let i = 0; i < n; i++) {
              student_answer_sheet[idx].push(...tmp)
            }
        }
        for(let i = 0; i < answers.length; i++) {
            if(answers[i] === sheet[i]) score[idx]++
        }
    })
    
    const max = Math.max(...score);
    student_answer_sheet.forEach((sheet, idx) => {
        if(max === score[idx]) {
            answer[idx] = idx+1
        }
    })

    // 오답 지점 확인, 위 코드를 아래코드로 수정하면 정답
    // answer에 index 값을 수정
    // let idx = 0;
    // student_answer_sheet.forEach((sheet, i) => {
    //     if(max === score[i]) {
    //         answer[idx] = i+1
    //         idx++
    //         or -> answer.push(i+1)
    //     }
    // })

    return answer;
}

// 정답제출 - 개선된 코드
function solution(answers) {
    const no1_student = [1, 2, 3, 4, 5];
    const no2_student = [2, 1, 2, 3, 2, 4, 2, 5];
    const no3_student = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5];
    let answer = [];
    let scores = [0, 0, 0];
    
    answers.forEach((answer, i) => {
        if(no1_student[i % 5] === answer) scores[0]++
        if(no2_student[i % 8] === answer) scores[1]++
        if(no3_student[i % 10] === answer) scores[2]++
    })
    
    const max = Math.max(...scores);
    let idx = 0;
    scores.forEach((score, i) => {
        if(score === max) {
            answer[idx] = i+1
            idx++
            // or -> answer.push(i+1)
        }
    })

    return answer;
}
```
