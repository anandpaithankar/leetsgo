class Solution {
public:
    bool isPalindrome(int x) {
//         if (number < 0)
//         return false;
//     int decimal = 1, x = number;
//     while (x / 10)
//     {
//         decimal = decimal * 10;
//         x /= 10;
//     }

//     x = number;
//     while (x)
//     {
//         int left = (x / decimal);
//         int right = (x % 10);
//         if (left != right)
//         {
//             return false;
//         }
//         x = (x % 10) / decimal;
//         decimal /= 100;
//     }
//     return true;
        
    long y = 0;
    for (int tmp = x; tmp; y = y * 10 + tmp % 10, tmp /= 10) {}
    return x == fabs(y);

        
    }
};