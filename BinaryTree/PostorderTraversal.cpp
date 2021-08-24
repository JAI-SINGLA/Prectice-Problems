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
    void postorderTraversal(TreeNode*root, vector<int>&ans){
        if(root==NULL) return;
        postorderTraversal(root->left,ans);
        postorderTraversal(root->right,ans);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        postorderTraversal(root,ans);
        return ans;
        
    }
};

//Iterative solution using 2 stacks O(2n) time and space

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root==NULL)return ans;
        stack<TreeNode*>s1,s2;
        s1.push(root);
        while(!s1.empty()){
            s2.push(s1.top());
            TreeNode*temp=s1.top();
            s1.pop();
            if(temp->left!=NULL) s1.push(temp->left);
            if(temp->right!=NULL)s1.push(temp->right);
        }
        while(!s2.empty()){
            ans.push_back(s2.top()->val);
            s2.pop();
        }
        return ans;
    }
};

// Iterative single stack solution

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root==NULL)return ans;
        stack<TreeNode*>st;
        TreeNode*curr=root;
        while(curr!=NULL || !st.empty()){
            if(curr!=NULL){
                st.push(curr);
                curr=curr->left;
            }
            else{
                TreeNode*temp=st.top()->right;
                if(temp==NULL){
                    ans.push_back(st.top()->val);
                    temp=st.top();
                    st.pop();
                    while(!st.empty()&&st.top()->right==temp){
                        ans.push_back(st.top()->val);
                        temp=st.top();
                        st.pop();
                    }
                }
                else{
                    curr=temp;
                }
            }
        }
        return ans;
        
    }
};
