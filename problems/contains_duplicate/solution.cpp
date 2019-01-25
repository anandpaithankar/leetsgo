class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_set<int> values;
		for (int i = 0; i < nums.size(); i++) {
			if (values.count(nums[i])) {
				return true;
			} else {
				values.insert(nums[i]);
			}
		}
		return false;
    }
};