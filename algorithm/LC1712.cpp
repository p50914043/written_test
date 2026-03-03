// LC 1712. 将数组分成三个子数组的方案数

#include <algorithm>
#include <iostream>
#include <vector>

// 前缀和，二分查找,
class Solution {
 public:
  static constexpr int MOD = 1e9 + 7;  // 取余常数
  int waysToSplit(std::vector<int>& nums) {
    int n = nums.size();
    // 计算前缀和，即preSum[i] = nums[0] + nums[1] + ... + nums[i - 1]
    // 先获取leftsum[i], 且已知total，找出满足条件的j
    // middle=presum[j] - preSum[i]
    // right=total-presum[j]
    // presum[i] < middle = presum[j] - preSum[i]
    // middle < right = total - presum[j]
    // 因此需要找出j, 使得presum[j] >= 2 * presum[i]
    //所以需要满足： 2 * presum[i] <= presum[j] <= (total + presum[i]) / 2
    std::vector<int> preSum(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
      preSum[i] = preSum[i - 1] + nums[i - 1];
    }
    // 采用二分法查找j
    int ans = 0;
    long long result = 0;
    for (int i = 1; i <= n - 2; ++i)  // 第一个分割点从1开始
    {
      int leftsum = preSum[i];
      int leftj = std::lower_bound(preSum.begin(), preSum.end(), 2 * leftsum) -
                  preSum.begin();  // 找到第一个大于2 * leftsum的元素 左闭右开
      std::cout << leftj << std::endl;
      auto middleLeft = (preSum[n] + leftsum) / 2;
      int rightj = std::upper_bound(preSum.begin(), preSum.end(), middleLeft) - preSum.begin() -
                   1;  // 找到第一个大于middleLeft的元素 左闭右开
      std::cout << rightj << std::endl;
      if (rightj > leftj) {
        result += rightj - leftj + 1;  // 总个数累加
        result %= MOD;
      }
    }
    return result;
  }
};

int main() {
  Solution s;
  std::vector<int> nums = {1, 2, 3};
  std::cout << s.waysToSplit(nums) << std::endl;
  return 0;
}