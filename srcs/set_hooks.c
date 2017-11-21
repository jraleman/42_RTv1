/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 07:28:08 by jaleman           #+#    #+#             */
/*   Updated: 2017/11/21 07:28:09 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
** Hook to exit the program cleanly, by clicking the red button in the winow's
** frame thingy from the mac window.
*/

static int	exit_hook(t_rtv1 *rtv1)
{
	mlx_destroy_window(rtv1->mlx.init, rtv1->mlx.win);
	exit(0);
	return (0);
}

/*
** Hook used when a key is released, reset the value of a key back to zero.
*/

static int	key_release_hook(int key, t_rtv1 *rtv1)
{
	if (key == KEY_ESCAPE)
		exit_hook(rtv1);
	return (0);
}

/*
** Hook used when a key is released, updates the value of a key to one,
** indicating that it's being pressed.
*/

static int	key_press_hook(int key, t_rtv1 *rtv1)
{
	if (key == KEY_ESCAPE)
		exit_hook(rtv1);
	return (0);
}

/*
** Set mlx the hooks (keys, and exit).
*/

void		set_hooks(t_rtv1 *rtv1)
{
	mlx_hook(rtv1->mlx.win, 2, 0, key_press_hook, rtv1);
	mlx_hook(rtv1->mlx.win, 3, 0, key_release_hook, rtv1);
	mlx_hook(rtv1->mlx.win, 17, 0, exit_hook, rtv1);
	return ;
}
