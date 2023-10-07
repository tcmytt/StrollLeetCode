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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *a = new ListNode(0);
        ListNode *b = a;

        int nho =0;
        int tong=0;

        while(l1 != nullptr || l2 != nullptr){
            tong =0;
            if(l1 != nullptr){
                tong = l1->val ;
                l1 = l1->next;
            }

            if(l2 != nullptr){
                tong = tong + l2->val;
                l2 = l2->next;
            }

            if(nho == 1){
                tong = tong + 1;
            }

            if(tong >= 10){
                nho = 1;
                tong = tong - 10;
            }else{
                nho = 0;
            }

            b->next = new ListNode(tong);
            b= b->next;
        }

        if(nho == 1){
            b->next = new ListNode(nho);
        }

        return a->next;
    }
};