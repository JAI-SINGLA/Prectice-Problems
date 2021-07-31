class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        vector<vector<int>>temp;
        temp.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=temp[0][1]){
                temp[0][1]=max(temp[0][1],intervals[i][1]);
            }
            else{
                ans.push_back(temp[0]);
                temp[0][0]=intervals[i][0];
                temp[0][1]=intervals[i][1];
            }
        }
        ans.push_back(temp[0]);
        return ans;
        
    }
};
