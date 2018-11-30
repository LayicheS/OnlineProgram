#include <iostream>
#include <string>
using namespace std;
/*
 * ��Դ: ��ָOffer
 * ��Ŀ: ����������ĳһλ������
 *
 * ����:
 * ������ 0123456789101112131415...�ĸ�ʽ���л���һ���ַ�������
 * ����������У���5λ(��0��ʼ����)��5����13λ��1����19λ��4�ȵ�
 * ��дһ���������������nλ��Ӧ������
 *
 * ˼·��
 * 1. Brute-Force
 * 2. ���ս�ָoffer 225 ҳ
*/
class Solution {
public:
    int solve1(int n)
    {
        if (n < 0) throw ("Invalid input.");
        string seq = "";
        int i = 0;
        while(seq.size() < n + 1) {
            seq += to_string(i);
            ++i;
        }
        return seq[n] - '0';
    }
    int solve2(int n) {
        if (n < 0) throw ("Invalid input.");
        if (n < 10) return n;
        int cnt = 10, i = 2, len = 90;
        while(n > cnt + i * len) {
            cnt += i * len;
            ++i;
            len *= 10;
        }
        int base = len / 9, num = base + (n - cnt) / i, bit = (n - cnt) % i;
        return to_string(num)[bit] - '0';
    }
};
