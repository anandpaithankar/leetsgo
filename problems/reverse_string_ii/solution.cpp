class Solution {
public:
    void reverseStr(std::string &s, size_t start, size_t end) {
		int i = start, j = end;
		while (i < j) {
			std::swap(s[i], s[j]);
			i++, j--;
		}
	}
    
    string reverseStr(string s, int k) {
        for (size_t start = 0; start < s.length(); start += (2*k)) {
			size_t i = start, j = std::min(start+k-1, s.length()-1);
			reverseStr(s, i, j);
		}
        return s;
    }
};