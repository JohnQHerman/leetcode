# Given a string s, return true if s can be a palindrome after deleting at most 1 character from it.

# Example 1:
# Input: s = "aba"
# Output: true

# Example 2:
# Input: s = "abca"
# Output: true
# Explanation: You could delete the character 'c'.

# Example 3:
# Input: s = "abc"
# Output: false

# Constraints:
# 1 <= s.length <= 10^5
# s consists of lowercase English letters.

class Solution:
    def validPalindrome(self, s: str) -> bool:
        def isPalindrome(s):
            return s == s[::-1]

        def isPalindrome2(s):
            i, j = 0, len(s) - 1
            while i < j:
                if s[i] != s[j]:
                    return isPalindrome(s[i:j]) or isPalindrome(s[i+1:j+1])
                i += 1
                j -= 1
            return True

        return isPalindrome2(s)