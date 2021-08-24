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
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        int lh=height(root->left);
        int rh=height(root->right);
        if(abs(lh-rh)>1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};


// O(n) Solution


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
    pair<bool,int>isBalancedHelper(TreeNode*root){
        if(root==NULL){
            pair<bool,int>p({true,0});
            return p;
        }
        pair<bool,int>p1;
        pair<bool,int>p2;
        p1=isBalancedHelper(root->left);
        p2=isBalancedHelper(root->right);
        bool check=true;
        if(abs(p1.second-p2.second)>1) check=false;
        int height=1+max(p1.second,p2.second);
        check= check&&p1.first&&p2.first;
        pair<bool,int>finalP({check,height});
        return finalP;
        
        
    }
    bool isBalanced(TreeNode* root) {
        return isBalancedHelper(root).first;
    }
};

// Another O(n) Solution
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
    int heightModified(TreeNode*root){
        if(root==NULL) return 0;
        int lh=heightModified(root->left);
        if(lh==-1) return -1;
        int rh=heightModified(root->right);
        if(rh==-1)return -1;
        if(abs(rh-lh)>1)return -1;
        return 1+max(lh,rh);
    }
    bool isBalanced(TreeNode* root) {
        return heightModified(root)==-1?false:true;
        
    }
};
