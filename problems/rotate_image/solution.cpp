class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size() - 1;
	for (int i = 0; i < matrix.size() /2 ; i++) {
		for (int j = i; j < size -i; j++) {
			auto tmp = matrix[i][j];
			matrix[i][j] = matrix[size - j][i];
			matrix[size - j][i] = matrix[size-i][size-j];
			matrix[size-i][size-j] = matrix[j][size - i];
			matrix[j][size - i] = tmp;
		}
	}
    return ;

        
    }
};