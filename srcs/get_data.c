/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 21:24:43 by jaleman           #+#    #+#             */
/*   Updated: 2017/11/21 21:24:43 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

// remove memory allocation from this function.
char      *ft_first_word(char *str)
{
    int   i;
    char  word[9000];

    i = 0;
    ft_bzero(word, 9000);
    while (str[i] != '\0' && !ft_iswspace(str[i]))
    {
        word[i] = str[i];
        i += 1;
    }
    word[i] = '\0';
    return (ft_strdup(word));
}

/*
** Save shape properties into the structure.
*/

// static void get_value(char *line, t_shape shape)
// {
//     return ;
// }

/*
** Read the file content.
*/

static void read_file(t_rtv1 *rtv1, int fd)
{
  char  *buff;

  buff = NULL;
  while (get_next_line(fd, &buff) > 0)
  {
      if (ft_line_is_comment(buff, "#") == 1 || *buff == '\0')
      {
          ft_memdel((void **)&buff);
          continue ;
      }
      else if (ft_strrchr(buff, '{'))
      {
          rtv1->shape.name = ft_first_word(buff);
          rtv1->props_flg = 1;
      }
      // else if (rtv1->props_flg == 1)
      //     get_value(buff, rtv1->shape);
      else if (ft_strtrim(buff)[0] == '}')
          rtv1->props_flg = 0;
      ft_memdel((void **)&buff);
  }
  return ;
}

/*
** Get the data from the file.
*/

t_rtv1	*get_data(t_rtv1 *rtv1, char *filename)
{
  int     fd;

  if (ft_file_extension(filename, ".rt") == 0)
      ft_puterror("Check the file extension! :O", 2);
  if ((fd = open(filename, O_RDONLY)) < 0)
      ft_puterror("Error opening file, does it exist?", 3);
  read_file(rtv1, fd);
  close(fd);
	return (rtv1);
}
