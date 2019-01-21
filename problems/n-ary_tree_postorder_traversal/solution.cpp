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
    void postOrderHelper(Node *node, std::vector<int> &nodes) {
		if (!node) {
			return;
		}
		
		for (auto child : node->children) {
			postOrderHelper(child, nodes);
		}
		
		nodes.push_back(node->val);
	}
    
    vector<int> postorder(Node* root) {
        std::vector<int> nodes;
		postOrderHelper(root, nodes);
        return nodes;
    }
};