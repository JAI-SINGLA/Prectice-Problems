class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size()==0){
            return 0;
        }
        
        int currentStreak=1;
        int maxStreak=1;
        int i=1;
        while(i<nums.size()){
            if(nums[i]==nums[i-1]+1){
                currentStreak++;
                i++;
            }
            else if(nums[i]==nums[i-1]){
                i++;
            }
            else{
                currentStreak=1;
                i++;
            }
            maxStreak=max(currentStreak,maxStreak);
        }
        return maxStreak;
        
    }
};
