class Solution {
public:
    int searchInsert(vector<int>& arr, int value) {
        int start = 0;
        int mid = 0;
        int end = arr.size() - 1;

        while (start <= end)
        {
            mid = (start + end) / 2;
            if (arr[mid] > value)
            {
                end = mid - 1;
            }
            else if (arr[mid] < value)
            {
                start = mid + 1;
            }
            else
            {
                return mid;
            }
        }

        if (arr[start] == value)
        {
            return start;
        }
        else
        {
            return end + 1;
        }
    }
};