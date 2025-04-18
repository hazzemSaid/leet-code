class Solution {
public:
string countAndSaysol(int n,int l,string str){
    if(l == n)return str;
    str=fun(str);
    return countAndSaysol(n,l+1,str);
}
string fun(string str){
    string s="";
    int sz=str.size();
    if(sz  == 0)return "1";
    for(int i=0;i<sz;i++){
        int cnt=1;
        char x= str[i];
        while(i+1<sz and x==str[i+1]){cnt++;i++;}
        s+=to_string(cnt)+x;
    }
    return s;

}
    string countAndSay(int n) {
            return countAndSaysol(n,0,"");
    }
};