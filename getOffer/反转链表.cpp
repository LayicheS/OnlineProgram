#include <iostream>
#include <vector>
using namespace std;
/*
 * ��Դ: ��ָOffer
 * ��Ŀ: ��ת����
 *
 * ����: ����һ��������ת��������������ı�ͷ��
 *
 * ˼·:
 * A -> B -> C
 * ���ֱ�� A <- B����ô B �� C ֮������ӻ����
 * �����Ҫһ��pNext�����ֽ� C ��������
 * ���⣬����Ҫһ��pPrev����ǰ�����
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
    ListNode* ReverseList(ListNode* pHead) {
        if (!pHead || !pHead -> next) return pHead;
        ListNode* pNext = nullptr;
        ListNode* pPrev = nullptr;
        while(pHead -> next) {
            pNext = pHead -> next; //��ס��һ��
            pHead -> next = pPrev; //��ת
            // ָ��ǰ��
            pPrev = pHead;
            pHead = pNext;
        }
        pHead -> next = pPrev; //���һ���ֶ�
        return pHead;
    }
};