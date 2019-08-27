//
// Created by hualong on 2019/3/30.
//

/*
 * 检测序列是否为非递减序列 01_array[i] <=01_array[i+1] for 1<i<n
 * 最多只能改变一个数
 * 输出 是 1  ||   否 0
 * 测试示例：
 * 3 4 6 5 5 7 8
 * 1
 * [6 变成 4  改变一个数就可以了]
 */


/*
 * 也是一个查找遍历问题
 *
 * -一个指针从前往后查找，看是否是递增的
 * -一个指针从后往前查找，看是否是递减的
 * -记住他们各自出现逆序的位置，然后看差了几个长度，能否通过修改一个元素进行弥补
 */

#include <vector>
#include <iostream>

using  namespace std;
    bool checkPossibility(vector<int>& nums)
    {
      int n = nums.size();
      int i = 0, j = n - 1; //双指针
      while (i < j && nums[i] <= nums[i + 1]) {
        i++;
//        cout << "i: " << i << endl;
      }
      while (i < j && nums[j] >= nums[j - 1]){
        j--;
//        cout << "j: " << j << endl;
      }
      int head = (i == 0 ? INT_MIN : nums[i - 1]);
      int tail = (j == n - 1 ? INT_MAX : nums[j + 1]);
//      cout << "heda " << head << "tail: " << tail << endl;
      if (j - i <= 1 && (head <= nums[j] || tail >= nums[i]))
        return true;
      else
        return false;
    }

int main()
{
  vector<int> nums{3, 4, 6, 5, 5, 7, 8};

  bool flag = checkPossibility(nums);
  if(flag)
    cout << "it's an Poss-increasing sequence" << endl;
  else
    cout << "it's not an Poss-increasing sequence" << endl;


}