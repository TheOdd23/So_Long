/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhebert <anhebert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 07:49:25 by anhebert          #+#    #+#             */
/*   Updated: 2022/06/27 07:33:45 by anhebert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_map_errors(t_vars *vars)
{
	vars->p = 0;
	vars->e = 0;
	vars->c = 0;
	vars->e_i_c = 0;
	vars->e_w = 0;
	vars->row_size = ft_strlen(vars->map[0]);
	vars->i_n_r = is_rectangle(vars->map, vars->row_size, vars->column_size);
	check_first_and_last(vars);
	check_mid_rows(vars);
	if (elements_error(*vars) == 0)
	{
		del_tab(vars->map, vars->column_size);
		exit (1);
	}
}

int	map_size(int fd)
{
	int		i;
	char	*temp;

	i = 0;
	while (1)
	{
		temp = get_next_line(fd);
		if (temp == NULL)
		{
			free (temp);
			close(fd);
			break ;
		}
		free (temp);
		i++;
	}
	return (i);
}

void	read_map(int fd, t_vars *vars)
{
	int		i;

	i = -1;
	vars->map = malloc(sizeof(char *) * vars->column_size);
	while (++i < vars->column_size)
	{
		vars->map[i] = get_next_line(fd);
		if (vars->map == NULL)
		{
			free (vars->map[i]);
			close(fd);
			break ;
		}
	}
	check_map_errors(vars);
}

void	check_ext(char *arg)
{
	char	*res;

	res = ft_strrchr(arg, '.');
	if (res == NULL)
	{
		write(2, "Error\n", 6);
		ft_putstr_fd(strerror(EINVAL), 2);
		exit (1);
	}
	if (*(res + 1) == 'b' && *(res + 2) == 'e'
		&& *(res + 3) == 'r' && *(res + 4) == '\0')
		return ;
	write(2, "Error\n", 6);
	ft_putstr_fd(strerror(EINVAL), 2);
	exit (1);
}

void	check_map(char **av, t_vars *vars)
{
	int		fd;

	check_ext(av[1]);
	fd = open(av[1], O_RDONLY);
	vars->column_size = map_size(fd);
	fd = open(av[1], O_RDONLY);
	read_map(fd, vars);
}
