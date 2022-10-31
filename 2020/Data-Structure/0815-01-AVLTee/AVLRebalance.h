#ifndef _AVL_REBALANCE_H_
#define _AVL_REBALANCE_H_

#include "BinTree.h"

int getHeight(Node * binTree);
int getHeightDifference(Node * binTree);

Node * rotateLL(Node * binTree);
Node * rotateRR(Node * binTree);
Node * rotateLR(Node * binTree);
Node * rotateRL(Node * binTree);

Node * rebalance(Node * binTree);

#endif
