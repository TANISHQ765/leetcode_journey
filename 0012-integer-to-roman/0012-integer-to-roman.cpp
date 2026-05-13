#include <string>
#include <vector>

class Solution {
public:
    string intToRoman(int num) {
        // Define mappings for values and symbols in descending order
        std::vector<std::pair<int, std::string>> mapping = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };
        
        std::string result = "";
        
        for (auto const& [value, symbol] : mapping) {
            // While the number is greater than or equal to the current Roman value
            while (num >= value) {
                result += symbol;
                num -= value;
            }
        }
        
        return result;
    }
};