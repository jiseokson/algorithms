#ifndef _BIN_TREE_H_
#define _BIN_TREE_H_

typedef int BinTreeNodeData;

typedef struct _BinTreeNode {
	BinTreeNodeData data;
	struct _BinTreeNode * left;
	struct _BinTreeNode * right;
} BinTreeNode;

inline BinTreeNode * makeBinTreeNode   (void);
inline void          setBinTreeNodeData(BinTreeNode * binTreeNode, BinTreeNodeData data);

inline BinTreeNode * makeLeftSubTree (BinTreeNode * mainTree, BinTreeNode * subTree);
inline BinTreeNode * makeRightSubTree(BinTreeNode * mainTree, BinTreeNode * subTree);

inline BinTreeNodeData getBinTreeNodeData(BinTreeNode * binTreeNode);
inline BinTreeNode *   getLeftSubTree    (BinTreeNode * binTree);
inline BinTreeNode *   getRightSubTree   (BinTreeNode * binTree);

#endif
