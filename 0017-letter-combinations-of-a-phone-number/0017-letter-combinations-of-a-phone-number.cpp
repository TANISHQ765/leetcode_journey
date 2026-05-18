#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    // Mapping of digits to letters corresponding to the keypad
    const vector<string> keypad = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz"  // 9
    };

    void backtrack(string &digits, int index, string &current, vector<string> &result) {
        // Base case: if the current combination is complete
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }

        // Get the letters corresponding to the current digit
        string letters = keypad[digits[index] - '0'];
        
        for (char letter : letters) {
            current.push_back(letter);             // Choose
            backtrack(digits, index + 1, current, result); // Explore
            current.pop_back();                    // Unchoose (Backtrack)
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) {
            return result;
        }
        
        string current = "";
        backtrack(digits, 0, current, result);
        return result;
    }
};