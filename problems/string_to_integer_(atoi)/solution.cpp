class Solution {
public:
    int myAtoi(string str) {
        int sign = 1, result = 0, i = 0;
		
		// skip whitespaces
		while (str[i] == ' ' || str[i] == '\t') i++;
		
		// sign
		if (str[i] == '-' || str[i] == '+') {
			sign = 1 - 2 * (str[i++] == '-');
		}
		
		while (str[i] >= '0' && str[i] <= '9') {
			
			if ((result > INT_MAX / 10) || 
				(result == INT_MAX / 10 && str[i] - '0' > 7)) {
					return (sign == 1) ?INT_MAX:INT_MIN;
				}
				result = 10 * result + (str[i++] - '0');
		}
		
		return result * sign;
    }
};