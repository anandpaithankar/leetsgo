class Solution {
public:
    bool isValid(string s) {
        std::stack<char> st;
        for (auto c : s)
        {
            if (c == '[')
            {
                st.push(']');
                continue;
            }
            else if (c == '{')
            {
                st.push('}');
                continue;
            }
            else if (c == '(')
            {
                st.push(')');
                continue;
            }

            if (!st.empty() && st.top() == c)
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }

        return st.empty();
    }
};