// // create  a map
// const map = new Map() ;
// map.set("apple" , 10) ;
// map.set("banan", 4) ;
// map.set(43, "answer") ;
// map.has("banana");
// console.log(map.get("apple"))
//  // true
//  for (let [key, value] of map){
//     console.log(key, value) ;
//  }
//  console.log(map.has("apple"))
// // map.delete("apple");
//  console.log(map.has("apple"))

//  count a frequney

// function countFreq(arr) {
//   const map = new Map();
//   for (let x of arr) {
//     map.set(x, (map.get(x) ?? 0) + 1);
//   }
//   return map;
// }

// console.log(countFreq([2, 7, 1, 3, 4, 1, 2, 4, 4, 5]));

// function twoSum(num, target) {
//   const map = new Map();
//   for (let i = 0; i < num.length; i++) {
//     const diff = num[i] - target;
//     if (map.has(diff)) {
//       return [map.get(diff), i];
//     }
//     map.set(num[i], i);
//   }
// }
// console.log(twoSum([1, 2, 3, 4, 5, 6, 7, 4], 11));

function BoyandGirl(arr) {
  const map = new Map();
  for (let x of arr) {
    map.set(x, (map.get(x) || 0) + 1);
  }

  for (const x of map) {
    let count = map[x];
    const parity =count % 2 === 0 ? "CHAR WITH HER!" : "IGNORE IT!!";
    console.log(`Character: '${x}', Count "${count}" Parity: ${parity}`);
    return parity;
  }

  // return map;
}
console.log(BoyandGirl("sevenkplus"));

//  this is odd and even index contatenation
// function OddandEven(str) {
//   let evenChar = "";
//   let oddChar = "";
//   for (let i = 0; i < str.length; i++) {
//     if (i % 2 == 0) {
//       evenChar += str[i];
//     } else {
//       oddChar += str[i];
//     }
//   }
//   console.log( "original value of string " , str)
//   console.log( "Even value of string " , evenChar)
//   console.log( "Odd value of string " , oddChar)
// }

// OddandEven("wjmzbmr")
