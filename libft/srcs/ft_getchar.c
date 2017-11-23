/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 22:34:28 by jaleman           #+#    #+#             */
/*   Updated: 2017/11/22 22:34:29 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Obtains the next input character (if present) from the stream pointed
** at by stream, by a macro that expands in-line.
*/

int ft_getchar(void)
{
    static int  i = 0;
    static char buff[BUFSIZ];
    static char *buff_ptr = buff;

    if (i == 0)
    {
        i = read(0, buff, 1);
        buff_ptr = buff;
    }
    if (--i >= 0)
        return  (*buff_ptr++);
    return (EOF);
}
