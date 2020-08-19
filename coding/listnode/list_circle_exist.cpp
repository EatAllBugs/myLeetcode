/*
  判断链表是否有环
  穷举法简单，但是时间复杂度太高，所以直接放弃。
  快慢指针法：
 （1）定义两个指针分别为 slow，fast，并且将指针均指向链表头节点。
 （2）规定，slow 指针每次前进 1 个节点，fast 指针每次前进两个节点。
 （3）当 slow 与 fast 相等，且二者均不为空，则链表存在环。
*/

bool isExistLoop(ListNode* head){
	ListNode* fast = head; //快指针
	ListNode* slow = head;	
	while(fast->next != NULL && slow->next != NULL){
		fast = fast->next->next;
		slow = slow->next;
		if(fast->val == slow->val){
			return true;
		}
	}
	return false;
}
/*
  找到相遇节点

*/
ListNode* getMeetingNode(ListNode* head){
	ListNode* slow = head;	
	while(fast->next != NULL && slow->next != NULL){
		fast = fast->next->next;
		slow = slow->next;
		if(fast->val == slow->val){
			return fast;
		}
	}
	return NULL;
}

/*
  定位环入口
*/

ListNode* getEntryNode(ListNode* head){
	ListNode* meetingNode = getMeetingNode(head);
	if(meetingNode == NULL){
		return NULL;
	}
	ListNode* p1 = meetingNode;
	ListNode* p2 = head;
	while(p1 != p2){
		p1 = p1->next;
		p2 = p2->next;
	}
	return p1;	
}

/*
  求出环的长度
  第一次相遇先break，接着循环，第二次相遇，记下走了多长，返回值即为环的长度
*/
int getLoopLength(ListNode* head){
	ListNode* fast = head; //快指针
	ListNode* slow = head;	
	while(fast->next != NULL && slow->next != NULL){
		fast = fast->next->next;
		slow = slow->next;
		if(fast->val == slow->val){
			break;
		}
	}
    slow = slow->next;
	fast = fast->next;
	int length = 0;
	while(fast != slow){
		fast = fast->next->next;
		slow = slow->next;
		length++;	
	}
	return length;
}









