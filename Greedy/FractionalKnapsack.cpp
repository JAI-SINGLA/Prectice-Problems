class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool cmp(Item a, Item b){
        return ((double)a.value/a.weight)>((double)b.value/b.weight);
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr,arr+n,cmp);
        double maxValue=0;
        for(int i=0;i<n;i++){
            if(W>=arr[i].weight){
                maxValue+=(double)(arr[i].value);
                W-=arr[i].weight;
            }
            else{
                maxValue+=(double)(W)*((double)arr[i].value/arr[i].weight);
                break;
            }
        }
        return maxValue;
    }
        
};
