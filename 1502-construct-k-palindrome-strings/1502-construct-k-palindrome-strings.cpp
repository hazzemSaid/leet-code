class Solution {
public:
    bool canConstruct(string s, int k) {
        if(k>s.size())return false;
        //frequence for all char from a to z
        vector<char>frq(26,0);

        for(auto &it:s){
            frq[it-'a']++;
        }
        // using the oddfrq to count the number of odd frequence char in s
        int oddfrq=0;
        for(int i=0;i<26l;i++){

            if(frq[i] % 2 == 1)oddfrq++;
        }

        return (k>=oddfrq);

    }
};