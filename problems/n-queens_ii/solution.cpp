class Solution {
public:
    
    bool isValid(std::vector<std::string> &grid, int row, int col)
    {
        for (int r = 0; r < row; ++r)
        {
            if (grid[r][col] == 'Q')
            {
                return false;
            }
        }

        for (int c = 0; c < col; c++)
        {
            if (grid[row][c] == 'Q')
            {
                return false;
            }
        }

        // diagonal - upper left
        for (int r = row - 1, c = col - 1; r >= 0 && c >= 0; --r, --c)
        {
            if (grid[r][c] == 'Q')
            {
                return false;
            }
        }

        // diagonal - lower left
        for (int r = row + 1, c = col - 1; r < grid.size() && c >= 0; r++, c--)
        {
            if (grid[r][c] == 'Q')
            {
                return false;
            }
        }

        // diagonal - upper right
        for (int r = row - 1, c = col + 1; r >= 0 && c < grid.size(); r--, c++)
        {
            if (grid[r][c] == 'Q')
            {
                return false;
            }
        }

        // diagnoal - lower right
        for (int r = row + 1, c = col + 1; r < grid.size() && c < grid.size(); r++, c++)
        {
            if (grid[r][c] == 'Q')
            {
                return false;
            }
        }

    return true;
}
    
    void placeNQueens(std::vector<std::string> &grid, int n, int row, int &count) {
        if (row == n) {
            count = count + 1;
            return;
        }
        
        for (int c = 0; c < n; c++) {
            grid[row][c] = 'Q';
            if (isValid(grid, row, c)) {
                placeNQueens(grid, n, row + 1, count);   
            }
            grid[row][c] = '.';
        }
    }
    
    int totalNQueens(int n) {
        std::vector<std::string> grid(n, std::string(n,'.'));
        int count = 0;
        placeNQueens(grid, n, 0, count);
        return count;
    }
};