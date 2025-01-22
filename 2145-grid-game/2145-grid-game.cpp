class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n=grid[0].size();
        vector<long long>prfix(n),sufix(n);
        prfix[0]=grid[0][0];
        for(int i=1;i<n;i++)prfix[i]+=grid[0][i]+prfix[i-1];
        sufix[n-1]=grid[1][n-1];
        for(int i=n-2;i>=0;i--)sufix[i]+=grid[1][i]+sufix[i+1];
        long long st1=prfix[n-1];
        long long st2=sufix[0];
        // for(int i=0;i<n;i++)cout<<prfix[i]<<" ";
        // cout<<endl;
        // for(int i=0;i<n;i++)cout<<sufix[i]<<" ";
        // cout<<endl;
        long long maxx=LONG_LONG_MAX;
        for(int i=0;i<n;i++){
          maxx=min(maxx*1ll,1ll*max(st2-sufix[i],st1-prfix[i]));
        }
     
        return maxx;
    }
};