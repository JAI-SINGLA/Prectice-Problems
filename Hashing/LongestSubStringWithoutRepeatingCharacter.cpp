//O(n^2) & O(n) Solution
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen=0;
        for(int i=0;i<s.length();i++){
            unordered_map<char,int>mp;
            int length=0;
            for(int j=i;j<s.size();j++){
                if(mp.count(s[j])>0){
                    break;
                }
                mp[s[j]]=1;
                length++;
                maxLen=max(maxLen,length);
                
            }
        }
        return maxLen;
    }
};

//O(2n) solution
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int r=0;
        int maxLen=0;
        unordered_map<char ,int>mp;
        while(r<s.size()){
            if(mp.count(s[r])>0){
                char c=s[r];
                while(s[l]!=c){
                    mp.erase(s[l]);
                    l++;
                }
                mp.erase(s[l]);
                l++;
            }
            mp[s[r]]=1;
            r++;
            int len=r-l;
            maxLen=max(len,maxLen);
        }
        return maxLen;
    }
};
//O(n) Solution
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int r=0;
        int maxLen=0;
        unordered_map<char , int>mp;
        while(r<s.size()){
            if((mp.count(s[r])>0)&&mp[s[r]]>=l){
                l=mp[s[r]]+1;
            }
            mp[s[r]]=r;
            r++;
            int len=r-l;
            maxLen=max(maxLen,len);
        }
                                      return maxLen;
    }
};
