/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    vector<double> averageOfLevels(TreeNode* root) {
        std::vector<double> averages;
		
		if (root == nullptr) {
			return averages;
		}
		
		TreeNode *current = root;
		std::queue<TreeNode*> q;
		q.push(current);
		
		while(!q.empty())
		{
			int nodeCount = q.size();
            int count = nodeCount;
            double sum = 0;
			
			while (nodeCount--)
			{
				TreeNode *current = q.front();
				q.pop();
				
				sum += current->val;
				if(current->left) q.push(current->left);
				if(current->right) q.push(current->right);
			}
			
			if (count > 0)
			{
				double avg = sum/count;
				averages.push_back(avg);
			}
		
		}
		
		return averages;
        
    }
};