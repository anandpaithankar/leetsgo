class Solution {
    struct Element {
      int val;
      int frequency;
      bool operator<(const Element &e1) const {
          return frequency < e1.frequency;
      }
    
        Element(int v, int f) :val(v), frequency(f) {}
    };
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::priority_queue<Element, std::vector<Element>> pq;
        std::unordered_map<int, int> values;
        
        for (auto n  : nums) {
            values[n]++;
        }
        
        for (auto p : values) {
            pq.emplace(Element{p.first, p.second});
        }
        
        std::vector<int> result;
        while(!pq.empty() && k-1 >= 0) {
            result.push_back(pq.top().val);
            pq.pop();
            k--;
        }
        
        return result;
    }
};