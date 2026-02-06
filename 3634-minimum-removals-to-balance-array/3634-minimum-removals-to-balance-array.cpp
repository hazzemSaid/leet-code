class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        long long maxx=1;
        long long j=0,sz=nums.size();
        sort(nums.begin(),nums.end());
        if(k==1){
            unordered_map<int,int>mp;
            for(auto &it:nums){
                mp[it]++;
                maxx=max(maxx,1ll*mp[it]);
            }
            return sz-maxx;
        }
        for(int i=0;i<sz;i++)
        {
            while(j<i && ceil(1.00*nums[i]/nums[j])>k){
                j++;
            }
            maxx=max(maxx,(i-j)+1);
        }
        return sz-maxx;
    }
};