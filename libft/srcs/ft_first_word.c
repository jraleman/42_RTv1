/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 22:34:01 by jaleman           #+#    #+#             */
/*   Updated: 2017/11/22 22:34:01 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns the first word found in a string.
*/

char		*ft_first_word(char *str)
{
	int		i;
	char	word[9000];

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
