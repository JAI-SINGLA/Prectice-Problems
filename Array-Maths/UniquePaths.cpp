class Solution {
public:
    
    int uniquePaths(int i, int j ,int m , int n,vector<vector<int>>&ans){
        if(i==m-1&&j==n-1){
            ans[m-1][n-1]=1;
            return 1;
        }
        int ways=0;
        if(ans[i][j]!=0){
            return ans[i][j];
        }
        
        if(j!=n-1){
            ways+=(uniquePaths(i,j+1,m,n,ans));
        }
        if(i!=m-1){
            ways+=(uniquePaths(i+1,j,m,n,ans));
        }
        ans[i][j]=ways;
        return ways;
                   
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>ans;
        vector<int>temp;
            for(int j=0;j<n;j++){
                temp.push_back(0);
            }
        for(int i=0;i<m;i++){
            ans.push_back(temp);
        }
        return uniquePaths(0,0,m,n,ans);
        
        
    }
};
