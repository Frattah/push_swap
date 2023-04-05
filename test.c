#include "push_swap.h"
#include <unistd.h>

void    start(t_lst a, t_lst b)
{
    int mid;
    int size;           // salvo la lunghezza perché viene modificata strada facendo da push
	int	j;

    size = a->ln;
    j = -1;
	mid = find_midpoint(a, a->cur_col);
    printf("%d\n",mid);
	while (++j < size && pushable(a, mid))
	{
        printf("[%d]\n",a->head->num);
		if (a->head->num < mid)
			push(a,b, 1);
		else if (a->head->num >= mid)
            rot(a);
        lst_print(a);
        lst_print(b);
	}
}

void	push_swap(t_lst a, t_lst b)
{
    start(a,b);
}

int main(int argc, char **argv)
{
    int i;
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
    // lst_debug(a);
	push_swap(a,b);
	// lst_print(b);
}