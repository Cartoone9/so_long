/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 21:17:07 by *******           #+#    #+#             */
/*   Updated: 2025/02/19 01:51:54 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/so_long.h"

int	ft_check_map(t_data *data, char **map)
{
	t_elem		elem;
	t_pos		pos;
	t_cursor	csr;

	if (!map || !map[0] || !map[1] || !map[2])
		return (ft_error("missing or invalid map"), -1);
	ft_init_elem_csr(&elem, &csr);
	while (map && map[csr.row])
	{
		csr.col = 0;
		if (elem.player > 1 || elem.exit > 1)
			break ;
		if (csr.row == 1 || (map[csr.row + 1] && !map[csr.row + 2]))
		{
			if (ft_topnbot_row(map, csr.row, &(csr.col)) == -1)
				return (-1);
		}
		else if (csr.row > 0 && map[csr.row + 1] && ft_middle_row(map, &elem,
				&pos, &csr) == -1)
			return (-1);
		(csr.row)++;
	}
	if (ft_check_elem(map, elem, pos, data) == -1)
		return (-1);
	return (0);
}

int	ft_middle_row(char **map, t_elem *elem, t_pos *pos, t_cursor *csr)
{
	size_t	row_len;
	char	c;

	row_len = ft_strlen(map[csr->row]);
	if (ft_strlen(map[0]) != row_len)
		return (ft_error("invalid map length"), -1);
	while (map[csr->row][csr->col] && map[csr->row][csr->col] != '\n')
	{
		c = map[csr->row][csr->col];
		if ((csr->col == 1 || csr->col == row_len - 2) && c != '1')
			return (ft_error("invalid map wall"), -1);
		else if (c == 'C' || c == 'P' || c == '#' || c == 'E')
			ft_middle_row_update(c, elem, pos, csr);
		else if (csr->col != 0 && map[csr->row][csr->col + 1]
			&& map[csr->row][csr->col + 2] != '\n' && map[csr->row][csr->col
			+ 2] != '\0' && c != '0' && c != '1')
			return (ft_error("invalid map char"), -1);
		(csr->col)++;
	}
	return (0);
}

void	ft_middle_row_update(char c, t_elem *elem, t_pos *pos, t_cursor *csr)
{
	if (c == 'C')
		elem->collect++;
	else if (c == 'P')
		ft_update_elem(csr, elem, pos, 0);
	else if (c == '#')
		ft_update_elem(csr, elem, pos, 1);
	else if (c == 'E')
		ft_update_elem(csr, elem, pos, 2);
}

int	ft_topnbot_row(char **map, size_t row, size_t *col)
{
	if (row > 0 && ft_strlen(map[0]) != ft_strlen(map[row]))
		return (ft_error("invalid map length"), -1);
	while (map[row][*col] && map[row][*col] != '\n')
	{
		if (*col == 0 || !map[row][(*col) + 1] || map[row][(*col) + 1] == '\n')
		{
			if (map[row][*col] != '*')
				return (ft_error("invalid map wall"), -1);
		}
		else if (map[row][*col] != '1')
			return (ft_error("invalid map wall"), -1);
		(*col)++;
	}
	return (0);
}

void	ft_update_elem(t_cursor *csr, t_elem *elem, t_pos *pos, int which)
{
	if (which == 1)
	{
		(elem->enemy)++;
	}
	else if (which == 2)
	{
		pos->e[0] = csr->row;
		pos->e[1] = csr->col;
		(elem->exit)++;
	}
	else
	{
		pos->p[0] = csr->row;
		pos->p[1] = csr->col;
		(elem->player)++;
	}
}
