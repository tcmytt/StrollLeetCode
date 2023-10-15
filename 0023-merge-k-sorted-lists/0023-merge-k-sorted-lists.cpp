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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        ListNode* ans = dummy;

        while (list1 && list2) {
            if (list1->val < list2->val) {
                ans->next = list1;
                list1 = list1->next;
            } else {
                ans->next = list2;
                list2 = list2->next;
            }
            ans = ans->next;
        }

        if (list1) {
            ans->next = list1;
        } else {
            ans->next = list2;
        }

        return dummy->next;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (n == 0) {
            return nullptr;
        }

        while (n > 1) {
            int k = (n + 1) / 2;
            for (int i = 0; i < n / 2; i++) {
                lists[i] = mergeTwoLists(lists[i], lists[i + k]);
            }
            n = k;
        }

        return lists[0];
    }
};