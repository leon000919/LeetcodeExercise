/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 *
 * https://leetcode-cn.com/problems/move-zeroes/description/
 *
 * algorithms
 * Easy (63.87%)
 * Likes:    1259
 * Dislikes: 0
 * Total Accepted:    496.3K
 * Total Submissions: 776.9K
 * Testcase Example:  '[0,1,0,3,12]'
 *
 * 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
 * 
 * 示例:
 * 
 * 输入: [0,1,0,3,12]
 * 输出: [1,3,12,0,0]
 * 
 * 说明:
 * 
 * 
 * 必须在原数组上操作，不能拷贝额外的数组。
 * 尽量减少操作次数。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for (int i = 0; i < nums.size();i++)
        {
            if (nums[i] != 0)
                nums[j++] = nums[i];
        }
        while (j < nums.size())
            nums[j++] = 0;
    }
};
// @lc code=end

