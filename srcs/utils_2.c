/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 02:38:30 by *******           #+#    #+#             */
/*   Updated: 2025/02/22 16:20:13 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/so_long.h"

int	ft_init_game_info(t_data *data)
{
	data->game = malloc(sizeof(t_game));
	if (!data->game)
		return (ft_error("t_game_data malloc failed"), -1);
	data->game->available = 0;
	data->game->collected = 0;
	data->game->enemy = 0;
	data->game->moves = 0;
	return (0);
}

void	ft_init_elem_csr(t_elem *elem, t_cursor *csr)
{
	elem->collect = 0;
	elem->player = 0;
	elem->enemy = 0;
	elem->exit = 0;
	csr->row = 0;
	csr->col = 0;
}

int	ft_init_pos(t_data *data)
{
	size_t	y;
	size_t	x;

	data->pos = malloc(sizeof(t_pos));
	if (!data->pos)
		return (ft_error("t_pos malloc failed"), -1);
	y = 0;
	while (data->map->main[y])
	{
		x = 0;
		while (data->map->main[y][x])
		{
			if (data->map->main[y][x] == 'P')
			{
				data->pos->e[0] = -1;
				data->pos->e[1] = -1;
				data->pos->p[0] = y;
				data->pos->p[1] = x;
				return (0);
			}
			x++;
		}
		y++;
	}
	return (-1);
}

int	ft_close_window(t_data *data)
{
	ft_free_data(data);
	exit(0);
}

/*void	ft_rm_pixel(t_data *data)*/
/*{*/
/*	size_t	y;*/
/*	size_t	x;*/
/*	char	*pixel_addr;*/
/**/
/*	y = 0;*/
/*	x = 0;*/
/**/
/*	pixel_addr = data->addr_m + (y * data->line_length + x * (data->bpp
				/ 8));*/
/*	while (*(unsigned int*)pixel_addr)*/
/*	{*/
/*		if (*(unsigned int*)pixel_addr == 0xFF000000)*/
/*			*(unsigned int*)pixel_addr = 0xFF0000FF;*/
/*		pixel_addr += 4;*/
/*	}*/
/*}*/

// int	ft_render_game(void *vdata)
// {
// 	t_data	*data;
// 	size_t	y;
// 	size_t	x;
//
// 	data = (t_data *)vdata;
// 	y = 0;
// 	while (y < data->map->height)
// 	{
// 		x = 0;
// 		while (x < data->map->width)
// 		{
// 			if (data->map->main[y][x] == 'P')
// 				mlx_put_image_to_window(data->server, data->win,
// data->sprite->player, x * CS, y * CS);
// 			if (data->map->main[y][x] == 'E')
// 				mlx_put_image_to_window(data->server, data->win,
// data->sprite->exit, x * CS, y * CS);
// 			if (data->map->main[y][x] == 'C')
// 				mlx_put_image_to_window(data->server, data->win,
// data->sprite->collect, x * CS, y * CS);
// 			x++;
// 		}
// 		y++;
// 	}
// 	return (0);
// 	}
//
// void	*ft_which_loser(t_data *data)
// {
// 	static size_t	i;
// 	void			*ret;
//
// 	if (i < 24)
// 		ret = data->sprite->lose_0;
// 	else if (i >= 24 && i < 40)
// 		ret = data->sprite->lose_1;
// 	printf("frame (i) : %li\n", i);
// 	if (i < 40)
// 		i++;
// 	else
// 		i = 0;
// 	return (ret);
// }
//
// int	ft_set_colors(size_t i)
// {
// 	while (i >= 12)
// 		i -= 12;
// 	if (i == 0)
// 		return (0xFF0000);
// 	if (i == 1)
// 		return (0xFF7F00);
// 	if (i == 2)
// 		return (0xFFFF00);
// 	if (i == 3)
// 		return (0x7FFF00);
// 	if (i == 4)
// 		return (0x00FF00);
// 	if (i == 5)
// 		return (0x00FF7F);
// 	if (i == 6)
// 		return (0x00FFFF);
// 	if (i == 7)
// 		return (0x007FFF);
// 	if (i == 8)
// 		return (0x0000FF);
// 	if (i == 9)
// 		return (0x7F00FF);
// 	if (i == 10)
// 		return (0xFF00FF);
// 	if (i == 11)
// 		return (0xFF007F);
// 	else
// 		return (0);
// }
