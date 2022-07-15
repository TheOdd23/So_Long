/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhebert <anhebert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 09:57:34 by anhebert          #+#    #+#             */
/*   Updated: 2022/06/27 13:54:22 by anhebert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	go_up(t_vars *vars, int i, int ii)
{
	if (vars->map[i - 1][ii] == 'E' && vars->c != 0)
		return (0);
	else if (vars->map[i - 1][ii] == 'W')
		game_over(vars);
	else if (vars->map[i - 1][ii] == 'E' && vars->c == 0)
	{
		printf("T'as gagné! bravo! Tu te trouves bon ein? ");
		printf("Tu veux une médaille?\n");
		mlx_destroy_window(vars->mlx, vars->win);
		del_tab(vars->map, vars->column_size);
		del_sprites(vars);
		exit (0);
	}
	else if (vars->map[i - 1][ii] == 'C')
		vars->c--;
	vars->map[i - 1][ii] = 'P';
	vars->map[i][ii] = '0';
	vars->moves += 1;
	return (1);
}

int	go_left(t_vars *vars, int i, int ii)
{
	if (vars->map[i][ii - 1] == 'E' && vars->c != 0)
		return (0);
	else if (vars->map[i][ii - 1] == 'W')
		game_over(vars);
	else if (vars->map[i][ii - 1] == 'E' && vars->c == 0)
	{
		printf("T'as gagné! bravo! Tu te trouves bon ein? ");
		printf("Tu veux une médaille?\n");
		mlx_destroy_window(vars->mlx, vars->win);
		del_tab(vars->map, vars->column_size);
		del_sprites(vars);
		exit (0);
	}
	else if (vars->map[i][ii - 1] == 'C')
		vars->c--;
	vars->map[i][ii - 1] = 'P';
	vars->map[i][ii] = '0';
	vars->moves += 1;
	return (1);
}

int	go_down(t_vars *vars, int i, int ii)
{
	if (vars->map[i + 1][ii] == 'E' && vars->c != 0)
		return (0);
	else if (vars->map[i + 1][ii] == 'W')
		game_over(vars);
	else if (vars->map[i + 1][ii] == 'E' && vars->c == 0)
	{
		printf("T'as gagné! bravo! Tu te trouves bon ein? ");
		printf("Tu veux une médaille?\n");
		mlx_destroy_window(vars->mlx, vars->win);
		del_tab(vars->map, vars->column_size);
		del_sprites(vars);
		exit (0);
	}
	else if (vars->map[i + 1][ii] == 'C')
		vars->c--;
	vars->map[i][ii] = '0';
	vars->map[i + 1][ii] = 'P';
	vars->moves += 1;
	return (1);
}

int	go_right(t_vars *vars, int i, int ii)
{
	if (vars->map[i][ii + 1] == 'E' && vars->c != 0)
		return (0);
	else if (vars->map[i][ii + 1] == 'W')
		game_over(vars);
	else if (vars->map[i][ii + 1] == 'E' && vars->c == 0)
	{
		printf("T'as gagné! bravo! Tu te trouves bon ein? ");
		printf("Tu veux une médaille?\n");
		mlx_destroy_window(vars->mlx, vars->win);
		del_tab(vars->map, vars->column_size);
		del_sprites(vars);
		exit (0);
	}
	else if (vars->map[i][ii + 1] == 'C')
		vars->c--;
	vars->map[i][ii + 1] = 'P';
	vars->map[i][ii] = '0';
	vars->moves += 1;
	return (1);
}
