////
//// Created by lqc on 2021/10/23.
////
//
//#include "Rtree.h"
////
//// Created by wy on 2021/10/22.
////
//
//#ifndef RTREETEMPLATE_INTSERT_H
//#define RTREETEMPLATE_INTSERT_H
//#include <stdio.h>
//#include <math.h>
//#include <assert.h>
//#include <stdlib.h>
//
//#define ASSERT assert // RTree uses ASSERT( condition )
//#ifndef Min
//#define Min __min
//#endif //Min
//#ifndef Max
//#define Max __max
//#endif //Max
//
////
//// RTree.h
////
//// Fwd decl
//class RTFileStream;
//#define RTREE_TEMPLATE template<class DATATYPE, class ELEMTYPE, int NUMDIMS, class ELEMTYPEREAL, int TMAXNODES, int TMINNODES>
//#define RTREE_QUAL RTree<DATATYPE, ELEMTYPE, NUMDIMS, ELEMTYPEREAL, TMAXNODES, TMINNODES>
//
//#define RTREE_DONT_USE_MEMPOOLS // This version does not contain a fixed memory allocator, fill in lines with EXAMPLE to implement one.此版本不包含固定内存分配器，请用示例填充行以实现一个。
//#define RTREE_USE_SPHERICAL_VOLUME // Better split classification, may be slower on some systems更好的分割分类，在某些系统上可能较慢
//template<class DATATYPE, class ELEMTYPE, int NUMDIMS,
//        class ELEMTYPEREAL = ELEMTYPE, int TMAXNODES = 8, int TMINNODES = TMAXNODES / 2>
//class RTree
//{
//protected:
//
//    struct Node;  // Fwd decl.  Used by other internal structs and iterator由其他内部结构和迭代器使用
//
//public:
//
//    // These constant must be declared after Branch and before Node struct这些常量必须在分支之后和节点结构之前声明
//    // Stuck up here for MSVC 6 compiler.  NSVC .NET 2003 is much happier.
//    enum
//    {
//        MAXNODES = TMAXNODES,                         ///< Max elements in node
//        MINNODES = TMINNODES,                         ///< Min elements in node
//    };
//
//
//public:
//
//    RTree();
//    virtual ~RTree();
//
//    /// Insert entry
//    /// \param a_min Min of bounding rect
//    /// \param a_max Max of bounding rect
//    /// \param a_dataId Positive Id of data.  Maybe zero, but negative numbers not allowed.可能是零，但不允许出现负数
//    void Insert(const ELEMTYPE a_min[NUMDIMS], const ELEMTYPE a_max[NUMDIMS], const DATATYPE& a_dataId);
//
//    /// Remove entry
//    /// \param a_min Min of bounding rect
//    /// \param a_max Max of bounding rect
//    /// \param a_dataId Positive Id of data.  Maybe zero, but negative numbers not allowed.
//    void Remove(const ELEMTYPE a_min[NUMDIMS], const ELEMTYPE a_max[NUMDIMS], const DATATYPE& a_dataId);
//
//    /// Find all within search rectangle
//    /// \param a_min Min of search bounding rect
//    /// \param a_max Max of search bounding rect
//    /// \param a_searchResult Search result array.  Caller should set grow size. Function will reset, not append to array.搜索结果数组。调用方应设置增长大小。函数将重置，而不是附加到数组。
//    /// \param a_resultCallback Callback function to return result.  Callback should return 'true' to continue searching返回结果的\u resultCallback回调函数。回调应返回“true”以继续搜索
//    /// \param a_context User context to pass as parameter to a_resultCallback要作为参数传递给\u resultCallback的\u上下文用户上下文
//    /// \return Returns the number of entries found返回找到的条目数
//    int Search(const ELEMTYPE a_min[NUMDIMS], const ELEMTYPE a_max[NUMDIMS], bool a_resultCallback(DATATYPE a_data, void* a_context), void* a_context);
//
//    /// Remove all entries from tree
//    void RemoveAll();
//
//    /// Count the data elements in this container.  This is slow as no internal counter is maintained.统计此容器中的数据元素。这很慢，因为没有维护内部计数器。
//    int Count();
//
//    /// Load tree contents from file从文件中加载树内容
//    bool Load(const char* a_fileName);
//    /// Load tree contents from stream
//    bool Load(RTFileStream& a_stream);
//
//
//    /// Save tree contents to file将树内容保存到文件
//    bool Save(const char* a_fileName);
//    /// Save tree contents to stream
//    bool Save(RTFileStream& a_stream);
//
//    /// Iterator is not remove safe.
//    class Iterator
//    {
//    private:
//
//        enum { MAX_STACK = 32 }; //最大栈大小。几乎允许n^32，其中n是节点中的分支数
//
//        struct StackElement
//        {
//            Node* m_node;
//            int m_branchIndex;
//        };
//
//    public:
//
//        Iterator()                                    { Init(); }
//
//        ~Iterator()                                   { }
//
//        /// Is iterator invalid
//        bool IsNull()                                 { return (m_tos <= 0); }
//
//        /// Is iterator pointing to valid data
//        bool IsNotNull()                              { return (m_tos > 0); }
//
//        /// Access the current data element. Caller must be sure iterator is not NULL first.访问当前数据元素。调用方必须首先确保迭代器不为NULL。
//        DATATYPE& operator*()
//        {
//                    ASSERT(IsNotNull());
//            StackElement& curTos = m_stack[m_tos - 1];
//            return curTos.m_node->m_branch[curTos.m_branchIndex].m_data;
//        }
//
//        /// Access the current data element. Caller must be sure iterator is not NULL first.
//        const DATATYPE& operator*() const
//        {
//                    ASSERT(IsNotNull());
//            StackElement& curTos = m_stack[m_tos - 1];
//            return curTos.m_node->m_branch[curTos.m_branchIndex].m_data;
//        }
//
//        /// Find the next data element
//        bool operator++()                             { return FindNextData(); }
//
//        /// Get the bounds for this node获取此节点的边界
//        void GetBounds(ELEMTYPE a_min[NUMDIMS], ELEMTYPE a_max[NUMDIMS])
//        {
//                    ASSERT(IsNotNull());
//            StackElement& curTos = m_stack[m_tos - 1];
//            Branch& curBranch = curTos.m_node->m_branch[curTos.m_branchIndex];
//
//            for(int index = 0; index < NUMDIMS; ++index)
//            {
//                a_min[index] = curBranch.m_rect.m_min[index];
//                a_max[index] = curBranch.m_rect.m_max[index];
//            }
//        }
//
//    private:
//
//        /// Reset iterator
//        void Init()                                   { m_tos = 0; }
//
//        /// Find the next data element in the tree (For internal use only)
//        bool FindNextData()
//        {
//            for(;;)
//            {
//                if(m_tos <= 0)
//                {
//                    return false;
//                }
//                StackElement curTos = Pop(); // Copy stack top cause it may change as we use it复制堆栈顶部，因为在使用时它可能会更改
//
//                if(curTos.m_node->IsLeaf())
//                {
//                    // Keep walking through data while we can尽可能地继续浏览数据
//                    if(curTos.m_branchIndex+1 < curTos.m_node->m_count)
//                    {
//                        // There is more data, just point to the next one还有更多数据，请指向下一个
//                        Push(curTos.m_node, curTos.m_branchIndex + 1);
//                        return true;
//                    }
//                    // No more data, so it will fall back to previous level没有更多的数据，因此它将回落到以前的水平
//                }
//                else
//                {
//                    if(curTos.m_branchIndex+1 < curTos.m_node->m_count)
//                    {
//                        // Push sibling on for future tree walk
//                        // This is the 'fall back' node when we finish with the current level
//                        Push(curTos.m_node, curTos.m_branchIndex + 1);
//                    }
//                    // Since cur node is not a leaf, push first of next level to get deeper into the tree
//                    Node* nextLevelnode = curTos.m_node->m_branch[curTos.m_branchIndex].m_child;
//                    Push(nextLevelnode, 0);
//
//                    // If we pushed on a new leaf, exit as the data is ready at TOS
//                    if(nextLevelnode->IsLeaf())
//                    {
//                        return true;
//                    }
//                }
//            }
//        }
//
//        /// Push node and branch onto iteration stack (For internal use only)将节点和分支推送到迭代堆栈上（仅供内部使用）
//        void Push(Node* a_node, int a_branchIndex)
//        {
//            m_stack[m_tos].m_node = a_node;
//            m_stack[m_tos].m_branchIndex = a_branchIndex;
//            ++m_tos;
//                    ASSERT(m_tos <= MAX_STACK);
//        }
//
//        /// Pop element off iteration stack (For internal use only)从迭代堆栈中弹出元素（仅供内部使用）
//        StackElement& Pop()
//        {
//                    ASSERT(m_tos > 0);
//            --m_tos;
//            return m_stack[m_tos];
//        }
//
//        StackElement m_stack[MAX_STACK];              ///迭代
//        int m_tos;                                    ///栈顶索引
//
//        friend RTree; // Allow hiding of non-public functions while allowing manipulation by logical owner
//    };
//
//    /// Get 'first' for iteration
//    void GetFirst(Iterator& a_it)
//    {
//        a_it.Init();
//        Node* first = m_root;
//        while(first)
//        {
//            if(first->IsInternalNode() && first->m_count > 1)
//            {
//                a_it.Push(first, 1); // Descend sibling branch later
//            }
//            else if(first->IsLeaf())
//            {
//                if(first->m_count)
//                {
//                    a_it.Push(first, 0);
//                }
//                break;
//            }
//            first = first->m_branch[0].m_child;
//        }
//    }
//
//    /// Get Next for iteration
//    void GetNext(Iterator& a_it)                    { ++a_it; }
//
//    /// Is iterator NULL, or at end?
//    bool IsNull(Iterator& a_it)                     { return a_it.IsNull(); }
//
//    /// Get object at iterator position
//    DATATYPE& GetAt(Iterator& a_it)                 { return *a_it; }
//
//protected:
//
//    ///最小边界矩形（n维）
//    struct Rect
//    {
//        ELEMTYPE m_min[NUMDIMS];                      ///边界框的最小尺寸
//        ELEMTYPE m_max[NUMDIMS];                      ///边界框的最大尺寸
//    };
//
//    /// 可以是数据，也可以是另一子树
//    ///  父级决定了这一点。
//    /// 如果父级为0，则这是数据
//    struct Branch
//    {
//        Rect m_rect;                                  ///< Bounds
//        union
//        {
//            Node* m_child;                              ///< Child node
//            DATATYPE m_data;                            ///< Data Id or Ptr
//        };
//    };
//
//
//    struct Node
//    {
//        bool IsInternalNode()                         { return (m_level > 0); }
//        bool IsLeaf()                                 { return (m_level == 0); }
//
//        int m_count;
//        int m_level;
//        Branch m_branch[MAXNODES];
//    };
//
//    ///删除操作后重新插入的节点链接列表
//    struct ListNode
//    {
//        ListNode* m_next;
//        Node* m_node;
//    };
//
//    ///用于查找分割分区的变量
//    struct PartitionVars
//    {
//        int m_partition[MAXNODES+1];   //划分
//        int m_total;     //总量size
//        int m_minFill;    //最小填充
//        int m_taken[MAXNODES+1];
//        int m_count[2];     //分割的两个组里的size
//        Rect m_cover[2];     //分割的两个rect
//        ELEMTYPEREAL m_area[2];   //
//
//        Branch m_branchBuf[MAXNODES+1];   //当缓存用
//        int m_branchCount;      //分支当前数量
//        Rect m_coverSplit;   //存缓存当前的矩阵
//        ELEMTYPEREAL m_coverSplitArea;    //大小
//    };
//
//    Node* AllocNode();
//    void FreeNode(Node* a_node);
//    void InitNode(Node* a_node);
//    void InitRect(Rect* a_rect);
//    bool InsertRectRec(Rect* a_rect, const DATATYPE& a_id, Node* a_node, Node** a_newNode, int a_level);
//    bool InsertRect(Rect* a_rect, const DATATYPE& a_id, Node** a_root, int a_level);
//    Rect NodeCover(Node* a_node);
//    bool AddBranch(Branch* a_branch, Node* a_node, Node** a_newNode);
//    void DisconnectBranch(Node* a_node, int a_index);
//    int PickBranch(Rect* a_rect, Node* a_node);
//    Rect CombineRect(Rect* a_rectA, Rect* a_rectB);
//    void SplitNode(Node* a_node, Branch* a_branch, Node** a_newNode);
//    ELEMTYPEREAL RectSphericalVolume(Rect* a_rect);
//    ELEMTYPEREAL RectVolume(Rect* a_rect);
//    ELEMTYPEREAL CalcRectVolume(Rect* a_rect);
//    void GetBranches(Node* a_node, Branch* a_branch, PartitionVars* a_parVars);
//    void ChoosePartition(PartitionVars* a_parVars, int a_minFill);
//    void LoadNodes(Node* a_nodeA, Node* a_nodeB, PartitionVars* a_parVars);
//    void InitParVars(PartitionVars* a_parVars, int a_maxRects, int a_minFill);
//    void PickSeeds(PartitionVars* a_parVars);
//    void Classify(int a_index, int a_group, PartitionVars* a_parVars);
//    bool RemoveRect(Rect* a_rect, const DATATYPE& a_id, Node** a_root);
//    bool RemoveRectRec(Rect* a_rect, const DATATYPE& a_id, Node* a_node, ListNode** a_listNode);
//    ListNode* AllocListNode();
//    void FreeListNode(ListNode* a_listNode);
//    bool Overlap(Rect* a_rectA, Rect* a_rectB);
//    void ReInsert(Node* a_node, ListNode** a_listNode);
//    bool Search(Node* a_node, Rect* a_rect, int& a_foundCount, bool a_resultCallback(DATATYPE a_data, void* a_context), void* a_context);
//    void RemoveAllRec(Node* a_node);
//    void Reset();
//    void CountRec(Node* a_node, int& a_count);
//
//    bool SaveRec(Node* a_node, RTFileStream& a_stream);
//    bool LoadRec(Node* a_node, RTFileStream& a_stream);
//
//    Node* m_root;                                    ///< Root of tree
//    ELEMTYPEREAL m_unitSphereVolume;                 ///< Unit sphere constant for required number of dimensions
//};
//
//void Insert(const ELEMTYPE a_min[NUMDIMS], const ELEMTYPE a_max[NUMDIMS], const DATATYPE& a_dataId)
//{
//
//    //通过min max 声明一个rect
//
//    //InsertRect(&rect, a_dataId, &m_root, 0);//因为要插到叶子节点上，所以级别为0
//}
///* 将数据矩形插入索引结构中。
// InsertRect 提供分裂根；
// 如果根被拆分，则返回 1，否则返回 0。
// level 参数指定从叶子向上的步数
// 要插入的级别； 例如 数据矩形在 level = 0 处进入。
// InsertRect2 进行递归。*/
//bool InsertRect(Rect* a_rect, const DATATYPE& a_id, Node** a_root, int a_level)
//{
//    //声明新节点，防止添加节点后拆出新的节点 Node* newNode
//    //声明新的根节点，防止根节点发生变化 Node* newRoot
//    //声明branch
//
//    if(InsertRectRec(a_rect, a_id, *a_root, &newNode, a_level))  // 判断根节点是否被拆分
//    {
//        newRoot = AllocNode();  // 实例一个新节点
//        newRoot->m_level = (*a_root)->m_level + 1;//因为原来的根节点满了，所以分裂了原来的根节点，向上再加上新的根节点，所以level+1
//        branch.m_rect = NodeCover(*a_root);  //将原来的根节点重新调整矩阵大小，加入branch中
//        branch.m_child = *a_root;    //将原来的根节点加入branch的子节点中
//        AddBranch(&branch, newRoot, NULL);    //将branch中的原根节点，插入到新根节点中
//        branch.m_rect = NodeCover(newNode);   //把因为添加节点后，根节点分裂出来的新节点调整矩阵大小，加入到branch中
//        branch.m_child = newNode; //将分裂出来的新的根节点加入到branch
//        AddBranch(&branch, newRoot, NULL);  //添加到新的根节点
//        *a_root = newRoot;   //该节点为新的根节点
//        return true;
//    }
//
//    return false;
//}
///* 在索引结构中插入一个新的数据矩形。
// 递归下降树，传播分裂回来。
// 如果节点未被拆分，则返回 0。 旧节点更新。
// 如果节点被拆分，则返回 1 并设置指向的指针
// new_node 指向新节点。 旧节点更新为两个节点之一。
// level 参数指定从叶子向上的步数
// 要插入的级别； 例如 数据矩形在 level = 0 处进入。*/
//bool InsertRectRec(Rect* a_rect, const DATATYPE& a_id, Node* a_node, Node** a_newNode, int a_level)
//{
//
//    //可能会用到的方法
//    //PickBranch(Rect* a_rect, Node* a_node)
//
//    //判断当前节点的level是否大于目标级别
//    //（大于）
//    //递归InsertRectRec，看当前节点中添加rect会不会被拆分
//    //（如果添加后没有被拆分）直接合并两个rect  用CombineRect方法
//    //（如果添加后有被拆分）重新调整rect大小  用NodeCover方法和AddBranch方法
//    //（等于）在一个level 直接插入 用AddBranch方法
//    //（小于）直接报错，都没这种情况
//}
//
//
//
//
//
//void Remove(const ELEMTYPE a_min[NUMDIMS], const ELEMTYPE a_max[NUMDIMS], const DATATYPE& a_dataId)
//{
//    //根据min和max声明一个rect
//    //RemoveRect(&rect, a_dataId, &m_root); 把rect和dataid还有根节点传进去
//}
///*从索引结构中删除数据矩形。
//传入一个指向 Rect 的指针，记录的 tid，ptr 到 ptr 到根节点。
//如果没有找到记录，则返回 1，如果成功则返回 0。
//RemoveRect 用于消除根*/
//bool RemoveRect(Rect* a_rect, const DATATYPE& a_id, Node** a_root)
//{
//    //声明一个临时节点 Node* tempNode;
//    //声明一个节点链表，记录的是因为拆分节点之后，发生下溢，需要重新加入到树的节点 ListNode* reInsertList=NULL;
//
//    if(!RemoveRectRec(a_rect, a_id, *a_root, &reInsertList))   // 找到并删除了一个数据项
//    {
//        // 重新插入已消除节点的任何分支
//        while(reInsertList)
//        {
//            tempNode = reInsertList->m_node;
//
//            for(int index = 0; index < tempNode->m_count; ++index)
//            {
//                InsertRect(&(tempNode->m_branch[index].m_rect),   //这个方法是刘庆成实现的，从索引结构中添加数据矩形，你可以随便用
//                           tempNode->m_branch[index].m_data,
//                           a_root,
//                           tempNode->m_level);
//            }
//            //链表指向下一个
//            ListNode* remLNode = reInsertList;
//            reInsertList = reInsertList->m_next;
//            //当前插入过得节点可以释放了
//            FreeNode(remLNode->m_node);
//            FreeListNode(remLNode);
//        }
//
//        // 检查多余的根（不是叶子且只有一个孩子）并消除
//        if((*a_root)->m_count == 1 && (*a_root)->IsInternalNode())
//        {
//            tempNode = (*a_root)->m_branch[0].m_child;
//            FreeNode(*a_root);
//            //删除多余的根节点之后，根节点也要发生改变
//            *a_root = tempNode;
//        }
//        return false;
//    }
//    else
//    {
//        return true;
//    }
//}
///* 从索引结构的非根部分删除一个矩形。
// 由 RemoveRect 调用。 递归下降树，
// 在返回的路上合并分支。
// 如果没有找到记录，则返回 1，如果成功则返回 0。*/
////通俗来讲，只有被成功删除了数据项，才会返回false，否则都是true
//bool RemoveRectRec(Rect* a_rect, const DATATYPE& a_id, Node* a_node, ListNode** a_listNode)
//{
//    if(a_node->IsInternalNode())   //不是叶子节点
//    {
//        //遍历当前节点中branch的rect
//        //判断遍历的rect是否与我们的目标a_rect有重叠部分，用Overlap方法来看是否有重叠部分
//        //如果有重叠部分，下一步递归判断这个子节点RemoveRectRec是否为false，如果是false，说明成功删除了一个数据项
//        //删除数据项之后，判断是否发生了下溢
//        //没有发生下溢， 因为删除了孩子，所以只需调整父矩形的大小，用NodeCover方法来调整矩阵大小
//        //发生下溢， 因为孩子被移除，且节点中没有足够的条目，所以消除节点  用ReInsert方法，先将该节点中branch的孩子加到a_listNode链表(该节点就放的就是需要重新加载到索引结构中的节点)中，然后用DisconnectBranch方法把该节点从branch中去除掉
//    }
//    else     //是叶子节点
//    {
//        //遍历叶子节点中branch的孩子
//        //如果孩子节点与目标a_id比较相等（注意把a_id强转成Node*的形式再做比较），则调用DisconnectBranch方法把该节点从branch中去除掉
//    }
//}