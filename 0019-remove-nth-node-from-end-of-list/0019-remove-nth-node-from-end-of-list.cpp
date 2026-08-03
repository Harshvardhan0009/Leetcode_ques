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
        // ListNode *temp = head;\
        // int count=0;
        // while(temp!=nullptr){
        //     count++;
        //     temp=temp->next;
        // }
        // if(count == n){
        //     return head->next;
        // }
        // int step = count-n-1;
        // ListNode *extra = head;
        // for(int i=0; i<step; i++){
        //     extra = extra->next;
        // }
        // extra->next = (extra->next)->next;
        // return head;
        // now with fast and slow pointer
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *slow = dummy;
        ListNode *fast = dummy;
        for(int i=0; i<=n; i++){
            fast = fast->next;
        }
        while(fast!=nullptr){
            slow = slow->next;
            fast = fast->next;
        }
        slow->next=slow->next->next;
        return dummy->next;
    }
};