/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucelik <mucelik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 11:17:58 by mucelik           #+#    #+#             */
/*   Updated: 2023/07/09 11:54:24 by mucelik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	len(int a)
{
	int	i;

	i = 0;
	while (a)
	{
		i++;
		a = a / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int			length;
	char		*ret;
	const char	*digits = "0123456789";

	length = len(n);
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (0);
	ret[length] = 0;
	if (n == 0)
		ret[0] = '0';
	if (n < 0)
		ret[0] = '-';
	while (n)
	{
		if (n > 0)
			ret[--length] = digits[n % 10];
		else
			ret[--length] = digits[n % 10 * -1];
		n /= 10;
	}
	return (ret);
}

int	ft_atoi(const char *str)
{
	int	d;
	int	s;

	d = 1;
	s = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
			str++;
	if (*str == '-')
	{
		d = d * -1;
		str++;
	}
	else if (*str == '+')
		str++;
	if (*str == '-' || *str == '+')
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		s = (s * 10);
		s = s + (*str - '0');
		str++;
	}
	return (s * d);
}
