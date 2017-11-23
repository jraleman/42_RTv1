/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_pause_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 22:56:17 by jaleman           #+#    #+#             */
/*   Updated: 2017/11/22 22:56:18 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Prints a message and pause the program, waiting for the user to press enter.
*/

void	debug_pause_print(char *message)
{
	ft_putstr(message);
	ft_getchar();
	ft_putendl(">=========================================================<\n");
	return ;
}
