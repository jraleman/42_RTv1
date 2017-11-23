/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 21:05:28 by jaleman           #+#    #+#             */
/*   Updated: 2016/11/03 21:05:29 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Lexicographically compare the null-terminated strings s1 and s2.
*/

size_t    ft_strlen(const char *str)
{
    int   len;

    len = 0;
    while (str[len] != '\0')
        len += 1;
    return (len);
}
