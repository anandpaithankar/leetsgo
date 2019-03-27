class Solution {
public:
    void generateParenthesis(int n, std::string answer, int left, int right, std::vector<std::string> &result) {
        if (n == 0) {
            return;
        }
        
        if (left == n && right == n) {
            result.push_back(answer);
            return;
        }
        
        if (left < n) {
            generateParenthesis(n, answer +"(", left+1, right, result);
        }
        
        if (right < left) {
            generateParenthesis(n, answer+")", left, right+1, result);
        }        
    }
    
    vector<string> generateParenthesis(int n) {
        std::vector<std::string> result;
        generateParenthesis(n, "", 0, 0, result);
        return result;        
    }
};