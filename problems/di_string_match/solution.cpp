class Solution {
public:
    vector<int> diStringMatch(string S) {
        std::vector<int> perm;
        int low = 0, high = S.length();

        for (int i = 0; i <= S.length() ; i++)
        {
            if (S[i] == 'I')
            {
                perm.push_back(low++);
            }
            else
            {
                perm.push_back(high--);
            }
        }

        return perm;
    }
};