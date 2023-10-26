# 버블 정렬 (Bubble Sort)

> ### O(N^2)

```js
// 선택 정렬과 다르게(배열의 뒤쪽부터 정렬) 거품이 일어났다가 꺼지듯이 정렬이 이루어진다.
// ex
[1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
[1, 2, 3, 4, 5, 6, 7, 8, 9]
[1, 2, 3, 4, 5, 6, 7, 8]
[1, 2, 3, 4, 5, 6, 7]
[1, 2, 3, 4, 5, 6]
[1, 2, 3, 4, 5]
[1, 2, 3, 4]
[1, 2, 3]
[1, 2]
```

옆에 있는 값과 비교하여 더 작은 값을 반복적으로 앞으로 보내는 정렬 방법으로 정렬 알고리즘 중에서 구현은 가장 쉽지만 가장 성능이 안좋은 알고리즘입니다.(선택정렬보다 더 비효율적)

옆에 있는 값이 더 작다면 계속해서 배열의 값을 바꿔주는 연산이 발생하기 때문에 선택정렬보다 비효율적인 알고리즘입니다.

---



```js
// 오름차순
function sortFunc(nums) {
  let len = nums.length;
  let temp;
  for(let i = 0; i < len; i++) {
    for(let j = 0; j < (len-1)-i; j++) {
      // 현재 j번째 값과 다음값(j+1번째)을 비교하기 때문에 j는 nums.length-1(배열의 마지막 값 전까지만확인)까지 loop를 실행한다
      if(nums[j] > nums[j+1]) { // 현재 값이 다음 값보다 크면 두 값의 자리를 바꿔준다
        temp = nums[j];
        nums[j] = nums[j+1];
        nums[j+1] = temp;
      }
    }
  }
  return nums
}

// 내림차순
function sortFunc(nums) {
  let len = nums.length;
  let temp;
  for(let i = 0; i < len; i++) {
    for(let j = 0; j < (len-1)-i; j++) {
      if(nums[j] < nums[j+1]) { // 간단하게 부등호만 바꿔주면 내림차순 정렬
        temp = nums[j];
        nums[j] = nums[j+1];
        nums[j+1] = temp;
      }
    }
  }
  return nums
}
```
