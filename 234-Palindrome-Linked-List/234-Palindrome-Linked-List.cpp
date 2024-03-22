/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int>res;
    void fun(ListNode *head){
        if(head==NULL)return;
        res.push_back(head->val);
        fun(head->next);
    }
    bool valid(vector<int>r){
        vector<int>vr=r;
        reverse(vr.begin(),vr.end());
        for(int i=0;i<r.size();i++){
            if(vr[i]!=r[i])return false;
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        fun(head);
        return valid(res);
    }
};