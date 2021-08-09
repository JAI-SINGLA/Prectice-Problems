class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool cmp(Job J1, Job j2){
        return J1.profit>j2.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code 
        vector<int>ans;
        if(n==0){
            return ans;
        }
        sort(arr,arr+n,cmp);
        int maxProfit=0;
        int count=0;
        int mx=arr[0].dead;
        for(int i=1;i<n;i++){
            mx=max(mx,arr[i].dead);
        }
        vector<int>v(mx+1);
        for(int i=0;i<mx+1;i++){
            v[i]=-1;
        }
        v[arr[0].dead]=arr[0].id;
        count++;
        maxProfit+=arr[0].profit;
        for(int i=1;i<n;i++){
            for(int j=arr[i].dead;j>=1;j--){
                if(v[j]==-1){
                    count++;
                    maxProfit+=arr[i].profit;
                    v[j]=arr[i].id;
                    break;
                }
            }
        }
        ans.push_back(count);
        ans.push_back(maxProfit);
        return ans;
    } 
};
