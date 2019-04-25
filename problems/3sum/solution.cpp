class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        if (nums.size() < 3) {
            return {};
        }
        
        std::sort(nums.begin(), nums.end());
        int start = 0 , end = nums.size()-1;
        set<vector<int>> result;
        
        for (int i = 0; i < nums.size()-2; i++) {
            start = i+1;
            end = nums.size()-1;
            while (start < end){
                if (nums[start]+nums[i]+nums[end] == 0) {
                    result.insert(std::vector<int>{nums[start], nums[i], nums[end]});
                    start++, end--;
                } else if (nums[start]+nums[i]+nums[end] < 0) {
                    start++;
                } else {
                    end--;
                }
            }   
        }
        
        std::vector<vector<int>> r;
        for (auto x : result) {
            r.push_back(x);
        } 
        return r;
    }
};