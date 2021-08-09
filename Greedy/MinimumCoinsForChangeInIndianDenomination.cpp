class Solution{

	public:
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	    sort(coins,coins+M);
	    int coin=0;
	    for(int j=M-1;j>=0;){
	        if(coins[j]<=V){
	            V-=coins[j];
	            coin++;
	        }
	        else{
	            j--;
	        }
	    }
	    return coin;
	} 
	  
};
