class Solution {
public:
    int partition(vector<int> &nums, int start, int end) {
        int pivot = nums[end];
        int j=start;
        for (int i = start; i <= end-1; i++) {
            if (nums[i] > pivot) {
                std::swap(nums[i], nums[j]);
                j++;
            }
        }
        std::swap(nums[j], nums[end]);
        return j;
    }
    
    int findKthLargest(vector<int> &nums, int start, int end, int k) {
        while (start <= end) {
            int index = partition(nums, start, end);
            if (k-1 == index) {
                return nums[index];
            } else if (index > k-1) {
                return findKthLargest(nums, start, index-1, k);
            } else {
                return findKthLargest(nums, index+1, end, k);
            }
        }
        return INT_MAX;
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        return findKthLargest(nums, 0, nums.size()-1, k);
    }
};