class Solution {
public:
    string addStrings(string num1, string num2) {
        std::string result;
        int sum = 0, carry = 0;
        int i = num1.length() - 1, j = num2.length() - 1;

        while (i >= 0 && j >= 0)
        {
            sum = num1[i] - '0' + num2[j] - '0' + carry;
            carry = sum > 9 ? 1 : 0;
            result.push_back(sum % 10 + '0');
            i--, j--;
        }

        while (i >= 0)
        {
            sum = (num1[i] - '0' + carry);
            carry = sum > 9 ? 1 : 0;
            result.push_back(sum % 10 + '0');
            i--;
        }

        while (j >= 0)
        {
            sum = (num2[j] - '0' + carry);
            carry = sum > 9 ? 1 : 0;
            result.push_back(sum % 10 + '0');
            j--;
        }

        if (carry)
        {
            result.push_back(carry + '0');
        }

        std::reverse(result.begin(), result.end());
        return result;
    }
};