
#ifndef MY_LIST_H
#define MY_LIST_H

typedef int Rank;
#define ListNodePosi(T) ListNode<T>*  //定义listode position 指向节点的指针
/*
 * 定义 ListNode 类 描述每一个节点
 */
template <typename T> struct ListNode
{
    //默认公有
    T data; //数据
    ListNodePosi(T) pred; //前驱
    ListNodePosi(T) succ; //后继

    //构造函数
    ListNode() {}  //针对哨兵节点 header和trailer的构造
    //默认构造函数
    ListNode(T e, ListNodePosi(T) p= nullptr, ListNodePosi(T) s= nullptr):
        data(e), pred(p), succ(s){}

    //接口操作
    ListNodePosi(T) insertAsPred(T const& e); //紧靠当前节点之前插入新节点
    ListNodePosi(T) insertAsSucc ( T const& e ); //紧随当前节点之后插入新节点
};





/*
 * 定义 List类
 */
//定义比较器 <
template <typename T> static bool lt ( T& a, T& b ) { return a < b; } //less than

template <typename T> class List
{
private:
    int _size;
    ListNodePosi(T) header;
    ListNodePosi(T) trailer;

protected:
    void init(); //双向链表初始化
    void copyNodes ( ListNodePosi(T) p, int n); //复制列表中自位置p起的n项
    int clear(); //清除所有节点

    //排序算法
    void insertionSort ( ListNodePosi(T), int ); //对从p开始连续的n个节点插入排序
    void selectionSort ( ListNodePosi(T), int ); //对从p开始连续的n个节点选择排序
       //归并排序
    void merge ( ListNodePosi(T)&, int, List<T>&, ListNodePosi(T), int ); //归并
    void mergeSort ( ListNodePosi(T)&, int ); //对从p开始连续的n个节点归并排序

public:

    // 构造函数
    List() { init(); } //默认
    List ( List<T> const& L ); //整体复制列表L
    List ( List<T> const& L, Rank r, int n ); //复制列表L中自第r项起的n项
    List ( ListNodePosi(T) p, int n ); //复制列表中自位置p起的n项
// 析构函数
    ~List(); //释放（包含头、尾哨兵在内的）所有节点
// 只读访问接口
    Rank size() const { return _size; } //规模
    bool empty() const { return _size <= 0; } //判空


    //首末节点的位置
    ListNodePosi(T) first() { return  header->succ;}
    ListNodePosi(T) last() { return  trailer->pred;}

    //无序查找
    //在无序列表内节点p的n个前驱中，找到值为e的最后者
    ListNodePosi(T) find(T const& e, int n, ListNodePosi(T) p) const;
    //有序列表的查找
    ListNodePosi(T) search(T const& e, int n, ListNodePosi(T) p) const;

    //在p及其n-1个后继中选出最大者
    ListNodePosi(T) selectMax ( ListNodePosi(T) p, int n );

    //插入
    ListNodePosi(T) insertAsFirst(T const& e) ; //首节点插入
    ListNodePosi(T) insertAsLast(T const& e) ; //尾节点插入
    ListNodePosi(T) insertAsBefore(ListNodePosi(T) p, T const& e) ;
    ListNodePosi(T) insertAsAfter(ListNodePosi(T) p, T const& e) ;

    //删除
    T remove(ListNodePosi(T) p);//删除合法位置p处的节点,返回被删除节点

    //排序
    void sort ( ListNodePosi(T) p, int n ); //列表区间排序
    void sort() { sort ( first(), _size ); } //列表整体排序

    //唯一化
    int deduplicate(); //无序去重
    int uniquify(); //有序去重

    //重载 `[]`操作符，通过秩索引找到Node的位置(指针)
    T& operator[] (Rank r);

// 遍历
    void traverse ( void (* ) ( T& ) ); //遍历，依次实施visit操作（函数指针，只读或局部性修改）
    template <typename VST> //操作器
    void traverse ( VST& ); //遍历，依次实施visit操作（函数对象，可全局性修改）
// print List
    void printList();

};





#endif