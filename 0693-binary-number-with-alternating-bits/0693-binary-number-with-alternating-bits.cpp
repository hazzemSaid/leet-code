class Solution {
public:
    bool hasAlternatingBits(int n) {
       int b=-1;
       while(n){
        if(n%2==1){
            if(b==1)return false;
            b=1;
        }
        else{
            if(b==0)return false;
            b=0;
        }
        n>>=1;
       }
       return true;

    }
};