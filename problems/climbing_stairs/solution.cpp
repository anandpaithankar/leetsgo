class Solution {
public: 
    std::unordered_map<int, int> m;
    int climbStairs(int n) {
        if (m.count(n)) {
            return m[n];
        }
        
        if (n <= 2) {
            m[n] = n;
            return n;
        }
        
        m[n] = climbStairs(n-1) + climbStairs(n-2);
        return m[n];
    }
};