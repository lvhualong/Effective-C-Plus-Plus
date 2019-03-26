
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
    ListNode(T e, ListNodePosi(T) p=NULL, ListNodePosi(T) s=NULL):
        data(e), pred(p), succ(s){}

    //接口操作
    ListNodePosi(T) insertAsPred(T const& e); //紧靠当前节点之前插入新节点
    ListNodePosi(T) insertAsSucc ( T const& e ); //紧随当前节点之后插入新节点

};





/*
 * 定义 List类
 */

template <typename T> class List
{
private:
    int _size;
    ListNodePosi(T) header;
    ListNodePosi(T) trailer;


protected:


public:
    void init(); //双向链表初始化


    //首末节点的位置
    ListNodePosi(T) first() { return  header->succ;}
    ListNodePosi(T) last() { return  trailer->pred;}

    //无序查找
    //在无序列表内节点p的n个前驱中，找到值为e的最后者
    ListNodePosi(T) find(T const& e, int n, ListNodePosi(T) p) const;

    //插入
    ListNodePosi(T) insertAsFirst(T const& e) ; //首节点插入
    ListNodePosi(T) insertAsLast(T const& e) ; //尾节点插入
    ListNodePosi(T) insertAsBefore(ListNodePosi(T) p, T const& e) ;
    ListNodePosi(T) insertAsAfter(ListNodePosi(T) p, T const& e) ;


    //删除

    //重载 `[]`操作符，通过秩索引找到Node的位置(指针)
    T& operator[] (Rank r);

};





#endif