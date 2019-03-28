class Solution {
public:
    bool isPalindrome(const std::string &word) {
        int start = 0, end = word.size()-1;
        while (start < end) {
            if (word[start++] != word[end--]) {
                return false;
            }
        }
        return true;
    }
    
    void partition(string s, int index, vector<string> &partial, vector<vector<string>> &result) {
        if (index == s.length()) {
            result.push_back(partial);
            return;
        }
        
        for (int i = index+1 ; i <= s.size(); i++) {
            string ss = s.substr(index, i-index);
            if (isPalindrome(ss)) {
                partial.push_back(ss);
                partition(s, i, partial, result);
                partial.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> partial;
        partition(s, 0, partial, result);
        return result;   
    }
};