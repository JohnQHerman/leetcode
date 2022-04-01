// You are given a string s and an array of strings words of the same length. Return all starting indices of substring(s) in s that is a concatenation of each word in words exactly once, in any order, and without any intervening characters.

// You can return the answer in any order.

// Example 1:
// Input: s = "barfoothefoobarman", words = ["foo","bar"]
// Output: [0,9]
// Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar" respectively.
// The output order does not matter, returning [9,0] is fine too.

// Example 2:
// Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
// Output: []

// Example 3:
// Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
// Output: [6,9,12]
 
// Constraints:
// 1 <= s.length <= 104
// s consists of lower-case English letters.
// 1 <= words.length <= 5000
// 1 <= words[i].length <= 30
// words[i] consists of lower-case English letters.

use std::collections::HashSet;
use std::collections::HashMap;
use std::collections::VecDeque;

impl Solution {
    pub fn find_substring(s: String, words: Vec<String>) -> Vec<i32> {
        let mut res = vec![];
        if words.len() == 0 {
            return res;
        }
        let word_len = words[0].len();
        let mut word_count = vec![0; words.len()];
        let mut word_map = HashMap::new();
        for i in 0..words.len() {
            let word = words[i].clone();
            *word_map.entry(word).or_insert(0) += 1;
        }
        for i in 0..s.len() {
            let mut word_map_clone = word_map.clone();
            let mut j = i;
            let mut count = 0;
            while j + word_len <= s.len() {
                let word = &s[j..j + word_len];
                if let Some(c) = word_map_clone.get(word) {
                    if *c > 0 {
                        word_map_clone.entry(word.to_string()).and_modify(|e| *e -= 1);
                        count += 1;
                        j += word_len;
                    } else {
                        break;
                    }
                } else {
                    break;
                }
            }
            if count == words.len() {
                res.push(i as i32);
            }
        }
        res
    }
}