class Solution {
public:
    bool isEven(int num) { return (num & 0x01) == 0; }
    
    vector<int> sortArrayByParityII(vector<int>& A) {
        int i = 0, j = 0;

        while (i < A.size() && j < A.size())
        {
            if (isEven(i) && isEven(A[j]))
            {
                std::swap(A[i], A[j]);
                i++, j = i;
            }
            else if (isEven(i) && !isEven(A[j]))
            {
                j++;
            }
            else if (!isEven(i) && !isEven(A[j]))
            {
                std::swap(A[i], A[j]);
                i++, j = i;
            }
            else
            {
                j++;
            }
        }
        return A;
        
       
    }
};