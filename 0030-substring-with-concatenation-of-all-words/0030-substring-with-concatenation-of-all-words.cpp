#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;

        int word_len = words[0].length();
        int num_words = words.size();
        int total_len = word_len * num_words;
        int s_len = s.length();

        if (s_len < total_len) return result;

        // Count frequencies of each word in the input list
        unordered_map<string, int> word_counts;
        for (const string& word : words) {
            word_counts[word]++;
        }

        // Run the sliding window for each possible shift offset
        for (int i = 0; i < word_len; ++i) {
            int left = i;
            int right = i;
            unordered_map<string, int> current_counts;
            int count = 0; // Tracks how many valid words are currently in the window

            // Slide the window across the string
            while (right + word_len <= s_len) {
                // Pull out the word at the right end of our window
                string word = s.substr(right, word_len);
                right += word_len;

                // Case 1: The word is part of our target list
                if (word_counts.find(word) != word_counts.end()) {
                    current_counts[word]++;
                    count++;

                    // If we have more occurrences of 'word' than needed, 
                    // shrink the window from the left until it's valid again.
                    while (current_counts[word] > word_counts[word]) {
                        string left_word = s.substr(left, word_len);
                        current_counts[left_word]--;
                        count--;
                        left += word_len;
                    }

                    // If the number of matched words equals total target words, we found a match!
                    if (count == num_words) {
                        result.push_back(left);
                    }
                } 
                // Case 2: The word is completely invalid. Reset the window.
                else {
                    current_counts.clear();
                    count = 0;
                    left = right; // Move left pointer past the invalid word
                }
            }
        }

        return result;
    }
};