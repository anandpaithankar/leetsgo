class Solution {
public:
    int lengthOfLongestSubstring(string arr) {
        if (arr.empty()) {
            return 0;
        }
        std::unordered_set<char> set;
	    int i = 0, j = 1, max = 0, currentLength = 1;
	    set.insert(arr[0]);
	
        while (i < arr.size() && j < arr.size()) {
            if (!set.count(arr[j])) {
                set.insert(arr[j++]);
                currentLength++;
            } else {
                max = std::max(max, currentLength);
                currentLength--;
                set.erase(set.find(arr[i]));
                i++; 
            }
        }

        return std::max(max, currentLength);
    }
};