/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonfer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:10:03 by antonfer          #+#    #+#             */
/*   Updated: 2024/08/07 17:50:24 by antonfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	initi_array(int n[8])
{
	n[0] = 128;
	n[1] = 64;
	n[2] = 32;
	n[3] = 16;
	n[4] = 8;
	n[5] = 4;
	n[6] = 2;
	n[7] = 1;
}

static void	ft_handler(int sig, siginfo_t *info, void *context)
{
	static char	chr;
	static int	i;
	static int	n[8];
	static int	client_pid;

	(void)context;
	if (i == 0)
		initi_array(n);
	client_pid = info->si_pid;
	if (sig == SIGUSR1)
		chr += n[i];
	i++;
	if (i == 8)
	{
		write(1, &chr, 1);
		if (chr == '\0')
			write(1, "\n", 1);
		i = 0;
		chr = 0;
	}
	kill(client_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉");
	ft_printf("BEM-VINDO AO SERVIDOR DO ANTÓNIO VICTOR");
	ft_printf("🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉\n");
	ft_printf("\033[93mPID: %d\n \033[0m", getpid());
	ft_printf("\033[90mEsperando pela Mensagem!\n \033[0m");
	sa.sa_sigaction = ft_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
