# 가장 큰 수

### 문제 설명
0 또는 양의 정수가 주어졌을 때, 정수를 이어 붙여 만들 수 있는 가장 큰 수를 알아내 주세요.

예를 들어, 주어진 정수가 [6, 10, 2]라면 [6102, 6210, 1062, 1026, 2610, 2106]를 만들 수 있고, 이중 가장 큰 수는 6210입니다.

0 또는 양의 정수가 담긴 배열 numbers가 매개변수로 주어질 때, 순서를 재배치하여 만들 수 있는 가장 큰 수를 문자열로 바꾸어 return 하도록 solution 함수를 작성해주세요.

### 제한사항
* numbers의 길이는 1 이상 100,000 이하입니다.
* numbers의 원소는 0 이상 1,000 이하입니다.
* 정답이 너무 클 수 있으니 문자열로 바꾸어 return 합니다.

### 입출력 예
| numbers |	return |
|:-----|:-----|
| [6, 10, 2]	| "6210" |
| [3, 30, 34, 5, 9]		| "9534330" |

### 제출
```js
function solution(numbers) {
    const sorted_numbers = numbers.sort((a, b) => {
        const string_a = String(a);
        const string_b = String(b);
        return (string_b+string_a) - (string_a+string_b)
    }).join('');
    return sorted_numbers[0] !== "0" ? sorted_numbers : "0"
}

// 타인의 좋아보였던 코드
function solution(numbers) {
    let answer = numbers.sort((a, b) => `${b}${a}` - `${a}${b}`).join('');
    return answer[0] === '0' ? '0' : answer;
}
```

입력 받는 numbers 배열에 0만(ex. [0,0,0] 이나 [0,0]이면 "000" 혹은 "00"이 리턴되므로 예외처리필요) 들어오는 경우 예외처리에 주의
