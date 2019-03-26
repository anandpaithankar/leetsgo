class Solution {
public:
    void subsets(const std::vector<int> &nums, int currentIndex, std::vector<int> &subsetSoFar,
                 std::vector<std::vector<int>> &result) {
        if (currentIndex == nums.size()) {
            result.push_back(subsetSoFar);
            return;
        }        
        
        // include nums[currentIndex] in the subset
        subsetSoFar.push_back(nums[currentIndex]);
        subsets(nums, currentIndex+1, subsetSoFar, result);
        
        // exclude nums[currentIndex] from the subset
        subsetSoFar.pop_back();
        subsets(nums, currentIndex+1, subsetSoFar, result);        
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> subsetSoFar;
        int currentIndex = 0;
        
        subsets(nums, currentIndex, subsetSoFar, result);
        return result;        
    }
};