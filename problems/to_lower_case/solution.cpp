class Solution {
public:
    string toLowerCase(string str) {
        std::string lowercase;
        for (auto c : str) {
        	if (c >= 'A' && c <= 'Z') {
        		lowercase += (c + ' ');
        	} else {
        		lowercase += c;
        	}
        }
		return lowercase;
    }
};