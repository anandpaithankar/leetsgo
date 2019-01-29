class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if (s.length() != t.length()) {
            return false;
        }
        
        std::array<int, 26> frequency{0};
        
		
		for (auto n : s) {
			frequency[n-'a']++;
		}
		
		for (auto n : t) {
			frequency[n-'a']--;
		}
		
		for (auto f : frequency) {
			if (f > 0) {
				return false;
			}
		}
        
        return true;
    }
};