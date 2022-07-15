/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhebert <anhebert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:46:26 by anhebert          #+#    #+#             */
/*   Updated: 2022/06/27 13:54:46 by anhebert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	game_over(t_vars *vars)
{
	printf("HaHa! T'as perdu! ");
	printf("Pourtant c'est si facile\n");
	mlx_destroy_window(vars->mlx, vars->win);
	del_tab(vars->map, vars->column_size);
	del_sprites(vars);
	exit (0);
}

void	move_left(t_vars *vars, int i, int *ii)
{
	if (vars->map[i][*ii - 1] == 'P')
		game_over(vars);
	vars->map[i][*ii - 1] = 'W';
	vars->map[i][*ii] = '0';
	*ii -= 1;
	if (vars->map[i][*ii - 1] != '0' && vars->map[i][*ii - 1] != 'P')
		vars->dir = 0;
}

void	move_right(t_vars *vars, int i, int *ii)
{
	if (vars->map[i][*ii + 1] == 'P')
		game_over(vars);
	vars->map[i][*ii + 1] = 'W';
	vars->map[i][*ii] = '0';
	*ii += 1;
	if (vars->map[i][*ii + 1] != '0' && vars->map[i][*ii + 1] != 'P')
		vars->dir = 1;
}

void	move_if(t_vars *vars, int i, int *ii)
{
	if (vars->map[i][*ii + 1] != '0' && vars->map[i][*ii + 1] != 'P'
		&& vars->map[i][*ii] == 'W')
	{
		vars->dir = 1;
		move_left(vars, i, ii);
	}
	else if (vars->map[i][*ii - 1] != '0' && vars->map[i][*ii - 1] != 'P'
		&& vars->map[i][*ii] == 'W')
	{
		vars->dir = 0;
		move_right(vars, i, ii);
	}
}

void	move_enemy(t_vars *vars)
{
	int	i;
	int	ii;

	i = -1;
	while (++i < vars->column_size - 1)
	{
		ii = 0;
		while (vars->map[i][++ii])
		{
			if (vars->map[i][ii + 1] == '0' && vars->dir == 0
				&& vars->map[i][ii] == 'W')
				move_right(vars, i, &ii);
			else if (vars->map[i][ii - 1] == '0' && vars->dir == 1
				&& vars->map[i][ii] == 'W')
				move_left(vars, i, &ii);
			else if (vars->map[i][ii + 1] == 'P' && vars->dir == 0
				&& vars->map[i][ii] == 'W')
				game_over(vars);
			else if (vars->map[i][ii - 1] == 'P' && vars->dir == 1
				&& vars->map[i][ii] == 'W')
				game_over(vars);
			else
				move_if(vars, i, &ii);
		}
	}
}
