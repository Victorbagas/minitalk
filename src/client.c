/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonfer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:09:45 by antonfer          #+#    #+#             */
/*   Updated: 2024/08/08 09:20:43 by antonfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static int	g_confirm = 0;

static void	ft_resposta_servidor(int nu)
{
	static int	i;

	(void)nu;
	g_confirm = 1;
	if (i == 0)
	{
		i = 1;
	}
}

static void	ft_enviar_bit(pid_t pid, int bit)
{
	int	sig;

	if (bit == 1)
		sig = SIGUSR1;
	else if (bit == 0)
		sig = SIGUSR2;
	if (kill(pid, sig) == -1)
	{
		ft_putstr_fd("\033[101mErro \033[0m", 2);
		exit(EXIT_FAILURE);
	}
	while (!g_confirm)
		pause();
	g_confirm = 0;
}

static void	ft_enviar_char(pid_t pid, unsigned char chr)
{
	int	i;
	int	n[8];

	n[0] = 128;
	n[1] = 64;
	n[2] = 32;
	n[3] = 16;
	n[4] = 8;
	n[5] = 4;
	n[6] = 2;
	n[7] = 1;
	i = 0;
	while (i < 8)
	{
		if (chr & n[i])
			ft_enviar_bit(pid, 1);
		else
			ft_enviar_bit(pid, 0);
		i++;
	}
}

static void	ft_enviar_string(pid_t pid, const char *str)
{
	while (*str)
		ft_enviar_char(pid, *(str++));
	ft_enviar_char(pid, '\0');
}

int	main(int ac, char **av)
{
	pid_t	pid;

	if (ac != 3)
	{
		ft_putstr_fd("Repete: ./client [PID] [MENSAGEM]\n", 2);
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(av[1]);
	if (pid == 0)
	{
		ft_putstr_fd("\033[101mPID Invalido", 2);
		exit(EXIT_FAILURE);
	}
	signal(SIGUSR2, ft_resposta_servidor);
	ft_enviar_string(pid, av[2]);
	return (0);
}
