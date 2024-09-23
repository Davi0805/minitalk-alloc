#ifndef MINITALK_H
#define MINITALK_H

#define LOG 0
#define ERRO 1

//FLAG: 0 = SEM STRLEN | 1 = COM STRLEN | 2 = ALOCACAO CONCLUIDA

typedef struct	buffer
{
	int flag;
	int size;
	char *str;
	char c;
	unsigned int str_index;
}				data_buffer;


#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "../print_functions/ft_printf.h"

void ft_log(int flag, char *str);
void sigaction_check(struct sigaction *sig_config);

#endif
