#include "push_swap.h"

// void    start(t_lst a, t_lst b)
// {
//     int mid;
// 	int	i;
// 	int	size;
//     int rot_type;

// 	size = a->qnt;
// 	i = -1;
// 	mid = find_midpoint(a);
//     rot_type = 0;
//     if (rot_or_rrot(a,mid))
//         rot_type = 1;
// 	while (++i < size && pushable(a, mid))
// 	{
// 		if (a->info[a->head].num < mid)
//         {
// 			push(a,b, b->curr_chunck);
//         }
// 		else
//         {
//             if (rot_type)
//                 rot(a);
//             else
//                 rrot(a);
//         }
// 	}
// }

// void	push_swap(t_lst a, t_lst b)
// {
//     int c;

//     while (!lst_is_ordered(a) || a->qnt != 2)
//     {
//         b->curr_chunck++;
//         start(a,b);
//     }
//     if (!lst_is_ordered(a))
//         swap(a);
//     c = b->info[b->head].chunck;
//     lst_debug(a);
// 	lst_debug(b);
//     if (chunck_ordered(b, c))
//     {
//         while (b->info[b->head].chunck == c)
//             push(b,a,c);
//     }
//     lst_debug(a);
// 	lst_debug(b);
// }

int main(int argc, char **argv)
{
    int i;
    t_lst a;
    t_lst b;
    
    a = (t_lst) malloc(sizeof(struct s_lst));
    b = (t_lst) malloc(sizeof(struct s_lst));
    a->qnt = 0;
    i = 1;
    while (i <= argc - 1)
    {
        lst_ins_back(a, atoi(argv[i]));
        i++;
    }
    // lst_debug(a);
	//push_swap(a,b);
	lst_print(a);
	// lst_print(b);
}