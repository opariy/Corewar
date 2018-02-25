/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 18:52:49 by opariy            #+#    #+#             */
/*   Updated: 2017/10/29 18:52:50 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H
# define GLOBAL_H
# include "corewar.h"

typedef struct					s_process
{
	unsigned int				regs[REG_NUMBER];
	int							cary;
	int							mem_addres;
	int							number;
	void						(*f)(struct s_process *p);
	int							exec_cycle;
	int							alive;
	int							args[4];
	int							codage_octal;
	int							command;
	struct s_process			*next;
}								t_process;

typedef struct					s_player
{
	unsigned char				magic[4];
	unsigned char				*prog_name;
	unsigned char				prog_size[4];
	unsigned char				*comment;
	int							number;
	int							player_size;
	unsigned char				*instructions;
	int							mem_addr;
	struct s_player				*next;
	int							n_live;
}								t_player;

typedef struct					s_data
{
	int							dump;
	int							aff;
	int							visual;
	int							count_players;
	int							nbr_live;
	int							max_checks;
	int							cycle;
	t_player					*last_live;
	int							cycle2die;
	int							cycle_per_sec;
	int							count_processes;
	int							change_cycle;
	unsigned char				**map;
	t_player					*player_g;
	t_process					*process_g;
}								t_data;

t_data g_dt;
void							(*g_f[16])(struct s_process *p);

#endif
