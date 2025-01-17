class Solution {
public:
    bool doesValidArrayExist(vector<int>& d) {
       int xorr=0;
       for(auto &it:d){
        xorr^=it;
       }
       return !(xorr);
    }
};