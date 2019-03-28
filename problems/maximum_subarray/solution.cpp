class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSoFar = INT_MIN;
        int maxHere = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            maxHere = std::max(nums[i], maxHere+nums[i]);
            maxSoFar = std::max(maxSoFar, maxHere);
        }
        return maxSoFar;
    }
};
