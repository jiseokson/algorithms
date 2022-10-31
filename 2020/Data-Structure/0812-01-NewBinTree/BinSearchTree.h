#ifndef _BIN_SEARCH_TREE_H_
#define _BIN_SEARCH_TREE_H_

#include "BinTree.h"

void   initBinSearchTree  (Node ** root);
void   insertBinSearchTree(Node ** root, Data data);
Node * searchBinSearchTree(Node *  root, Data target);
Node * deleteBinSearchTree(Node ** root, Data target);

#endif
