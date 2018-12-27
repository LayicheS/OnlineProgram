#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 移除元素(Remove Element)
 *
 * 描述:
 * 给定一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，返回移除后数组的新长度
 * 不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成
 * 元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素
 *
 * 示例:
 * 给定 nums = [3,2,2,3], val = 3,
 * 函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2
 * 你不需要考虑数组中超出新长度后面的元素
 *
 * 思路:
 * 简单题
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, k = nums.size() - 1, j = 0;
        while(j <= k) {
            if (nums[j] != val) ++i;
            else {
                swap(nums[k--], nums[j]);
                continue;
            }
            ++j;
        }
        return i;
    }
};