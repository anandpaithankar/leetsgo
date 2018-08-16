class Solution {
public:
    string reverseString(string s) {
        std::string reversed;
        for(int i = s.size() - 1; i >=0; --i) {
            reversed += s[i];
        }
        return reversed;
    }
};