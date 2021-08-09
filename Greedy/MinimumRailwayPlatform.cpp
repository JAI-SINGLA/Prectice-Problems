class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	int maxPlat=0;
    	int plat=0;
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	int i=0;
    	int j=0;
    	while(i<n){
    	    if(arr[i]<=dep[j]){
    	        plat++;
    	        maxPlat=max(maxPlat,plat);
    	        i++;
    	    }
    	    else{
    	        plat--;
    	        j++;
    	    }
    	}
    	return maxPlat;
    }
};
