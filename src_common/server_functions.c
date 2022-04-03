/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-nico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 09:13:51 by tde-nico          #+#    #+#             */
/*   Updated: 2022/02/11 10:12:01 by tde-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_ack;

void	receive_pid(char **str, int *curr_bit, int *pid, int s)
{
	static int	id = 0;

	if (s == SIGUSR2)
		id += recursive_power(2, *curr_bit);
	if (*curr_bit == 31)
	{
		*pid = id;
		id = 0;
		*str = calloc(2, sizeof(char));
		*curr_bit = 0;
		return ;
	}
	(*curr_bit)++;
}

void	restart_variables(int *pid, char **str)
{
	if (str)
	{
		recived(pid, str, &g_ack);
		free(*str);
		*str = 0;
	}
	*pid = 0;
}

void	receive_from_client(int signal)
{
	static int	char_value = 0;
	static int	current_bit = 0;
	static int	client_pid = 0;
	static char	*final_str = 0;

	if (!client_pid)
		receive_pid(&final_str, &current_bit, &client_pid, signal);
	else
	{
		if (signal == SIGUSR2)
			char_value += recursive_power(2, current_bit);
		if (current_bit == 7)
		{
			final_str = ft_charjoin(final_str, char_value);
			current_bit = 0;
			if (char_value == 0)
				return (restart_variables(&client_pid, &final_str));
			char_value = 0;
			return ;
		}
		current_bit++;
	}
}

void	recive(void)
{
	g_ack = 1;
	signal(SIGUSR1, receive_from_client);
	signal(SIGUSR2, receive_from_client);
	while (g_ack)
		pause();
}
