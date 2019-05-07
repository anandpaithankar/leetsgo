class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> s;
        for (auto n : nums) {
            s.insert(n);
        }
        
        int maxLength = 0;
        for (auto n : s) {
            
            int currentLength = 1;
            // if the set contains a number less than n, then
            // n will be automatically included as part of the
            // sequence generated using "n-1".
            if (!s.count(n-1)) {
                int currentNum = n;
                currentLength = 1;
                
                // look for numbers greater than n
                while(s.count(currentNum+1)) {
                    currentNum++;
                    currentLength++;
                }
            }
            
            maxLength = std::max(currentLength, maxLength);
        }
        
        return maxLength;
    }
};