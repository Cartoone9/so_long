/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 23:01:42 by *******           #+#    #+#             */
/*   Updated: 2025/02/22 16:17:46 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/so_long.h"

void	ft_free_str(char *str)
{
	if (str)
	{
		free(str);
		str = NULL;
	}
}

void	ft_free_strr(char **strr)
{
	size_t	i;

	i = 0;
	while (strr[i])
	{
		free(strr[i]);
		strr[i] = NULL;
		i++;
	}
	if (strr)
	{
		free(strr);
		strr = NULL;
	}
}

void	ft_free_image_1(t_data *data)
{
	if (data->img->main)
		mlx_destroy_image(data->server, data->img->main);
	if (data->img->temp_a)
		mlx_destroy_image(data->server, data->img->temp_a);
	if (data->img->temp_b)
		mlx_destroy_image(data->server, data->img->temp_b);
}

void	ft_free_data(t_data *data)
{
	if (!data)
		return ;
	if (data->img)
	{
		ft_free_image_1(data);
		free(data->img);
	}
	if (data->sprite)
	{
		ft_free_sprite_1(data);
		ft_free_sprite_2(data);
		ft_free_sprite_3(data);
		ft_free_sprite_4(data);
		free(data->sprite);
	}
	if (data->map)
	{
		if (data->map->main)
			ft_free_strr(data->map->main);
		free(data->map);
	}
	ft_free_data_suite(data);
}

void	ft_free_data_suite(t_data *data)
{
	if (data->pos)
		free(data->pos);
	if (data->game)
		free(data->game);
	if (data->win)
		mlx_destroy_window(data->server, data->win);
	if (data->server)
	{
		mlx_destroy_display(data->server);
		free(data->server);
	}
}
