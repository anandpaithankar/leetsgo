class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int j = 0;
		int size = A.size();
		
		while (j < size && A[j] < 0) {
			j++;
		}
		
		int i = j - 1 ;
		std::vector<int> result;
		
		while (i >= 0 && j < size) {
			if (A[i] * A[i] > A[j] * A[j]) {
				result.push_back(A[j]*A[j]);
				j++;
				
			} else {
				result.push_back(A[i]*A[i]);
				i--;
			}
		}
		
		while (i >= 0)
		{
			result.push_back(A[i]*A[i]);
			i--;
		}
		
		while (j < size)
		{
			result.push_back(A[j] * A[j]);
			j++;
		}
		
		return result;
    }
};