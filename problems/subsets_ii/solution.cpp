class Solution {
public:
    void subsets(const std::vector<int> &nums, int currentIndex, std::vector<int> &subsetSoFar,
                     std::set<std::vector<int>> &result) {
            if (currentIndex == nums.size()) {
                std::sort(subsetSoFar.begin(), subsetSoFar.end());
                result.insert(subsetSoFar);
                return;
            }        
        
            // include nums[currentIndex] in the subset
            subsetSoFar.push_back(nums[currentIndex]);
            subsets(nums, currentIndex+1, subsetSoFar, result);
        
            // exclude nums[currentIndex] from the subset
            subsetSoFar.pop_back();
            subsets(nums, currentIndex+1, subsetSoFar, result);        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::set<std::vector<int>> result;
        std::vector<int> subsetSoFar;
        int currentIndex = 0;
        
        std::sort(nums.begin(), nums.end());        
        subsets(nums, currentIndex, subsetSoFar, result);
        
        std::vector<std::vector<int>> res;
        for (auto &r : result) {
            res.push_back(r);
        }
        return res;
    }
};