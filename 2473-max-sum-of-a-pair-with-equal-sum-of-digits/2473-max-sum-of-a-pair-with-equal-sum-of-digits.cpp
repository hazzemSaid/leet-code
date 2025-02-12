class Solution {
public:
int sum_digits(int x){
    int sum=0;
    while(x){
        sum+=x%10;
        x/=10;
    }
    return sum;
}
    int maximumSum(vector<int>& nums) {
        map<int,vector<int>>mp;
        for(auto &it:nums){
            int sum_digit=sum_digits(it);
            mp[sum_digit].push_back(it);
        }
        int maxx=-1;
        for(auto &it:mp){
            if(it.second.size()>=2){
                sort(it.second.rbegin(),it.second.rend());
                maxx=max(maxx,it.second[0]+it.second[1]);
            }
        }
        return maxx;
    }
};