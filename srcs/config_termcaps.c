/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_termcaps.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuokka <vkuokka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 11:10:04 by vkuokka           #+#    #+#             */
/*   Updated: 2020/06/25 03:06:29 by vkuokka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include "print.h"

/*
** Termcaps is used for moving cursor position around the screen.
** Program exits if it fails to configurate termcaps.
*/

void		config_termcaps(void)
{
	char	*type;
	char	buffer[2048];
	int		success;

	type = getenv("TERM");
	if (type == 0)
		ft_putendl_fd("Specify a terminal type.", 2);
	success = tgetent(buffer, type);
	if (success > 0)
		return ;
	else if (success < 0)
		ft_putendl_fd("Could not access the termcap data base.", 2);
	else if (success == 0)
		ft_putendl_fd("Terminal type is not defined.", 2);
	exit(1);
}
