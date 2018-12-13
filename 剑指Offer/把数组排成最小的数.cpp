#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
/*
 * ��Դ: ��ָOffer
 * ��Ŀ: �������ų���С����
 *
 * ����:
 * ����һ�����������飬����������������ƴ�������ų�һ����
 * ��ӡ��ƴ�ӳ���������������С��һ�������磬��������{3, 32, 321}
 * ���ӡ����3���������ųɵ���С����Ϊ321323
 *
 * ˼·��
 * �Ƚ���������ת�����ַ������飬�Զ���������
 * return a+ b > b + a
 * ��Ч��������Ҫ��3���Ƕ�ȥ֤��:
 * �Է��ԣ��Գ����Լ�������
*/
bool cmp(string a, string b) {
    return a + b < b + a;
}
class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        vector<string> strNums;
        for (int i : numbers) strNums.push_back(to_string(i));
        sort(strNums.begin(), strNums.end(), cmp);
        string rlt = "";
        for (string s : strNums) rlt += s;
        return rlt;
    }
};
int main() {
    vector<int > num = {3, 32, 321};
    Solution s;
    cout << s.PrintMinNumber(num) << endl;
}
