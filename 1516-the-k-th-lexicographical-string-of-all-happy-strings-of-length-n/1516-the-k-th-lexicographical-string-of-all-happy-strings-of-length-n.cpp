class Solution {
public:
bool func(int n,int& k,int indx,vector<char>& ans){
    if(indx == n and k==1  ){
     return true;
    }
    if(indx == n){
        k--;
        return false;
    }
    if(!k)return false;
    for(char i='a';i<='c';i++){
        if(indx  == 0  || ans[indx-1]!=i){
            ans[indx]=i;
           if( func(n,k,indx+1,ans))return true;
            ans[indx]='-';
        }
    }
    return false;
}
    string getHappyString(int n, int k) {
        vector<char>str(n,'-');
        if(!func(n,k,0,str))return "";
        string ans="";
        for(auto &it:str)ans+=it;
        return ans;
    }
};