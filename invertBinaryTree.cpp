/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        //BASE CASE
        if(root == NULL) return NULL;

        invertTree(root->left);
        invertTree(root->right);

        //swap the nodes
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        return root;
    }
};

------------------------------------------------------------
#include <queue>

TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) return nullptr;
    
    std::queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        
        // Swap left and right children
        TreeNode* temp = current->left;
        current->left = current->right;
        current->right = temp;
        
        if (current->left != nullptr) q.push(current->left);
        if (current->right != nullptr) q.push(current->right);
    }
    
    return root;
}
