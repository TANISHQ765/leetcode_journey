class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Map to store grouped anagrams: {sorted_string -> vector of original strings}
        unordered_map<string, vector<string>> anagramMap;
        
        // Iterate through each string in the input array
        for (const string& str : strs) {
            string sortedStr = str;
            // Sorting the string to use it as a common key
            sort(sortedStr.begin(), sortedStr.end());
            
            // Push the original string into its corresponding anagram group
            anagramMap[sortedStr].push_back(str);
        }
        
        // Collect all grouped vectors from the map into the result vector
        vector<vector<string>> result;
        for (auto& pair : anagramMap) {
            result.push_back(move(pair.second)); // move avoids unnecessary copying
        }
        
        return result;
    }
};