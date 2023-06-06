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

## 소수

- **약수**

소수는 1과 자기자신만으로 나누어 떨어져야 하기 때문에 어떤 수 N이 소수인지 알아보기 위해서는 2부터 N보다 작을때까지 나눠서 떨어지는 수가 존재하면 소수가 아니라는 뜻이 된다. 

나누어 떨어지는 수마다 배열에 추가해 주면 약수의 개수를 구할 수도 있고 나누어 떨어지는 수가 나올때 loop문을 종료하면 전체 반복을 돌지 않고도 소수인지 판별할 수 있다.

- **[에라토스테네스의 체](https://namu.wiki/w/%EC%97%90%EB%9D%BC%ED%86%A0%EC%8A%A4%ED%85%8C%EB%84%A4%EC%8A%A4%EC%9D%98%20%EC%B2%B4)**

임의의 자연수 n에 대해 그 이하의 소수를 모두 찾는, 가장 간단하고 빠른 방법

1~100까지 숫자 중 소수를 찾는다 해보자.

1. 일단 1부터 100까지 숫자를 쭉 쓴다.
2. 일단 소수도, 합성수도 아닌 유일한 자연수 1(기초수)을 제거하자.
3. 2를 제외한 2의 배수를 제거한다.
4. 3을 제외한 3의 배수를 제거한다.
5. 4의 배수는 지울 필요 없다.(2의 배수에서 이미 지워졌다.) 그러면 2, 3 다음으로 남아있는 가장 작은 소수, 즉 5를 제외한 5의 배수를 제거해야 한다.
6. 그리고 마지막으로 7을 제외한 7의 배수까지 제거하면 된다. 8의 배수는 지울 필요 없다.(2의 배수에서 이미 지워졌다.) 9의 배수도 지울 필요 없다.(3의 배수에서 이미 지워졌다.) 10의 배수도 지울 필요 없다.(2의 배수에서 이미 지워졌다.)

그리고 11 이상의 소수들의 배수부터는 11 >  $\sqrt{100}$ 이기 때문에 역시 지울 필요 없다. 이런 식으로 남은 것들의 2배수, 3배수,...n배수를 지우다보면 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97이 남는다. 이것이 100 이하의 소수이다. 이런 방법으로 만약 n이하의 소수를 모두 찾고 싶다면 1부터 n까지 쭉 나열한 다음에(...) 2의 배수, 3의 배수, 5의 배수...쭉쭉 나누는 것이다.

일종의 노가다 방식이라 상당히 무식한 방법이긴 하지만, 특정 범위가 주어지고 그 범위 내의 모든 소수를 찾아야 하는 경우 아직까지 소수들 간의 연관성(=소수를 생성할 수 있는 공식)이 나오지 않았으므로(윌런스의 공식이 있긴 하지만 너무 비효율적. 소수 정리는 소수의 개수를 근사하는 공식.) 에라토스테네스의 체보다 빠른 방법이 없다.(사실 작은 범위에 대해 먼저 체를 쓴 다음 그 체로 합성수를 미리 거르는 wheel이란 기법을 쓰면 좀더 빨라지긴 한다. 대개 60을 쓴다.)

다만 에라토스테네스의 체는 '특정 범위 내의 소수'를 판정하는 데에만 효율적이다. 만약 주어진 수 하나가 소수인가? 만을 따지는 상황이라면 이는 소수판정법이라 해서 에라토스테네스의 체 따위와는 비교도 안되게 빠른방법이 넘쳐난다.

한편, 에라토스테네스의 체를 이용해 1\~n까지의 소수를 알고 싶다면, n까지 모든 수의 배수를 다 나눠 볼 필요는 없다. 만약 n보다 작은 어떤 수 m이 m=ab라면 a와 b 중 적어도 하나는 $\sqrt{n}$ 이하이다. 즉 n보다 작은 합성수 m은 
$\sqrt{n}$ 보다 작은 수의 배수만 체크해도 전부 지워진다는 의미이므로, $\sqrt{n}$  이하의 수의 배수만 지우면 된다. 단적으로 1~100인 위의 경우, 사실은 7의 배수 중 남아있는 `49(7*7), 77(7*11), 91(7*13)`만 더 지우면 끝난다. 만일 표에 11<sup>2</sup>(121)보다 큰 수가 있다면 11을 제외한 11의 배수를 지워야 하는데, 이 과정에서 최초로 지워지는 수는 121(11<sup>2</sup>)이다. 그런데 이는 주어진 범위를 초과하는 수다.


- **제곱근**
 
![제곱근 이미지](https://raw.githubusercontent.com/euijunh/algorithm-part2/main/boj/js/img/prime-number1.png)

10을 기준으로 수들이 대칭이 된다. 5로 100을 나눌 수 있으면 5의 몫인 20으로도 100을 나눌 수 있는것이고 4로 100을 나눌 수 있으면 4의 몫인 25로도 100을 나울수 있기 때문에 i가 소수인지 아닌지 판별할 때 10을 기준으로 오른쪽에 있는 수들은 나누어 볼 필요가 없고 10을 포함한 10을 기준으로 왼쪽(1은 제외, 1은 모든 수의 약수)에 숫자들만 계산 해봐도 소수인지 아닌지 판별이 가능하다.

대칭에 기준이 되는 가운데에 10은 제곱근 i, $\sqrt{i}$ 이다. 결론은 2부터 제곱근까지 나누어 봤을때 나눌수 있는수가 존재하면 소수가 아니고 나눌수 있는 수가 없으면 소수라는 뜻이다.
