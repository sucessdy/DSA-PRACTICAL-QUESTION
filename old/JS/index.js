"use strict";
// const map = new Map() ;
// map.set("Tv" , 100);
// map.set("Laptop" , 10);
// map.set("Headphone" , 90);
// map.set("Speaker" , 60);

// console.log(map.get("Tv"));

// map.set("Tv", 97);

// console.log(map.get("Tv"));

// console.log(map.size);

// function Rotated(arr, target) {
//   let st = 0;
//   let end = arr.length - 1;

//   while (st <= end) {
//     let mid = Math.floor(st + end / 2);

//     if (arr[mid] == target) return mid;

//     if (arr[st] <= arr[mid]) {
//       if (arr[st] <= target && target <= arr[mid]) {
//         end = mid - 1;
//       } else {
//         st = mid + 1;
//       }
//     } else {
//       if (arr[mid] <= target && target <= arr[end]) {
//         st = mid + 1;
//       } else {
//         end = mid - 1;
//       }
//     }
//   }
//   return -1;
// }

function productExpectSelf(arr) {
    let n = arr.length ;
  let ans  = new Array(n).fill(1);

  for (let i = 0; i < n; i++) {

    for (let j = 0; j <n; j++) {
      if (i !== j) {
        ans[i] *= arr[j];
      }
    }

  }
  return ans;
}
let arr  = [1, 2, 3, 4] ;

console.log(productExpectSelf(arr));

// // let arr = [4, 5, 6, 7, 0, 1, 2];
// // let target = 2;
// // // console.log(Rotated(arr , target));

// function ReverseString(a) {
//   let reverse = "" ;
// for (let i = a.length -1 ; i >= 0 ; i--) {
//   reverse += a[i];
//  }
//  return reverse ;
// }

// let a = "hello world" ;
// console.log(ReverseString(a)) ;

// // Find Maximum Element in an Array

// function MaximumElement(arr) {
//   let max = arr[0];
//   for (let i = 1; i < arr.length; i++) {
//     if (arr[i] > max) {
//       max = arr[i];
//     }
//   }
//   return max;
// }

// let arr = [1, 2, 3, 4, 5, 7];

// console.log(MaximumElement(arr));

// var isPalindrome = function (n) {
//   function IsReverse(n) {
//     let revNum = 0;
//     while (n != 0) {
//       let dig = n % 10;
//       revNum = revNum * 10 + dig;
//       n = Math.floor(n / 10);
//     }
//     return revNum;
//   }
//   if (n < 0) return false;
//   return IsReverse(n) === n;
// };

// let n = 121;
// console.log(isPalindrome(n));

// function toFindVowel(str) {
//   let vowel = "aeiouAEIOU";
//   let count = 0;

//   for (let char of str) {
//     if (vowel.includes(char)) {
//       count++;
//     }
//   }
//   return count;
// }

// function doesAliceWin(str) {
//   let n = str.length;
//   let vowel = "aeiouAEIOU";
//   let hasVowel = false;
//   let oneV = false;
//   let count = 0;

//   for (let char of str) {
//     if (vowel.includes(char)) {
//       hasVowel = true;
//       oneV = true;

//       count++;
//       break;
//     } else if (n % 2 === 1) {
//       count % 2 === 1;

//       //alice
//     } else {
//       count % 2 === 0;
//     }
//   }
//   return hasVowel && oneV;
// }

// let str = "eaibo";
// console.log(doesAliceWin(str));

// let str = "datastructures";
// console.log(toFindVowel(str));

// function sumArray(num) {
//   let sum = 0;
//   for (let i = 0; i < num.length; i++) {
//     sum += num[i];
//   }
//   return sum;
// }

// let num = [1, 2, 3,4, 5] ;

// console.log(sumArray(num)) ;

// function leftRotate(arr) {
//   let temp = arr[0];
//   for (let i = 1; i < arr.length; i++) {
//     arr[i - 1] = arr[i];
//   }
//   arr[arr.length - 1] = temp;
//   return arr;
// }

// let arr = [1, 2, 3, 4, 5];

// console.log(leftRotate(arr));

// function RotateTheLeftArray(nums, d) {
//   let n = nums.length;
//   d = d % n;

//   let temp = new Array(d);
//   for (let i = 0; i < d; i++) {
//     temp[i] = nums[i];
//   }
//   for (let i = d; i < n; i++) {
//     nums[i - d] = nums[i]; // shifting
//   }
//   for (let i = n - d; i < n; i++) {
//     /// put back
//     nums[i] = temp[i - (n - d)];
//   }

//   return nums;
// }
// // let nums = [1, 2, 3, 4, 5, 6, 7];
// // let d = 2;
// // console.log(RotateTheLeftArray(nums, d)); // t c= 0 (n + d) and SC = O(n)

// // function reverse(nums, st, end) {
// //   while (st < end) {
// //     [nums[st], nums[end]] = [nums[end], nums[st]]; // // swap
// //     st++;
// //     end--;
// //   }
// // }
// // function RotateTheLeftArrayWithOptimal(nums, d) {
// //   let n = nums.length;

// //   d = d % n;

// //   reverse(nums, 0, d - 1);

// //   reverse(nums, d, n - 1);
// //   reverse(nums, 0, n - 1);
// //   return nums;
// // }

// // let nums = [1, 2, 3, 4, 5, 6, 7];
// // let d = 2;
// // console.log(RotateTheLeftArrayWithOptimal(nums, d));

// // function leftRotatewithInbuilt(num, d) {
// //   let n = num.length;
// //   d = d % n;
// //   return num.slice(d).concat(num.slice(0, d));
// // }
// // let num = [1, 2, 3, 4, 5, 6, 7];
// // console.log(leftRotatewithInbuilt(num, 2));

// function moveTheZero(arr) {
//   let temp = [];

//   for (let i = 0; i < arr.length; i++) {
//     if (arr[i] != 0) {
//       temp.push(arr[i]);
//     }
//   }

//   let zero = arr.length - temp.length;
//   for (let i = 0; i < zero; i++) {
//     temp.push(0);
//   }

//   return temp;
// }
// let arr = [1, 4, 5, 6, 6, 0, 0, 44, 2];

// console.log(moveTheZero(arr));

function movethezeroWithOptimal(n) {
  let j = -1;
  for (let i = 0; i < n.length; i++) {
    if (n[i] == 0) {
      j = i;
      break; // so first zero is store in the j so we can find and compare with non-zero number
    }
  }

  if (j == -1) return n;

  for (let i = j + 1; i < n.length; i++) {
    if (n[i] != 0) {
      let temp = n[i];
      n[i] = n[j];
      n[j] = temp;
      j++;
    }
  }
  return n;
}
// let n = [1, 2, 3, 0, 4, 5, 0, 0, 6];
// console.log(movethezeroWithOptimal(n));

// function linearSearch(num , target) {

//   for (
//     let i = 0 ; i < num.length ; i++
//   ){
//     if (num[i] == target) {
//        return i
//     }
//   }
//   return -1
// }

// let num = [1, 2,3,4,5,8];
// console.log(linearSearch(num, 8));

// function UnionFn(a, b) {
//   const set = new Set();
//   for (let i = 0; i < a.length; i++) {
//     set.add(a[i]);
//   }
//   for (let i = 0; i < b.length; i++) {
//     set.add(b[i]);
//   }

//   let res = Array.from(set);
//   res.sort((x, y) => x - y);
//   return res;
// }

// let a = [1, 2, 3, 4, 5];
// let b = [1, 2, 3, 6, 7];
// let res = UnionFn(a, b);

// for (let i of res) {
//   console.log(i);
// // }
// function repeating(arr) {
//   for (let i = 0; i < arr.length; i++) {
//     let alreadyMarked = false;
//     for (let k = 0; k < i; k++) {
//       if (arr[i] == arr[k]){
//  alreadyMarked = true;
//       break;
//       }

//     }

//     if (alreadyMarked) continue;
//     for (let j = i+1; j < arr.length; j++) {
//       if (arr[i] == arr[j]) {
//         console.log(arr[i]);
//         break;
//       }
//     }
//   }
// }

// let arr = [1, 2,2,2,4] ;
// repeating(arr)

// var  a = 10;

// var s = 10;
// {
// var s = 100;
// console.log(s);
// }
// console.log(s);

// // closure

function z() {
  var b = 10;

  function x() {
    var i = 40;
    function y() {
      console.log(i, b);
    }
    i = 90;
  y()
  }
  x();
}
z();
// const z = x() ;
// // console.log(z);



// var r =0;
// console.log(r)
// r = 1;

// console.log(r)
