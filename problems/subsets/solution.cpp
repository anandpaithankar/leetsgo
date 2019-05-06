class Solution {
    void generateSubset(std::vector<int> &arr, 
                        std::vector<int> current, int index,
                        std::vector<std::vector<int>> &result)
{
	if (index == arr.size())
	{
		result.push_back(current);
		return;
	}

	current.push_back(arr[index]);
	generateSubset(arr, current, index + 1, result);
	current.pop_back();
	generateSubset(arr, current, index + 1, result);
}
public:
    vector<vector<int>> subsets(vector<int>& arr) {
        vector<vector<int>> result;
        vector<int> current;
        generateSubset(arr, current, 0, result);
        return result;
    }
};