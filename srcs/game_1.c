/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 02:38:30 by *******           #+#    #+#             */
/*   Updated: 2025/02/22 15:57:36 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/so_long.h"

int	ft_run_game(t_data *data)
{
	if (ft_init_data(data) == -1)
		return (-1);
	mlx_hook(data->win, 2, 1L << 0, &ft_key_press, data);
	mlx_hook(data->win, 17, 0, &ft_close_window, data);
	mlx_loop_hook(data->server, ft_end_game, data);
	mlx_loop(data->server);
	return (0);
}

int	ft_init_data(t_data *data)
{
	data->server = mlx_init();
	if (!data->server)
		return (ft_error("mlx_init failed"), -1);
	if (ft_load_sprites(data) == -1)
		return (-1);
	if (ft_render_background(data) == -1)
		return (-1);
	data->win = mlx_new_window(data->server, data->map->width * CS,
			data->map->height * CS, "so_long");
	if (!data->win)
		return (ft_error("mlx_new_window failed"), -1);
	if (ft_render_elements(data) == -1)
		return (-1);
	return (0);
}

int	ft_render_background(t_data *data)
{
	size_t	y;
	size_t	x;

	if (ft_init_image(data) == -1)
		return (-1);
	y = 0;
	while (y < data->map->height)
	{
		x = 0;
		while (x < data->map->width)
		{
			if (ft_render_background_loop(data, x, y) == -1)
				return (-1);
			x++;
		}
		y++;
	}
	return (0);
}

int	ft_init_image(t_data *data)
{
	data->img = malloc(sizeof(t_image));
	if (!data->img)
		return (ft_error("t_image malloc failed"), -1);
	data->img->temp_a = NULL;
	data->img->temp_b = NULL;
	data->img->addr_m = NULL;
	data->img->addr_t = NULL;
	data->img->main = mlx_new_image(data->server, data->map->width
			* CS, data->map->height * CS);
	if (!data->img->main)
		return (ft_error("image->main new_image failed"), -1);
	data->img->addr_m = mlx_get_data_addr(data->img->main,
			&data->img->bpp, &data->img->line_length,
			&data->img->endian);
	if (!data->img->addr_m)
		return (ft_error("image->main get_data_addr failed"), -1);
	return (0);
}

int	ft_render_background_loop(t_data *data, size_t x, size_t y)
{
	int		ret;

	ret = 0;
	if ((data->map->main[y][x] == '1' || data->map->main[y][x] == '*')
		&& (y <= 1 || y + 1 == data->map->height || y
			+ 2 == data->map->height))
		ret = ft_topbot_wall(data, y, x);
	else if (data->map->main[y][x] == '1'
		|| data->map->main[y][x] == '*')
		ret = ft_middle_wall(data, y, x);
	else
		ret = ft_which_sprite(data, x, y, 9);
	if (ret == -1)
		return (-1);
	return (0);
}
