#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        // Map to store the values of Roman numerals
        unordered_map<char, int> romanMap = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };
        
        int total = 0;
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            // If the current numeral is smaller than the next one, subtract it
            if (i < n - 1 && romanMap[s[i]] < romanMap[s[i+1]]) {
                total -= romanMap[s[i]];
            } 
            // Otherwise, add it to the total
            else {
                total += romanMap[s[i]];
            }
        }
        
        return total;
    }
};