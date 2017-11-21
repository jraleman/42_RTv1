#include "rtv1.h"

/*
** Hook to exit the program cleanly, by clicking the red button in the winow's
** frame thingy from the mac window.
*/

static int	exit_hook(t_rtv1 *rtv1)
{
    mlx_destroy_window(rtv1->mlx.init, rtv1->mlx.win);
    exit(0);
}

/*
** Set mlx the hooks (keys, and exit).
*/

void      set_hooks(t_rtv1 *rtv1)
{
    mlx_hook(rtv1->mlx.win, 17, 0, exit_hook, rtv1);
    return ;
}
