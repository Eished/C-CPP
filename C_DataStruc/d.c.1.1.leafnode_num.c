#include <stdlib.h>
int leafnode_num(BinTree bt)
{
  if (bt == NULL)
    return 0;
  else if (bt->lchild == NULL && bt->rchild == NULL)
    return 1;
  else
    return leafnode_num(bt->lchlid) + leafnode_num(bt->rchild);
}