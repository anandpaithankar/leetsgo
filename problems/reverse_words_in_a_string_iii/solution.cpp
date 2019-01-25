class Solution {
public:
    void reverseStr(std::string &s, int start, int end) {
		while (start < end) {
			std::swap(s[start], s[end]);
			start++, end--;
		}
	}
    
    string reverseWords(string s) {
        int j = 0;
        for (int i = 0; i < s.length(); i++) {
        	if (s[i] == ' ') {
        		reverseStr(s, j, i-1);
				j = i + 1;
        	}
        }
		
		reverseStr(s, j, s.length()-1);
		return s;
    }
};