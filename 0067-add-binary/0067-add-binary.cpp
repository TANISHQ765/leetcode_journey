class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;

        // Loop as long as there are digits to add or a carry remaining
        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;

            if (i >= 0) {
                sum += a[i] - '0'; // Convert char to int
                i--;
            }
            if (j >= 0) {
                sum += b[j] - '0'; // Convert char to int
                j--;
            }

            // The bit to append is sum % 2 (either '0' or '1')
            result += (sum % 2) + '0';

            // Calculate the new carry
            carry = sum / 2;
        }

        // Since we added digits from right to left, reverse the result
        reverse(result.begin(), result.end());
        
        return result;
    }
};