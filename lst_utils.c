#include "push_swap.h"

// t_lst     lst_new(int size)
// {
//     t_lst out = (t_lst)malloc(sizeof(struct s_lst));
//     if (!out)
//         return (NULL);

//     out->h = (int *)malloc(sizeof(int) * size);
//     out->info = (t_elem *)malloc(sizeof(t_elem) * size);
//     out->prev = (int *)malloc(sizeof(int) * size);
//     if (!out->next || !out->info || !out->prev)
//         return (NULL);
//     for (int i = 0; i < size; i++)
//     {
//         out->next[i] = i + 1;                     
//         out->prev[i] = i - 1;
//         out->info[i].chunck = 0;
//     }
//     out->next[size - 1] = -1;
//     out->head = -1;
//     out->tail = -1;
//     out->free = 0;
//     out->size = size;
//     out->qnt = 0;
//     return (out);
// }

void    lst_print(t_lst l)
{
    printf("\n");
    int	j = 0;
    t_elem *i;

    i = l->head;
    while (j < l->qnt)        
    {
        printf("(%d|%d)", i->num, i->chunck);
        if (j + 1 != l->qnt)
            printf("->");
        i = i->next;
	    j++;
    }
    printf("\n");
}

void    lst_ins_back(t_lst l, int v)
{
    t_elem *nw;

    nw = (t_elem *)malloc(sizeof(t_elem));
    if (!nw)
        return ;
    nw->next = l->head;
    nw->prev  = l->tail->prev;
    nw->num = v;
    nw->chunck = 0;
    l->tail = nw;
    if (l->qnt == 0)
        l->head = nw;
}

// void    lst_debug(t_lst l)
// {
//     printf("Head: %d\n", l->head);
//     printf("Tail: %d\n", l->tail);
//     printf("Next:");
//     for (int i = 0; i < l->size; i++)
//         printf("|%d|",l->next[i]);
//     printf("\nInfo:");
//     for (int i = 0; i < l->size; i++)
//     {
//         if (i == l->free)
//             printf("|(*|*)|");
//         else
//             printf("|(%d|%d)|",l->info[i].num, l->info[i].chunck);
//     }
//     printf("\nPrev:");
//     for (int i = 0; i < l->qnt; i++)
//         printf("|%d|",l->prev[i]);
//     printf("\n");
// }


// int lst_is_ordered(t_lst l)
// {
//     int tmp;

//     tmp = 0;
//     int i = l->head;
//     while (tmp != 2)        
//     {
//         if (l->info[i].num > l->info[l->next[i]].num)
//             tmp++;
//         if (l->next[i] == l->head)
//             break;
//         i = l->next[i];
//     }
//     if (tmp == 2)
//         return (0);
//     return (1);
// }

// int chunck_ordered(t_lst l, int chunck)
// {
//     int j;
//     int i;
    
//     j = 0;
//     i = l->head;
//     while (j < l->qnt && l->info[i].chunck == chunck)        
//     {
//         if (l->info[i].num < l->info[l->next[i]].num)
//             return (0);
//         i = l->next[i];
//     }
//     return (1);
// }
