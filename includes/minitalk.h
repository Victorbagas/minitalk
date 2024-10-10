/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonfer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:10:39 by antonfer          #+#    #+#             */
/*   Updated: 2024/08/05 13:10:42 by antonfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <signal.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

void	ft_putchar(char c, int *i);
void	ft_putstr_fd(char *s, int fd);
void	ft_putstr(const char *s, int *i);
void	ft_putnbr(int n, int *i);
void	ft_format(const char *s, va_list args, int *i);
int		ft_printf(const char *l, ...);
int		ft_atoi(const char *str);

#endif
