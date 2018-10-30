class Solution {
public:
    bool isSubsequence(string word, string str) {
        int i, j, k;
        
        if (word.empty()) 
            return true;

        j = k= 0;
        for (i = 0; i < str.size(); i++)
        {
            if (str[i] != word[j])
            {
                continue;
            }

            for (k = j + 1; k < word.size(); k++)
            {
                if (str[i + k] != word[k])
                {
                    j = k;
                    break;
                }
            }
        }

        return (k == word.size());
    }
};