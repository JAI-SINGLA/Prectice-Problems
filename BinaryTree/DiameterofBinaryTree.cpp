//O(n*h) Solution

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
    int height(TreeNode*root){
        if(root==NULL)return 0;
        return 1+max(height(root->left),height(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)return 0;
        int lh=height(root->left);
        int rh=height(root->right);
        int ld=diameterOfBinaryTree(root->left);
        int rd=diameterOfBinaryTree(root->right);
        return max(max(lh+rh,ld),rd);
    }
};

//O(n) Solution

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
    pair<int,int>diameterHelp(TreeNode*root){
        if(root==NULL){
            pair<int,int>p({0,0});
            return p;
        }
        pair<int,int>p1=diameterHelp(root->left);
        pair<int,int>p2=diameterHelp(root->right);
        int ld=p1.first;
        int lh=p1.second;
        int rd=p2.first;
        int rh=p2.second;
        int height=1+max(lh,rh);
        int diameter=max(max(lh+rh,ld),rd);
        pair<int,int>p({diameter,height});
        return p;
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return diameterHelp(root).first;
    }
};
