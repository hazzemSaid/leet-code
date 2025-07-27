class Solution {
public:
    int countHillValley(vector<int>& nums) {
        // set<int>s;
        // vector<int>dn;
        // int sz=nums.size();
        // for(int i=0;i<sz;i++){
        //     if(s.find(nums[i]) == s.end()){
        //         s.insert(nums[i]);
        //         dn.push_back(nums[i]);
        //     }
        // }
        // sz=dn.size();
        // if(sz<=2)return 0;
        // int cnt=0;
        // // for(auto &it:dn)cout<<it<<" ";
        // for(int i=1;i<sz-1;i++){
        //     if(dn[i-1]>dn[i] and dn[i+1]>dn[i]) 
        //         cnt++;
        //     if(dn[i-1]<dn[i] and dn[i+1]<dn[i]) 
        //         cnt++;
        // }
        // return cnt;
        int sz=nums.size(),j=1;
        if(sz<=2)return 0;
        int cnt=0;
        for(int i=1;j<sz;){
            if(nums[i]==nums[j]){
                j++;
                continue;
            }
            if(nums[i-1]>nums[i] and nums[i]<nums[j]){
                i=j;
                j++;
                cnt++;
            }
            else if(nums[i-1]<nums[i] and nums[i]>nums[j]){
                i=j;
                j++;
                cnt++;
            }
            else{
                i=j;
                j++;
            }
        }
        return cnt;
    }
};