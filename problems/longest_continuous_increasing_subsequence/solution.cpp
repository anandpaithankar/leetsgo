class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int maxLength = 0;
		int currentLength = 1;
		int j = 1;
		
		if (nums.empty()) {
			return 0;
		}
		
		for (int i = 0; i < nums.size() - 1; i++) {
			if (nums[i] < nums[i+1]) {
				currentLength++;
			} else {
				maxLength = std::max(maxLength, currentLength);
				currentLength = 1;
			}
		}
		return std::max(maxLength, currentLength);
    }
};