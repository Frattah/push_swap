#include "push_swap.h"

int main(int argc, char **argv)
{
	int i;
	lst a = lst_new(argc - 1);
	lst b = lst_new(argc - 1);
	i = 0;
	while (i < argc - 1)
	{
		lst_ins_back(a, atoi(argv[i + 1]));
		i++;
	}
	printf("%d", lis(a));
	lst_print(a);
	lst_print(b);

}
