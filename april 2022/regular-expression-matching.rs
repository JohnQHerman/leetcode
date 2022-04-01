// Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

// '.' Matches any single character.​​​​
// '*' Matches zero or more of the preceding element.
// The matching should cover the entire input string (not partial).

 
// Example 1:
// Input: s = "aa", p = "a"
// Output: false
// Explanation: "a" does not match the entire string "aa".

// Example 2:
// Input: s = "aa", p = "a*"
// Output: true
// Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".

// Example 3:
// Input: s = "ab", p = ".*"
// Output: true
// Explanation: ".*" means "zero or more (*) of any character (.)".
 

// Constraints:
// 1 <= s.length <= 20
// 1 <= p.length <= 30
// s contains only lowercase English letters.
// p contains only lowercase English letters, '.', and '*'.
// It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.

impl Solution {
    pub fn is_match(s: String, p: String) -> bool {
        let s = s.as_bytes();
        let p = p.as_bytes();
        let mut dp = vec![vec![false; p.len() + 1]; s.len() + 1];
        dp[0][0] = true;
        for i in 1..=p.len() {
            if p[i - 1] == b'*' {
                dp[0][i] = dp[0][i - 2];
            }
        }
        for i in 1..=s.len() {
            for j in 1..=p.len() {
                if p[j - 1] == b'.' || p[j - 1] == s[i - 1] {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if p[j - 1] == b'*' {
                    dp[i][j] = dp[i][j - 2];
                    if p[j - 2] == b'.' || p[j - 2] == s[i - 1] {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                }
            }
        }
        dp[s.len()][p.len()]
    }
}