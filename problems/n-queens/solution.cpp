class Solution {
public:
    bool isValid(std::vector<std::string> &grid, int row, int col) {
        for (int r = 0; r < row; ++r) {
            if (grid[r][col] == 'Q') {
                return false;
            }
        }

        for (int c = 0; c < col; c++) {
            if (grid[row][c] == 'Q') {
                return false;
            }
        }

        // diagonal - upper left
        for (int r = row-1, c = col-1; r >= 0 && c >= 0; --r, --c) {
            if (grid[r][c] == 'Q') {
                return false;
            }
        }

        // diagonal - lower left
        for (int r = row+1, c = col-1; r < grid.size() && c >= 0 ; r++, c--) {
            if (grid[r][c] == 'Q') {
                return false;
            }
        }

        // diagonal - upper right
        for (int r = row-1, c = col+1; r >= 0 && c < grid.size(); r--, c++) {
            if (grid[r][c] == 'Q') {
                return false;
            }
        }

        // diagnoal - lower right
        for (int r = row+1, c = col+1; r < grid.size() && c < grid.size(); r++, c++) {
            if (grid[r][c] == 'Q') {
                return false;
            }
        }

        return true;
    }
    
    // Input 
    //  grid - to place queens (grid is vector or vector containing string for each row)
    //  row - current row index to place a queen
    //  
    // Output
    //  result - final output ...which is vector or vectors. each inner vector will store 
    //          the entire row in as a string.
    //  
    void placeNQueens(std::vector<std::string> &grid, int row, int n,
                      std::vector<std::vector<std::string>> &result) {
        // base case
        if (row == n) {
            result.push_back(grid);
            return;
        }
        
        // go over every column and place queen on a given row
        for (int col = 0; col < n; ++col) {
            // place a queen
            grid[row][col] = 'Q';
            
            if (isValid(grid, row, col)) {
                placeNQueens(grid, row+1, n, result);
                
            }
            grid[row][col] = '.';
        }
    }
   
    vector<vector<string>> solveNQueens(int n) {
        std::vector<std::string> grid(n, std::string(n,'.'));
        std::vector<std::vector<std::string>> result;
        
        placeNQueens(grid, 0, n, result);
        return result;
        
    }
};