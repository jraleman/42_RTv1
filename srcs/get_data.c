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
** Save shape properties into the structure.
*/

static void	parse_value(t_shape *shape, char *line)
{
	int		pos;

	pos = 0;
	(void)shape;
	(void)line;
	//printf("%s\n", line);
	return ;
}

static int	read_line(t_rtv1 *rtv1, char *line)
{
	int		ret;

	ret = 0;
	printf("%s\n", line);
	if (*line == '\0' || ft_line_is_comment(line, "#") == 1)
		ret = 1;
	else if (ft_strrchr(line, '{') && rtv1->props_flg == 0)
	{
		rtv1->props_flg = 1;
		rtv1->shape.name = ft_first_word(line);
	}
	else if (rtv1->props_flg == 1)
	{
		if (line[0] == '}')
			rtv1->props_flg = 0;
		else
			parse_value(&rtv1->shape, line);
	}
	else
		ret = -1;
	ft_memdel((void **)&line);
	return (ret);
}

/*
** Read the file content.
*/

static void	read_file(t_rtv1 *rtv1, int fd)
{
	int		ret;
	char	*buff;

	ret = 0;
	buff = NULL;
	while (get_next_line(fd, &buff) > 0)
	{
		ret = read_line(rtv1, ft_strtrim(buff));
		if (ret == -1)
			ft_puterror("Invalid characters in the file!", 4);
		// else if (ret == 2)
		// 	rtv1->shape = rtv1->shape.next;
		ft_memdel((void **)&buff);
	}
	return ;
}

/*
** Get the data from the file.
*/

t_rtv1		*get_data(t_rtv1 *rtv1, char *filename)
{
	int		fd;

	if (ft_file_extension(filename, ".rt") == 0)
		ft_puterror("Check the file extension! :O", 2);
	if ((fd = open(filename, O_RDONLY)) < 0)
		ft_puterror("Error opening file, does it exist?", 3);
	read_file(rtv1, fd);
	close(fd);
	return (rtv1);
}
