class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount=0;
        int count=0;
        int i=0;
        while(i<nums.size()){
            if(nums[i]==1){
                count++;
                maxCount=max(maxCount,count);
            }
            else{
                count=0;
            }
            i++;
        }
        return maxCount;
    }
};
