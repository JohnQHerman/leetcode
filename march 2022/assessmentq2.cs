// Given an array of strings 'words' and an integer 'k', return the 'k' most frequent strings.

// Return the answer sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.

// Example 1:
// Input: words = ["i","love","leetcode","i","love","coding"], k = 2
// Output: ["i","love"]
// Explanation: "i" and "love" are the two most frequent words. However "i" comes before "love" due to a lower alphabetical order.

// Constraints:
// 1 <= words.length <= 500
// 1 <= words[i] <= 10
// words[i] consists of lowercase English letters.
// k is in the range [1, The number of unique words[i]]

public class Solution {
    public IList<string> TopKFrequent(string[] words, int k) {
        Dictionary<string, int> dict = new Dictionary<string, int>();
        foreach (string word in words)
        {
            if (dict.ContainsKey(word))
            {
                dict[word]++;
            }
            else
            {
                dict.Add(word, 1);
            }
        }
        var sortedDict = dict.OrderByDescending(x => x.Value).ThenBy(x => x.Key);
        List<string> result = new List<string>();
        foreach (var item in sortedDict)
        {
            result.Add(item.Key);
            if (result.Count == k)
            {
                break;
            }
        }
        return result;
    }
}