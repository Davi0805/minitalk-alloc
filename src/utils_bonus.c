/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelo-ca <dmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:54:38 by dmelo-ca          #+#    #+#             */
/*   Updated: 2024/10/07 14:32:44 by dmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_log(int flag, char *str)
{
	if (flag == 0)
	{
		ft_printf("\033[0;32m[LOG]: \033[0m %s\n", str);
	}
	else if (flag == 1)
	{
		ft_printf("\033[0;31m[ERRO]: \033[0m %s\n", str);
		exit(1);
	}
}

void	sigaction_check(struct sigaction *sig_config)
{
	int		signal_1;
	int		signal_2;

	signal_1 = sigaction(SIGUSR1, sig_config, NULL);
	signal_2 = sigaction(SIGUSR2, sig_config, NULL);
	if (signal_1 == -1)
	{
		perror("sigaction");
		ft_log(ERRO, "Failed to setup SIGUSR1 | Falha ao configurar SIGUSR1");
	}
	if (signal_2 == -1)
	{
		perror("sigaction");
		ft_log(ERRO, "Failed to setup SIGUSR2 | Falha ao configurar SIGUSR2");
	}
}
