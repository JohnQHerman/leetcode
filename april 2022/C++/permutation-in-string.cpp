// Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

// In other words, return true if one of s1's permutations is the substring of s2.

// Example 1:
// Input: s1 = "ab", s2 = "eidbaooo"
// Output: true
// Explanation: s2 contains one permutation of s1 ("ba").

// Example 2:
// Input: s1 = "ab", s2 = "eidboaoo"
// Output: false
 
// Constraints:
// 1 <= s1.length, s2.length <= 10^4
// s1 and s2 consist of lowercase English letters.

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if (n > m) return false;
        vector<int> cnt(26, 0);
        for (int i = 0; i < n; ++i) {
            cnt[s1[i] - 'a']++;
            cnt[s2[i] - 'a']--;
        }
        if (allZero(cnt)) return true;
        for (int i = n; i < m; ++i) {
            cnt[s2[i] - 'a']--;
            cnt[s2[i - n] - 'a']++;
            if (allZero(cnt)) return true;
        }
        return false;
    }
private:
    bool allZero(vector<int>& cnt) {
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] != 0) return false;
        }
        return true;
    }
};
