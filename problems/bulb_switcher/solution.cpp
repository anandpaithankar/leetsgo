class Solution {
public:
    int bulbSwitch(int n) {
        // Excceds timeout
//         std::vector<int> arr(n, 0);
//         for (int i = 1; i <= n; i++)
//         {
//             for (int j = i; j <= n; j += i)
//             {
//                 if (arr[j - 1] == 0)
//                 {
//                     arr[j - 1] = 1;
//                 }
//                 else
//                 {
//                     arr[j - 1] = 0;
//                 }
//             }
//         }

//         int count = 0;
//         for (auto n : arr)
//         {
//             if (n == 1)
//                 count++;
//         }
//         return count;
        return std::sqrt(n);
    }
};