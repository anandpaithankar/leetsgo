class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        int size = digits.size();
        
        int sum = digits[size-1] + 1;
        carry = sum > 9 ? 1 : 0;
        digits[size-1] = sum % 10;
        
        for (int i = size - 2; i >= 0; i--) {
            sum = digits[i] + carry;
            carry = sum > 9 ? 1 : 0;
            digits[i] = sum % 10;
        }
        
        if (carry) {
            digits.insert(digits.begin(), carry);
        }
        
        int i = 0;
        while (i < size && digits[i] == 0)
        {
            i++;
        }
        
        return std::vector<int>(digits.begin()+i, digits.end());
    }
};