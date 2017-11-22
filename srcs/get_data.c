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

int   ft_is_comment(char *line, char sign)
{
    return (ft_strtrim(line)[0] == sign);
}

/*
** Read the file content.
*/

static void read_file(t_rtv1 *rtv1, char *filename)
{
  int   fd;
  char  *buff;

	rtv1 = NULL;
  buff = NULL;
  if ((fd = open(filename, O_RDONLY)) < 0)
      ft_puterror("Error opening file, does it exist?", 3);

  while (get_next_line(fd, &buff) > 0)
  {
      if (!ft_is_comment(buff, '#'))
          printf("%s\n", buff);
      ft_memdel((void **)&buff);
  }

  close(fd);
  return ;
}

/*
** Get the data from the file.
*/

t_rtv1	*get_data(t_rtv1 *rtv1, char *filename)
{
	rtv1 = NULL;
  if (ft_file_extension(filename, ".rt") == 0)
       ft_puterror("Check the file extension! :O", 2);
  read_file(rtv1, filename);
	return (rtv1);
}
