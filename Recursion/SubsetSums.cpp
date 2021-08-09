//O(2^N) Space and Time solution
class Solution
{
public:
    void subsetSums(int *arr, int n, vector<int>&ans,int S){
        if(n==0){
            ans.push_back(S);
            return;
        }
        subsetSums(arr+1,n-1,ans,S+arr[0]);
        subsetSums(arr+1,n-1,ans,S);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int>ans;
        subsetSums(&arr[0],N,ans,0);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
