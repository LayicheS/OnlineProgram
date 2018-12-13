#include <iostream>
#include <vector>
using namespace std;
/*
 * ��Դ: ��ָOffer
 * ��Ŀ: �����еĵ�����k�����
 *
 * ����: ����һ����������������е�����k����㡣
 *
 * ˼·:
 * ˫ָ�뷨��2��ָ������ k ������
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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if (!pListHead || k == 0) return nullptr;
        ListNode* i = pListHead;
        ListNode* j = pListHead;
        for (int t = 1; t < k; ++t) {
            if (!(i -> next)) return nullptr;
            i = i -> next;
        }
        while(i -> next) {
            i = i -> next;
            j = j -> next;
        }
        return j;
    }
};