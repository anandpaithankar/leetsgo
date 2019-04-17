class Solution {
    struct Index
    {
        int row, col;
    };
    
    Index getRookIndex(const std::vector<std::vector<char>> &board) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] == 'R') {
                    return Index{i,j};
                }
            }
        }
        return Index{-1,-1};
    }
    
    int CollectUp(const std::vector<std::vector<char>> &board, const Index &index) {
        int num = 0;
        for (int row = index.row-1; row >= 0 ; row--) {
            if (board[row][index.col] == 'B') {
                return 0;
            }
            else if (board[row][index.col] == 'p') {
                num++;
                return num; 
            }
        }
        return num;
    }
    
    int CollectDown(const std::vector<std::vector<char>> &board, const Index &index) {
        int num = 0;
        for (int row = index.row+1; row < board.size() ; row++) {
            if (board[row][index.col] == 'B') {
                return 0;
            }
            else if (board[row][index.col] == 'p') {
                num++;
                return num; 
            }
        }
        return num;
    }
    
    int CollectLeft(const std::vector<std::vector<char>> &board, const Index &index) {
        int num = 0;
        for (int col = index.col-1; col >= 0 ; col--) {
            if (board[index.row][col] == 'B') {
                return 0;
            }
            else if (board[index.row][col] == 'p') {
                num++;
                return num; 
            }
        }
        return num;
    }
    
    int CollectRight(const std::vector<std::vector<char>> &board, const Index &index) {
        int num = 0;
        for (int col = index.col+1; col < board[index.row].size() ; col++) {
            if (board[index.row][col] == 'B') {
                return 0;
            }
            else if (board[index.row][col] == 'p') {
                return 1; 
            }
        }
        return 0;
    }
public:
    int numRookCaptures(vector<vector<char>>& board) {
        Index index = getRookIndex(board);
        int count = 0;
        count += CollectUp(board, index);
        count += CollectDown(board, index);
        count += CollectLeft(board, index);
        count += CollectRight(board, index);  
        
        return count; 
    }
};