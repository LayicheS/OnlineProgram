#include <iostream>
#include <vector>
#include <string.h>
#include <string>
using namespace std;
/*
 * ��Դ: ��ָOffer
 * ��Ŀ: ���л�������
 *
 * ����: ��ʵ�������������ֱ��������л��ͷ����л�������
 *
 * ����:
 * string -> char* : strdup(s.c_str())
 * char* -> string : string = char*
 *
 * string -> int : atoi (string.c_str())
 * int -> string : to_string(int)
 *
 * ˼·��
 * ��ѭ�� -> �� -> �� ԭ��
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
    char* Serialize(TreeNode *root) {
        if (!root)
            tmp += "$,";
        else {
            tmp += (to_string(root -> val) + ",");
            Serialize(root -> left);
            Serialize(root -> right);
        }
        char* rlt = strdup(tmp.c_str());
        return rlt;
    }
    TreeNode* Deserialize(vector<string> str_arr) {
        if (cnt == str_arr.size()) return nullptr; //�ݹ��յ�
        ++cnt;
        TreeNode *crt = nullptr;
        if (str_arr[cnt] != "$") {
            crt = new TreeNode(atoi(str_arr[cnt].c_str()));
            crt->left = Deserialize(str_arr);
            crt->right = Deserialize(str_arr);
        }
        return crt;
    }
    TreeNode* Deserialize(char* s) {
        vector<string> str_arr;
        int i = 0;
        string buffer = "";
        /* ��','Ϊ��־���ָ��ַ���Ϊ�ַ�������*/
        while (s[i] != '\0') {
            if (s[i] != ',')
                buffer.push_back(s[i]);
            else {
                str_arr.push_back(buffer);
                buffer = "";
            }
            ++i;
        }
        /* ��','Ϊ��־���ָ��ַ���Ϊ�ַ�������*/
        return Deserialize(str_arr);
    }
private:
    string tmp = "";
    int cnt = -1;
};