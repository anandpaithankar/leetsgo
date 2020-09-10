func twoSum(nums []int, target int) []int {
    m := make(map[int]int)

	for i, v := range nums {
		diff := target - v
		if x, ok := m[diff]; ok {
			return []int{x, i}
		}
		m[v] = i
	}
	return []int{}
    
}