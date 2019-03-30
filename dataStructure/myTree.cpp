//
// Created by hualong on 2019/3/28.
//

#include "myTree.h"


/*
 *  BinNode struct operate
 */

template <typename T>
int BinNode<T>::size() //递归求解当前节点后代的数量
{
    int s = 1;
    if(lc) s += lc->size();
    if(rc) s += rc->size();

    return s;
}

//将e作为当前节点的左孩子插入二叉树
template <typename T> BinNodePosi(T) BinNode<T>::insertAsLC ( T const& e )
{ return lc = new BinNode ( e, this ); } // lc指向这个新建的节点，而且新建的节点的父节点就是当前节点

//将e作为当前节点的右孩子插入二叉树
template <typename T> BinNodePosi(T) BinNode<T>::insertAsRC ( T const& e )
{ return rc = new BinNode ( e, this ); }

//定位节点v的直接后继
template <typename T>
BinNodePosi(T) BinNode<T>::succ() {
    BinNodePosi(T) s = this; //记录后继的临时变量
    if ( rc ) { //若有右孩子，则直接后继必在右子树中，具体地就是
        s = rc; //右子树中
        while ( HasLChild ( *s ) ) s = s->lc; //最靠左（最小）的节点
    } else { //否则，直接后继应是“将当前节点包含于其左子树中的最低祖先”，具体地就是
        while ( IsRChild ( *s ) ) s = s->parent; //逆向地沿右向分支，不断朝左上方移动
        s = s->parent; //最后再朝右上方移动一步，即抵达直接后继（如果存在）
    }
    return s;
}

//定位节点v的直接后继
template <typename T> BinNodePosi(T) BinNode<T>::succ() {
    BinNodePosi(T) s = this; //记录后继的临时变量
    if ( rc )
    { //若有右孩子，则直接后继必在右子树中，具体地就是
        s = rc; //右子树中
        while ( HasLChild ( *s ) ) s = s->lc; //最靠左（最小）的节点
    }
    els
    { //否则，直接后继应是“将当前节点包含于其左子树中的最低祖先”，具体地就是
        while ( IsRChild ( *s ) ) s = s->parent; //逆向地沿右向分支，不断朝左上方移动
        s = s->parent; //最后再朝右上方移动一步，即抵达直接后继（如果存在）
    }
    return s;
}


/*
 * BinTree的操作
 */
//更新当前节点x高度 孩子节点最大高度+1
template <typename T>
int BinTree<T>::updateHeight ( BinNodePosi(T) x )
{ return x->height = 1 + max ( stature ( x->lc ), stature ( x->rc ) ); } //孩子的最大身高+1

//更新历代祖先的高度
template <typename T>
void BinTree<T>::updateHeightAbove ( BinNodePosi(T) x )
{
    while ( x )
    {
        updateHeight ( x );
        x = x->parent; //从x出发，覆盖历代祖先。
    }
}

// 二叉树插入节点
template <typename T>//将e当作根节点插入空的二叉树
BinNodePosi(T) BinTree<T>::insertAsRoot ( T const& e )
{ _size = 1; return _root = new BinNode<T> ( e ); }

template <typename T>//e插入为x的左孩子
BinNodePosi(T) BinTree<T>::insertAsLC ( BinNodePosi(T) x, T const& e )
{
    _size++;
    x->insertAsLC ( e );
    updateHeightAbove ( x ); //更新x所有祖父节点的高度
    return x->lc;
}

template <typename T> //e插入为x的右孩子
BinNodePosi(T) BinTree<T>::insertAsRC ( BinNodePosi(T) x, T const& e )
{ _size++; x->insertAsRC ( e ); updateHeightAbove ( x ); return x->rc; }

// 二叉树接入
template <typename T> //二叉树子树接入算法：将S当作节点x的左子树接入，S本身置空
BinNodePosi(T) BinTree<T>::attachAsLC ( BinNodePosi(T) x, BinTree<T>* &S ) { //x->lc == NULL
    if ( x->lc = S->_root ) //将S的根节点作为x的左节点
        x->lc->parent = x;  //同时令x作为S根节点的父亲
    _size += S->_size; updateHeightAbove ( x ); //更新全树规模与x所有祖先的高度
    S->_root = NULL; S->_size = 0; release ( S ); S = NULL; return x; //释放原树，返回接入位置
}

template <typename T> //二叉树子树接入算法：将S当作节点x的右子树接入，S本身置空
BinNodePosi(T) BinTree<T>::attachAsRC ( BinNodePosi(T) x, BinTree<T>* &S ) { //x->rc == NULL
    if ( x->rc = S->_root ) x->rc->parent = x; //接入
    _size += S->_size; updateHeightAbove ( x ); //更新全树规模与x所有祖先的高度
    S->_root = NULL; S->_size = 0; release ( S ); S = NULL; return x; //释放原树，返回接入位置
}

// 二叉树删除
template <typename T> //删除二叉树中位置x处的节点及其后代，返回被删除节点的数值
int BinTree<T>::remove ( BinNodePosi(T) x ) { //assert: x为二叉树中的合法位置
    FromParentTo ( *x ) = NULL; //切断来自父节点的指针
    updateHeightAbove ( x->parent ); //更新祖先高度
    int n = removeAt ( x ); _size -= n; return n; //删除子树x，更新规模，返回删除节点总数
}
template <typename T> //删除二叉树中位置x处的节点及其后代，返回被删除节点的数值
static int removeAt ( BinNodePosi(T) x ) { //assert: x为二叉树中的合法位置
    if ( !x ) return 0; //递归基：空树
    int n = 1 + removeAt ( x->lc ) + removeAt ( x->rc ); //递归释放左、右子树
    release ( x->data ); release ( x ); return n; //释放被摘除节点，并返回删除节点总数
}

// 二叉树遍历

// 迭代版本 先序遍历
template <typename T, typename VST> //元素类型 操作器
void BinNode<T>::