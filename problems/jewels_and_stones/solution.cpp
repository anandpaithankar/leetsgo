class Solution {
public:
    int numJewelsInStones(string J, string S) {
        
        std::unordered_set<char> jewels(J.size());
        
        for (const auto &c: J) {
            jewels.insert(c);
        }
        
        int jewelsCount = 0;
        for (const auto &c : S) {
            jewelsCount += jewels.count(c);
        }
        
        return jewelsCount;
    }
    
    // Note: The runtime of the solution drops if we use
    // a bit array[0-255] to store ascii. This will avoid
    // hashing for insertion and lookup required in unordered_set().
};