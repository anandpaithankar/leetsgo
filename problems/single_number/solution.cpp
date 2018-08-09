class Solution {
public:
    int singleNumber(vector<int>& arr) {
        int number = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        number ^= arr[i];
    }
    return number;
    }
};