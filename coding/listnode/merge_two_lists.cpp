// 合并两个有序的链表，采用递归的方式

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* mergeNode = nullptr;
        if(l1 == NULL){
            return l2;
        }
        if(l2 == NULL){
            return l1;
        }
        if(l1->val <= l2->val){
            mergeNode = l1;
            mergeNode->next = mergeTwoLists(l1->next,l2); 
        }else{
            mergeNode = l2;
            mergeNode->next = mergeTwoLists(l1,l2->next);
        }
        return mergeNode;
    }
};