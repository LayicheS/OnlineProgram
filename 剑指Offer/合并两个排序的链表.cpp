#include <iostream>
#include <vector>
using namespace std;
/*
 * ��Դ: ��ָOffer
 * ��Ŀ: �ϲ��������������
 *
 * ����: ���������������������������������ϳɺ��������Ȼ������Ҫ�ϳɺ���������㵥����������
 *
 * ˼·:
 * �����⣬�����ƽ��
 *
*/
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {
	}
};
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode* pDummy = new ListNode(0);
        ListNode* pNew = pDummy;
        while(pHead1 || pHead2) {
            int val1 = pHead1 ? pHead1 -> val : INT32_MAX;
            int val2 = pHead2 ? pHead2 -> val : INT32_MAX;
            if (val1 < val2){
                pNew -> next = pHead1;
                pHead1 = pHead1 -> next;
            } else {
                pNew -> next = pHead2;
                pHead2 = pHead2 -> next;
            }
            pNew = pNew -> next;
        }
        return pDummy -> next;
    }
};