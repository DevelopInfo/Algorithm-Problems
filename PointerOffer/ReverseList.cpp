#include <iostream>

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead == nullptr)
            return nullptr;
        if(pHead->next == nullptr)
            return pHead;
        if(pHead->next->next == nullptr){
            ListNode *t = pHead->next;
            t->next = pHead;
            pHead->next = nullptr;
            return t;
        }
        
        ListNode *pre = pHead;
        ListNode *current = pHead->next;
        ListNode *after = current->next;
        pHead->next = nullptr;
        while(current != nullptr){
            current->next = pre;
            pre = current;
            current = after;
            after = after->next;
        }
        return pre;
    }
};

int main(){
    ListNode *pHead = new ListNode(1);
    for(int i = 2; i < 5; i++){
        pHead->next = new ListNode(i);
    }

    Solution s;
    pHead = s.ReverseList(pHead);

    for(int i = 1; i < 5; i++){
        cout << pHead->val << endl;
    }

    ListNode *p = pHead;
    while(p != nullptr){
        pHead = p;
        p = p->next;
        delete pHead;
    }
}