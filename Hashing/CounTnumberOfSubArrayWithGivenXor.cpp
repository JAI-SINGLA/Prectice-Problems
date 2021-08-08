#include<iostream>
#include<unordered_map>
using namespace std;

int countSubwithGivenXor(int*a, int n, int k){
    unordered_map<int ,int>mp;
    int xxor=0;
    int count=0;
    for(int i=0;i<n;i++){
        xxor=xxor^a[i];
        if(xxor==k){
            count++;
        }
        int y=xxor^k;
        if(mp.count(y)>0){
            count+=mp[y];
        }
        mp[xxor]++;
    }
    return count;
}

int main(){
    int n;
    cin>>n;
    int *a=new int[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int k;
    cin>>k;
    cout<<countSubwithGivenXor(a,n,k);
}
