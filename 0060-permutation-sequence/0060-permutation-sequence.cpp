class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int> numbers;
        
        // Calculate (n-1)! and populate the list of available numbers
        for (int i = 1; i < n; i++) {
            fact *= i;
            numbers.push_back(i);
        }
        numbers.push_back(n);
        
        string ans = "";
        k = k - 1; // Convert to 0-based indexing
        
        while (true) {
            // Find the correct index for the current position
            int index = k / fact;
            ans += to_string(numbers[index]);
            
            // Remove the used number from the available list
            numbers.erase(numbers.begin() + index);
            
            if (numbers.empty()) {
                break;
            }
            
            // Update k and reduce the factorial for the next position
            k = k % fact;
            fact = fact / numbers.size();
        }
        
        return ans;
    }
};