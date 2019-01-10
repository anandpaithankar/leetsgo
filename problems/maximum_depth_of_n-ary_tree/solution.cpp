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
    int maxDepth(Node* root) {
        if (root == nullptr) {
            return 0;
        } else if (root->children.empty()) {
            return 1;
        } else {
            std::vector<int> heights;
            for (auto n : root->children) {
                heights.push_back(maxDepth(n));
            }
            return *(std::max_element(heights.begin(), heights.end(),[](int n1, int n2) { return n1 < n2; }))+1;       
        }
        
    }
};