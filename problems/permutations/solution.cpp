class Solution {
public:
    void permuteHelper(std::vector<int> &nums, int i , 
                       std::vector<std::vector<int>> &result) {
        if (i == nums.size()-1) {
            result.emplace_back(nums);
            return;
        }
        
        for (int j = i; j < nums.size(); j++) {
            std::swap(nums[i], nums[j]);
            permuteHelper(nums,i+1,result);
            std::swap(nums[i], nums[j]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        std::vector<std::vector<int>> result;
        permuteHelper(nums, 0, result);
        return result; 
    }
};
