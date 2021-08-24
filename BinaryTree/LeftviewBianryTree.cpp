vector<int> leftView(Node *root)
{
   vector<int>ans;
   if(root==NULL)return ans;
   queue<Node*>q;
   q.push(root);
   while(!q.empty()){
       int sz=q.size();
       for(int i=0;i<sz;i++){
           Node*temp=q.front();
           q.pop();
           if(i==0) ans.push_back(temp->data);
           if(temp->left!=NULL)q.push(temp->left);
           if(temp->right!=NULL)q.push(temp->right);
       }
   }
   return ans;
}


// Recursive Solution
void leftView(Node*root, int level, int&maxLevel, vector<int>&ans){
    if(root==NULL)return;
    if(maxLevel<level){
        ans.push_back(root->data);
        maxLevel=level;
    }
    leftView(root->left,level+1,maxLevel,ans);
    leftView(root->right,level+1,maxLevel,ans);
}
//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int>ans;
   int maxLevel=0;
   leftView(root,1,maxLevel,ans);
   return ans;
}
