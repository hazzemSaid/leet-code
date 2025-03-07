class Solution {
public:
void findprime(vector<int>&primes,int right){
    vector<bool>vis(right+1,false);
    for(int i=2;i<=right;i++){
        if(!vis[i]){
            primes.push_back(i);
            for(int j=i;j<=right;j+=i){
                vis[j]=1;
            }
        }
    }
}
    vector<int> closestPrimes(int left, int right) {
        vector<int>primes;
        findprime(primes,right);
        auto l=lower_bound(primes.begin(),primes.end(),left)-primes.begin();
        auto r=upper_bound(primes.begin(),primes.end(),right)-primes.begin();
        cout<<l<<" "<<r<<endl;
        int minn=INT_MAX;
        vector<int>ans(2,-1);
        for(auto it:primes)cout<<it<<" ";
        if(l+1 == primes.size())return {-1,-1};
        cout<<endl;
        for(int indx=l;indx<r-1;indx++){
            if(minn>primes[indx+1]-primes[indx]){
                ans[0]=primes[indx];
                ans[1]=primes[indx+1];
                minn=primes[indx+1]-primes[indx];
            }
        }
        return ans;
    }
};