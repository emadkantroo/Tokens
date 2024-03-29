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
    bool helper(TreeNode* l, TreeNode* r) {
        if(l == nullptr || r == nullptr) return l == r;
        if(l->val != r->val) return false;
        return helper(l->left, r->right) && helper(l->right, r->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        return helper(root->left, root->right);
    }
};

//python 3
class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        def isSmallSymmetric(a,b):
            if type(a)==TreeNode and type(b)==TreeNode:
                if a.val==b.val:
                    return isSmallSymmetric(a.left,b.right) and isSmallSymmetric(a.right,b.left)
            else:
                return a==b
        return isSmallSymmetric(root.left,root.right)