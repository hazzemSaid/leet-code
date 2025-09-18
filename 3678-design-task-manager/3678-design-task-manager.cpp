class TaskManager {
public:
//taskid - > userid
map<int,int>tofinduser;
map<int,set<int>>higherproirtytaskfind;
// -pr -> front * -1 -> higher task
map<int,int>taskpr;
//taskid -> pr
// void printx(){
//     cout<<"----------------------"<<endl;
//      for(auto it:higherproirtytaskfind){
//             cout<<it.first<<"->";
//             for(auto item:it.second){
//                 cout<<item<<" ";
//             }
//             cout<<endl;
//         }
// }
    TaskManager(vector<vector<int>>& tasks) {
        for(auto it:tasks){
            int userid=it[0];
            int taskid=it[1];
            int pr=it[2];
            tofinduser[taskid]=userid;
            taskpr[taskid]=pr;
            higherproirtytaskfind[-pr].insert(-taskid);
        }
    //    printx();
    }
    
    void add(int userId, int taskId, int priority) {
          tofinduser[taskId]=userId;
            taskpr[taskId]=priority;
            higherproirtytaskfind[-priority].insert(-taskId);
            // printx();
    }
    
    void edit(int taskId, int newPriority) {
        int oldpr=taskpr[taskId];
        higherproirtytaskfind[-oldpr].erase(-taskId);
        if( higherproirtytaskfind[-oldpr].empty()){
             higherproirtytaskfind.erase(-oldpr);
        }
        higherproirtytaskfind[-newPriority].insert(-taskId);
        taskpr[taskId]=newPriority;
        // printx();
    }
    
    void rmv(int taskId) {
        cout<<taskId<<endl;
        int oldpr=taskpr[taskId];
        tofinduser.erase(taskId);
        taskpr.erase(taskId);
        higherproirtytaskfind[-oldpr].erase(-taskId);
          if( higherproirtytaskfind[-oldpr].empty()){
             higherproirtytaskfind.erase(-oldpr);
        }
        // cout<<"rmv----------"<<endl;
        // printx();
    }
    
    int execTop() {
        // printx();
        if(higherproirtytaskfind.empty())return -1;
        int res=tofinduser[(*higherproirtytaskfind.begin()->second.begin()) * -1];
        rmv((*higherproirtytaskfind.begin()->second.begin())*-1);
        return res;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */