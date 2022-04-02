// Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

// Example 1:
// Input: s = "cbaebabacd", p = "abc"
// Output: [0,6]

// Explanation:
// The substring with start index = 0 is "cba", which is an anagram of "abc".
// The substring with start index = 6 is "bac", which is an anagram of "abc".

// Example 2:
// Input: s = "abab", p = "ab"
// Output: [0,1,2]

// Explanation:
// The substring with start index = 0 is "ab", which is an anagram of "ab".
// The substring with start index = 1 is "ba", which is an anagram of "ab".
// The substring with start index = 2 is "ab", which is an anagram of "ab".
 
// Constraints:

// 1 <= s.length, p.length <= 3 * 10^4
// s and p consist of lowercase English letters.

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int n = s.size();
        int m = p.size();
        if (n < m) return res;
        vector<int> cnt(26, 0);
        for (int i = 0; i < m; ++i) {
            cnt[p[i] - 'a']++;
            cnt[s[i] - 'a']--;
        }
        if (allZero(cnt)) res.push_back(0);
        for (int i = m; i < n; ++i) {
            cnt[s[i] - 'a']--;
            cnt[s[i - m] - 'a']++;
            if (allZero(cnt)) res.push_back(i - m + 1);
        }
        return res;
    }
private:
    bool allZero(vector<int>& cnt) {
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] != 0) return false;
        }
        return true;
    }
};