/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhebert <anhebert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 09:57:47 by anhebert          #+#    #+#             */
/*   Updated: 2022/06/27 12:46:31 by anhebert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	do_moves(t_vars *vars, int key, int i, int ii)
{
	int	res;

	res = 0;
	if (key == 13 && vars->map[i][ii] == 'P' && vars->map[i - 1][ii] != '1')
		res = go_up(vars, i, ii);
	else if (key == 0 && vars->map[i][ii] == 'P' && vars->map[i][ii - 1] != '1')
		res = go_left(vars, i, ii);
	else if (key == 1 && vars->map[i][ii] == 'P' && vars->map[i + 1][ii] != '1')
		res = go_down(vars, i, ii);
	else if (key == 2 && vars->map[i][ii] == 'P' && vars->map[i][ii + 1] != '1')
		res = go_right(vars, i, ii);
	return (res);
}

int	check_moves(t_vars *vars, int key)
{
	int	i;
	int	ii;
	int	res;

	i = 0;
	move_enemy(vars);
	while (++i < vars->column_size - 1)
	{
		ii = 0;
		while (vars->map[i][++ii])
		{
			res = do_moves(vars, key, i, ii);
			if (res == 1)
			{
				if (key == 1 || key == 13)
					vars->key = key;
				break ;
			}
		}
		if (res == 1)
			break ;
	}
	mlx_clear_window(vars->mlx, vars->win);
	put_screen(vars);
	return (0);
}

int	key_hook(int key, t_vars *vars)
{
	if (key == 13 || key == 0 || key == 2 || key == 1)
		check_moves(vars, key);
	else if (key == 53)
	{
		printf("Ark, pourquoi tu fermes le jeu, il est trop cool\n");
		mlx_destroy_window(vars->mlx, vars->win);
		del_tab(vars->map, vars->column_size);
		del_sprites(vars);
		exit (0);
	}
	return (0);
}
