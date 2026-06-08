class Solution {
public:
    void findCombinations(int ind, int target, vector<int>& candidates, vector<vector<int>>& ans, vector<int>& ds) {
        // Base Case: If we reached the end of the array
        if (ind == candidates.size()) {
            if (target == 0) {
                ans.push_back(ds);
            }
            return;
        }

        // 1. Pick the element (only if it's less than or equal to the remaining target)
        if (candidates[ind] <= target) {
            ds.push_back(candidates[ind]);
            // Notice we don't increment 'ind' because we can reuse the same element
            findCombinations(ind, target - candidates[ind], candidates, ans, ds);
            // Backtrack: remove the element before trying the next path
            ds.pop_back();
        }

        // 2. Skip the element (move to the next index)
        findCombinations(ind + 1, target, candidates, ans, ds);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds; // Stores the current path/combination
        findCombinations(0, target, candidates, ans, ds);
        return ans;
    }
};