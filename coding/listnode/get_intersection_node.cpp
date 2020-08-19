/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/* 
我们使用两个指针 node1，node2 分别指向两个链表 headA，headB 的头结点，然后同时分别逐结点遍历，当 node1 到达链表 headA 的末尾时，重新定位到链表 headB 的头结点；当 node2 到达链表 headB 的末尾时，重新定位到链表 headA 的头结点。
*/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* node1 = headA; //node1 代指 headA 
        ListNode* node2 = headB; //node2 代指 headB
		//当node1和node2相遇时结束遍历，返回相遇节点
        while(node1 != node2){
			// 当node1 遍历结束 指向headB
            node1 = node1 != NULL ? node1->next : headB;
			// 当node2遍历结束  指向headA
            node2 = node2 != NULL ? node2->next : headA;
        }
        return node1;
    }
};