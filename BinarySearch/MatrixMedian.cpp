int countSmallerAndEqual(vector<int>&v ,int x){
    int lo=0;
    int hi=v.size()-1;
    while(lo<=hi){
        int mid= (lo+hi)/2;
        if(v[mid]<=x){
            lo=mid+1;
        }
        else{
            hi=mid-1;
        }
        
    }
    return lo;
    
}
int getMedian(vector<vector<int>> &matrix)
{
    // Write your code here.
    int lo=0;
    int hi=1000000000;
    int size=matrix.size()*matrix[0].size();
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        int countEqualSmaller=0;
        for(int i=0;i<matrix.size();i++)
        countEqualSmaller += countSmallerAndEqual(matrix[i],mid);
        if(countEqualSmaller<=(size)/2){
            lo=mid+1;
        }
        else{
            hi=mid-1;
        }
    }
    return lo;
}
