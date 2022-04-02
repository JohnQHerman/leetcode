// Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

// The testcases will be generated such that the answer is unique.

// A substring is a contiguous sequence of characters within the string.

// Example 1:
// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
// Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

// Example 2:
// Input: s = "a", t = "a"
// Output: "a"
// Explanation: The entire string s is the minimum window.

// Example 3:
// Input: s = "a", t = "aa"
// Output: ""
// Explanation: Both 'a's from t must be included in the window.
// Since the largest window of s only has one 'a', return empty string.
 
// Constraints:
// m == s.length
// n == t.length
// 1 <= m, n <= 10^5
// s and t consist of uppercase and lowercase English letters.

public class Solution {
    public string MinWindow(string s, string t) {
        int[] tCount = new int[128];
        int[] sCount = new int[128];
        int minLen = int.MaxValue;
        int minStart = 0;
        int minEnd = 0;
        int start = 0;
        int end = 0;
        int count = 0;
        for (int i = 0; i < t.Length; i++) {
            tCount[t[i]]++;
        }
        while (end < s.Length) {
            if (tCount[s[end]] > 0) {
                sCount[s[end]]++;
                if (sCount[s[end]] <= tCount[s[end]]) {
                    count++;
                }
            }
            end++;
            while (count == t.Length) {
                if (end - start < minLen) {
                    minLen = end - start;
                    minStart = start;
                    minEnd = end;
                }
                if (tCount[s[start]] > 0) {
                    sCount[s[start]]--;
                    if (sCount[s[start]] < tCount[s[start]]) {
                        count--;
                    }
                }
                start++;
            }
        }
        if (minLen == int.MaxValue) {
            return "";
        }
        return s.Substring(minStart, minLen);
    }
}