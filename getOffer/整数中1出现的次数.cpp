#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
 * ��Դ: ��ָOffer
 * ��Ŀ: ������1���ֵĴ���(��1��n������1���ֵĴ���)
 *
 * ����:
 * ����һ������n��ͳ��1~n��n��������1���ֵĴ���
 *
 * ˼·��
 * 1. �����λ�����λ��һͳ��1���ֵĴ���
 * 2. ���� i λ, 1�ĸ����������ڣ���ǰλ����ǰλ����λ���Լ���ǰλ��һλ
 *    ���Ƿֱ���curr, prev �� next ��ʾ
 *    2.1 ��� curr ���� 1, �� cnt += (prev + 1) * i
 *    2.2 ��� curr ���� 1, �� cnt += prev * i + next + 1
 *    2.3 ��� curr ���� 0, �� cnt += prev * i
*/
class Solution {
public:
    /**
     *
     * @param cnt[in, out] ��������
     * @param i ����λ(1, 10, 100, ...)
     * @param curr ��ǰλ
     * @param prev ���ڵ�ǰλ������λ
     * @param next ���ڵ�ǰλ����һλ
     * @return cnt
     */
    int NumberOf1Between1AndN_Solution(int n)
    {
        int cnt = 0;
        int i = 1;
        int curr, prev, next;
        while(n / i) {
            curr = n / i % 10;
            prev = n / i / 10;
            next = n - n / i * i;
            if (curr > 1) cnt += (prev + 1) * i;
            else if (curr == 1) cnt += prev * i + next + 1;
            else cnt += prev * i;
            i *= 10;
        }
        return cnt;
    }
};