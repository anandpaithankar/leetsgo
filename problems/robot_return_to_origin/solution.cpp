class Solution {
public:
    std::unordered_map<char, int> weights = 
    {{'L', 1}, {'R', -1}, {'U', 2}, {'D', -2}};
    
    bool judgeCircle(string moves) {
        int fromOrigin = 0;
        for (auto c: moves) {
            if (weights.find(c) == weights.end()) {
                return false;
            }
            
            fromOrigin += weights[c];
        }
        return (fromOrigin == 0);
    }
};