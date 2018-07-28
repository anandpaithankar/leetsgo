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
    
    void preOrderHelper(Node *root, std::vector<int>& nodes) {
        if (root == nullptr) {
            return;
        }
        
        nodes.push_back(root->val);
        for (int i = 0 ; i < root->children.size(); i++) {
            preOrderHelper(root->children[i], nodes);
        }
    }
    
    void PreOrderRecursive(Node *root, std::vector<int>& nodes) {
        if (root == nullptr) {
            return;
        }
        
       if (root == nullptr)
	{
		return;
	}
	std::stack<Node *> st;
	Node *current = root;
	st.push(current);

	while (!st.empty())
	{
		Node *top = st.top();
		nodes.push_back(top->val);
		st.pop();
		for (int i = top->children.size() - 1; i >= 0; --i)
		{
			const auto &child = top->children[i];
			st.push(child);
		}
	}
            
    }
    
    vector<int> preorder(Node* root) {
        std::vector<int> nodes;
        //preOrderHelper(root, nodes);
        PreOrderRecursive(root, nodes);
        
        return nodes;
        
    }
};