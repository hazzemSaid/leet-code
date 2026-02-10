class Solution {
public:
    bool isPalindrome(int x) {
            if(x<0)
       {return false;}
         int u=x;
        int digit=0;
        while(u)
        {
          u=u/10;
          digit++;
        }
        string asd=to_string(x);
        int p=0;
        for(int i=0;i<digit;i++)
        {
          if(asd[i]==asd[digit-i-1])
          {
            p++;
          }
        }
        if(p==digit)
        {
          return true;
        }
        else
        {
          return false;
        }
    }
   
};