class Solution {
public:
    void subsetWithDup(int *nums,int n ,vector<vector<int>>& ans){
        if(n==0){
            vector<int>temp;
            ans.push_back(temp);
            return;
        }
        subsetWithDup(nums+1,n-1,ans);
        int ansSize=ans.size();
        for(int i=0;i<ansSize;i++){
            vector<int>temp=ans[i];
            temp.push_back(nums[0]);
            ans.push_back(temp);
        }
    }
    static bool isEqual(vector<int>a,vector<vector<int>>finalAns){
        for(int i=0;i<finalAns.size();i++){
            vector<int>b=finalAns[i];
            if(a.size()==b.size()){
                int flag=0;
                 for(int j=0;j<a.size();j++){
                    if(a[j]!=b[j]){
                        flag=1;
                        break;
                    }
            }
                if(flag==0){
                    return true;
                }
            }
        }
        return false;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        subsetWithDup(&nums[0],nums.size(),ans);
        for(int i=0;i<ans.size();i++){
            sort(ans[i].begin(),ans[i].end());
        }
        vector<vector<int>>finalAns;
        finalAns.push_back(ans[0]);
        for(int i=1;i<ans.size();i++){
            if(!isEqual(ans[i],finalAns)){
                finalAns.push_back(ans[i]);
            }
        }
        return finalAns;
    }
};
