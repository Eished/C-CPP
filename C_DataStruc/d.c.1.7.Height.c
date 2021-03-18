#include <stdlib.h>
// 递归 求树高
typedef struct btnode
{
  DataType data;
  struct btnode *lchild, *rchild;
} * BinTree;
int Height(BinTree bt)
{
  int lh, rh;
  if (bt != NULL)
    return 0;
  else
  {
    lh = Height(bt->lchild);
    rh = Height(bt->rchild);
    return 1 + (lh > rh ? lh : rh);
  }
}