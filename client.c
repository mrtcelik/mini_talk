/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucelik <mucelik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 11:18:10 by mucelik           #+#    #+#             */
/*   Updated: 2023/07/09 13:52:11 by mucelik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	modulate(int pid, char *str)
{
	int		i;
	char	c;

	while (*str)
	{
		i = 7;
		c = *str++;
		while (i >= 0)
		{
			if (c >> i & 1)
				kill(pid, 30);
			else
				kill(pid, 31);
			usleep(DELAY_TIME);
			i--;
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		modulate(ft_atoi(argv[1]), argv[2]);
		modulate(ft_atoi(argv[1]), "\n");
	}
	else
	{
		write(1, "Error: wrong format.\n", 22);
		write(1, "Try: ./client <PID> <MESSAGE>\n", 31);
	}
	return (0);
}
