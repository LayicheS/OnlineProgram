#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
 * ��Դ: ��ָOffer
 * ��Ŀ: �������е���λ��
 *
 * ����:
 * ��εõ�һ���������е���λ����������������ж�����������ֵ����ô��λ������������ֵ����֮��λ���м����ֵ
 * ������������ж���ż������ֵ����ô��λ������������ֵ����֮���м���������ƽ��ֵ������ʹ��Insert()������ȡ��������ʹ��GetMedian()������ȡ��ǰ��ȡ���ݵ���λ��
 *
 * ˼·��
 * �������������飬����ң����ҵ�Ԫ�ظ��������1
 * �����ܹ���O(1)��ʱ��ȡ�������󣬺��ҵ����
 * ���Ѻ���С���ǲ����ѡ�񣬵�ȻҲ���������ȶ���
 *
 * 1. ����:
 *    1.1 �ж�Ԫ����������ż��: �����ż������ŵ��ұ�(��С��);��֮����ŵ����(����)
 *    1.2 ����������Ӧ�����Ǳ�֤��ߵ�Ԫ�ز������ұߵ�Ԫ��
 *    ����ż�����������Ӧ���ж���Ԫ���Ƿ��������Ļ�Ҫ������ǣ������ֱ�ӷŵ��ұ�;
 *    ��������Ӧ���ȷŵ���ߣ�Ȼ�����������ó������ٷŵ��ұ�
 *    �����������Ҳ��ͬ��
 *
 * 2. ȡ��λ��:
 *    2.1 ���Ԫ�ص�������ż������һ������(left_max + right_min) / 2.0
 *    2.2 ���Ԫ�ص���������������Ϊ�ұߵ�Ԫ�����Ǵ��ڵ�����ߵģ��ʴ�ʱ���Ϊż�������ұ�Ϊ������
 *    ���һ��ʱ����right_min
 *
*/
class Solution {
public:
    void Insert(int num)
    {
        const size_t size = left.size() + right.size();
        if(!(size & 1)) { // ż��ʱ����Ҫ������С��(�ұ�)
            // �ȼ�飬����Ҫ��֤������ķŵ��ұ�������˿�һ��num�ǲ��Ǳ�������Ĵ�
            if (!left.empty() && num < left.top()) {
                left.push(num);
                num = left.top(); // ���ѵ����
                left.pop();
            }
            right.push(num);
        }
        else { // ����ʱ, ��Ҫ�ŵ�����(���)
            //�ȼ�飬����Ҫ��֤�ұ���С�ķŵ�����������Ҫ��һ��num�ǲ��Ǳ��ұ���С��С
            if (num > right.top()) {
                right.push(num);
                num = right.top();
                right.pop();
            }
            left.push(num);
        }
    }
    double GetMedian()
    {
        const size_t size = left.size() + right.size();
        if (!size) throw("No");
        else if (!(size & 1)) return (left.top() + right.top()) / 2.0;
        else return double(right.top());
    }
private:
    priority_queue<int> left; // ��� ����
    priority_queue<int, vector<int>, greater<int>> right; // �ұ� ��С��
};
