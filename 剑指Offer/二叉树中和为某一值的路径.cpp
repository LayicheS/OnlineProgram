#include <iostream>
#include <vector>
using namespace std;
/*
 * ��Դ: ��ָOffer
 * ��Ŀ: �������к�Ϊĳһֵ��·��
 *
 * ����: ����һ�Ŷ������ĸ��ڵ��һ����������ӡ���������н��ֵ�ĺ�Ϊ��������������·��
 * ·������Ϊ�����ĸ���㿪ʼ����һֱ��Ҷ����������Ľ���γ�һ��·��
 * (ע��: �ڷ���ֵ��list�У����鳤�ȴ�����鿿ǰ)
 *
 * ˼·:
 * ���ݷ�
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
bool cmp(vector<int>& a,vector<int>& b){
    return a.size() > b.size();
}
class Solution {
public:
    void backTrack(TreeNode* crt, vector<vector<int> >& rlt, vector<int> tmp, int expectNumber, int sum) {
        if (!(crt -> left) && !(crt -> right)) {
            if (expectNumber == sum) rlt.push_back(tmp);
        }
        else {
            if (crt -> left) {
                tmp.push_back(crt -> left -> val);
                backTrack(crt -> left, rlt, tmp, expectNumber, sum + tmp.back());
                tmp.pop_back();
            }
            if (crt -> right) {
                tmp.push_back(crt -> right -> val);
                backTrack(crt -> right, rlt, tmp, expectNumber, sum + tmp.back());
                tmp.pop_back();
            }
        }
    }
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int> > rlt;
        if (root) backTrack(root, rlt, {root -> val}, expectNumber, root -> val);
        sort(rlt.begin(), rlt.end(), cmp);
        return rlt;
    }
};