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
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> levels;
		
		if (root == nullptr) {
			return levels;
		}
		
		TreeNode *current = root;
		int currentLevel = 0;
		
		std::queue<TreeNode*> q;
		q.push(current);
		
		while(!q.empty()) {
			int nodeCount = q.size();
			if (levels.size() < currentLevel+1) {
				levels.push_back(std::vector<int>());
			}
			
			while(nodeCount--) {
				TreeNode *temp = q.front();
				q.pop();
				
				levels[currentLevel].push_back(temp->val);
				if (temp->left) q.push(temp->left);
				if (temp->right) q.push(temp->right);
			}
			currentLevel++;
		}
		return levels;
    }
};