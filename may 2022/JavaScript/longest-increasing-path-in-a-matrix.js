// Given an m x n integers matrix, return the length of the longest increasing path in matrix.

// From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).

// Example 1:
// Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
// Output: 4
// Explanation: The longest increasing path is [1, 2, 6, 9].

// Example 2:
// Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
// Output: 4
// Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

// Example 3:
// Input: matrix = [[1]]
// Output: 1
 
// Constraints:
// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 200
// 0 <= matrix[i][j] <= 2^31 - 1

/**
 * @param {number[][]} matrix
 * @return {number}
 */

// let's use a depth-first search to find the longest increasing path in the matrix

// set up a dfs function and return the max
dfs = function(i, j, matrix, dp){
    if(dp[i][j] !== 0) return dp[i][j];
    let max = 1;
    if(i > 0 && matrix[i][j] > matrix[i-1][j]) max = Math.max(max, 1 + dfs(i-1, j, matrix, dp));
    if(i < matrix.length-1 && matrix[i][j] > matrix[i+1][j]) max = Math.max(max, 1 + dfs(i+1, j, matrix, dp));
    if(j > 0 && matrix[i][j] > matrix[i][j-1]) max = Math.max(max, 1 + dfs(i, j-1, matrix, dp));
    if(j < matrix[0].length-1 && matrix[i][j] > matrix[i][j+1]) max = Math.max(max, 1 + dfs(i, j+1, matrix, dp));
    dp[i][j] = max;
    return max;
}

// find the max of all the dfs calls and return it
 var longestIncreasingPath = function(matrix) {
     // set up a dp array
    if(matrix.length === 0) return 0;
    let dp = [];
    //
    for(let i = 0; i < matrix.length; i++){
        dp[i] = [];
        for(let j = 0; j < matrix[0].length; j++){
            dp[i][j] = 0;
        }
    }
    let max = 0;
    for(let i = 0; i < matrix.length; i++){
        for(let j = 0; j < matrix[0].length; j++){
            max = Math.max(max, dfs(i, j, matrix, dp));
        }
    }
    return max;
};