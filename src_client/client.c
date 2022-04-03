/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-nico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 17:21:40 by tde-nico          #+#    #+#             */
/*   Updated: 2022/02/11 10:14:06 by tde-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	arg_errors(int argc, char **argv)
{
	int	i;

	if (argc != 3)
		return (1);
	i = -1;
	while (argv[1][++i])
		if (!ft_strchr("0123456789", argv[1][i]))
			return (1);
	return (0);
}

void	recived(int *pid, char **str, int *g_ack)
{
	if (!ft_strncmp(*str, "ACK", 3))
		ft_printf("ACK successfully recived from: %d\n", *pid);
	*g_ack = 0;
}

int	main(int argc, char **argv)
{
	int		pid;

	if (arg_errors(argc, argv))
		return (1);
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		return (1);
	send(pid, argv[2]);
	recive();
	return (0);
}
