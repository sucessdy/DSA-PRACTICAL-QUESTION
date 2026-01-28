function compute(freq1, freq2) {
  for (let i = 0; i < 26; i++) {
    if (freq1[i] !== freq2[i]) {
      return false;
    }
  }
  return true;
}

function stringPermutation(s1, s2) {
    if (s1.length == 0)return false; 
    if ( s1.length > s2.length ) return false ; 
  let freq = new Array(26).fill(0);
  for (let i = 0; i < s1.length; i++) {
    freq[s1.charCodeAt(i) - "a".charCodeAt(0)]++;
  }

  let FreqSize = s1.length;

  for (let i = 0; i < s2.length; i++) {
    let idx = i;
    let windSize = 0;
    let Windfreq = new Array(26).fill(0);
    while  (windSize < FreqSize && idx < s2.length) {
      Windfreq[s2.charCodeAt(idx) - "a".charCodeAt(0)]++;
      windSize++;
      idx++;
    }

    if (compute(freq, Windfreq)) {
      return true;
    }
  }
  return false;
}

let s1 = "ab";
let s2 = "eidbaooo";
console.log(stringPermutation(s1, s2));
