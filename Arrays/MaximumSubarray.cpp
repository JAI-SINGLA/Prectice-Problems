class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       vector<int>cumulativeSum;
        cumulativeSum.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            cumulativeSum.push_back(cumulativeSum[i-1]+nums[i]);
        }
        int maxSum=INT_MIN;
        for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                int currentSum=cumulativeSum[j]-cumulativeSum[i]+nums[i];
                maxSum=max(currentSum,maxSum);
            }
        }
        return maxSum;
        
    }
};

/*Kadane's Algo
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ms=0;
        int cs=0;
        int negFlag=1;
        int maxNeg=INT_MIN;
        for(int i=0;i<nums.size();i++){
            maxNeg=max(maxNeg,nums[i]);
            if(nums[i]>0){
                negFlag=0;
            }
            cs=cs+nums[i];
            if(cs<0){
                cs=0;
                continue;
            }
            ms=max(ms,cs);
        }
        if(negFlag)return maxNeg;
        return ms;
        
    }
};
/*
