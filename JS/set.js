function cntDistint(arr) {
  let s = new Set(); 
  for (let i = 0; i < arr.length; i++) {
    s.add(arr[i]);
  } 
  return s.size;
}
let str = "wjmzbmr";
console.log(cntDistint(str));


