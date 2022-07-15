/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhebert <anhebert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 09:57:06 by anhebert          #+#    #+#             */
/*   Updated: 2022/06/27 07:33:18 by anhebert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	elements_error(t_vars vars)
{
	if (vars.p == 0)
		write(2, "Error\nNo start\n", 16);
	if (vars.p > 1)
		write(2, "Error\nToo many starts\n", 23);
	if (vars.c == 0)
		write(2, "Error\nNo collectibles\n", 23);
	if (vars.e == 0)
		write(2, "Error\nNo exit\n", 15);
	if (vars.e_w == 1 && vars.i_n_r == 1)
		write(2, "Error\nFrontieres not all walls\n", 32);
	if (vars.e_i_c == 1)
		write(2, "Error\nInvalid character on the map\n", 36);
	if (vars.i_n_r == 0)
		write(2, "Error\nMap is not rectangle\n", 28);
	if (vars.p != 1 || vars.c == 0 || vars.e == 0 || vars.e_w == 1
		|| vars.e_i_c == 1 || vars.i_n_r == 0)
		return (0);
	return (1);
}

int	is_rectangle(char **map_rows, int row_size, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (ft_strlen(map_rows[i]) != row_size)
			return (0);
	}
	return (1);
}

void	check_mid_rows(t_vars *vars)
{
	int		i;
	int		ii;

	ii = 0;
	while (++ii < vars->column_size - 1)
	{
		i = -1;
		while (vars->map[ii][++i])
		{
			if (vars->map[ii][0] != '1' ||
				vars->map[ii][vars->row_size - 1] != '1')
				vars->e_w = 1;
			if (vars->map[ii][i] == 'P')
				vars->p += 1;
			else if (vars->map[ii][i] == 'E')
				vars->e += 1;
			else if (vars->map[ii][i] == 'C')
				vars->c += 1;
			else if (vars->map[ii][i] != '0' && vars->map[ii][i] != '1'
				&& vars->map[ii][i] != 'P' && vars->map[ii][i] != 'E'
				&& vars->map[ii][i] != 'C' && vars->map[ii][i] != 'W')
				vars->e_i_c = 1;
		}
	}
}

void	check_first_and_last(t_vars *vars)
{
	int	i;

	i = -1;
	while (vars->map[0][++i])
	{
		if (vars->map[0][i] == '\n')
			break ;
		else if (vars->map[0][i] != '1')
		{
			vars->e_w = 1;
			return ;
		}
	}
	i = -1;
	while (vars->map[vars->column_size - 1][++i])
	{
		if (vars->map[vars->column_size - 1][i] == '\n')
			break ;
		if (vars->map[vars->column_size - 1][i] != '1')
		{
			vars->e_w = 1;
			return ;
		}
	}
}
