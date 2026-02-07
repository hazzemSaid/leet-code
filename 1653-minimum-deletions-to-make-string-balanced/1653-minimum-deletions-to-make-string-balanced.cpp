class Solution {
public:
    int minimumDeletions(string s) {
        int sz=s.size();
        vector<int>a(sz,0),b(sz,0);
        int cnt=0;
        for(int i=0;i<sz;i++){
                b[i]=cnt;
                if(s[i]=='b')cnt++;
        }
        cnt=0;
        for(int i = sz-1;i>=0;i--){
            a[i]=cnt;
            if(s[i]=='a')cnt++;
        }
        int res=INT_MAX;
        for(int i=0;i<sz;i++){
            res=min(res,a[i]+b[i]);
        }
        return res;
    }
};