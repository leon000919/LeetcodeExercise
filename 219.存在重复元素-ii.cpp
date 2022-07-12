/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 *
 * https://leetcode.cn/problems/contains-duplicate-ii/description/
 *
 * algorithms
 * Easy (44.40%)
 * Likes:    477
 * Dislikes: 0
 * Total Accepted:    179.7K
 * Total Submissions: 404.5K
 * Testcase Example:  '[1,2,3,1]\n3'
 *
 * 给你一个整数数组 nums 和一个整数 k ，判断数组中是否存在两个 不同的索引 i 和 j ，满足 nums[i] == nums[j] 且
 * abs(i - j) <= k 。如果存在，返回 true ；否则，返回 false 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,3,1], k = 3
 * 输出：true
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,0,1,1], k = 1
 * 输出：true
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [1,2,3,1,2,3], k = 2
 * 输出：false
 * 
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * 0 <= k <= 10^5
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        if(k == 0)
            return false;
        unordered_set<int> us;
        for (int i = 0; i < n; ++i) {
            if(i > k)
                us.erase(nums[i - k - 1]);
            if (us.find(nums[i]) != us.end())
                return true;
            us.insert(nums[i]);
        }
        return false;
    }
};
// @lc code=end

