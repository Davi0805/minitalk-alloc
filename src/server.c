#include "minitalk.h"

void str_size(int signum, siginfo_t *info, data_buffer *buffer, int *bit_count)
{

	if (signum == SIGUSR1)
		{
			buffer->size = (buffer->size << 1) | 0;
		}
		else if (signum == SIGUSR2)
		{
			buffer->size = (buffer->size << 1) | 1;
		}
		(*bit_count)++;


	if (*bit_count == (sizeof(unsigned int) * 8))
	{
		ft_printf("[SIZE OF STRING]:  %u\n", buffer->size);
		*bit_count = 0;
		buffer->flag = 1;
		kill(info->si_pid, SIGUSR1);
	}
}

void str_parse(int signum, data_buffer *buffer, int *bit_count)
{
/* 	if (buffer->flag == 1)
	{
		buffer->str = ft_calloc((buffer->size + 1), sizeof(char));
		if (buffer->str == NULL)
			ft_log(ERRO, "Falha ao alocar a string! | Failed to allocate string!");
		buffer->flag = 2;
	} */

	//DESENVOLVER RESTO DA STR PARSE
	if (signum == SIGUSR1)
		buffer->c = (buffer->c << 1) | 0;
	else if (signum == SIGUSR2)
		buffer->c = (buffer->c << 1) | 1;

	(*bit_count)++;

	/* if((*bit_count == (sizeof(char) * 8)) && buffer->c == '\0')
	{
		buffer->str[buffer->str_index] = buffer->c;
		ft_printf("[STRING]:  %s\n", buffer->str);
		free(buffer->str);
		*bit_count = 0;
		buffer->flag = 0;
		buffer->c = 0;
		buffer->str_index = 0;
		buffer->size = 0;
	}
	else if(*bit_count == (sizeof(char) * 8))
	{
		buffer->str[buffer->str_index] = buffer->c;
		*bit_count = 0;
		buffer->str_index++;
		buffer->c = 0;
	} */
	if (*bit_count == (sizeof(char) * 8))
    {
		ft_printf("Charcater %c\n", buffer->c);
        buffer->str[buffer->str_index] = buffer->c;
        buffer->str_index++;
        *bit_count = 0;
        buffer->c = 0;

        if (buffer->str[buffer->str_index - 1] == '\0')
        {
            ft_printf("[STRING]:  %s\n", buffer->str);
            free(buffer->str);
            buffer->flag = 0;
            buffer->str_index = 0;
            buffer->size = 0;
			buffer->c = 0;
        }
    }
}

/* void str_parse(int signum, data_buffer *buffer, int *bit_count)
{
    if (signum == SIGUSR1)
        buffer->c = (buffer->c << 1) | 0;
    else if (signum == SIGUSR2)
        buffer->c = (buffer->c << 1) | 1;

    (*bit_count)++;

    if (*bit_count == (sizeof(char) * 8))
    {
        buffer->str[buffer->str_index] = buffer->c;
        buffer->str_index++;
        *bit_count = 0;
        buffer->c = 0;

        if (buffer->str[buffer->str_index - 1] == '\0')
        {
            ft_printf("[STRING]:  %s\n", buffer->str);
            free(buffer->str);
            buffer->flag = 0;
            buffer->str_index = 0;
            buffer->size = 0;
        }
    }
} */

void handle_sigusr(int signum, siginfo_t *info, void *context)
{
	static data_buffer buffer;
    static int bit_count;

	/* ft_log(LOG, "Sinal recebido!"); */

	(void)context;

	if (buffer.flag == 0)
		str_size(signum, info, &buffer, &bit_count);
	
	if (buffer.flag == 1 && buffer.str == NULL)
	{
		buffer.str = ft_calloc((buffer.size + 1), sizeof(char));
		if (buffer.str == NULL)
			ft_log(ERRO, "Falha ao alocar a string! | Failed to allocate string!");
		buffer.flag = 2;
	}
	else if (buffer.flag == 2)
		str_parse(signum, &buffer, &bit_count);
	
		
}

int	main(void)
{
	struct sigaction	sig_config;

	sig_config.sa_flags = SA_RESTART | SA_SIGINFO;
	sig_config.sa_sigaction = handle_sigusr;
	sigemptyset(&sig_config.sa_mask);
	sigaction_check(&sig_config);
	ft_log(LOG, "Server initialized! | Servidor iniciado! ");

	/* ft_printf("Size of int %d", sizeof(int)); */

	ft_printf("\033[0;32m[PID]:  \033[0m%d\n", getpid());
	while (1)
		pause();
	return (0);
}
