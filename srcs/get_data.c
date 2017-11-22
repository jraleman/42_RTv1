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

t_rtv1	*get_data(t_rtv1 *rtv1, char *filename)
{
	rtv1 = NULL;
  if (ft_file_extension(filename, ".rt") == 0)
       ft_puterror("Check the file extension! :O", 2);
	return (rtv1);
}
