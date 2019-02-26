class Solution {
public:
    void sortColors(vector<int>& nums) {
        int redIndex=0;
        int blueIndex = nums.size()-1;
        int current = 0;
        while (current <= blueIndex) {
            if (nums[current] == 2) {
                std::swap(nums[current], nums[blueIndex--]);
            } else if (nums[current] == 0) {
                std::swap(nums[current], nums[redIndex++]);
                current++;
            } else {
                current++;
            }
        }
    }
};