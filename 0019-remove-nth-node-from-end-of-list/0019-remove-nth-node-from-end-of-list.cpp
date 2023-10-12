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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* tmp = head;
        int sz=0;
        while(tmp != nullptr){
            sz++;
            tmp= tmp->next;
        }
        
        
        tmp = head;
        int index = sz-n;
        
        if(sz == 1 | index == 0){
            head = head->next;
            return head;
        }
        
        
        for(int i =1;i<index;i++){
            tmp = tmp->next;
        }
        tmp->next = tmp->next->next;
        
        
        return head;
    }
};