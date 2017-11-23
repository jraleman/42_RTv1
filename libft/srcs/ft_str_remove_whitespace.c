/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_remove_whitespace.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 12:37:58 by jaleman           #+#    #+#             */
/*   Updated: 2016/12/02 12:38:01 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Create a new string, and remove all the whitespace from the string.
** For instance: "  a b c   d  " -> "abcd".
*/

char		*ft_str_remove_whitespace(char *str)
{
	int		i;
	int		j;
	char	shrink[9001];

	i = 0;
	j = 0;
	ft_bzero(shrink, 9001);
	while (str[i] != '\0')
	{
		if (!ft_iswspace(str[i]))
			shrink[j++] = str[i];
		i += 1;
	}
	return (ft_strdup(shrink));
}
