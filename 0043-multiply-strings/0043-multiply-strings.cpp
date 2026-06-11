class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        
        int n = num1.size();
        int m = num2.size();
        vector<int> result(n + m, 0);
        
        // Loop from right to left
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                // Calculate the product of current digits
                int mul = (num1[i] - '0') * (num2[j] - '0');
                
                // Indices in the result array where the multiplication contributes
                int p1 = i + j;
                int p2 = i + j + 1;
                
                // Add to current position
                int sum = mul + result[p2];
                
                // Update digits and carry
                result[p2] = sum % 10;
                result[p1] += sum / 10;
            }
        }
        
        // Convert the result vector into a string, skipping leading zeros
        string product = "";
        int i = 0;
        while (i < result.size() && result[i] == 0) {
            i++;
        }
        
        while (i < result.size()) {
            product += to_string(result[i]);
            i++;
        }
        
        return product;
    }
};