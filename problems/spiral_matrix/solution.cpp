class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        std::vector<int> elements;
        if (matrix.size() == 0) {
            return {};
        }
        
        int m = matrix.size(), n = matrix[0].size();
        int row = 0, col = -1;
        while(true) {
            for (int i = 0; i < n; i++) {
                elements.push_back(matrix[row][++col]);
            }
            
            // are we finished all rows?
            if (--m == 0) {
                break;
            }
            
            for (int i = 0; i < m; i++) {
                elements.push_back(matrix[++row][col]);
            }
            
            // are we finished all cols?
            if (--n == 0) {
                break;
            }
            
            for (int i = 0; i < n; i++) {
                elements.push_back(matrix[row][--col]);
            }
            
            if (--m == 0) {
                break;
            }
            
            for (int i = 0; i < m; i++) {
                elements.push_back(matrix[--row][col]);
            }
            
            if (--n == 0) {
                break;
            }
        }
        return elements;
    }
};