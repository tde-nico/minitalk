/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-nico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 17:18:54 by tde-nico          #+#    #+#             */
/*   Updated: 2022/02/11 10:18:46 by tde-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include "../libft/libft.h"

int		recursive_power(int nb, int power);
char	*ft_charjoin(char *s1, char s2);
void	recive(void);
void	send(int pid, char *str);
void	recived(int *pid, char **str, int *g_ack);

# define WAIT_TIME 100

#endif
