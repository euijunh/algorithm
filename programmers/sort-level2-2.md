# H-Index

### 문제 설명
H-Index는 과학자의 생산성과 영향력을 나타내는 지표입니다. 어느 과학자의 H-Index를 나타내는 값인 h를 구하려고 합니다. 위키백과1에 따르면, H-Index는 다음과 같이 구합니다.

어떤 과학자가 발표한 논문 n편 중, h번 이상 인용된 논문이 h편 이상이고 나머지 논문이 h번 이하 인용되었다면 h의 최댓값이 이 과학자의 H-Index입니다.

어떤 과학자가 발표한 논문의 인용 횟수를 담은 배열 citations가 매개변수로 주어질 때, 이 과학자의 H-Index를 return 하도록 solution 함수를 작성해주세요.

### 제한사항
* 과학자가 발표한 논문의 수는 1편 이상 1,000편 이하입니다.
* 논문별 인용 횟수는 0회 이상 10,000회 이하입니다.

### 입출력 예
| citations |	return |
|:-----|:-----|
| [3, 0, 6, 1, 5]	| 3

### 입출력 예 설명
이 과학자가 발표한 논문의 수는 5편이고, 그중 3편의 논문은 3회 이상 인용되었습니다. 그리고 나머지 2편의 논문은 3회 이하 인용되었기 때문에 이 과학자의 H-Index는 3입니다.

### 제출
```js
// 처음 구상( 문제자체를 정확히 이해하진 못하고 푼 풀이 )
function solution(citations) {
    // if(citations.length === 1) return citations[0]
    const sorted_citations = [...citations].sort((a, b) => a - b);
    const n = sorted_citations.length
    let answer = 0;
    
    sorted_citations.forEach((thesis, i) => {
        if((n - i) >= thesis) {
            answer = thesis
        }
    })
    
    return answer;
}

// 정답
function solution(citations) {
    const sorted_citations = [...citations].sort((a, b) => b - a);
    let answer = 0;

    while(sorted_citations[answer] >= (answer + 1)) {
        answer++
    }

    return answer;
}

// 다른풀이방법
function solution(citations) {
  citations.sort((a, b) => b - a);
  for (let i = 0; i < citations.length; i++) {
    if (i >= citations[i]) {
      return i;
    }
  }
  return citations.length;
}
```

### 참고
문제풀이 : 
1. 전체 논문중 많이 인용된 순으로 정렬
2. 피인용수가 논문수와 같아지거나 피인용수가 논문수보다 작아지기 시작하는 숫자가 바로 나의 h가 됩니다.

[문제이해를 위한 참고자료](https://www.ibric.org/bric/trend/bio-series.do?mode=series_view&newsArticleNo=8802417&articleNo=8882714&beforeMode=latest_list)
