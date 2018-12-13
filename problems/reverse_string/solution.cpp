class Solution {
public:
    string reverseString(string s) {
        int start = 0;
        int end = s.size() - 1;
        
        while(start < end)
        {
            auto c = s[start];
            s[start] = s[end];
            s[end] = c;
            start++;
            end--;
        }
        
        return s;         
    }
};