class Solution {
public:
    
    bool isVowel(const char c) {
    return ((c == 'a' || c == 'A') ||
    (c == 'e' || c == 'E') ||
    (c == 'i' || c == 'I') ||
    (c == 'o' || c == 'O') ||
    (c == 'u' || c == 'U'));
}
    string reverseVowels(string s) {
        int start = 0;
        int end = s.size() - 1;
        std::string str = s;
        while (start < end) {
            while (start < end && !isVowel(str[start])) start++;
            while (start < end && !isVowel(str[end])) end --;
            char c = str[start];
            str[start] = str[end];
            str[end] = c;
            start++;
            end--;
        }
        return str;
        
    }
};