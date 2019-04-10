class Solution {
public:
    int findPivotIndex(std::vector<int> &nums) {
        if (nums.empty()) {
            return -1;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= nums[nums.size()-1]) {
                return i;
            }
        }
        return 0;
    }
    
    int binarySearch(const std::vector<int> &nums, int start, int end, int target) {
        while (start <= end) {
            int mid =  (end+start)/2;
            if (nums[mid] == target) {
                return mid;
            } else if (target < nums[mid]) {
                end = mid-1;
            } else {
                start = mid+1;
            }
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        if (nums.empty()) {
            return -1;
        }
        int index = -1;
        int pivotIndex = findPivotIndex(nums);
        if (pivotIndex == 0) {
            return binarySearch(nums, 0, nums.size()-1, target);
        } else {
            if ((index = binarySearch(nums, 0, pivotIndex-1, target) )!= -1) {
                return index;
            }
            
            if ((index = binarySearch(nums, pivotIndex, nums.size()-1, target)) != -1) {
                return index;
            }
        }
        return index;
    }
    
};