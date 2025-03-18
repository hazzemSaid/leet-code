class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int l=0;
        int mask=0;
        int ans=0;
        int sz=nums.size();
        for(int r=0;r<sz;r++){
            while((mask & nums[r]) != 0){
                mask^=nums[l++];
            }
            mask|=nums[r];
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};