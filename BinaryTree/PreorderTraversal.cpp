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
    
    void preorderTraversal(TreeNode* root, vector<int>&ans){
        if(root==NULL)return;
        ans.push_back(root->val);
        preorderTraversal(root->left,ans);
        preorderTraversal(root->right,ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        preorderTraversal(root,ans);
        return ans;
        
    }
};

//Iterative Solution

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode*>st;
        if(root==NULL) return ans;
        st.push(root);
        while(!st.empty()){
            ans.push_back(st.top()->val);
            TreeNode*node=st.top();
            st.pop();
            if(node->right!=NULL)st.push(node->right);
            if(node->left!=NULL)st.push(node->left);
        }
        return ans;
        
    }
};
