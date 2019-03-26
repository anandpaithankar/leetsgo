class Solution {
public:
    using IntGrid = std::vector<std::vector<int>>;

    int minPathSum(const vector<vector<int>> &grid, int row, int col, IntGrid &memo)
    {
        if (row >= grid.size() || col >= grid[0].size())
        {
            return INT_MAX;
        }

        if (row == grid.size() - 1 && col == grid[0].size() - 1)
        {
            return grid[row][col];
        }

        if (memo[row][col] != INT_MAX)
        {
            return memo[row][col];
        }

        int val = std::min(minPathSum(grid, row + 1, col, memo), minPathSum(grid, row, col + 1, memo))
            + grid[row][col];
        memo[row][col] = val;
        return val;
    }

    int minPathSum(vector<vector<int>> &grid)
    {
        IntGrid memo{grid.size(), std::vector<int>(grid[0].size(), INT_MAX)};
        return minPathSum(grid, 0, 0, memo);
    }
};