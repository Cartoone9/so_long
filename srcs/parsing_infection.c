/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_infection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 21:17:07 by *******           #+#    #+#             */
/*   Updated: 2025/02/17 20:44:40 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/so_long.h"

void	ft_infect_map(char **map, int pos[2], size_t *collected)
{
	if (map[pos[0] - 1][pos[1]] == 'C' || map[pos[0] - 1][pos[1]] == '0')
	{
		ft_infect_top(map, pos, collected);
	}
	if (map[pos[0]][pos[1] + 1] == 'C' || map[pos[0]][pos[1] + 1] == '0')
	{
		ft_infect_right(map, pos, collected);
	}
	if (map[pos[0] + 1][pos[1]] == 'C' || map[pos[0] + 1][pos[1]] == '0')
	{
		ft_infect_bot(map, pos, collected);
	}
	if (map[pos[0]][pos[1] - 1] == 'C' || map[pos[0]][pos[1] - 1] == '0')
	{
		ft_infect_left(map, pos, collected);
	}
}

void	ft_infect_top(char **map, int pos[2], size_t *collected)
{
	if (map[pos[0] - 1][pos[1]] == 'C')
		(*collected)++;
	map[pos[0] - 1][pos[1]] = 'P';
	pos[0]--;
	ft_infect_map(map, pos, collected);
	pos[0]++;
}

void	ft_infect_right(char **map, int pos[2], size_t *collected)
{
	if (map[pos[0]][pos[1] + 1] == 'C')
		(*collected)++;
	map[pos[0]][pos[1] + 1] = 'P';
	pos[1]++;
	ft_infect_map(map, pos, collected);
	pos[1]--;
}

void	ft_infect_bot(char **map, int pos[2], size_t *collected)
{
	if (map[pos[0] + 1][pos[1]] == 'C')
		(*collected)++;
	map[pos[0] + 1][pos[1]] = 'P';
	pos[0]++;
	ft_infect_map(map, pos, collected);
	pos[0]--;
}

void	ft_infect_left(char **map, int pos[2], size_t *collected)
{
	if (map[pos[0]][pos[1] - 1] == 'C')
		(*collected)++;
	map[pos[0]][pos[1] - 1] = 'P';
	pos[1]--;
	ft_infect_map(map, pos, collected);
	pos[1]++;
}
