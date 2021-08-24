class Solution {
  public:
  void bottomView(Node*root, int d,int level,map<int,pair<int,int>>&mp){
      if(root==NULL)return;
      if(mp.count(d)==0)
      mp[d]=make_pair(level,root->data);
      else{
          if(mp[d].first<=level){
              mp[d].first=level;
              mp[d].second=root->data;
          }
      }
      bottomView(root->left,d-1,level+1,mp);
      bottomView(root->right,d+1,level+1,mp);
  }
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int>ans;
        map<int,pair<int,int>>mp;
        bottomView(root,0,1,mp);
        for(auto it=mp.begin();it!=mp.end();it++){
            ans.push_back(it->second.second);
        }
        return ans;
    }
};
