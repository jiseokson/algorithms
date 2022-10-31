#ifndef _BIN_SEARCH_TREE_H_
#define _BIN_SEARCH_TREE_H_

#include "BinTree.h"
#include "AVLRebalance.h"

void   initBinSearchTree  (Node ** root);
Node * insertBinSearchTree(Node ** binTree, Data data);
Node * searchBinSearchTree(Node *  root, Data target);
Node * deleteBinSearchTree(Node ** root, Data target);

#endif
