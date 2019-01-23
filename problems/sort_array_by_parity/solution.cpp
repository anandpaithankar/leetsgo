class Solution {
public:
    bool isOdd(int n) {
		return (n & 0x1);
	}
    
    vector<int> sortArrayByParity(vector<int>& A) {
        int i = 0;
		int j = A.size() - 1;
		
		while(i < j)
		{
			if (isOdd(A[i]) && !isOdd(A[j]))
			{
				std::swap(A[i], A[j]);
				i++, j--;
			}
			else if(!isOdd(A[i]))
			{
				i++;
			}
			else if (isOdd(A[j]))
			{
				j--;
			}
		}
		
		return A;
    }
};