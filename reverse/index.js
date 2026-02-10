// function ReversePair(arr) {
//   let count = 0;
//   for (let i = 0; i < arr.length ; i++) {
//     for (let j = i + 1;  j < arr.length ; j++) {
//       if (arr[i] > 2 *  arr[j] ) {
// count++

//       }
//     }
//   }
// return count
// }

// let arr = [1, 3, 2, 3, 1];
// console.log(ReversePair(arr));

// function ReversePair() {

// }

// function mergerSort() {

// }

// function Pair(arr, target) {
//   for (let i = 0; i < arr.length; i++) {
//     for (let j = i + 1; j < arr.length; j++) {
//       if (arr[i] + arr[j] == target) {
//         return { i, j };
//       }
//     }
//   }
// }
// let arr1 = [1, 2, 3, 4, 5];

// console.log(Pair(arr1, 5));

// function pair(nums, target) {
//   let st = 0;

//   let end = nums.length - 1;
//     // nums = nums.filter(n => n != undefined)
//   while (st < end) {
//     if (!(st in nums) || nums[st] === undefined) {
//         st++;
//         continue ;
//     }
//     if (!(end in nums) || nums[end] === undefined) {
//         end--;
//         continue ;
//     }

//     let sum = nums[st] + nums[end];
//     if (sum === target) {
//       return [st, end];
//     }
//     if (sum < target) {
//       st++;
//     } else if (sum > target) {
//       end--;
//     }
//   }

//   return -1;
// }

// let nums = [-1, 0, 1, 2, , 5, 6];
// console.log(pair(nums, 3));

function Majority(arr) {
  let cnt = 0;
  for (let i = 0; i < arr.length; i++) {
    cnt=0
    for (let j = 0; j < arr.length; j++) {
      if (arr[i] === arr[j]) {
        cnt++;
      }
    }
    if (cnt > Math.floor(arr.length / 2)) {
      return arr[i];
    }
  }

  return false
}

let arr = [1, 1, 1, 1, 2, 2, 2, 2, 2, 2];
console.log(Majority(arr));
