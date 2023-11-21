# 카펫

### 문제 설명
Leo는 카펫을 사러 갔다가 아래 그림과 같이 중앙에는 노란색으로 칠해져 있고 테두리 1줄은 갈색으로 칠해져 있는 격자 모양 카펫을 봤습니다.

![carpet](https://github.com/euijunh/algorithm/assets/52102634/3a64aee9-25ec-4910-8ee1-a20ba8f7b197)

Leo는 집으로 돌아와서 아까 본 카펫의 노란색과 갈색으로 색칠된 격자의 개수는 기억했지만, 전체 카펫의 크기는 기억하지 못했습니다.

Leo가 본 카펫에서 갈색 격자의 수 brown, 노란색 격자의 수 yellow가 매개변수로 주어질 때 카펫의 가로, 세로 크기를 순서대로 배열에 담아 return 하도록 solution 함수를 작성해주세요.

### 제한 조건
* 갈색 격자의 수 brown은 8 이상 5,000 이하인 자연수입니다.
* 노란색 격자의 수 yellow는 1 이상 2,000,000 이하인 자연수입니다.
* 카펫의 가로 길이는 세로 길이와 같거나, 세로 길이보다 깁니다.

### 입출력 예
|brown|	yellow|return|
|:-----|:-----|:-----|
| 10 | 2 | [4, 3] |
| 8 | 1 | [3, 3] |
| 24 | 24 | [8, 6] |

		
	


### 입출력 예 설명


### 제출
```js
// 첫제출 - 오답
// 적용한 개념
// 1. 카펫의 너비는 높이와 같거나, 높이보다 깁니다.
// 2. brown + yellow 는 너비 * 높이 입니다.

function solution(brown, yellow) {
    let answer = [];
    const sum = brown + yellow;
    const n = brown > yellow ? brown : yellow;
    for(let i = 1; i < n; i++) {
        if(answer.length) break
        for(let j = 1; j <= i; j++) {
            if((i*j) === sum) {
                answer.push(...[i, j])
            }
        }
    }
    return answer;
}

// 정답 제출
// 조건정리
/*
1. brown/2 +2 === 너비 + 높이
2. (가로-2) * (높이-2) = 노란색 격자 수
3. 최소높이는 3이다
4. brown + yellow 는 높이의 배수 입니다.
*/
function solution(brown, yellow) {
    let answer = [];
    const sum = brown + yellow;
    for(let h = 3; h <= sum/h; h++) {
	// brown + yellow 는 높이의 배수이기 때문에 h <= sum/h 까지만 반복수행
        if(sum%h === 0) {
            const w = sum/h;
            if(yellow === (w-2)*(h-2)) {
                answer.push(w, h);
                break;
            }
        }
    }
    return answer;
}
```



