class Solution {
public:
    // Time Limit Exceeds
//     int uniquePaths(int row, int col, int m, int n) {
//         if (row >= m || col >= n) {
//             return 0;
//         }
        
//         if (row == m-1 && col == n-1) {
//             return 1;
//         }
        
//         return uniquePaths(row+1, col, m, n) + 
//         uniquePaths(row, col+1, m, n);
//     }
    
    // int uniquePaths(int m, int n) {
    //     return uniquePaths(0, 0, m, n);
    // }

    int uniquePaths(int m, int n) {
        std::vector<std::vector<int>> mat(m+1, std::vector<int>(n+1, 0));
        mat[m-1][n] = 1;
        for (int r = m-1; r >= 0; r--) {
            for (int c = n-1; c >= 0; c--) {
                mat[r][c] = mat[r+1][c] + mat[r][c+1];
            }
        }
        return mat[0][0];
     }
};