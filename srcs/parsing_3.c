/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 23:19:33 by *******           #+#    #+#             */
/*   Updated: 2025/02/19 02:05:58 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/so_long.h"

int	ft_check_elem(char **map, t_elem elem, t_pos pos, t_data *data)
{
	char	**map_cpy;
	size_t	collected;

	if (elem.player != 1 || elem.exit != 1 || elem.collect == 0)
		return (ft_error("wrong and/or missing map element"), -1);
	if (ft_init_game_info(data) == -1)
		return (-1);
	data->game->available = elem.collect;
	data->game->enemy = elem.enemy;
	map_cpy = ft_copy_map(map);
	if (!map_cpy)
		return (-1);
	collected = 0;
	ft_infect_map(map_cpy, pos.p, &collected);
	if (collected != elem.collect)
		return (ft_free_strr(map_cpy),
			ft_error("cannot access collectible"), -1);
	if (ft_check_exit(map_cpy, pos.e) == -1)
		return (ft_free_strr(map_cpy),
			ft_error("cannot access exit"), -1);
	ft_free_strr(map_cpy);
	return (0);
}

int	ft_middle_wall(t_data *data, size_t y, size_t x)
{
	int	ret;

	ret = 0;
	if (x == 0 || x == data->map->width - 1)
		ret = ft_which_sprite(data, x, y, 10);
	else if (x == 1)
		ret = ft_which_sprite(data, x, y, 2);
	else if (x == data->map->width - 2)
		ret = ft_which_sprite(data, x, y, 3);
	else
		ret = ft_which_sprite(data, x, y, 8);
	return (ret);
}

int	ft_topbot_wall(t_data *data, size_t y, size_t x)
{
	int	ret;

	if (y == 0 || y + 1 == data->map->height)
		ret = ft_which_sprite(data, x, y, 10);
	else if (x == 0 || x == data->map->width - 1)
		ret = ft_which_sprite(data, x, y, 10);
	else if (y == 1)
	{
		if (x == 1)
			ret = ft_which_sprite(data, x, y, 4);
		else if (x == data->map->width - 2)
			ret = ft_which_sprite(data, x, y, 5);
		else
			ret = ft_which_sprite(data, x, y, 0);
	}
	else
	{
		if (x == 1)
			ret = ft_which_sprite(data, x, y, 6);
		else if (x == data->map->width - 2)
			ret = ft_which_sprite(data, x, y, 7);
		else
			ret = ft_which_sprite(data, x, y, 1);
	}
	return (ret);
}
