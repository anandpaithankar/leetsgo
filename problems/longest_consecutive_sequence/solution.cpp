class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> numSet;
        for (int n : nums) {
            numSet.insert(n);
        }
        
        int longestStreak = 0;
        for (int n : numSet) {
            if (numSet.count(n-1) == 0) {
                int currentNum = n;
                int currentStreak = 1;
                
                while(numSet.count(currentNum+1)) {
                    currentNum++;
                    currentStreak++;
                }
                
                longestStreak = std::max(longestStreak, currentStreak);
            }
        }
        return longestStreak;
    }
};