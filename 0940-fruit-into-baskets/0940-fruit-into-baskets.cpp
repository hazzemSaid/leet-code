class Solution {
public:
    int totalFruit(vector<int>& f) {
       unordered_map<int,int>s;
       int sz=f.size(),j=0;
       int ans=0;
       for(int i=0;i<sz;i++){
        s[f[i]]++;
        while(s.size()>2){
            if(--s[f[j]] == 0){
                s.erase(f[j]);
            }
            j++;
        }
        ans=max(ans,i-j+1);
       }
       return ans;
    }
};