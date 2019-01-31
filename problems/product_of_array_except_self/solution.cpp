class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> result(nums.size());
        std::vector<int> left(nums.size()), right(nums.size());
        
        int p = 1;
        for (int i = 0; i < nums.size(); i++) {
            left[i] = p;
            p *= nums[i];
        }
        
        p = 1;
        for (int j = nums.size()-1; j >= 0; --j) {
            right[j] = p;
            p *= nums[j];
        }
        
        for (int i = 0; i < nums.size(); i++) {
            result[i] = left[i] * right[i];
        }
        
        return result;
    }
};