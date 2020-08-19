//定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。	

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
    ListNode* reverseList(ListNode* head) {
        ListNode* pNode = head; //当前节点
        ListNode* pPrev = nullptr; //当前节点上一节点
        ListNode* pNext = nullptr; //当前节点下一节点
        ListNode* pReverseHead = nullptr; //反转后的头节点

        while(pNode != nullptr){
            pNext = pNode->next;
            if(pNext == NULL ){
                pReverseHead = pNode;
            }
            pNode->next = pPrev;
            pPrev = pNode;
            pNode = pNext;
        }
        return pReverseHead;
    }
};