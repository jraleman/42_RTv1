#include "rtv1.h"

static void print_usage(char *progname)
{
    printf("usage: %s file.rtv1\n", progname);
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
