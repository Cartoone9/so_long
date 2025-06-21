/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 02:38:30 by *******           #+#    #+#             */
/*   Updated: 2025/02/19 15:45:12 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/so_long.h"

int	ft_render_elements(t_data *data)
{
	static int	which;
	void		*which_img;

	if (which == 0 || which == 1)
		which_img = ft_render_elements_whichimg_a(data, &which);
	else
		which_img = ft_render_elements_whichimg_b(data, &which);
	data->img->addr_t = mlx_get_data_addr(which_img, &data->img->bpp,
			&data->img->line_length, &data->img->endian);
	if (!data->img->addr_t)
		return (ft_error("image->temp get_data_addr failed"), -1);
	ft_cpy_background(data);
	ft_render_elements_onbackg(data);
	if (ft_display_score(data) == -1 || ft_display_keys(data) == -1)
		return (-1);
	if (which > 1)
		mlx_put_image_to_window(data->server, data->win, data->img->temp_a,
			0, 0);
	else
		mlx_put_image_to_window(data->server, data->win, data->img->temp_b,
			0, 0);
	if (ft_display_score(data) == -1 || ft_display_keys(data) == -1)
		return (-1);
	return (0);
}

void	*ft_render_elements_whichimg_a(t_data *data, int *which)
{
	size_t		x;
	size_t		y;

	x = data->map->width * CS;
	y = data->map->height * CS;
	if (*which == 0)
	{
		data->img->temp_a = mlx_new_image(data->server, x, y);
		if (!data->img->temp_a)
			return (ft_error("image->temp_a new_image failed"), NULL);
	}
	if (*which == 0)
		*which = 2;
	else
		*which = 3;
	return (data->img->temp_a);
}

void	*ft_render_elements_whichimg_b(t_data *data, int *which)
{
	size_t		x;
	size_t		y;

	x = data->map->width * CS;
	y = data->map->height * CS;
	if (*which == 2)
	{
		data->img->temp_b = mlx_new_image(data->server, x, y);
		if (!data->img->temp_b)
			return (ft_error("image->temp_b new_image failed"), NULL);
	}
	*which = 1;
	return (data->img->temp_b);
}

void	ft_cpy_background(t_data *data)
{
	char	*main_addr;
	char	*temp_addr;

	main_addr = data->img->addr_m;
	temp_addr = data->img->addr_t;
	while (*(unsigned int *)main_addr)
	{
		if (*(unsigned int *)main_addr != 0xFF0000)
			*(unsigned int *)temp_addr = *(unsigned int *)main_addr;
		main_addr += (data->img->bpp / 8);
		temp_addr += (data->img->bpp / 8);
	}
}

int	ft_render_elements_onbackg(t_data *data)
{
	size_t		x;
	size_t		y;

	y = 0;
	while (y < data->map->height)
	{
		x = 0;
		while (x < data->map->width)
		{
			if (ft_render_elements_onbackg_loop(data, x, y) == -1)
				return (-1);
			x++;
		}
		y++;
	}
	return (0);
}
