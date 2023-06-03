# JavaScript

***node.js***

## 입력
* String
  * 문자배열
    * `let input = require('fs').readFileSync('dev/stdin').toString().split(' ');`
  * 문자
    * `let input = require('fs').readFileSync('dev/stdin').toString().trim();`

* Number
  * ``let input = require('fs').readFileSync('dev/stdin').toString().split(' ').map(value => +value);``

## 입력 에러
**node.js - 런타임 에러 (EACCES) 현상**

fs모듈는 예제 입력 파일에 접근해야 하기 때문에 일부 문제에서는 "런타임 에러 (EACCES)" 형태의 접근권한 오류가 생김

해결방법 : readline 모듈 사용

* fs모듈이 비교적 속도가 빠르기 때문에 처음부터 readline을 쓰면 시간초과가 될 수 있다.

### readline 모듈
```
 // 예제 입력이 한줄로 되어 있을 때
const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', function(line) {
  console.log(line);

  rl.close();
}).on("close", function() {
  process.exit();
});

-----------------------------------------

// 예제 입력이 여러줄로 되어 있을 떼
const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let input = [];

rl.on('line', function (line) {
  input.push(line)
})
  .on('close', function () {
  console.log(input);
  process.exit();
});
```

### fs 모듈
```
// 예제 입력이 한줄로 되어 있을 때
const fs = require('fs')
//숫자 하나인 경우
const input = Number(fs.readFileSync('dev/stdin'))
//' ' 기준으로 구분
const input = fs.readFileSync('dev/stdin').toString().split(' ')

console.log(input)

-----------------------------------------

// 예제 입력이 여러줄로 되어 있을 떼
let fs = require('fs')
let input = fs.readFileSync('dev/stdin').toString().split('\n')

// 예제 데이터 개수가 주어진 경우
let cnt = input[0]
let lines = []

for(let i = 1; i <= cnt; i++) {
	lines.push(input[i].split(' '))
}

console.log(lines)
```


## 출력
```
console.log("Hello World");
```

## 100*100 크기의 2차원 배열 만들기
```
Array.from(new Array(100), () => new Array(100).fill(0))

// x는 현재 배열의 현재 index의 값을 의미
Array.from(new Array(100), x => x + 1)
```

## 제곱
```
Math.pow(2, 2) => 2에 2제곱을 구하는 함수

** =>  거듭제곱 연산자
```

## 제곱근
```
Math.sqrt
ex) 9의 제곱을 구하는 방법 9**0.5
```

## 큰수 다루기
```
BigInt(9007199254740991) -> 9007199254740991n
뒤에 붙는 n을 없애려면 toString()을 사용
```
