/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucelik <mucelik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 11:18:04 by mucelik           #+#    #+#             */
/*   Updated: 2023/07/09 13:51:57 by mucelik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef DELAY_TIME
#  define DELAY_TIME 100
# endif

//utils.c
char	*ft_itoa(int a);
int		ft_atoi(const char *str);
int		len(int a);
//client.c
void	modulate(int pid, char *str);
//server.c
void	demodulate(int sig);

#endif
