/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (root == nullptr) return {};  // Edge case

        vector<vector<int>> ans;
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int numberOfNodes = q.size();
            vector<int> array;  // Store values of the current level

            for (int i = 0; i < numberOfNodes; i++) {
                Node* node = q.front();
                q.pop();
                array.push_back(node->val);  // Store node value

                // Push all children of the current node
                for (Node* child : node->children) {
                    if (child != nullptr) q.push(child);
                }
            }

            ans.push_back(array);
        }

        return ans;
    }
};