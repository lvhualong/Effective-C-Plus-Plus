
#include <vector>
#include <algorithm> //include stl sorted
#include <iostream>

using namespace std;
//稳定排序，待排序序列中有相同的记录，排序前后不改变其相对位置成为稳定排序

/*
 * 冒泡排序：双重循环，逆序了就交换，每一趟会把一个元素的位置排好
 * 平均时间复杂度： O(n^2) 要执行n次冒泡，每次冒泡要执行n次比较、交换
 * 最好时间复杂度：O(n)   已经排序
 * 最坏时间复杂度：O(n^2) 完全逆序
 * 空间复杂度： O(n)
 * 适用情况：n 较小的情况
 * 稳定排序
 *
 */
 void bobble_sort(vector<int> &nums)
{
   int length = nums.size();
   for(int i=0; i<length-1; i++)
     for(int j=0; j<length-1; j++)
     {
       //逆序就交换
       if(nums[j] > nums[j+1])
       {
         int temp = nums[j];
         nums[j] = nums[j+1];
         nums[j+1] = temp;
       }
     }
}


/*
 * 选择排序：每次从乱序序列中找到最小值，与当前乱序的头部交换，这样从左往右依次进行
 * 平均时间复杂度：O(n^2)
 * 最好时间复杂度：O(n^2)
 * 最坏时间复杂度：O(n^2)
 * 空间复杂度： O(1)
 * 适用情况：
 * 不稳定排序
 *
 */
void selection_sort(vector<int>& nums) {

  int length = nums.size();
  for(int i=0; i<length; i++)
  {
    int min_index = i;
    //find the min_index
    for(int j=i; j<length; j++)
    {
      if(nums[j] < nums[min_index])
        min_index = j;

    }
    //swap
    int temp = nums[i];
    nums[i] = nums[min_index];
    nums[min_index] = temp;
  }
}

/*
 * 插入排序：每次从后面拿一个数，插入到前面排好序的正确位置上
 * 平均时间复杂度：O(n^2)
 * 最好时间复杂度：O(n^2)
 * 最坏时间复杂度：O(n^2)
 * 空间复杂度： O(1)
 * 适用情况：
 * 不稳定排序
 *
 */
void insert_sort(vector<int>& nums)
{
  int length = nums.size();
  for(int i=1; i<length; i++)
    for(int j=i; j<length; j++)
    {
      if(nums[j]<nums[j-1])
      {
        int temp = nums[j];
        nums[j] = nums[j-1];
        nums[j-1] = temp;
      }
    }
}

/*
 * 希尔排序：递减递增排序算法，插入排序的优化版本
 * 插入排 序需要一位一位比较，然后放置到正确位置。
 * 为了提升比较的跨度，希尔排序将数组按照一定步长分成几个子数组进行排序，通过逐渐减短步长来完成最终排序。
 *
 * - 计算当前步长，按步长划分子数组
 * - 子数组内插入排序
 * - 步长除以2后继续12两步，直到步长最后变成1
 *
 * 平均时间复杂度：O(nlogn)
 * 最好时间复杂度：O(nlogn)
 * 最坏时间复杂度：
 * 空间复杂度：
 * 适用情况：
 * 不稳定排序
 */
void shell_sort(vector<int> &nums)
{
  for (int gap = nums.size() >> 1; gap > 0; gap >>= 1) { // times
    for (int i = gap; i < nums.size(); i++) { // position
      int temp = nums[i];

      int j = i - gap;
      for (; j >= 0 && nums[j] > temp; j -= gap) {
        nums[j + gap] = nums[j];
      }

      nums[j + gap] = temp;
    }
  }
}


/*
 * 归并排序：采用分治法， 把一个数组打散成小数组，然后再把小数组拼凑再排序
 * - 把当前数组分化成n个单位为1的子数组，然后两两比较合并成单位为2的n/2个子数组
 * - 继续进行这个过程，按照2的倍数进行子数组的比较合并，直到最终数组有序
 * 平均时间复杂度：O(nlogn)
 * 最好时间复杂度：O()
 * 最坏时间复杂度：O()
 * 空间复杂度： O(n)
 * 适用情况：
 * 稳定排序
 *
 */

void merge_array(vector<int> &nums, int b, int m, int e, vector<int> &temp)
{
  int lb = b, rb = m, tb = b;
  while (lb != m && rb != e)
    if (nums[lb] < nums[rb])
      temp[tb++] = nums[lb++];
    else
      temp[tb++] = nums[rb++];

  while (lb < m)
    temp[tb++] = nums[lb++];

  while (rb < e)
    temp[tb++] = nums[rb++];

  for (int i = b;i < e; i++)
    nums[i] = temp[i];
}

void merge_sort(vector<int> &nums, int b, int e, vector<int> &temp)
{
  int m = (b + e) / 2;
  if (m != b) {
    merge_sort(nums, b, m, temp);
    merge_sort(nums, m, e, temp);
    merge_array(nums, b, m, e, temp);
  }
}

/*
 * 快速排序：也是采用分治法，快速排序和归并排序不同，
 * 它不是一半一半的分子数组，而是选择一个基准数，
 * 把比这个数小的挪到左边，把比这个数大的移到右边。
 * 然后不断对左右两部分也执行相同步骤，直到整个数组有序。
 * 步骤
 * - 用一个基准数将数组分成两个子数组
 * - 将大于基准数的移到右边，小于的移到左边
 * - 递归的对子数组重复执行1，2，直到整个数组有序
 * 平均时间复杂度：O(nlogn)
 * 最好时间复杂度：O()
 * 最坏时间复杂度：O()
 * 空间复杂度： O(n)
 * 适用情况：
 * 不稳定排序
 *
 */
void quick_sort(vector<int> &nums, int b, int e, vector<int> &temp)
{
  int m = (b + e) / 2;
  if (m != b) {
    int lb = b, rb = e - 1;

    for (int i = b; i < e; i++) {
      if (i == m)
        continue;
      if (nums[i] < nums[m])
        temp[lb++] = nums[i];
      else
        temp[rb--] = nums[i];
    }
    temp[lb] = nums[m];

    for (int i = b; i < e; i++)
      nums[i] = temp[i];

    quick_sort(nums, b, lb, temp);
    quick_sort(nums, lb + 1, e, temp);
  }
}
//解法2: 不需要辅助空间

void quick_sort_2(vector<int> &nums, int b, int e)
{
  if (b < e - 1) {
    int lb = b, rb = e - 1;
    while (lb < rb) {
      while (nums[rb] >= nums[b] && lb < rb)
        rb--;
      while (nums[lb] <= nums[b] && lb < rb)
        lb++;
      swap(nums[lb], nums[rb]);
    }
    swap(nums[b], nums[lb]);
    quick_sort_2(nums, b, lb);
    quick_sort_2(nums, lb + 1, e);
  }
}

/*
 * 堆排序：
 * 堆排序经常用于求一个数组中最大k个元素时。
 * 因为堆实际上是一个完全二叉树，所以用它可以用一维数组来表示。
 * 因为最大堆的第一位总为当前堆中最大值，所以每次将最大值移除后，
 * 调整堆即可获得下一个最大值，通过一遍一遍执行这个过程就可以得到前k大元素，或者使堆有序。
 *
 * 节点的下标：
 * 在了解算法之前，首先了解在一维数组中节点的下标：
i节点的父节点 parent(i) = floor((i-1)/2)
i节点的左子节点 left(i) = 2i + 1
i节点的右子节点 right(i) = 2i + 2

步骤

构造最大堆（Build Max Heap）：首先将当前元素放入最大堆下一个位置，
 然后将此元素依次和它的父节点比较，如果大于父节点就和父节点交换，直到比较到根节点。
 重复执行到最后一个元素。

最大堆调整（Max Heapify）：调整最大堆即将根节点移除后重新整理堆。
 整理方法为将根节点和最后一个节点交换，然后把堆看做n-1长度，
 将当前根节点逐步移动到其应该在的位置。

堆排序（HeapSort）：重复执行2，直到所有根节点都已移除。

 * 平均时间复杂度：O(nlogn)
 * 最好时间复杂度：O()
 * 最坏时间复杂度：O()
 * 空间复杂度： O(n)
 * 适用情况：
 * 不稳定排序
 堆执行一次调整需要O(logn)的时间，在排序过程中需要遍历所有元素执行堆调整，
 所以最终时间复杂度是O(nlogn)。空间复杂度是O(n)。
 */
void heap_sort(vector<int> &nums)
{
  int n = nums.size();
  for (int i = n / 2 - 1; i >= 0; i--) { // build max heap
    max_heapify(nums, i, nums.size() - 1);
  }

  for (int i = n - 1; i > 0; i--) { // heap sort
    int temp = nums[i];
    num[i] = nums[0];
    num[0] = temp;
    max_heapify(nums, 0, i);
  }
}

void max_heapify(vector<int> &nums, int beg, int end)
{
  int curr = beg;
  int child = curr * 2 + 1;
  while (child < end) {
    if (child + 1 < end && nums[child] < nums[child + 1]) {
      child++;
    }
    if (nums[curr] < nums[child]) {
      int temp = nums[curr];
      nums[curr] = nums[child];
      num[child] = temp;
      curr = child;
      child = 2 * curr + 1;
    } else {
      break;
    }
  }
}

void print_vector(vector<int>& nums);
int main() {

  //一维 vector的比较
  vector<int> inputNums{1,5,0,2,2,3,1,2,8,2,7};
  cout << "the input nums: " ;
  print_vector(inputNums);

  bobble_sort(inputNums);
  cout << "the bobble_sort nums: " ;
  print_vector(inputNums);

  selection_sort(inputNums);
  cout << "the selection_sort nums: " ;
  print_vector(inputNums);

  insert_sort(inputNums);
  cout << "the insert_sort nums: " ;
  print_vector(inputNums);

  //shell sort
  shell_sort(inputNums);
  cout << "the shell_sort nums: " ;
  print_vector(inputNums);

  // merge_sort
//  merge_sort(inputNums);
//  cout << "the shell_sort nums: " ;
//  print_vector(inputNums);

}



void print_vector(vector<int>& nums)
{
  for(auto num:nums)
    cout << num << " ";
  cout << endl;
}
