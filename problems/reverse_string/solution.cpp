class Solution {
public:
    void reverseStringHelper(std::vector<char>& s, int start, int end) {
        if (start >= end) {
            return;
        }
        std::swap(s[start], s[end]);
        reverseStringHelper(s, start+1, end-1);
    }
    
    void reverseString(vector<char>& s) {
        int start = 0, end = s.size()-1;
        reverseStringHelper(s, start, end);
    }
};