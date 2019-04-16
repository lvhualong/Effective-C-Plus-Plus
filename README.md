# C-Plus-Plus-Software-Developer
C++  基础知识/算法与数据结构 学习说明



## 说明

- 任意算法都应在执行有限次基本操作之后终止，并给出输出。[有穷性和正确性]  

**时间复杂度**  
- 大O表示法，对算法时间复杂度`最坏`的情况做出估计  
- 大Ω表示法，对算法时间复杂度`最好`的情况做出估计  
- 常数时间复杂度 ，比如 比较、交换、赋值……  
- 对数时间复杂度 ，比如 每次左移/右移一次的循环……  
- 多项式时间复杂度， O(f(n)), 比如函数调用  
- 指数时间复杂度  要注意改进，无法真正应用到实际问题中  
- 

**空间复杂度**   
- 输入原始数据本身不计入所占用空间  
- 计算其他的，比如(转存、中转、索引、映射、缓冲)等各方面所消耗的空间  
- 因为每次操作所涉及的存储空间都不会超过常数规模，所以时间复杂度本身就是空间复杂度的一个天然的上界  

## 递归调用的 时间复杂度和空间复杂度  

### 线性递归-减而知之  
- 分析递归： 每一递归实例都表示一个方框，在对应调用之间添加一条有向连线  
- 递归的时间包括，递归实例的创建、销毁、以及每个递归实例执行的总时间  
- 创建、销毁由操作系统完成，接近常数，我们只需要考虑每个递归实例计算所需要的时间  
- [时间复杂度：递归深度*每次递归的时间复杂度]  
- 递归算法的缺陷就是空间复杂度，主要取决于递归深度，以及创建、维护、销毁递归实例  
- 一般将递归算法，改成等价的非递归版本， 比如例如`栈结构`  

### 二分递归-分而治之  


### 哈希表 
> [哈希表的构建目的， 以空间换取时间，可以将查找时间从 O(n) 降低到O(1)]

## 动态规划与贪心算法

- 动态规划 O(n^2)时间复杂度和O(0)空间复杂度， 通常用递推实现  
  **动态图规划的特点**
  * 通常求一个问题的最优解
  * 整体问题的最优解依赖于子问题的最优解
  * 小问题还有相互重叠的小子问题
  * 从上往下分析，从下往上求解
  
- 贪心算法 O(1)时间复杂和空间复杂
    * 每一步都可以做一个贪婪的选择
    * 但是怎么来做贪婪选择需要数学方式来证明。
    
## vector list queue区别
- vector 动态数组，连续空间存储，静态特性好， 通常只在最后一个元素插入删除
> begin end rbegin rend size 
> front back []
> push_back  pop_back   

- deque 双端队列 小片的连续，小片间链表连接   front --- back
> 可以快速在开始和结尾插入删除，空间重新分配比vector快，不需要拷贝，但是随即访问元素没有vector快
> begin end rbegin rend size 
> front back []
> push_back  pop_back  push_front pop_front

- list 双向链表 每个元素间都用链表相连  front ---- back
>list随即访问不及vector快【所以list没有下标访问[]】， 但是随即插入会更快
> begin end rbegin rend size 
> front back 
> push_back  pop_back  push_front pop_front  
> insert erase sort


- queue  FIFO的队列   back  ---> front
> size() push  pop front back 

- stack LIFO的栈    ---> top
>size() push pop top 

- set 【内部元素唯一】，用一棵平衡树结构来存储, 遍历的时候就排序了
> begin end rbegin rend size 
> insert erase 
> find  count

- unordered_set 哈希表
> begin end rbegin rend size 
> insert erase 
> find  count



- map 一对一的映射的结合，key不能重复
>std::map<char,int> mymap
 mymap.insert ( std::pair<char,int>('a',100) );
 
 > begin end rbegin rend size 
 [] find 
 > insert erase 
 
 ### 堆 是一个完全二叉树 
  
 - 如果父节点 >= 子节点 称为大顶堆
 - 如果父节点 <= 子节点 称为大顶堆
 > (algorithm头文件中 make_heap pop_heap push_heap sort_heap实现)
 >  vector<int>  v
 std::make_heap (v.begin(),v.end());
 