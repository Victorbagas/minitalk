/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonfer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:09:51 by antonfer          #+#    #+#             */
/*   Updated: 2024/08/05 13:09:54 by antonfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	ft_putchar(char c, int *i)
{
	write(1, &c, 1);
	(*i)++;
}

void	ft_putstr(const char *s, int *i)
{
	int	c;

	c = 0;
	if (s == NULL)
		ft_putstr("(null)", i);
	else
	{
		while (s[c] != '\0')
		{
			ft_putchar(s[c], i);
			c++;
		}
	}
}

void	ft_putnbr(int n, int *i)
{
	if (n == -2147483648)
		ft_putstr("-2147483648", i);
	else if (n < 0)
	{
		ft_putchar('-', i);
		n = -n;
		ft_putnbr(n, i);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10, i);
		ft_putchar((n % 10) + 48, i);
	}
	else
		ft_putchar(n + 48, i);
}

void	ft_format(const char *s, va_list args, int *i)
{
	if (*s == '%')
		ft_putchar(*s, i);
	else if (*s == 's')
		ft_putstr(va_arg(args, char *), i);
	else if (*s == 'd' || *s == 'i')
		ft_putnbr(va_arg(args, int), i);
}

int	ft_printf(const char *l, ...)
{
	int		total;
	va_list	args;

	total = 0;
	va_start(args, l);
	while (*l)
	{
		if (*l == '%')
			ft_format(++l, args, &total);
		else
			ft_putchar(*l, &total);
		l++;
	}
	va_end(args);
	return (total);
}
