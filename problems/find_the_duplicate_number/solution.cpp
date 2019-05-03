class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // use piegon hole principle
        std::vector<int> holes(nums.size()-1, 0);
        for (size_t i = 0; i < nums.size(); i++) {
            if (holes[nums[i]-1] == 0)
            {
                holes[nums[i]-1]++;
            }
            else if (holes[nums[i]-1] == 1)
            {
                return nums[i];
            }
        }
        return -1;
    }
};