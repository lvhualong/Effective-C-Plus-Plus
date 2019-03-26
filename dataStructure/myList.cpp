
#include "myList.h"


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

// @ private   *********************



// @ public    *********************

//双向链表初始化
template <typename T>
void List<T>::init()
{
    header = new ListNode(T);
    trailer= new ListNode(T);
    header->succ = trailer; header->pred = NULL;
    trailer->pred = header; trailer->succ = NULL;

    _size = 0;
}

//无序查找
//在无序列表内节点p的n个前驱中，找到值为e的最后者
template <typename T>
ListNodePosi(T) List<T>::find(T const& e, int n, ListNodePosi(T) p) const
{
    while(n--)
    {
        //逐个比对，直至命中或范围越界
        if(e == (p = p->pred)->data ) return p;
    }
    return NULL;
}



//插入

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



//重载 `[]`操作符，通过秩索引找到Node的位置(指针)
template <typename T>
T&  List<T>::operator[] (Rank r)
{
    ListNodePosi(T) p = first();
    while(--r) p = p->succ; //找到目标节点的位置
    return p->data; //取出目标节点的数据
}