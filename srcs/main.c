#include "rtv1.h"

/*
** Prints the usage message if the number of arguments are invalid.
*/

static void print_usage(char *progname)
{
    ft_putstr("usage: ");
    ft_putstr(progname);
    ft_putendl(" file.rtv1");
    return ;
}

/*
** Init the rtv1 nested structure values (mlx, image).
*/

static t_rtv1 *init_values(void)
{
    t_rtv1  *rtv1;

    rtv1 = (t_rtv1 *)malloc(sizeof(t_rtv1));
    if (rtv1 == NULL)
        ft_puterror("Memory Allocation failed! :O", 1);
    rtv1->mlx.init = mlx_init();
    rtv1->mlx.img = mlx_new_image(rtv1->mlx.init, WIN_WIDTH, WIN_HEIGHT);
    rtv1->mlx.win = mlx_new_window(rtv1->mlx.init, WIN_WIDTH, WIN_HEIGHT, \
                                    WIN_TITLE);\
    rtv1->image.data = (int *)mlx_get_data_addr(rtv1->mlx.img, \
                                                &rtv1->image.bpp, \
                                                &rtv1->image.size, \
                                                &rtv1->image.endian);
    return (rtv1);
}

/*
** Let's rock and roll! (∩｀-´)⊃━☆ﾟ.*･｡ﾟ
*/

int   main(int argc, char *argv[])
{
    t_rtv1  *rtv1;

    if (argc != 2)
        print_usage(argv[0]);
    else
    {
        rtv1 = init_values();
        set_hooks(rtv1);
        // check for file extension (.rtv1)
        // save data to a 2d array
        // read from cli
        mlx_loop(rtv1->mlx.init);
    }
    return (0);
}
