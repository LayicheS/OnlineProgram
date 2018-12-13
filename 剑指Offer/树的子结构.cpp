#include <iostream>
#include <vector>
using namespace std;
/*
 * ��Դ: ��ָOffer
 * ��Ŀ: �����ӽṹ
 *
 * ����: �������ö�����A��B���ж�B�ǲ���A���ӽṹ����ps������Լ��������������һ�������ӽṹ��
 *
 * ˼·:
 * ����Ҫ����A���ҵ�һ����㣬�ý���ֵ�� B ���ĸ��ڵ�ֵһ��
 * �ҵ�������һ�Ƚ���������
 *
*/

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
    bool isSubEqual(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if (!pRoot2) return true;
        if (!pRoot1) return false;
        if (pRoot1 -> val == pRoot2 -> val)
            return isSubEqual(pRoot1 -> left, pRoot2 -> left) && isSubEqual(pRoot1 -> right, pRoot2 -> right);
        else
            return false;
    }
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if (!pRoot1 || !pRoot2) return false; //�����������������ӽṹ
        bool flag = false;
        if (pRoot1 -> val == pRoot2 -> val){
            flag = isSubEqual(pRoot1, pRoot2);
        }
        if (!flag) { //���ͷ��ƥ��
            flag = HasSubtree(pRoot1 -> left, pRoot2);
        }
        if (!flag) { //��������Ҳ��ƥ�䣬���������Ҷ���
            flag = HasSubtree(pRoot1 -> right, pRoot2);
        }
        return flag;
    }
};