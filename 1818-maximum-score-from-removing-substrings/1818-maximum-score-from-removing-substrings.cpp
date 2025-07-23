class Solution {
public:
int res (string s,int x,char h,char l,stack<char>&st){
    int sz=s.size();
    int cnt=0;
     for (int i = 0; i < sz; i++) {
                if (!st.empty() and st.top() == h and s[i] == l) {
                    cnt += x;
                    st.pop();
                } else {
                    st.push(s[i]);
                }
            }
            return cnt;
}
    int maximumGain(string s, int x, int y) {
        stack<char> st;
        int sz=s.size();
        int cnt=0;
        if(x>=y){
            //ab>ba
            cnt+=res(s,x,'a','b',st);
            string ns="";
            while(!st.empty()){
                ns+=st.top();
                st.pop();
            }
            reverse(ns.begin(),ns.end());
            cnt+=res(ns,y,'b','a',st);
        }
        else{
              cnt+=res(s,y,'b','a',st);
            string ns="";
            while(!st.empty()){
                ns+=st.top();
                st.pop();
            }
            reverse(ns.begin(),ns.end());
            cnt+=res(ns,x,'a','b',st);
        }
        return cnt;
    }
};