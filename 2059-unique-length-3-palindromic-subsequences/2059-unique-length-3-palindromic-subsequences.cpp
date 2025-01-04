class Solution {
public:
int duplicate(int l,int r, vector<vector<int>>&frq){
    int cnt=0;
    for(char i = 'a';i<='z' ;i++){
        //if have dublicated char more than 1 
        if(frq[r][i-'a']-frq[l][i-'a'] >1)
        cnt+=(frq[r][i-'a']-frq[l][i-'a'])-1;
    }
    return cnt;
}
    int countPalindromicSubsequence(string s) {
        int sz=s.size();

        //make the mapping to store the minmum index for char i-th
        map<char,int>mp;
        //make frequence for all char from 'a' to 'z' into all ith
        vector<vector<int>>frq;
        //globel frequence 
        vector<int>f(500,0);

        for(int i=0;i<sz;i++){
            //if not found this is a minimum index for char ith
            if(mp.find(s[i]) == mp.end()){
                mp[s[i]]=i;
            }
            //add into globel frequence
            f[s[i]-'a']++;
            //add into ith
            frq.push_back(f);
        }
      
        int cnt=0;

        //start from end until r == 0
        int r=sz-1;
        while(r>0){
            //if i found the char ->> r - (minimum indx + 1)
            if(mp.find(s[r]) !=mp.end() and r!=mp[s[r]]){
                //calculate the duplicate (from r-1 to minimum indx )
                int d=duplicate(mp[s[r]],r-1,frq);
                //add the value 
                cnt+=r-(mp[s[r]] + 1)-d;

                //becuse i already add the all subsequence
                mp.erase(s[r]);
            }
            //decreasing the r
            r--;
        }  
        return cnt;     
    }
};