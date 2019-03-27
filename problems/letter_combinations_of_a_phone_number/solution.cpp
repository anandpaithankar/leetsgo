class Solution {
public:
    // 2 to 9. Offset it with -2.
    std::array<std::string, 8> combinations{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    
    void letterCombinations(string digits, std::string current, int index, std::vector<string> &result) {
        if (digits.empty()) {
            return;
        }
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }
        
        int digit = digits[index]-'0';
        for (auto c : combinations[digit-2]) {
            current.push_back(c);
            letterCombinations(digits, current, index+1, result);
            current.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        std::vector<string> result;
        letterCombinations(digits, "", 0, result);
        return result;
    }
};