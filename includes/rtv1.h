/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 07:28:01 by jaleman           #+#    #+#             */
/*   Updated: 2017/11/21 20:11:05 by ivelutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

/*
** Required header files.
*/

# include <math.h>
# include <unistd.h>
# include <stdlib.h>

/*
** User defined header files.
*/

# include "mlx.h"
# include "libft.h"
# include "keys.h"

/*
** Macros used for the window.
*/

# define WIN_WIDTH		(1280)
# define WIN_HEIGHT		(720)
# define WIN_TITLE		"RTv1 - Pepa Edition"

/*
** Redefine some of the keys from the keyboard (not following a standard).
*/

# undef KEY_CONTROL
# define KEY_CONTROL	(0X100)
# undef KEY_SHIFT
# define KEY_SHIFT		(0X101)
# undef KEY_COMMAND
# define KEY_COMMAND	(0X103)
# undef KEY_OPTION
# define KEY_OPTION		(0X105)

/*
** RTv1 Structure
**
** @t_mlx  : Required minilibx arguments.
**             init -> set up a connection to the graphical system.
**             win -> manages the window.
**             img -> manipulates the image.
** @t_img  : Used to create a new image.
**             data -> information about the image, allowing to be modified.
**             size -> move from one line to another in the image.
**             endian -> how the pixel color in the image needs to be stored.
**             bpp -> filled with number of bits to represent a pixel color.
** @t_rtv1 : Nested structure that calls all the other structures. ;)
*/

typedef struct	s_mlx
{
	void	*init;
	void	*win;
	void	*img;
}				t_mlx;

typedef struct	s_img
{
	int		bpp;
	int		size;
	int		endian;
	int		*data;
}				t_img;

typedef struct	s_pln
{
	//props (flg, size, coord, color...);
	struct s_pln	*next;
}				t_pln;

typedef struct	s_cone
{
	//props (size, coord, color...);
	struct s_cone	*next;
}				t_cone;

typedef struct	s_sphr
{
	//props (size, coord, color...);
	struct s_sphr	*next;
}				t_sphr;


typedef struct	s_cyld
{
	//props (size, coord, color...);
	struct s_cyld	*next;
}				t_cyld;

// IDEA:
// put_obj(rtv1);
	// if (rtv1->shape.cone != NULL)
		//put_cone(rtv1->shape.cone);

typedef struct	s_shape
{
	t_pln	plane;
	t_cone	cone;
	t_sphr	sphere;
	t_cyld	cylinder;
}				t_shape;

typedef struct	s_rtv1
{
	t_mlx	mlx;
	t_img	image;
}				t_rtv1;

/*
** Function prototypes.
*/

void			set_hooks(t_rtv1 *rtv1);

#endif
