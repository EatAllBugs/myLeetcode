/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        //这道题不要用递归解决，耗费时间太多
        //构成循环链表，尾指针指向头节点，倒数第二个节点指向空指针
        if(!head || !head->next || k == 0){
            return head;
        }
        int len= 1;
        ListNode* tmp = head;
        while(tmp->next){
            ++len;
            tmp = tmp->next;
        }
        k = k % len;
        if(k == 0){
            return head;
        }
        tmp->next = head;
        ListNode* dummy = head;
        int num1 = len-k-1;
        int num2 = len-k;
        while(num1){
            --num1;
            dummy = dummy->next; 
        }
        while(num2){
            --num2;
            head = head->next;
        }
        dummy->next = NULL;
        return head;

    }
};