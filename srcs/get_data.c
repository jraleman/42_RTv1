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
	char	*tmp;
	char	**split;

	tmp = ft_str_remove_whitespace(line);
	split = ft_strsplit(tmp, ':');

	// modify || refactor here
	if (ft_strequ(split[0], "color") == 1 && *split[1] == '#' && ft_str_is_numeric(split[1] + 1))
		shape->color = ft_atoi(split[1] + 1);
	else if (ft_strequ(split[0], "size") == 1 && ft_str_is_numeric(split[1]))
		shape->size = ft_atoi(split[1]);

	ft_memdel((void **)&tmp);
	return ;
}

/*
** Read the line content, returning if it's valid, a comment, or invalid.
*/

static int	read_line_content(t_rtv1 *rtv1, char *line)
{
	int		ret;

	ret = 0;
	if (*line == '\0' || ft_line_is_comment(line, "#") == 1)
		ret = 1;
	else if (ft_strrchr(line, '{') && rtv1->props_flg == 0)
	{
		rtv1->props_flg = 1;
		rtv1->shape.name = ft_first_word(line);
	}
	else if (rtv1->props_flg == 1)
	{
		if (*line == '}')
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
** Read the file content, line by line.
*/

static void	read_file(t_rtv1 *rtv1, int fd)
{
	int		ret;
	char	*buff;

	ret = 0;
	buff = NULL;
	while (get_next_line(fd, &buff) > 0)
	{
		ret = read_line_content(rtv1, ft_strtrim(buff));
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
