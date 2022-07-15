/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhebert <anhebert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 09:40:43 by anhebert          #+#    #+#             */
/*   Updated: 2022/06/27 07:33:50 by anhebert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/* Revoir animations */

void	sprites_init(t_vars *vars)
{
	vars->fee.img1 = mlx_xpm_file_to_image(&vars->mlx,
			"sprites/Perso1.xpm", &vars->width, &vars->height);
	vars->fee.img2 = mlx_xpm_file_to_image(&vars->mlx,
			"sprites/PersoBack1.xpm", &vars->width, &vars->height);
	vars->walls.img1 = mlx_xpm_file_to_image(&vars->mlx,
			"sprites/Wall2.xpm", &vars->width, &vars->height);
	vars->end.img1 = mlx_xpm_file_to_image(&vars->mlx,
			"sprites/End.xpm", &vars->width, &vars->height);
	vars->collectibles.img1 = mlx_xpm_file_to_image(&vars->mlx,
			"sprites/Collectible.xpm", &vars->width, &vars->height);
	vars->back_ground.img1 = mlx_xpm_file_to_image(&vars->mlx,
			"sprites/Back_ground.xpm", &vars->width, &vars->height);
	vars->enemies.img1 = mlx_xpm_file_to_image(&vars->mlx,
			"sprites/Wall1.xpm", &vars->width, &vars->height);
}
