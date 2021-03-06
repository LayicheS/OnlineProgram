#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

/*
 * 来源: LeetCode
 * 题目: 买卖股票的最佳时机(Best Time to Buy and Sell Stock)
 *
 * 描述:
 * 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格
 * 如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。
 * 注意你不能在买入股票前卖出股票。
 *
 * 示例 1:
 * 输入: [7,1,5,3,6,4]
 * 输出: 5
 * 解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5
 *
 *
 * 示例 2:
 * 输入: [7,6,4,3,1]
 * 输出: 0
 * 解释: 在这种情况下, 没有交易完成, 所以最大利润为 0
 *
 *
 * 思路:
 * 动态规划
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int days = prices.size();
        int Min = prices[0], ans = 0;
        vector<int> dp(days, 0);

        for (int i = 1; i < days; ++i) {
            if (prices[i] >= prices[i - 1]) {
                dp[i] = prices[i] - Min;
                ans = max(ans, dp[i]);
            } else Min = min(Min,  prices[i]);
        }
        return ans;
    }
};