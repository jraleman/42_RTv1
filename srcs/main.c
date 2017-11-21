#include "rtv1.h"

static void print_usage(char *progname)
{
    ft_putstr("usage: ");
    ft_putstr(progname);
    ft_putendl(" file.rtv1");
    return ;
}

int   main(int argc, char *argv[])
{
    if (argc != 2)
        print_usage(argv[0]);
    else
    {
        // check for file extension (.rtv1)
        // save data to a 2d array
        // read from cli
    }
    return (0);
}
