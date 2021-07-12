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

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        
        if(root->val == key){
            // root->right is NULL
            if(root->right == NULL){
                TreeNode* left = root->left;
                delete root;
                return left;
            }
            
            // root->right exists
            else{
                TreeNode* right = root->right;
                while(right->left){
                    right = right->left;
                }
                swap(root->val, right->val);
            }
        }
        
        root->left = deleteNode(root->left, key);
        root->right = deleteNode(root->right, key);
        
        return root;
    }
};