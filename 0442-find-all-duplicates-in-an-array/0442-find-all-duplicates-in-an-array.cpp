class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;
        int sz=int(nums.size());
        for(int i=0;i<sz;i++){
            int x=abs(nums[i]);
            if(nums[x-1]<0){
                
                ans.push_back(x);
            }
            nums[x-1]*=-1;
        }
        return ans;
    }
};