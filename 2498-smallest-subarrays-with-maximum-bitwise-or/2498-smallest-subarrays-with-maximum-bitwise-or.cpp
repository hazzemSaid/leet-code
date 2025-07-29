class Solution {
public:
    int fun(unordered_map<int, int>& sn) {
        int cnt = 0;
        for (auto& it : sn) {
            cnt |= it.first;
        }
        return cnt;
    }
    vector<int> smallestSubarrays(vector<int>& nums) {
        vector<int> res;
        unordered_map<int, int> sm;
        int sz = nums.size();
       vector<int>maxx(sz,0);
        maxx[sz-1]=nums[sz-1];
        for(int j=sz-2;j>=0;j--){
            maxx[j]=maxx[j+1]|nums[j];
        }
       
        int l=0;
        for(int r=0;r<sz;r++){
            sm[nums[r]]++;
            while(l<=r and fun(sm)>=maxx[l]){
                res.push_back(r-l+1);
            if(--sm[nums[l]]==0)sm.erase(nums[l]);
                l++;
            }
        }
        return res;
    }
};