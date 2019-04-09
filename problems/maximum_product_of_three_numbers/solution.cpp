class Solution {
public:
    int maximumProduct(vector<int>& arr) {
        if (arr.size() < 3) {
            return INT_MAX;
        }
        
        int firstMax = INT_MIN, secondMax = INT_MIN, thirdMax = INT_MIN;
        int firstMin = INT_MAX, secondMin = INT_MAX;
        
        for (int i = 0; i < arr.size(); i++) {
            
            if (arr[i] > firstMax) {
                thirdMax = secondMax;
                secondMax = firstMax;
                firstMax = arr[i];
            } else if (arr[i] > secondMax) {
                thirdMax = secondMax;
                secondMax = arr[i];
            } else if (arr[i] > thirdMax) {
                thirdMax = arr[i];
            }
            
            if (arr[i] < firstMin) {
                secondMin = firstMin;
                firstMin = arr[i];
            } else if (arr[i] < secondMin) {
                secondMin = arr[i];
            }
        }
        
        return std::max((firstMin * secondMin * firstMax), 
                       (firstMax * secondMax * thirdMax));
        
    }
};