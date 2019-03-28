
#include "myList.h"
#include <iostream>


/*
 * ListNode 插入前驱和后继的实现
 */
//紧靠当前节点之前插入新节点
template <typename T>
ListNodePosi(T) ListNode<T>::insertAsPred(T const& e)
{
    ListNodePosi(T) x = new ListNode(e, pred, this); //新建node,并确定它自己的前驱和后继
    pred->succ = x;  //原来前驱节点的后继指向
    pred = x; //加入新节点后，pred的指向

    return x;
}

//紧随当前节点之后插入新节点
template <typename T>
ListNodePosi(T) ListNode<T>::insertAsSucc ( T const& e )
{
    ListNodePosi(T) x = new ListNode(e, this, succ);//新建node,并确定它自己的前驱和后继
    succ->pred = x; //原来后继节点的前驱指向
    succ->pred; //新加入节点后 succ指向

    return x;
}





/*
 * List 成员函数实现
 */
// @ protected *********************
//双向链表初始化
template <typename T>
void List<T>::init()
{
    header = new ListNode<T>;
    trailer= new ListNode<T>;
    header->succ = trailer; header->pred = nullptr;
    trailer->pred = header; trailer->succ = nullptr;

    _size = 0;
}


//列表内部方法：复制列表中自位置p起的n项
template <typename T>
void List<T>::copyNodes ( ListNodePosi(T) p, int n ) { //p合法，且至少有n-1个真后继节点
    init(); //创建头、尾哨兵节点并做初始化 空的List
    while ( n-- )
    {
        insertAsLast ( p->data ); //一个个从后面插入
        p = p->succ; //p向后移动
    } //将起自p的n项依次作为末节点插入
}

//清空列表
template <typename T> int List<T>::clear() {
    int oldSize = _size;
    while ( 0 < _size ) remove ( header->succ ); //反复删除首节点，直至列表变空
    return oldSize;
}

// 排序
//列表的插入排序算法：对起始于位置p的n个元素排序
template <typename T>
void List<T>::insertionSort ( ListNodePosi(T) p, int n ) { //valid(p) && rank(p) + n <= size
    printf ( "InsertionSort ...\n" );
    for ( int r = 0; r < n; r++ )
    { //逐一为各节点
        insertAsAfter( search ( p->data, r, p ), p->data ); //查找适当的位置并插入
        p = p->succ; remove ( p->pred ); //转向下一节点
    }
}


// 选择排序
template <typename T> //列表的选择排序算法：对起始于位置p的n个元素排序
void List<T>::selectionSort ( ListNodePosi(T) p, int n ) { //valid(p) && rank(p) + n <= size
    /*DSA*/printf ( "SelectionSort ...\n" );
    ListNodePosi(T) head = p->pred; ListNodePosi(T) tail = p;
    for ( int i = 0; i < n; i++ ) tail = tail->succ; //待排序区间为(head, tail)
    while ( 1 < n ) { //在至少还剩两个节点之前，在待排序区间内
        ListNodePosi(T) max = selectMax ( head->succ, n ); //找出最大者（歧义时后者优先）
        insertAsBefore ( tail, remove ( max ) ); //将其移至无序区间末尾（作为有序区间新的首元素）
        /*DSA*///swap(tail->pred->data, selectMax( head->succ, n )->data );
        tail = tail->pred; n--;
    }
}

//归并
template <typename T> //有序列表的归并：当前列表中自p起的n个元素，与列表L中自q起的m个元素归并
void List<T>::merge ( ListNodePosi(T) & p, int n, List<T>& L, ListNodePosi(T) q, int m ) {
// assert:  this.valid(p) && rank(p) + n <= size && this.sorted(p, n)
//          L.valid(q) && rank(q) + m <= L._size && L.sorted(q, m)
// 注意：在归并排序之类的场合，有可能 this == L && rank(p) + n = rank(q)
    ListNodePosi(T) pp = p->pred; //借助前驱（可能是header），以便返回前 ...
    while ( 0 < m ) //在q尚未移出区间之前
        if ( ( 0 < n ) && ( p->data <= q->data ) ) //若p仍在区间内且v(p) <= v(q)，则
        { if ( q == ( p = p->succ ) ) break; n--; } //p归入合并的列表，并替换为其直接后继
        else //若p已超出右界或v(q) < v(p)，则
        { insertAsBefore ( p, L.remove ( ( q = q->succ )->pred ) ); m--; } //将q转移至p之前
    p = pp->succ; //确定归并后区间的（新）起点
}

//归并排序
template <typename T> //列表的归并排序算法：对起始于位置p的n个元素排序
void List<T>::mergeSort ( ListNodePosi(T) & p, int n ) { //valid(p) && rank(p) + n <= size
    /*DSA*/printf ( "\tMERGEsort [%3d]\n", n );
    if ( n < 2 ) return; //若待排序范围已足够小，则直接返回；否则...
    int m = n >> 1; //以中点为界
    ListNodePosi(T) q = p; for ( int i = 0; i < m; i++ ) q = q->succ; //均分列表
    mergeSort ( p, m ); mergeSort ( q, n - m ); //对前、后子列表分别排序
    merge ( p, m, *this, q, n - m ); //归并
} //注意：排序后，p依然指向归并后区间的（新）起点

// @ public    *********************

template <typename T> //复制列表中自位置p起的n项（assert: p为合法位置，且至少有n-1个后继节点）
List<T>::List ( ListNodePosi(T) p, int n ) { copyNodes ( p, n ); }

template <typename T> //整体复制列表L
List<T>::List ( List<T> const& L ) { copyNodes ( L.first(), L._size ); }

template <typename T> //复制L中自第r项起的n项（assert: r+n <= L._size）
List<T>::List ( List<T> const& L, int r, int n ) { copyNodes ( L[r], n ); }

//查找
//在无序列表内节点p的n个前驱中，找到值为e的最后者
template <typename T>
ListNodePosi(T) List<T>::find(T const& e, int n, ListNodePosi(T) p) const
{
    while(n--)
    {
        //逐个比对，直至命中或范围越界
        if(e == (p = p->pred)->data ) return p;
    }
    return nullptr;
}

//有序查找
template <typename T>
ListNodePosi(T) List<T>::search(T const& e, int n, ListNodePosi(T) p) const
{
    while (n--)
    {
        if( (p = p->pred)->data <= e)
            return p;
    }
    return nullptr;
}

//从起始于位置p的n个元素中选出最大者
template <typename T>
ListNodePosi(T) List<T>::selectMax ( ListNodePosi(T) p, int n ) {
    ListNodePosi(T) max = p; //最大者暂定为首节点p
    for ( ListNodePosi(T) cur = p; 1 < n; n-- ) //从首节点p出发，将后续节点逐一与max比较
        if ( !lt ( ( cur = cur->succ )->data, max->data ) ) //若当前元素不小于max，则
            max = cur; //更新最大元素位置记录
    return max; //返回最大节点位置
}

//插入 *******************************

//首节点插入
template <typename T>
ListNodePosi(T) List<T>::insertAsFirst(T const& e)
{
    _size++;
    return  header->insertAsSucc(e);
}
//尾节点插入
template <typename T>
ListNodePosi(T) List<T>::insertAsLast(T const& e)
{
    _size++;
    return trailer->insertAsPred(e);
}
// 在p的前面插入
template <typename T>
ListNodePosi(T) List<T>::insertAsBefore(ListNodePosi(T) p, T const& e)
{
    _size++;
    return p->insertAsPred(e);
}

// 在p的后面插入
template <typename T>
ListNodePosi(T) List<T>::insertAsAfter(ListNodePosi(T) p, T const& e)
{
    _size++;
    return  p->insertAsSucc(e);
}

// 删除 *******************************************
template  <typename T>
T List<T>::remove(ListNode<T> *p)
{
    T e = p->data; //删除合法位置p处的节点,返回被删除节点
    p->pred->succ = p->succ;
    p->succ->pred = p->pred;

    delete p; _size--; //释放节点，更新规模
    return e;
}

// List排序
template <typename T> void List<T>::sort ( ListNodePosi(T) p, int n ) { //列表区间排序
    switch ( rand() % 3 ) { //随机选取排序算法。可根据具体问题的特点灵活选取或扩充
        case 1:  insertionSort ( p, n ); break; //插入排序
        case 2:  selectionSort ( p, n ); break; //选择排序
        default: mergeSort ( p, n ); break; //归并排序
    }
}


// 唯一化 ********************************

//剔除无序列表中的重复节点
template <typename T> int List<T>::deduplicate() {
    if ( _size < 2 ) return 0; //平凡列表自然无重复
    int oldSize = _size; //记录原规模
    ListNodePosi(T) p = header; Rank r = 0; //p从首节点开始
    while ( trailer != ( p = p->succ ) ) { //依次直到末节点
        ListNodePosi(T) q = find ( p->data, r, p ); //在p的r个（真）前驱中查找雷同者
        q ? remove ( q ) : r++; //若的确存在，则删除之；否则秩加一
    } //assert: 循环过程中的任意时刻，p的所有前驱互不相同
    return oldSize - _size; //列表规模变化量，即被删除元素总数
}

//成批剔除重复元素，效率更高
template <typename T> int List<T>::uniquify() {
    if ( _size < 2 ) return 0; //平凡列表自然无重复
    int oldSize = _size; //记录原规模
    ListNodePosi(T) p = first(); ListNodePosi(T) q; //p为各区段起点，q为其后继
    while ( trailer != ( q = p->succ ) ) //反复考查紧邻的节点对(p, q)
        if ( p->data != q->data ) p = q; //若互异，则转向下一区段
        else remove ( q ); //否则（雷同），删除后者
    return oldSize - _size; //列表规模变化量，即被删除元素总数
}


//重载 `[]`操作符，通过秩索引找到Node的位置(指针)
template <typename T>
T&  List<T>::operator[] (Rank r)
{
    ListNodePosi(T) p = first();
    while(--r) p = p->succ; //找到目标节点的位置
    return p->data; //取出目标节点的数据
}

//遍历
template <typename T>
void List<T>::traverse ( void ( *visit ) ( T& ) ) //借助函数指针机制遍历
{
    for ( ListNodePosi(T) p = header->succ; p != trailer; p = p->succ )
        visit ( p->data );
}

template <typename T> template <typename VST> //元素类型、操作器
void List<T>::traverse ( VST& visit ) //借助函数对象机制遍历
{  for ( ListNodePosi(T) p = header->succ; p != trailer; p = p->succ ) visit ( p->data );  }

template <typename T>
void List<T>::printList()
{
    ListNodePosi(T) posi = header;
        while (posi->succ != trailer)
        {
            std::cout << posi->succ->data << " ";
            posi = posi->succ;
        }
        std::cout << std::endl;

}

int main()
{
    //实例化
    List<int>  initListTest;
    //插入
    for(int i=0; i<=10; i++)
    {
        int temp = rand()%10;
        initListTest.insertAsLast(temp)
    }
    std::cout << "test vector_size " << initListTest.size() << std::endl;
    initListTest.printList();
    //排序
    intVectorTest.sort();
    initListTest.printList();

    return 0;
}