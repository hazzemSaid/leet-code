class Solution {
public:
bool func(int indx,string& pattern,vector<char> &ans,vector<bool>&use){
    if(indx == pattern.size())return true;

    for(char i='1';i<='9';i++){
        if(!use[i]){
            if(pattern[indx] == 'I' and ans[indx]<i){
            //I
            ans[indx+1]=i;
            use[i]=1;
            if(func(indx+1,pattern,ans,use))return true;
            use[i]=0;
            ans[indx+1]='-';
            }
            else if(ans[indx]>i){
            //D
            ans[indx+1]=i;
            use[i]=1;
            if(func(indx+1,pattern,ans,use))return true;
            use[i]=0;
            ans[indx+1]='-';
            }
        }
    }
    return false;
}
    string smallestNumber(string pattern) {
        int sz=pattern.size();
        vector<char>ans(sz+1,'-');
        vector<bool>use(900,false);
       
        if(pattern[0]=='I'){ ans[0]='1';use['1']=1;}
        else {
          int t=0;
          while(sz>t and pattern[t]=='D')t++;
          ans[0]='1'+t;
          use['1'+t]=1; 
            }
        func(0,pattern,ans,use);
        string res="";
        for(auto &it:ans){
            res+=it;
        }
        return res;
    }
};