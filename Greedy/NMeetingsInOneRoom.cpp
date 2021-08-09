class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            pair<int,int>p;
            p.first=end[i];
            p.second=start[i];
            v.push_back(p);
        }
        sort(v.begin(),v.end());
        int count=1;
        vector<pair<int,int>>ans;
        ans.push_back(v[0]);
        for(int i=1;i<v.size();i++){
            if(v[i].second>ans[ans.size()-1].first){
                count++;
                ans.push_back(v[i]);
            }
        }
        return count;
    }
};
