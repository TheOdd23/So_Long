/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhebert <anhebert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 09:57:27 by anhebert          #+#    #+#             */
/*   Updated: 2022/06/27 14:14:27 by anhebert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_image(t_vars *vars, int i, int ii)
{
	if (vars->map[i][ii] == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->walls.img1,
			vars->pos_x, vars->pos_y);
	else if (vars->map[i][ii] == '0')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->back_ground.img1,
			vars->pos_x, vars->pos_y);
	else if (vars->map[i][ii] == 'C')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->collectibles.img1, vars->pos_x, vars->pos_y);
	else if (vars->map[i][ii] == 'P')
	{
		if (vars->key == 1)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->fee.img1,
				vars->pos_x, vars->pos_y);
		else if (vars->key == 13)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->fee.img2,
				vars->pos_x, vars->pos_y);
	}
	else if (vars->map[i][ii] == 'E')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->end.img1,
			vars->pos_x, vars->pos_y);
	else if (vars->map[i][ii] == 'W')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->enemies.img1,
			vars->pos_x, vars->pos_y);
}

void	put_screen(t_vars *vars)
{
	int		i;
	int		ii;
	char	*str;

	i = 0;
	str = ft_itoa(vars->moves);
	vars->pos_y = 0;
	while (i < vars->column_size)
	{
		ii = -1;
		vars->pos_x = 0;
		mlx_string_put(vars->mlx, vars->win, 50, 20, 0x00ff00, "Moves: ");
		mlx_string_put(vars->mlx, vars->win, 120, 20, 0x00ff00, str);
		while (vars->map[i][++ii])
		{
			put_image(vars, i, ii);
			vars->pos_x += 64;
		}
		vars->pos_y += 64;
		i++;
	}
	free(str);
	return ;
}

int	kill_screen(t_vars *vars)
{
	printf("Tu oses utiliser le x pour fermer la fenetre, t'es qui toi!\n");
	mlx_destroy_window(vars->mlx, vars->win);
	del_tab(vars->map, vars->column_size);
	del_sprites(vars);
	exit (0);
}

void	game_init(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, (vars->row_size * 64),
			(vars->column_size * 64), "so_long");
	sprites_init(vars);
	put_screen(vars);
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_hook(vars->win, 17, 0, kill_screen, vars);
	mlx_loop(vars->mlx);
}
