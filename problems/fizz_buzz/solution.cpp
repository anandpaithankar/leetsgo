class Solution {
public:
    vector<string> fizzBuzz(int n) {
        std::vector<string> output;
        for (int i = 1 ; i <= n ; ++i) {
            bool isMultiple = false;
            std::string str;
            if (i % 3 == 0) {
                str = "Fizz";
                isMultiple = true;
            }
            
            if (i%5 == 0) {
                str += "Buzz";
                isMultiple = true;
            }
            
            if (!str.empty()) {
                output.push_back(str);
            }
            
            if (!isMultiple) {
                output.push_back(std::to_string(i));
            }
            
        }
        return output;
        
    }
};