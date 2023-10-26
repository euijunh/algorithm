# 선택 정렬 (Selection Sort)

> ### O(N^2) ====> N * (N + 1) / 2

```js
// 버블 정렬과 반대의 사이클(배열의 앞쪽부터 정렬)로 정렬이 이루어진다.
// ex
[1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
[2, 3, 4, 5, 6, 7, 8, 9, 10]
[3, 4, 5, 6, 7, 8, 9, 10]
[4, 5, 6, 7, 8, 9, 10]
[5, 6, 7, 8, 9, 10]
[6, 7, 8, 9, 10]
[7, 8, 9, 10]
[8, 9, 10]
[9, 10]
```

---

가장 직관적인 방법이나 비효율적이고 성능이 안좋은 알고리즘으로 오름차순의 정렬을 한다고 했을 때 가장 작은 수를 선택해서 제일 앞으로 보내는 알고리즘이다

```js
// 오름차순
function sortFunc(nums) {
  let max = Math.max(...nums)+1;
  let len = nums.length;
  let min, index, temp;
  for(let i = 0; i < len; i++) {
    min = max;
    for(let j = i; j < len; j++) {
      if(min > nums[j]) {
        min = nums[j]; // 현재 값이 min보다 작다면 min보다 작은 수를 min에 넣어준다
        index = j; // 작은 수의 index를 넣어준다
      }
    }
    temp = nums[i]; // 현재 값을 임시로 넣어준다
    nums[i] = nums[index]; // 현재 index에 가장 작은 수를 넣어준다
    nums[index] = temp; // 교체될 최소값의 인덱스에 임시로 넣어 주었던 현재 값을 넣어준다
  }
  return nums
}

// 내림차순
function sortFunc(nums) {
  let min = Math.min(...nums)-1;
  let len = nums.length;
  let max, index, temp;
  for(let i = 0; i < len; i++) {
    max = min;
    for(let j = i; j < len; j++) {
      if(max < nums[j]) {
        max = nums[j];
        index = j;
      }
    }
    temp = nums[i];
    nums[i] = nums[index];
    nums[index] = temp;
  }
  return nums
}
```
