class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Sort the array of strings alphabetically
        sort(strs.begin(), strs.end());
        
        // Get the first and last strings from the sorted array
        string first = strs[0];
        string last = strs[strs.size() - 1];
        
        int i = 0;
        
        // Compare characters of the first and last strings
        while (i < first.size() && i < last.size() && first[i] == last[i]) {
            i++;
        }
        
        // Return the matched prefix
        return first.substr(0, i);
    }
};
