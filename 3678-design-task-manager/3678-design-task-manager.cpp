#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class TaskManager {
    struct Task {
        int pr;
        int taskId;
        bool operator<(const Task& other) const {
            if (pr == other.pr) return taskId < other.taskId; 
            return pr < other.pr; // higher priority first
        }
    };

    priority_queue<Task> pq;
    unordered_map<int,int> tofinduser; // taskId -> userId
    unordered_map<int,int> taskpr;     // taskId -> pr

public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto &t : tasks) {
            int userId = t[0], taskId = t[1], pr = t[2];
            tofinduser[taskId] = userId;
            taskpr[taskId] = pr;
            pq.push({pr, taskId});
        }
    }

    void add(int userId, int taskId, int priority) {
        tofinduser[taskId] = userId;
        taskpr[taskId] = priority;
        pq.push({priority, taskId});
    }

    void edit(int taskId, int newPriority) {
        if (taskpr.find(taskId) == taskpr.end()) return;
        taskpr[taskId] = newPriority;
        pq.push({newPriority, taskId}); // old version left in heap (lazy deletion)
    }

    void rmv(int taskId) {
        tofinduser.erase(taskId);
        taskpr.erase(taskId);
        // lazy deletion: don't touch pq
    }

    int execTop() {
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            // check validity
            if (taskpr.find(top.taskId) != taskpr.end() && taskpr[top.taskId] == top.pr) {
                int userId = tofinduser[top.taskId];
                rmv(top.taskId);
                return userId;
            }
        }
        return -1;
    }
};
