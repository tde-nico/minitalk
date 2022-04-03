/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-nico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 09:08:50 by tde-nico          #+#    #+#             */
/*   Updated: 2022/02/08 17:04:02 by tde-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(unsigned char c, int pid)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		if (c & 0x01)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		c = c >> 1;
		usleep(WAIT_TIME);
	}
}

void	send_pid(int my_pid, int pid)
{
	int	i;

	i = -1;
	while (++i < 32)
	{
		if (my_pid & 0x01)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		my_pid = my_pid >> 1;
		usleep(WAIT_TIME);
	}
}

void	send(int pid, char *str)
{
	char	*to_send;
	int		i;

	if (pid <= 0)
		return ;
	to_send = str;
	i = -1;
	send_pid(getpid(), pid);
	while (to_send[++i])
		send_char(to_send[i], pid);
	send_char(to_send[i], pid);
}
