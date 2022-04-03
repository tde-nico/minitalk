/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-nico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 17:34:42 by tde-nico          #+#    #+#             */
/*   Updated: 2022/02/08 16:54:46 by tde-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	recived(int *pid, char **str, int *g_ack)
{
	(void)g_ack;
	ft_putendl_fd(*str, 1);
	usleep(WAIT_TIME * 10);
	send(*pid, "ACK");
}

int	main(void)
{
	int	pid;

	pid = (int)(getpid());
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	recive();
	return (0);
}
