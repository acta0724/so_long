/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiwasa <kiwasa@student.42.jp>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:15:57 by kiwasa            #+#    #+#             */
/*   Updated: 2025/03/31 00:42:09 by kiwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

int	is_valid_move(t_game *game, int x, int y)
{
	if (x < 0 || x >= game->map.width || y < 0 || y >= game->map.height)
		return (0);
	if (game->map.grid[y][x] == WALL)
		return (0);
	return (1);
}

int	check_win(t_game *game)
{
	if (game->map.player.x == game->map.exit.x
		&& game->map.player.y == game->map.exit.y
		&& game->collected == game->map.collectibles)
		return (1);
	return (0);
}

void	free_map(char **map, int height)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (i < height)
	{
		if (map[i])
			free(map[i]);
		i++;
	}
	free(map);
}
