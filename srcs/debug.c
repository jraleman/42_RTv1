/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 00:28:02 by jaleman           #+#    #+#             */
/*   Updated: 2017/11/23 00:28:03 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
** This functions is used for testing only.
** Prints the shape values.
*/

void		print_shape_vals(t_shape shape)
{
	printf(" > shape : %s\n", shape.name);
	printf(" > size  : %d\n", shape.size);
	printf(" > color : %d\n", shape.color);
	putchar('\n');
	return ;
}
