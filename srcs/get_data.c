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

/*
** Read the file content.
*/

static void read_file(t_rtv1 *rtv1, char *filename)
{
  int   fd;

	rtv1 = NULL;
  if ((fd = open(filename, O_RDONLY)) < 0)
      ft_puterror("Error opening file, does it exist?", 3);
  //while (get_next_line())
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
