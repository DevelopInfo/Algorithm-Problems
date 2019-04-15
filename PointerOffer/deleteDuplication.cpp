#include <iostream>
#include <vector>
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
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead == nullptr || pHead->next == nullptr) return pHead;
        ListNode *p = new ListNode(-1), *q = pHead;
        p->next = pHead;
        ListNode *ph = p;
        while(q != nullptr && q->next != nullptr){
            if(q->val == q->next->val){
                int val = q->val;
                while(q != nullptr && q->val == val){
                    q = q->next;
                }
                p->next = q;
            }else{
                p = q;
                q = q->next;
            }
        }
        p =  ph->next;
        delete ph;
        return p;
    }
};

int main(){
    // 建链表
    vector<int> num = {0,1,1,2,2,3,4,4,5};
    ListNode* pHead = new ListNode(num[0]);
    ListNode *p = pHead;
    for(int i = 1; i < num.size(); i++){
        p->next = new ListNode(num[i]);
        p = p->next;
    }
    Solution s;
    p = s.deleteDuplication(pHead);
    while(p != nullptr){
        cout << p->val << ", ";
        p = p->next;
    }
}