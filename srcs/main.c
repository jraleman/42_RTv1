/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 07:27:52 by jaleman           #+#    #+#             */
/*   Updated: 2017/11/21 20:08:53 by ivelutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
** Prints the usage message if the number of arguments are invalid.
*/

static void		print_usage(char *progname)
{
	ft_putstr("usage: ");
	ft_putstr(progname);
	ft_putendl(" file.rt");
	return ;
}

/*
** Init the rtv1 nested structure values (mlx, image).
*/

static t_rtv1	*init_values(void)
{
	t_rtv1		*rtv1;

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

int				main(int argc, char *argv[])
{
	t_rtv1		*rtv1;

	if (argc != 2)
		print_usage(argv[0]);
	else
	{
		rtv1 = init_values();
		set_hooks(rtv1);
		// 1. check and parse file (check extension and save data to 2d)
		//     rtv1->data = get_data(rtv1);
		// 2. draw the image to the screen
		//     raytrace(rtv1);
		// 3. read from cli (call 2nd function)
		mlx_loop(rtv1->mlx.init);
		ft_memdel((void**)&rtv1);
	}
	return (0);
}
