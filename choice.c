#include "push_swap.h"

int lis(lst l) {
    int i;
    int j;
    int k;
    int cnt;
    int max;

    max = 0;
    i = l->head;
    while(i < l->qnt)
    {
        j = i;
        cnt = 0;
        k = 0;
        while (j < l->qnt)
        {
            k++;
            cnt++;
            j = l->next[j];
        }
        if (max < cnt)
            max = cnt;
        i = l->next[i];
    }
    return (max);
}