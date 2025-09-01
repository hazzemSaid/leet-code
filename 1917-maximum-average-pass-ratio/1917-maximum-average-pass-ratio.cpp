class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
       priority_queue<pair<double,pair<int,int>>>q;
       for(auto &it:classes){
        double x=((it[0]*1.00)/(it[1]*1.00));
        double y=(((it[0]+1)*1.00)/((it[1]+1)*1.00));
        q.push({y-x,{it[0],it[1]}});
       }
       while(extraStudents--){
       auto it=q.top();
       q.pop();
        double x=(1.00*(it.second.first+1))/(it.second.second+1)*1.00;
        double y=(1.00*(it.second.first+2))/(it.second.second+2)*1.00;
        q.push({(y-x),{it.second.first+1,it.second.second+1}});
       }
      double ans=0;
      while(q.empty()  == false){
        auto it=q.top();
        q.pop();
        ans+=it.second.first/(it.second.second*1.00);
      }
      return (ans/classes.size());
    }
};