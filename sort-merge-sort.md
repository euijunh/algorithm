# 병합 정렬(Merge Sort)

> ### O(NlogN)

 병합 정렬은 퀵 정렬과 마찬가지로 분할 정복 알고리즘으로 퀵정렬과 같은 O(N * logN)의 시간 복잡도를 가집니다.

다만 퀵 정렬은 어떤 피벗 값을 선택하느냐에 따라서 편향되게 분할되어서 최악의 경우 O(N^2)의 시간 복잡도를 가질 수 있지만

병합 정렬은 정확히 절반씩 나눈다는 점에서 `최악의 경우에도 O(N * logN)을 보장`한다는 점이 다른점입니다.
-> 큰 문제를 두 개의 작은 문제로 분할한 뒤에 각자 계산하고 나중에 합치는 방법을 채택합니다. 

> 기존의 데이터를 담을 추가적인 배열 공간이 필요하기 때문에 비효율적인 메모리 사용이 있습니다.


---



```js
function merge(nums, m, mid, n) {
  let l_idx = m; // 좌측배열시작인덱스
  let r_idx = mid+1; // 우측배열시작인덱스
  let k = m; // sorted배열인덱스
  // 작은 순서대로 배열에 삽입 
  while(l_idx <= mid && r_idx <= n) {
    // 두개의 배열중 하나의 배열의 정렬이 완료될 때까지 반복
    if(nums[l_idx] <= nums[r_idx]) {
      sorted[k] = nums[l_idx];
      l_idx++;
    } else {
      sorted[k] = nums[r_idx];
      r_idx++;
    }
    k++;
  }
  // 남은 배열의 데이터도 삽입 
  if(l_idx > mid) { // 오른쪽 배열의 데이터를 삽입
    for(let i = r_idx; i <= n; i++) {
      sorted[k] = nums[i];
      k++;
    }
  } else { // r_idx > n, 왼쪽 배열의 데이터를 삽입
      for(let i = l_idx; i <= mid; i++) {
      sorted[k] = nums[i];
      k++;
    }
  }

  // 정렬된 원본배열을 삽입 
  for(let i = m; i <= n; i++) {
    nums[i] = sorted[i];
  }
}

function sortFunc(nums, m, n) {
  if(m < n) { // 1개이하의 원소를 가지는 배열을 제외하고 계속 쪼개준다
    let mid = Math.floor((m+n)/2);
    sortFunc(nums, m, mid); // 좌측쪼개기
    sortFunc(nums, mid+1, n); // 우측쪼개기
    merge(nums, m, mid, n); // 정렬함수
  }
}

let nums = [10,8,5,3,1,5];
let sorted = [];
sortFunc(nums, 0, nums.length-1);
console.log(nums);
```
