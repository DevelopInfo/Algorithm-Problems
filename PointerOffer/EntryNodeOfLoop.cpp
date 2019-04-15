#include <iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(pHead == nullptr) return nullptr;
        //计算环的长度
        ListNode *p = pHead, *q = pHead->next;
        int cout1 = 1, cout2 = 2;
        while(p != q){
            p = p->next;
            if(q != nullptr && q->next != nullptr )
            {
                q = q->next->next;
            }
            else
            {
                return nullptr;
            }
            
            cout1 += 1;
            cout2 += 2;
        }
        int loopLen = cout2-cout1-1;
        p = pHead; q = pHead->next;
        while(p != q){
            if(loopLen <= 0){
                p = p->next;
            }
            loopLen--;
            q = q->next;
        }
        return p;
    }
};

int main(){
    // 建链表
    ListNode* pHead = new ListNode(1);
    ListNode *p = pHead;
    ListNode *q;
    for(int i = 2; i < 5; i++){
        p->next = new ListNode(i);
        p = p->next;
        if(i == 3) q = p;
    }
    p->next = q;

    Solution s;
    p = s.EntryNodeOfLoop(pHead);
    cout << p << endl;
    cout << p->val << endl;
}