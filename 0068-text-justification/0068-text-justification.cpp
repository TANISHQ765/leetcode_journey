#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> fullJustify(std::vector<std::string>& words, int maxWidth) {
        std::vector<std::string> result;
        int i = 0;
        int n = words.size();
        
        while (i < n) {
            int j = i + 1;
            int lineLength = words[i].length();
            
            // Find how many words can fit into the current line
            while (j < n && lineLength + 1 + words[j].length() <= maxWidth) {
                lineLength += 1 + words[j].length();
                j++;
            }
            
            std::string line = "";
            int numberOfWords = j - i;
            
            // Case 1: Last line or a line with only 1 word -> Left Justified
            if (j == n || numberOfWords == 1) {
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) {
                        line += " ";
                    }
                }
                // Pad the remaining spaces at the end
                while (line.length() < maxWidth) {
                    line += " ";
                }
            } 
            // Case 2: Standard middle line -> Fully Justified
            else {
                int totalWordsLength = 0;
                for (int k = i; k < j; k++) {
                    totalWordsLength += words[k].length();
                }
                
                int totalSpaces = maxWidth - totalWordsLength;
                int gaps = numberOfWords - 1;
                
                int baseSpaces = totalSpaces / gaps;
                int extraSpaces = totalSpaces % gaps;
                
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) {
                        // Apply base spaces + 1 extra space to the leftmost gaps if any remain
                        int spacesToApply = baseSpaces + (k - i < extraSpaces ? 1 : 0);
                        line.append(spacesToApply, ' ');
                    }
                }
            }
            
            result.push_back(line);
            i = j; // Move to the next line's starting word
        }
        
        return result;
    }
};