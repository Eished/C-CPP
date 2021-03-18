#include <stdlib.h>
const int Maxsize = 20;
typedef struct
{
  KeyType key;

} TableElem;
typedef struct
{
  TableElem elem[Maxsize + 1];
  int n;
} SqTable;
int SearchBin(SqTable T, KeyType key)
{
  int low, high, mid;
  low = 1;
  high = T.length;
  while (low <= high)
  {
    mid = (low + high) / 2;
    if (mid == key)
      return mid;
    else if (key > mid)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return 0;
}
