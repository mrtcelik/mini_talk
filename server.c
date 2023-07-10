/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucelik <mucelik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 11:18:01 by mucelik           #+#    #+#             */
/*   Updated: 2023/07/09 13:52:36 by mucelik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	demodulate(int sig)
{
	static char	str;
	static int	i = 0;

	if (sig == 30)
		str = str | 1;
	i++;
	if (i == 8)
	{
		write(1, &str, 1);
		i = 0;
		str = 0;
	}
	else
		str = str << 1;
}

int	main(void)
{
	char	*str;

	str = ft_itoa(getpid());
	write(1, str, len(getpid()));
	free(str);
	write(1, "\nWaiting for a message...", 26);
	write(1, "\n", 1);
	while (1)
	{
		signal(SIGUSR1, demodulate);
		signal(SIGUSR2, demodulate);
		pause();
	}
	return (0);
}
