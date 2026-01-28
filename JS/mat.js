
// 2D Array in JS
let matrix = [
  [1, 2, 3],
  [4, 5, 6],
  [7, 8, 9],
  [10, 11, 12]
];

let row = 4;
let col = 3;

// Printing the matrix
for (let i = 0; i < row; i++) {
  for (let j = 0; j < col; j++) {
    process.stdout.write(matrix[i][j] + " "); // like cout (no newline)
  }
  console.log(); // new line after each row
}
