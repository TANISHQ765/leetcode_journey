class Solution {
public:
    string countAndSay(int n) {
        // Base case
        if (n == 1) return "1";
        
        string current = "1";
        
        // Build the sequence iteratively up to n
        for (int i = 2; i <= n; ++i) {
            string next_string = "";
            int len = current.length();
            
            // Look through the current string to encode it
            for (int j = 0; j < len; ) {
                int count = 0;
                char digit = current[j];
                
                // Count consecutive identical characters
                while (j < len && current[j] == digit) {
                    count++;
                    j++;
                }
                
                // Append the count and the digit to the next sequence
                next_string += to_string(count) + digit;
            }
            
            // Move to the newly generated string for the next iteration
            current = next_string;
        }
        
        return current;
    }
};