class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        for(auto &it:nums){
            int res=-1;
            int x=1;
            while((it&x)!=0){
                res=it-x;
                x<<=1;
            }
            it=res;
        }
        return nums;
    }
};