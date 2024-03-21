class Solution {
public:
    int bagOfTokensScore(vector<int>& t, int p) {
   int maxx=0;
   int s=0;
   sort(t.begin(),t.end());
   if(t.size() and t[0]>p)return 0;
   int l=0,r=t.size()-1;     
while(l<=r){
    if(p>=t[l]){
        p-=t[l++];
        s++;
    }
    else if(s){
        p+=t[r--];
        s--;
    }
    else{break;}
        maxx=max(maxx,s);

}
cout<<l<<" "<<r<<endl;
return maxx;
    }
};