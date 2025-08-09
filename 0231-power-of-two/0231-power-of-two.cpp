class Solution {
public:
    bool isPowerOfTwo(int n) {
       int cnt=0;
        if(n <= 0)return false;
       while(n){
        if(n%2 == 1){
            if(cnt)return false;
            cnt++;
        }
        n/=2;
       }
       return 1;
    }
};