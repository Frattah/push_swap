#include "push_swap.h"

void    lst_print(t_lst l)
{
    int	j = 0;
    t_elem *i;

    printf("\n");
    if (l->id == 'a')
        printf("A:  ");
    else if (l->id == 'b')
        printf("B:  ");
    i = l->head;
    while (j < l->ln)        
    {
        printf("(%d|%d)", i->num, i->col);
        if (j + 1 != l->ln)
            printf("->");
        i = i->next;
	    j++;
    }
    printf("\n");
}

t_lst lst_init(char id)
{
    t_lst l;

    l = (t_lst) malloc(sizeof(struct s_lst));
    if (!l)
        return (NULL);
    l->head = NULL;
    l->tail = NULL;
    l->cur_col = 0;
    l->ln = 0;
    l->id = id;
    return (l);
}

void    lst_ins_back(t_lst l, int v)
{
    t_elem *nw;

    nw = (t_elem *) malloc(sizeof(t_elem));
    if (!nw)
        return ;
    if (l->tail == NULL)
    {
        nw->prev = nw;
        nw->next = nw;
    }
    else
    {
        nw->prev = l->tail;
        nw->next = l->head;
        l->tail->next = nw;
    }
    nw->num = v;
    nw->col = 0;
    l->tail = nw;
    if (l->ln == 0)
        l->head = nw;
    l->ln++;
}

int lst_is_ordered(t_lst l, int col)
{
    int     j;
    int     viol;
    t_elem  *i;

    viol = 0;
    j = -1;
    i = l->head;
    while (++j < l->ln && i->col == col)
    {
        if (i->num < i->next->num)
            viol++;
        i = i->next;
    }
    return (viol < 2);
}
