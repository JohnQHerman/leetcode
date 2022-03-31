// Given a string s, return the longest palindromic substring in s.

// Constraints:
// 1 <= s.length <= 1000
// s consists of only digits and English letters.

class Solution {
    public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n == 0)
            return "";
        if (n == 1)
            return s;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int start = 0, end = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (s[i] == s[j]) {
                    if (i - j < 2)
                        dp[j][i] = true;
                    else
                        dp[j][i] = dp[j + 1][i - 1];
                }
                if (dp[j][i] && i - j + 1 > end - start) {
                    start = j;
                    end = i;
                }
            }
        }
        return s.substr(start, end - start + 1);
    }
};