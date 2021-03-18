#include <stdlib.h>
// 递归 二叉链表 先序遍历
typedef struct btnode
{
  DataType data;
  struct btnode *lchild, *rchild;
} * BinTree;
void preorder(BinTree bt)
{
  if (bt != NULL)
  {
    visit(bt);
    preorder(bt->lchild);
    preorder(bt->rchild);
  }
}