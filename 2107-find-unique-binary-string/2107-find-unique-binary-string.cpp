class Solution {
public:
map<string,bool>mp;
string ans;
bool func(int indx,int sz,string str){
    if(indx == sz){ 
        if(!mp[str]){
            ans=str;
            return true;
            }
        return false;
    }
    return (func(indx+1,sz,str+'1')||func(indx+1,sz,str+'0'));
}
    string findDifferentBinaryString(vector<string>& nums) {
        string str="";
        int sz=nums[0].size();
        for(auto &it:nums){
            mp[it]=1;
        }
        func(0,sz,str);
        return ans;
    }
};