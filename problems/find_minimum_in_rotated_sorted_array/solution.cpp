class Solution {
public:
    int FindSmallestElementInCircularArray(const std::vector<int>& arr) {
    
    int left = 0, right = arr.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] > arr[right]) {
            // the min is in [mid + 1 , right] region.
            left = mid + 1;
        } else {
            // the min is in [left, mid] region.
            right = mid;
        }
    }
    
    return arr[left]; // loop ends when left == right
}
    int findMin(vector<int>& nums) {
        return FindSmallestElementInCircularArray(nums);
        
    }
};