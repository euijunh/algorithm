# 소수 찾기

### 문제 설명
한자리 숫자가 적힌 종이 조각이 흩어져있습니다. 흩어진 종이 조각을 붙여 소수를 몇 개 만들 수 있는지 알아내려 합니다.

각 종이 조각에 적힌 숫자가 적힌 문자열 numbers가 주어졌을 때, 종이 조각으로 만들 수 있는 소수가 몇 개인지 return 하도록 solution 함수를 완성해주세요.

### 제한 조건
* numbers는 길이 1 이상 7 이하인 문자열입니다.
* numbers는 0~9까지 숫자만으로 이루어져 있습니다.
* "013"은 0, 1, 3 숫자가 적힌 종이 조각이 흩어져있다는 의미입니다.

### 입출력 예
|numbers|	return|
|:-----|:-----|
|"17"| 3|
|"011"| 2|

### 입출력 예 설명
예제 #1

[1, 7]으로는 소수 [7, 17, 71]를 만들 수 있습니다.

예제 #2

[0, 1, 1]으로는 소수 [11, 101]를 만들 수 있습니다.

  * 11과 011은 같은 숫자로 취급합니다.

### 제출
```js
function solution(numbers) {
    let answer = 0;
    const numbers_arr = numbers.split('');
    let numbers_set = new Set();
    const recursive = (comb, others) => {
        if(comb && comb != "0" && comb[0] != "0") numbers_set.add(comb)
        for(let i = 0; i < others.length; i++) {
            recursive(comb+others[i], [...others.slice(0, i), ...others.slice(i+1)]);
        }
    }
    
    recursive('', numbers_arr);

    const isPrimeNumber = num => {
        if(num == 0 || num == 1) return false
        let i = 2;
        while(i < num) {
            if(num%i === 0) return false
            i++
        }
        return true
    }
    
    numbers_set.forEach(num => {
        if(isPrimeNumber(num)) answer++
    })

    return answer;
}



// 성능개선 - "에라토스테네스의 체" 활용
function solution(numbers) {
    let answer = 0;
    const numbers_arr = numbers.split('');
    let numbers_set = new Set();
    const recursive = (comb, others) => {
        if(comb && comb != "0" && comb[0] != "0") numbers_set.add(comb)
        for(let i = 0; i < others.length; i++) {
            recursive(comb+others[i], [...others.slice(0, i), ...others.slice(i+1)]);
        }
    }
    
    recursive('', numbers_arr);

    const isPrimeNumber = num => {
        if(num == 0 || num == 1) return false
        let i = 2;
        // 에라토스테네스의 체
        const square_root = Math.sqrt(num);
        while(i <= square_root) {
            if(num%i === 0) return false
            i++
        }
        return true
    }
    
    numbers_set.forEach(num => {
        if(isPrimeNumber(num)) answer++
    })

    return answer;
}


// 더 성능개선 - "에라토스테네스의 체" 활용 + 배열로 변환 작업 삭제
function solution(numbers) {
    let answer = 0;
    let numbers_set = new Set();
    const recursive = (comb, others) => {
        if(comb && comb != "0" && comb[0] != "0") numbers_set.add(comb)
        for(let i = 0; i < others.length; i++) {
            recursive(comb+others[i], others.substring(0, i) + others.substring(i+1));
        }
    }
    
    recursive('', numbers);

    const isPrimeNumber = num => {
        if(num === 0 || num === 1) return false
        let i = 2;
        const square_root = Math.sqrt(num);
        while(i <= square_root) {
            if(num%i === 0) return false
            i++
        }
        return true
    }
    
    numbers_set.forEach(num => {
        if(isPrimeNumber(+num)) answer++
    })

    return answer;
}
```

* 재귀로 순열 만들기
* `Set`으로 중복 없애기
* `에라토스테네스의 체` - 제곱근을 구해 소수구하는 연산 줄이기

## 참고
[참고](https://www.youtube.com/watch?v=pF368QqdQb4)

```
매번 recursive 함수가 호출될 때 comb와 others 인자가 어떻게 변경되는 지를 쫓아가시면서 봐야 조금 더 정확하게 볼 수 있을 것 같아요. 제가 "17"을 예시로 문제를 푼다면 이렇게 정리하고 코딩을 시작할 것 같아요.

1. comb="", others="17" 
  - comb==""이기 때문에 numberSet에 add하지 않고 바로 for문으로 넘어감
  - others.length() == 2이기 때문에 i=0; i<2; i++ 로 2회 수행
    1-1 (i==0). comb="1", others="7"
      - numberSet.add("1") 수행
      - others.length() == 1이기 때문에 for문 1회 수행
        1-1-1. (i==0) comb="17", others=""
          - numberSet.add("17") 수행
          - others.length() == 0이기 때문에 for문 수행하지 않고 바로 나감
    1-2 (i==1). comb="7", others="1"
      - numberSet.add("7") 수행
      - others.length() == 1이기 때문에 for문 1회 수행
        1-2-1. (i==0) comb="71", others=""
          - numberSet.add("71") 수행
          - others.length() == 0이기 때문에 for문 수행하지 않고 바로 나감

1-1-1이 끝나면 다시 1-1로 돌아오고, 1-1이 끝나면 1-2로 들어가야 하는데, 1-2로 가지 않고 그냥 함수가 끝난다고 생각하셔서 헷갈리시는 것 같아요. 

1-2만 놓고 생각해보면, 1. 단계에서 comb="", others="17"로 들어왔기 때문에 for문을 두 번째 돌 때에도 comb=""이고, others.charAt(i==1)은 "7"이 될 겁니다. 
새로 만들어진 comb 는 "" + "7" 의 결과물인 "7"이 전달 될 거고요.

그래서 재귀함수를 처음 짤 때는 손코딩이 참 중요한 것 같아요. 해답을 보면서 공부를 해도 좋은데, 이 해답이 어떤 동작을 할지를 손으로 하나 하나 그려보면 생각의 힘을 기르는 데 큰 도움이 되고요, 특히나 재귀처럼 여러 번 호출됐다가 나왔다를 반복하는 경우에는 제대로 정리하지 않으면 매번 헷갈릴 거예요.

우선은 제가 정리해 놓은 걸 따라가면서 한번 이해하고, 직접 다시 그려보면서 같은 그림이 나오는지도 보면 좋을 것 같고요,
그게 잘 됐다면 "011" 예시에 대해서도 수행해보기 전에 제가 정리한 것처럼 쭉 정리를 해보고, 프로그램 실행할 때 print문 추가해서 예상하셨던 것처럼 잘 나오는 지 비교해보는 걸 추천드려요.

당장 이 문제 하나를 이해하고 말고를 떠나서 재귀를 정확하게 이해하려면 직접 그려보시는 게 가장 효과적일 것 같습니다:)
```
