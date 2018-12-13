#include <iostream>
#include <vector>
using namespace std;
/*
 * ��Դ: ��ָOffer
 * ��Ŀ: �����л�����ڽڵ�
 *
 * ����: ��һ�����������а����������ҳ�������Ļ�����ڽ�㣬�������null
 *
 * ˼·:
 * ���ҵ����� k ������˼·���ƣ�����˫ָ�뷨
 * ����������л������������ָ����ٶȣ������߱�����
 * ���
 * 1. i ָ����ٶ�Ϊ1��j ָ����ٶ�Ϊ2���������Ƿ������
 * 2. ����������ʱ�������ƶ�j, ��ض����� k �����»ص� i ��λ��, k���ǻ��ĳ���
 * 3. ������i, j ָ��ͷ��㣬�� j ���� k ����Ȼ��i, j ͬ�У��״��������������
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
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if (!pHead) return nullptr;
        ListNode* i = pHead; //��ָ��
        ListNode* j = pHead; //��ָ��

        bool flag = false; //�Ƿ��л�?
        while(j -> next && j -> next -> next) {
            j = j -> next -> next;
            i = i -> next;
            if (i == j) {
                flag = true;
                break;
            }
        }
        if (!flag) return nullptr; // �޻�������

        int len = 1; // ���ĳ���
        while(j -> next != i) {
            j = j -> next;
            ++len;
        }
        i = pHead, j = pHead; // ���´�ͷ��ʼ
        for(int k = 0; k < len; ++k) j = j -> next;
        while(i != j) {
            i = i -> next;
            j = j -> next;
        }
        return i;
    }
};