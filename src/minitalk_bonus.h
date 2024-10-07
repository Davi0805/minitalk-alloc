/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelo-ca <dmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:30:22 by dmelo-ca          #+#    #+#             */
/*   Updated: 2024/10/07 14:57:17 by dmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# define LOG 0
# define ERRO 1

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include "../print_functions/ft_printf.h"

//FLAG: 0 = SEM STRLEN | 1 = COM STRLEN | 2 = ALOCACAO CONCLUIDA

typedef struct s_buffer
{
	int				flag;
	int				size;
	char			*str;
	char			c;
	unsigned int	str_index;
}					t_data_buffer;

void	ft_log(int flag, char *str);
void	sigaction_check(struct sigaction *sig_config);

#endif
