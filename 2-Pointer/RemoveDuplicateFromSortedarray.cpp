//O(n) Solution
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int>s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        int i=0;
        for(auto it=s.begin();it!=s.end();it++){
            nums[i]=*it;
            i++;
        }
        return i;
    }
};

//O(1) Solution
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int j=1;
        if(nums.size()==0){
            return 0;
        }
        while(j<nums.size()){
            if(nums[i]==nums[j])
                j++;
            else{
                i++;
                nums[i]=nums[j];
                j++;
            }
        }
        return i+1;
    }
};
