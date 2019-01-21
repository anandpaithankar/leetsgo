/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        std::vector<std::vector<int>> levels;
		
		if (root == nullptr) {
			return levels;
		}
		
		Node *current = root;
		int currentLevel = 0;
		
		std::queue<Node*> q;
		q.push(current);
		
		while(!q.empty()) {
			int nodeCount = q.size();
			if (levels.size() < currentLevel+1) {
				levels.push_back(std::vector<int>());
			}
			
			while(nodeCount--) {
				Node *temp = q.front();
				q.pop();
				
				levels[currentLevel].push_back(temp->val);
				for (auto child : temp->children) {
					if (child) {
						q.push(child);
					}
				}
			}
			currentLevel++;
		}
		return levels;
    }
};