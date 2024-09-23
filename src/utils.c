#include "minitalk.h"

void ft_log(int flag, char *str)
{
    if (flag == 0)
    {
        ft_printf("\033[0;32m[LOG]: \033[0m %s\n", str); // Sucesso.
    }
	else if (flag == 1)
	{
		ft_printf("\033[0;31m[ERRO]: \033[0m %s\n", str); // ERRO.
		exit(1);
	}
}

void sigaction_check(struct sigaction *sig_config)
{
	int signal_1;
	int signal_2;
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