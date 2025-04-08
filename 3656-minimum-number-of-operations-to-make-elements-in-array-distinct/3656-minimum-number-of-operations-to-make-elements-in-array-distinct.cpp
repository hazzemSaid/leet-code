class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int end_indx=0;
        vector<int>frq(1000,0);
        int sz=nums.size();
        for(int i=sz-1;i>=0;i--){
            if(frq[nums[i]]>=1){
                end_indx=i+1;
                break;
            }
            frq[nums[i]]++;
        }
        return ceil(end_indx*1.00/3);
    }
};