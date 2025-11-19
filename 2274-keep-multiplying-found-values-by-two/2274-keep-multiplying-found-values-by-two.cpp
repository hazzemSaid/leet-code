class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_map<int,bool>mp;
        for(auto &it:nums){
            mp[it]=1;
        }
        while(mp.find(original) != mp.end())original*=2;
        return original;
    }
};