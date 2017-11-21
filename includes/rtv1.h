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

# define WIN_WIDTH    (1280)
# define WIN_HEIGHT    (720)
# define WIN_TITLE    "RTv1 - Pepa Edition"

/*
** Redefine some of the keys from the keyboard (not following a standard).
*/

# undef KEY_CONTROL
# define KEY_CONTROL  (0X100)
# undef KEY_SHIFT
# define KEY_SHIFT    (0X101)
# undef KEY_COMMAND
# define KEY_COMMAND  (0X103)
# undef KEY_OPTION
# define KEY_OPTION    (0X105)

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

typedef struct  s_mlx
{
  void   *init;
  void   *win;
  void   *img;
}               t_mlx;

typedef struct  s_img
{
  int    bpp;
  int    size;
  int    endian;
  int    *data;
}               t_img;

typedef struct  s_rtv1
{
  t_mlx  mlx;
  t_img  image;
}               t_rtv1;

/*
** Function prototypes.
*/

void      set_hooks(t_rtv1 *rtv1);

#endif
