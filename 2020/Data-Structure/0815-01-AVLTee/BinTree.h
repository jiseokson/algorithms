#ifndef _BIN_TREE_H_
#define _BIN_TREE_H_

typedef int Data;

typedef struct _Node {
	Data data;
	struct _Node * left;
	struct _Node * right;
} Node;

inline Node * makeNode(void);
inline void   setData (Node * node, Data data);

inline Node * makeLeftSubTree (Node * mainTree, Node * subTree);
inline Node * makeRightSubTree(Node * mainTree, Node * subTree);

inline Data   getData    (Node * node);
inline Node * getLeftSubTree (Node * binTree);
inline Node * getRightSubTree(Node * binTree);

#endif
