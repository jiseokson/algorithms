#ifndef _BIN_SEARCH_TREE_H_
#define _BIN_SEARCH_TREE_H_

#include "BinTree.h"

//typedef BinTreeNode     BinSearchTreeNode;
//typedef BinTreeNodeData BinSearchTreeNodeData;

inline void            initBinSearchTree       (BinTreeNode ** root);
inline BinTreeNodeData getBinSearchTreeNodeData(BinTreeNode *  binSearchTreeNode);
       void            insertBinSearchTree     (BinTreeNode ** root, BinTreeNodeData data);
       BinTreeNode *   searchBinSearchTree     (BinTreeNode *  root, BinTreeNodeData target);
       BinTreeNode *   deleteBinSearchTree     (BinTreeNode ** root, BinTreeNodeData target);

#endif
