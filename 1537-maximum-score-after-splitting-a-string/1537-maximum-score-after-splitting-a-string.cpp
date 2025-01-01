class Solution {
public:
    int maxScore(string s) {
        int sz=s.size();
        //build the prfix for zeros 
        vector<int>prfix(sz);
        //build the sufix for ones 
        vector<int>sufix(sz);
        prfix[0]=(s[0] == '0')?1:0;
        for(int i = 1 ;i<sz;i++){
           if(s[i] == '0'){
            prfix[i]+=prfix[i-1]+1;
           } 
           else
            prfix[i]+=prfix[i-1];
        }
         sufix[sz-1]=(s[sz-1] == '1')?1:0;
        for(int i = sz-2 ;i>=0;i--){
           if(s[i] == '1'){
            sufix[i]+=sufix[i+1]+1;
           } 
           else
            sufix[i]+=sufix[i+1];
        }
        int maxx=0;
        for(int i=0;i<sz-1;i++){
            // the maxx equal the sum of both prfix (i) and sufix (i+1)
            maxx=max(maxx,prfix[i]+sufix[i+1]);
        }
        return maxx;

    }
};