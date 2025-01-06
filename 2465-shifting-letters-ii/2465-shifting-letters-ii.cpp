class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& sh) {
        int sz=s.size();
        // make a prfix for movement the char
        vector<int>prfix(sz+1,0);
        for(int i=0;i<sh.size();i++){
            auto it=sh[i];
            // if it[2] == 1  forward 
            if(it[2] == 1){
                prfix[it[0]]+=1;
                //i add a 1 for end point to make valid prfix
                prfix[it[1]+1]+=-1;
            }
            else{
                 // if it[2] == 0  backward  
                prfix[it[0]]+=-1;
                //i add a 1 for end point to make valid prfix
                prfix[it[1]+1]+=1;
            }
        }
      
        for(int i=1;i<sz;i++){
            //make a prfix
            prfix[i]+=prfix[i-1];
        }
         for(int i = 0 ;i <sz;i++){
            if(prfix[i] <0){
                // if prfix is negative we move backword
                // i take a modelus because the letter is circle
                int cnt=abs(prfix[i])%26;
                while(cnt --){
                    //if s[i] == a -> z
                    if(s[i]=='a')s[i]='z';
                    else  s[i]--;
                }
            }else if(prfix[i]!=0){
                // if prfix is positif we move forword
                // i take a modelus because the letter is circle
                  int cnt=abs(prfix[i])%26;
                while(cnt --){
                    //if s[i] == z -> a
                    if(s[i]=='z')s[i]='a';
                    else s[i]++;
                }
            }
        }
        return s;
    }
};