class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans=0,cur=1,prv=0;
        for(int i=1;i<s.size();i++){
            if(s[i-1]==s[i])cur++;
            else{
                prv=cur;
                cur=1;
            }
            if(cur<=prv)ans++;
        }
        return ans;
    }
};