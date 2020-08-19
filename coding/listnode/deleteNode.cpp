/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。

返回删除后的链表的头节点
*/
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
		// 如果head 是空的 返回空值
        if(!head) {return head;}
        if(head->val == val) {return head->next;}
        ListNode* node = head;
        while(node->next->val != val && node->next != NULL){
            node = node->next;
        }
        if(node->next != NULL && node->next->val == val){
            node->next = node->next->next;
        }
        return head;
    }
};\

/* 采用递归方式 */
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if(!head) {return NULL;}
        if(head->val == val) {return head->next;}
        head->next = deleteNode(head->next,val);
        return head;
    }
};