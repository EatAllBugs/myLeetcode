/*
链表排序：
归并排序，归并的思想是不停的寻找链表的中间位置，并且通过递归将整个链表拆分成多个长度为1或者2的小链表。
在基础上按大小顺序合并成新的链表。这个思想在数组的排序中很好理解，但是在链表的排序中需要注意
a.将每段最后一个元素的next域指向空；
b.构造一个next域指向合并后有序链表的第一个节点的虚拟指针；由此可见总的时间复杂度为O(nlogn)。
*/

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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *fast = head, *slow = head;
        ListNode *middle = findMiddle(fast, slow); // 快慢指针找出中点
        return mergeSort(sortList(head), sortList(middle)); // 用了递归
    }
    ListNode *findMiddle(ListNode *fast, ListNode *slow)
    {
        ListNode *cut;
        while(fast && fast->next)
        {
            cut = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        cut -> next = nullptr; // 这一步很重要！需要把前半部分和后半部分断开
        return slow;
    }
    ListNode *mergeSort(ListNode *head, ListNode *mid)
    {
        ListNode *sorted = new ListNode(5201314);
        ListNode *pos = sorted;
        while(head && mid)
        {
            if(head->val < mid->val)
            {
                pos -> next = head;
                head = head -> next;
            }
            else
            {
                pos -> next = mid;
                mid = mid -> next;
            }
            pos = pos -> next;
        }
        pos -> next = head == nullptr ? mid : head;
        return sorted -> next;
    }
};