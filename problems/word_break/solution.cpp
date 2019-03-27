class Solution {
public:
    
    bool isWord(const std::string &word, const vector<string> &wordDict) {
        if (word.empty()) {
            return false;
        }
        for (auto &w : wordDict) {
            if (word == w) {
                return true;
            }
        }
        return false;
    }
    
    bool wordBreak(string s, string &answer, const vector<string> &wordDict, 
                   std::unordered_set<std::string> &memo) {
        if (s.empty()) {
            return true;
        }
        
        if (memo.find(s) != memo.end()) {
            return false;
        }
        
        int index = 0;
        std::string word;
        
        while (index < s.length()) {
            word.push_back(s[index]);
            if (isWord(word, wordDict)) {
                answer += word + " ";
                if (wordBreak(s.substr(index+1), answer, wordDict, memo)) {
                    return true;
                }
            }
            index++;
        }
        memo.insert(s);
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        std::string answer;
        std::unordered_set<std::string> memo;
        return wordBreak(s, answer, wordDict, memo);
    }
};