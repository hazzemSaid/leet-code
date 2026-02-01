class Solution {
public:
    int minimumCost(vector<int>& nums) {
        vector<int>add;
       for(int i=1;i<nums.size();i++){
        add.push_back(nums[i]);
       } 
       sort(add.begin(),add.end());
       int ans=nums[0];
       return ans+add[0]+add[1];
    }
};