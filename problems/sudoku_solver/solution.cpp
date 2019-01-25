class Solution {
public:
    
    bool IsValidValue(std::vector<std::vector<char>>& board, int row, 
		int col, char value) {
			
			// check row constraints
			for (int i = 0; i < board.size(); i++) {
				if (board[row][i] == value) {
					return false;
				}
			}
			
			for (int j = 0; j < board.size(); j++) {
				if (board[j][col] == value) {
					return false;
				}
			}
			
			int regionSize = std::sqrt(board.size());
			int rowFactor = row / regionSize;
			int colFactor = col / regionSize;
			
			for (int i = 0; i < regionSize; i++) {
				for (int j = 0; j < regionSize; j++) {
					if (board[rowFactor*regionSize+i][colFactor*regionSize+j]
						 == value) {
						return false;
					}
				}
			}
			return true;
	}
    
    bool solveSudokuHelper(std::vector<std::vector<char>>& board, 
		int row, int col) {
			
			if (row == board.size()) {
				row = 0;
				if (++col == board[row].size()) {
					return true;
				}
			}
			
			if (board[row][col] != '.') {
				return solveSudokuHelper(board, row + 1, col);
			}
			
			for (int val = 1; val <= board.size(); val++) {
                char c = '0' + val;
				if (IsValidValue(board, row, col, c)) {
					board[row][col] = c;
					if (solveSudokuHelper(board, row+1, col)) {
						return true;
					}
				}
			}
			
			board[row][col] = '.';
			return false;
	}
    
    void solveSudoku(vector<vector<char>>& board) {
        if (board.empty()) {
        	return;
        }
		
		solveSudokuHelper(board, 0, 0);
    }
};