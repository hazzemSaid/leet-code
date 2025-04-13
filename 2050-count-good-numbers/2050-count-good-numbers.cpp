class Solution {
public:
int mod=int(1e9)+7;
long long fastPower(long long a, long long b) {
  if(b==0) return 1;
  long long ans = fastPower(a,b/2);
  ans=((ans%mod)*(ans%mod))%mod;
  if(b&1)
    return ((a%mod)*(ans%mod))%mod;
  return ans;
}
    int countGoodNumbers(long long n) {
    long long cnt=((n+1)/2);
    cout<<cnt<<endl;
    long long x=fastPower(5,cnt);
    long long y=fastPower(4,cnt-(n%2));
    return ((x%mod)*(y%mod))%mod;
    }
};