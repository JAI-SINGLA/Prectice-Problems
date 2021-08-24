class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    void topView(Node*root,int d, int level,map<int,pair<int,int>>&mp){
        if(root==NULL) return;
        if(mp.count(d)==0){
            mp[d]=make_pair(root->data,level);
        }
        else{
            if(mp[d].second>level){
                mp[d].second=level;
                mp[d].first=root->data;
            }
        }
        topView(root->left,d-1,level+1,mp);
        topView(root->right,d+1,level+2,mp);
    }
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int>ans;
        map<int,pair<int,int>>mp;
        topView(root,0,1,mp);
        for(auto it:mp){
            ans.push_back(it.second.first);
        }
        return ans;
    }

};
