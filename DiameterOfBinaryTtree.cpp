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
    // Function to calculate the diameter and height of a subtree recursively
    pair<int, int> calculateDiameterAndHeight(TreeNode* root) {
        if (root == nullptr) {
            // Base case: Empty subtree has diameter and height 0
            return {0, 0};
        }

        // Get diameter and height information for left and right subtrees
        auto leftData = calculateDiameterAndHeight(root->left);
        auto rightData = calculateDiameterAndHeight(root->right);

        // Calculate current subtree's diameter:
        // - Maximum path passing through root
        // - Maximum diameter in left or right subtree
        int currentDiameter = max(leftData.second + rightData.second, 
                                  max(leftData.first, rightData.first));

        // Calculate current subtree's height (maximum path through root)
        int currentHeight = max(leftData.second, rightData.second) + 1;

        return {currentDiameter, currentHeight};
    }

    int diameterOfBinaryTree(TreeNode* root) {
        // The diameter of the entire tree is the maximum diameter found across subtrees
        return calculateDiameterAndHeight(root).first;
    }
};
-----------------------------------------------------------------------
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
    int height(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int left = height(root->left);
        int right = height(root->right);
        int ans = max(left, right) + 1;
        return ans;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int left = diameterOfBinaryTree(root->left); // Recursive diameter on left subtree
        int right = diameterOfBinaryTree(root->right); // Recursive diameter on right subtree

        int opt1 = height(root->left) + height(root->right); // Diameter through the root
        int opt2 = max(left, right); // Maximum diameter from left and right subtrees

        return max(opt1, opt2);
    }
};