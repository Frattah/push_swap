#include "push_swap.h"
#include <unistd.h>

int main(int argc, char **argv)
{
    int i;
    int opt;
    t_lst a;
    t_lst b;
    
    i = 1;
    a = lst_init('a');
    b = lst_init('b');
    while (i <= argc - 1)
    {
        lst_ins_back(a, atoi(argv[i]));
        i++;
    }

    // PUSHA
    while (a->ln > 3)
        push(a,b);

    // ORDINA I TRE

    // 2 1 3
    if (a->head->num > a->head->next->num && a->tail->num > a->head->next->num && a->head->num < a->tail->num)
        swap(a);

    // 3 2 1
    else if (a->head->num > a->head->next->num && a->tail->num < a->head->next->num)
    {
        rot(a);
        swap(a);
    }

    // 1 3 2
    else if (a->head->num < a->head->next->num && a->tail->num < a->head->next->num && a->head->num < a->tail->num)
    {
        rrot(a);
        swap(a);
    }
    
    // 3 1 2
    else if (a->head->num > a->head->next->num && a->tail->num > a->head->next->num && a->head->num > a->tail->num)
        rot(a);

    // 2 3 1
    else if (a->head->num < a->head->next->num && a->tail->num < a->head->next->num && a->head->num > a->tail->num)
        rrot(a);

    // ORDINA
    while(a->ln != argc - 1)
    {
        lst_print(a);
        lst_print(b);
        calc_moves_b(a,b);
    }

    // AGGIUSTA
    opt = rot_or_rrot(a);
    while(a->head->num > a->tail->num)
    {
        if (!opt)
            rot(a);
        else
            rrot(a);
    }


    lst_print(a);
    // lst_print(b);
    // printf("Mosse: %d\n", a->cnt + b->cnt);
}
