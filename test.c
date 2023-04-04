#include "push_swap.h"

int main(int argc, char **argv)
{
    int i;
    lst l;
    
    l = lst_new(argc - 1);
    i = 1;
    while (i <= argc - 1)
    {
        lst_ins_back(l, atoi(argv[i]));
        i++;
    }
    push_swap(l);
    lst_print(l);
    printf("%d\n", argc);
}