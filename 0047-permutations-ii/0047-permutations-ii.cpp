class Solution {
public:
    void backtrack(vector<int>& nums, vector<int>& current, vector<bool>& visited, vector<vector<int>>& result) {
        // Base case: if the current permutation is complete
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            // If the element is already used in this path, skip it
            if (visited[i]) continue;

            // De-duplication rule:
            // Skip duplicates if the previous identical element hasn't been visited yet 
            // in this specific branch of the recursion tree.
            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) {
                continue;
            }

            // Take the element
            visited[i] = true;
            current.push_back(nums[i]);

            // Recurse
            backtrack(nums, current, visited, result);

            // Backtrack (Undo choice)
            current.pop_back();
            visited[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> visited(nums.size(), false);

        // Crucial step: Sort the array so duplicates are adjacent
        sort(nums.begin(), nums.end());

        backtrack(nums, current, visited, result);
        return result;
    }
};