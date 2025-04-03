class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int sz=nums.size();
        vector<long long>prfmax(sz,0),sufmax(sz,0);
        prfmax[0]=nums[0];
        for(int i=1;i<sz;i++){
            prfmax[i]=max(prfmax[i-1],nums[i]*1ll);
        }
        sufmax[sz-1]=nums[sz-1];
        for(int i=sz-2;i>=0;i--){
            sufmax[i]=max(sufmax[i+1],nums[i]*1ll);
        }
        long long ans=0;
        for(int i=1;i<sz-1;i++){
            // cout<<prfmax[i-1]<<" "<<nums[i]<<" "<<sufmax[i+1]<<endl;
        ans=max(ans,(prfmax[i-1]-nums[i])*sufmax[i+1]*1ll);
        }
        return ans;

    }
};