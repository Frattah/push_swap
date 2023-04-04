#include "push_swap.h"

lst     lst_new(int size)
{
    lst out = (lst)malloc(sizeof(lst_struct));
    if (!out)
        return (NULL);
    out->next = (int *)malloc(sizeof(int) * size);
    out->info = (int *)malloc(sizeof(int) * size);
    out->prev = (int *)malloc(sizeof(int) * size);
    if (!out->next || !out->info || !out->prev)
        return (NULL);
    for (int i = 0; i < size; i++)
    {
        out->next[i] = i + 1;                     
        out->prev[i] = i - 1;
    }
    out->next[size - 1] = -1;
    out->head = -1;
    out->tail = -1;
    out->free = 0;
    out->size = size;
    out->qnt = 0;
    return (out);
}

void    lst_print(lst l)
{
    printf("\n");
    int	j = 0;
    int i = l->head;
    while (j < l->qnt)        
    {
        printf("(%d)", l->info[i]);
        if (j + 1 != l->qnt)
            printf("->");
        i = l->next[i];
	    j++;
    }
    printf("\n");
}

void    lst_ins_back(lst l, int v)
{
    int j = l->free;
    if (l->free == -1)
        return ;
    l->info[j] = v;
    l->free = l->next[j];
    l->prev[l->free] = -1;
    if (l->head == -1)
    {
        l->head = j;
        l->next[j] = j;
        l->prev[j] = j;
        l->tail = j;
    }
    else
    {
        l->next[l->tail] = j;
        l->next[j] = l->head;
        l->prev[j] = l->tail;
        l->tail = j;
        l->prev[l->head] = l->tail;
    }
    l->qnt++;
}

void    lst_debug(lst l)
{
    printf("Head: %d\n", l->head);
    printf("Tail: %d\n", l->tail);
    printf("Next:");
    for (int i = 0; i < l->size; i++)
        printf("|%d|",l->next[i]);
    printf("\nInfo:");
    for (int i = 0; i < l->size; i++)
    {
        if (i == l->free)
            printf("|*|");
        else
            printf("|%d|",l->info[i]);
    }
    printf("\nPrev:");
    for (int i = 0; i < l->qnt; i++)
        printf("|%d|",l->prev[i]);
    printf("\n");
}

int lst_is_ordered(lst l)
{
    int tmp;

    tmp = 0;
    int i = l->head;
    while (tmp != 2)        
    {
        if (l->info[i] > l->info[l->next[i]])
            tmp++;
        if (l->next[i] == l->head)
            break;
        i = l->next[i];
    }
    if (tmp == 2)
        return (0);
    return (1);
}
