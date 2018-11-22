#include <iostream>
#include <vector>
using namespace std;
/*
 * ��Դ: ��ָOffer
 * ��Ŀ: ����
 *
 * ����: ��ֻ����������2��3��5��������������Ugly Number��
 * ����6��8���ǳ�������14���ǣ���Ϊ������������7�� ϰ�������ǰ�1�����ǵ�һ������
 * �󰴴�С�����˳��ĵ�N������
 *
 * ˼·:
 * ���
 * 1. ���г�ʼ��� 1
 * 2. ���������ڱ����Ѿ���ǰ N - 1 ����˳�����еĳ���ʱ���� N ������һ��ʱǰN - 1���һ����
 * �� ��2 �� ��3 ���5 ����
 * ��ˣ�����һ�����飬ȡ֮���л��2 ���3 ���5����С�ģ��ָպô��ڵ�N - 1��������
 *
*/

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if (index <= 1) return index;
        int rlt[index + 1];
        rlt[1] = 1;
        for (int i = 2; i <= index; ++i) {
            //���ڼ���� i ��
            int j, M2, M3, M5;
            for (j = 1; j < i; ++j)
                if (rlt[j] * 5 > rlt[i - 1]) {M5 = rlt[j] * 5; break;}
            for (j = 1; j < i; ++j)
                if (rlt[j] * 3 > rlt[i - 1]) {M3 = rlt[j] * 3; break;}
            for (j = 1; j < i; ++j)
                if (rlt[j] * 2 > rlt[i - 1]) {M2 = rlt[j] * 2; break;}
            rlt[i] = (M5 < M3 ? M5 : M3) < M2 ? (M5 < M3 ? M5 : M3) : M2;
        }
        return rlt[index];
    }
};
