class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        std::unordered_set<int> c;
        for (auto n : candies)
        {
            c.insert(n);
        }

        size_t size = c.size();
        return std::min(size, candies.size()/2);
    }
};