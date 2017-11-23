/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_is_comment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 22:34:36 by jaleman           #+#    #+#             */
/*   Updated: 2017/11/22 22:34:37 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

/*
** Check if the line given as parameter is a comment.
** Useful if you're reading lines and checking comments in a script file.
*/

int   ft_line_is_comment(char *line, char *comment)
{
    return (!ft_strncmp(ft_strtrim(line), comment, ft_strlen(comment)));
}
