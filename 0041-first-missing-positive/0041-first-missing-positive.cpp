class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        bool check=0;
        for(auto it:nums){
            if(it==1){check=1;}
        }
        if(!check)return 1;
        if(nums.size()==1)return 2;
        int b=0;
        for(int i=0;i<nums.size();i++){
         if(nums[i]==nums.size())b=1;
            if(nums[i]<=0 || nums[i]>=nums.size())nums[i]=1;
        }
         for(int i=0;i<nums.size();i++){
         int x=abs(nums[i]);
         if(nums[x]<0)continue;
            nums[x]*=-1;
        }
        for(int i=1;i<nums.size();i++){
            if(nums[i]>0)return i;
        }
        return nums.size()+b;
    }
};