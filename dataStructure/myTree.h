//
// Created by hualong on 2019/3/28.
//

#ifndef C_PLUS_PLUS_SOFTWARE_DEVELOPER_MYTREE_H
#define C_PLUS_PLUS_SOFTWARE_DEVELOPER_MYTREE_H


#define BinNodePosi(T) BinNode<T>*  //BinNodePosi(T) 指向一个BinNode
#define stature(p) ((p)? (p)->height : -1) //约定空树的高度为1
typedef enum {RB_RED, RB_BLACK} RBColor;



/******************************************************************************************
 * BinNode状态与性质的判断
 ******************************************************************************************/
#define IsRoot(x) ( ! ( (x).parent ) )
#define IsLChild(x) ( ! IsRoot(x) && ( & (x) == (x).parent->lc ) )
#define IsRChild(x) ( ! IsRoot(x) && ( & (x) == (x).parent->rc ) )
#define HasParent(x) ( ! IsRoot(x) )
#define HasLChild(x) ( (x).lc )
#define HasRChild(x) ( (x).rc )
#define HasChild(x) ( HasLChild(x) || HasRChild(x) ) //至少拥有一个孩子
#define HasBothChild(x) ( HasLChild(x) && HasRChild(x) ) //同时拥有两个孩子
#define IsLeaf(x) ( ! HasChild(x) )

/******************************************************************************************
 * 与BinNode具有特定关系的节点及指针
 ******************************************************************************************/
#define sibling(p) /*兄弟*/ \
   ( IsLChild( * (p) ) ? (p)->parent->rc : (p)->parent->lc )

#define uncle(x) /*叔叔*/ \
   ( IsLChild( * ( (x)->parent ) ) ? (x)->parent->parent->rc : (x)->parent->parent->lc )

#define FromParentTo(x) /*来自父亲的引用*/ \
   ( IsRoot(x) ? _root : ( IsLChild(x) ? (x).parent->lc : (x).parent->rc ) )


template <typename T> struct BinNode
{
    T data; //节点的数据
    BinNodePosi(T) parent; //父节点以及左右子节点的位置
    BinNodePosi(T) lc;
    BinNodePosi(T) rc;

    int height; //节点的高度
    int npl; // null path length （左式堆，直接height
    RBColor color; //颜色(红黑树)

    // 构造函数
    BinNode() :
            parent ( NULL ), lc ( NULL ), rc ( NULL ), height ( 0 ), npl ( 1 ), color ( RB_RED ) { }
    BinNode ( T e, BinNodePosi(T) p = NULL, BinNodePosi(T) lc = NULL, BinNodePosi(T) rc = NULL,
              int h = 0, int l = 1, RBColor c = RB_RED ) :
            data ( e ), parent ( p ), lc ( lc ), rc ( rc ), height ( h ), npl ( l ), color ( c ) { }

    // BinNode操作接口
    int size(); //统计当前节点后代总数，亦即以其为根的子树的规模
    BinNodePosi(T) insertAsLC ( T const& ); //作为当前节点的左孩子插入新节点
    BinNodePosi(T) insertAsRC ( T const& ); //作为当前节点的右孩子插入新节点
    BinNodePosi(T) succ(); //取当前节点的直接后继

    // 二叉树遍历算法的接口
    template <typename VST> void travLevel ( VST& ); //子树层次遍历
    template <typename VST> void travPre ( VST& ); //子树先序遍历
    template <typename VST> void travIn ( VST& ); //子树中序遍历
    template <typename VST> void travPost ( VST& ); //子树后序遍历
// 比较器、判等器（各列其一，其余自行补充）
    bool operator< ( BinNode const& bn ) { return data < bn.data; } //小于
    bool operator== ( BinNode const& bn ) { return data == bn.data; } //等于
    /*DSA*/
    /*DSA*/BinNodePosi(T) zig(); //顺时针旋转
    /*DSA*/BinNodePosi(T) zag(); //逆时针旋转
};


template <typename T> class BinTree
{
protected:
    int _size;  //规模
    BinNodePosi(T) _root; //根节点位置
    virtual int updateHeight ( BinNodePosi(T) x ); //更新节点x的高度
    void updateHeightAbove ( BinNodePosi(T) x ); //更新节点x及其祖先的高度

public:
    BinTree() : _size ( 0 ), _root ( NULL ) { } //构造函数
    ~BinTree() { if ( 0 < _size ) remove ( _root ); } //析构函数
    int size() const { return _size; } //规模
    bool empty() const { return !_root; } //判空
    BinNodePosi(T) root() const { return _root; } //树根
    //插入
    BinNodePosi(T) insertAsRoot ( T const& e ); //插入根节点
    BinNodePosi(T) insertAsLC ( BinNodePosi(T) x, T const& e ); //e作为x的左孩子（原无）插入
    BinNodePosi(T) insertAsRC ( BinNodePosi(T) x, T const& e ); //e作为x的右孩子（原无）插入
    //子树接入
    BinNodePosi(T) attachAsLC ( BinNodePosi(T) x, BinTree<T>* &T ); //T作为x左子树接入
    BinNodePosi(T) attachAsRC ( BinNodePosi(T) x, BinTree<T>* &T ); //T作为x右子树接入
    //删除
    int remove ( BinNodePosi(T) x ); //删除以位置x处节点为根的子树，返回该子树原先的规模
    //子树分离
    BinTree<T>* secede ( BinNodePosi(T) x ); //将子树x从当前树中摘除，并将其转换为一棵独立子树

    //二叉树遍历


    template <typename VST> //操作器
    void travLevel ( VST& visit ) { if ( _root ) _root->travLevel ( visit ); } //层次遍历
    template <typename VST> //操作器
    void travPre ( VST& visit ) { if ( _root ) _root->travPre ( visit ); } //先序遍历
    template <typename VST> //操作器
    void travIn ( VST& visit ) { if ( _root ) _root->travIn ( visit ); } //中序遍历
    template <typename VST> //操作器
    void travPost ( VST& visit ) { if ( _root ) _root->travPost ( visit ); } //后序遍历
    bool operator< ( BinTree<T> const& t ) //比较器（其余自行补充）
    { return _root && t._root && lt ( _root, t._root ); }
    bool operator== ( BinTree<T> const& t ) //判等器
    { return _root && t._root && ( _root == t._root ); }
    /*DSA*/
    /*DSA*/void stretchToLPath() { stretchByZag ( _root ); } //借助zag旋转，转化为左向单链
    /*DSA*/void stretchToRPath() { stretchByZig ( _root, _size ); } //借助zig旋转，转化为右向单链
};




#endif //C_PLUS_PLUS_SOFTWARE_DEVELOPER_MYTREE_H
