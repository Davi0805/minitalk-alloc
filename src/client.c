/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelo-ca <dmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:56:40 by dmelo-ca          #+#    #+#             */
/*   Updated: 2024/10/07 14:44:53 by dmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_number_32bit(int pid, int number)
{
	int	bit_count;

	bit_count = (sizeof(int) * 8) - 1;
	while (bit_count >= 0)
	{
		if ((number >> bit_count) & 1)
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				perror("kill");
				ft_log(ERRO, "Failed to send SIGUSR2");
			}
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				perror("kill");
				ft_log(ERRO, "Failed to send SIGUSR1");
			}
		}
		pause();
/* 		usleep(100); */
		bit_count--;
	}
}

void	send_char(int pid, char c)
{
	int	bit_count;

	bit_count = (sizeof(char) * 8) - 1;
	while (bit_count >= 0)
	{
		if ((c >> bit_count) & 1)
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				perror("kill");
				ft_log(ERRO, "Failed to send SIGUSR2");
			}
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				perror("kill");
				ft_log(ERRO, "Failed to send SIGUSR1");
			}
		}
		pause();
/* 		usleep(100); */
		bit_count--;
	}
}

void	send_string(int pid, char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		send_char(pid, str[i++]);
	send_char(pid, '\0');
}

void	handle_sigusr_client(int signum, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (signum == SIGUSR2)
		ft_log(LOG, "Mensagem recebida com sucesso!");
}

int	main(int ac, char **av)
{
	int					server_pid;
	int					number;
	struct sigaction	sig_config;

	server_pid = ft_atoi(av[1]);
	number = ft_strlen(av[2]);
	if (ac != 3)
		ft_log(ERRO, "Numero insuficiente de argumentos!");
	sig_config.sa_flags = SA_RESTART | SA_SIGINFO;
	sig_config.sa_sigaction = handle_sigusr_client;
	sigemptyset(&sig_config.sa_mask);
	sigaction_check(&sig_config);
	ft_printf("Tamanho da string = %u\n", number);
	send_number_32bit(server_pid, number);
	usleep(3000);
	send_string(server_pid, av[2]);
	return (0);
}
