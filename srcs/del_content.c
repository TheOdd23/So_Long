/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_content.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhebert <anhebert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 08:39:37 by anhebert          #+#    #+#             */
/*   Updated: 2022/06/27 07:33:27 by anhebert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*void	del_lists(t_list *list)
{
	t_list	*temp;

	temp = list;
	while (list != NULL)
	{
		temp = list;
		list = list->next;
		free(temp);
	}
	free(list);
}*/

void	del_tab(char **str, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	del_sprites(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->walls.img1);
	mlx_destroy_image(vars->mlx, vars->fee.img1);
	mlx_destroy_image(vars->mlx, vars->fee.img2);
	mlx_destroy_image(vars->mlx, vars->collectibles.img1);
	mlx_destroy_image(vars->mlx, vars->end.img1);
	mlx_destroy_image(vars->mlx, vars->back_ground.img1);
	if (vars->enemies.img1)
		mlx_destroy_image(vars->mlx, vars->enemies.img1);
}
