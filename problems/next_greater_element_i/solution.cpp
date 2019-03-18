class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        std::vector<int> result;
        for (size_t i = 0; i < findNums.size(); i++) {
            bool isFound = false;
            int n = findNums[i];
            for (size_t j = 0; j < nums.size(); j++) {
                if (n == nums[j]) {
                    // number found
                    isFound = true;
                }
                
                if (isFound && nums[j] > n) {
                    result.push_back(nums[j]);
                    isFound = false;
                    break;
                }
            }
            
            if (isFound) {
                result.push_back(-1);
            }
        }
        return result;
    }
};