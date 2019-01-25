class Solution {
public:
    bool HasDuplicate(std::vector<std::vector<char>>&board, int startRow,
	 int endRow, int startCol, int endCol) {
		 std::unordered_set<char> digits;
		 
		 for (int i = startRow; i < endRow; i++) {
			 for (int j = startCol; j < endCol; j++) {
				 if (board[i][j] != '.' && digits.count(board[i][j])) {
					 return true;
				 } else {
					 digits.insert(board[i][j]);
				 }
			 }
		 }
		 return false;
	}
    
    bool isValidSudoku(vector<vector<char>>& board) {
        // check row constraints
		for (int i = 0; i < board.size(); i++) {
			if (HasDuplicate(board, i, i+1, 0, board.size())){
				return false;
			}
		}
		
		for (int j = 0; j < board.size(); j++) {
			if (HasDuplicate(board, 0, board.size(), j, j+1)) {
				return false;
			}
		}
		
		// check region constraints
		int regionSize = std::sqrt(board.size());
		for (int i = 0; i < regionSize; i++) {
			for (int j = 0; j < regionSize; j++) {
				if (HasDuplicate(board, i * regionSize, regionSize *(i+1), 
				j * regionSize, regionSize * (j+1))) {
					return false;
				}
			}
		}
		return true;
    }
};