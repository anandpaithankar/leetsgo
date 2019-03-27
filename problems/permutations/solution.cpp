class Solution {
public:
    void permute(std::vector<int> &nums, int currentIndex, std::vector<std::vector<int>> &result) {
        if (currentIndex == nums.size()) {
            result.push_back(nums);
            return;
        }
        
        for (int i = currentIndex; i < nums.size(); i++) {
            std::swap(nums[i], nums[currentIndex]);
            permute(nums, currentIndex+1, result);
            std::swap(nums[i], nums[currentIndex]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        std::vector<std::vector<int>> result;
        int currentIndex = 0;
        permute(nums, currentIndex, result);
        return result;
    }
};