class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            for(int j=i+1;j<nums.size();j++){
                if(j>i+1 && nums[j]==nums[j-1]){
                    continue;
                }
                int required=target-nums[i]-nums[j];
                int p=j+1;
                int q=nums.size()-1;
                while(p<q){
                    if(nums[p]+nums[q]==required){
                        vector<int>temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[p]);
                        temp.push_back(nums[q]);
                        ans.push_back(temp);
                        p++;
                        q--;
                        while(nums[p]==nums[p-1] && p<q && nums[q]==nums[q+1]){
                            p++;
                            q--;
                        }
                    }
                    else if(nums[p]+nums[q]>required){
                        q--;
                    }
                    else{
                        p++;
                    }
                }
            }
        }
        return ans;
    }
};
