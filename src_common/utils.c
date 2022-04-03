/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-nico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 17:50:21 by tde-nico          #+#    #+#             */
/*   Updated: 2022/02/11 10:14:49 by tde-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0 && power == 0)
		return (1);
	else
		return (nb * recursive_power(nb, power - 1));
}

char	*ft_charjoin(char *s1, char s2)
{
	size_t	i;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1)
		return (NULL);
	str = malloc((ft_strlen(s1) + 2) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = -1;
	if (s1)
		while (s1[++i] != '\0')
			str[i] = s1[i];
	str[i++] = s2;
	str[ft_strlen(s1) + 1] = '\0';
	free(s1);
	return (str);
}
