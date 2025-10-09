class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
         long long n = skill.size(),m=mana.size();
        vector< long long>dp(n,0);
        for(int j=0;j<m;j++){
            long long curmaxx=0;
            for(int i=0;i<n;i++){
                curmaxx=max(curmaxx,dp[i])+skill[i]*mana[j]*1ll;
            }            
            // cout<<curmaxx<<endl;
            dp[n-1]=curmaxx;
            for(int i=n-2;i>=0;i--){
                dp[i]=dp[i+1]-skill[i+1]*mana[j];
            }
        }
        return dp[n-1];
    }
};