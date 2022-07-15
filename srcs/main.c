/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhebert <anhebert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 13:06:00 by anhebert          #+#    #+#             */
/*   Updated: 2022/06/27 13:54:36 by anhebert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	count_enemies(t_vars *vars)
{
	int	i;
	int	ii;

	i = -1;
	vars->enemy_nb = 0;
	while (++i < vars->column_size - 1)
	{
		ii = 0;
		while (vars->map[i][++ii])
		{
			if (vars->map[i][ii] == 'W')
				vars->enemy_nb += 1;
		}
	}
}

int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac == 2)
	{
		check_map(av, &vars);
		vars.key = 1;
		vars.dir = 0;
		vars.moves = 0;
		count_enemies(&vars);
		game_init(&vars);
		return (0);
	}
	write(2, "Error\nWrong number of arguments\n", 33);
	return (0);
}
