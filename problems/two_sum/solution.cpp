class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int, int> table;
        for (int i = 0; i < nums.size(); ++i) {
            int diff = target - nums[i];
            if (table.find(diff) != table.end()) {
                return {table[diff], i};
            }
            
            table[nums[i]] = i;
        }
        
        return {-1,-1};
    }
};