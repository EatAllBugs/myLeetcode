/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /* 
 输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。例如，一个链表有6个节点，从头节点开始，它们的值依次是1、2、3、4、5、6。这个链表的倒数第3个节点是值为4的节点。
 
 */
 /*
（1）遍历单链表，遍历同时得出链表长度 N 。
（2）再次从头遍历，访问至第 N - K 个节点为所求节点。
 这种方法时间复杂度是n*n。遍历了两次
 */
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if(!head) return NULL;
        int n = 0;
        ListNode* p = head;
        while(p->next){
            ++n;
            p = p->next;
        }
        int l = n-k+1;
        while(head->next && l){
            --l;
            head = head->next;
        }
        return head;
    }
};
/*
双指针法，笔试中最常见。一般只回答这个
定义两个指针pi,p2都指向头节点，p1向前移动k次，p2保持不动，然后两者同时向后移动
当p1指向尾节点时，p2指向了K节点。
*/
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
		ListNode* p1 = head;
		ListNode* p2 = head;
		while((k-1)--){
			p1 = p1->next;
		}
		while(p1->next){
			p1 = p1->next;
			p2 = p2->next;
		}
		return p2;
										
};




















