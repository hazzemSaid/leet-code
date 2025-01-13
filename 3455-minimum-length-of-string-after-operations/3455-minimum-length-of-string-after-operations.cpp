class Solution {
public:
    int minimumLength(string s) {
        int cnt=0;
        //the approch if even frq -> increase 2 
        //the approch if odd frq -> increase 1
        int frq[26]{0};
        for(auto &it:s)frq[it-'a']++;
        for(int i=0;i<26;i++){
            if(frq[i] == 0)continue;
            if(frq[i]%2==0 ){
                cnt+=2;
            }
            else{
                cnt++;
            }
        } 
        return cnt;
    }
};