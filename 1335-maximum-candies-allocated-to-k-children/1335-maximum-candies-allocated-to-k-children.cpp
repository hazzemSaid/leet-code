class Solution {
public:
int binary(vector<int>&cand, long long  k){
    int l=1,r=*max_element(cand.begin(),cand.end());
    int ans=0;
    while(l<=r){
        int mid=(l+r)>>1;
        if(valid(cand,mid) >= k){
            l=mid+1;
            ans=mid;
        }
        else r=mid-1;
    }
    return ans;
}
long long valid(vector<int>&cand,int mid){
    long long  cnt=0;
    for(int i=0;i<cand.size();i++){
        cnt+=cand[i]/mid;        
    }
    return cnt;
}
    int maximumCandies(vector<int>& candies, long long k) {
     return    binary(candies,k);
    }
};