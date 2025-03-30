/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiwasa <kiwasa@student.42.jp>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:15:24 by kiwasa            #+#    #+#             */
/*   Updated: 2025/03/31 00:33:25 by kiwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

int	close_window(t_game *game)
{
	free_map_finish(game);
	free_mlx_resources(game);
	get_next_line(-1);
	exit(0);
	return (0);
}

int	key_handler(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_window(game);
	else if (keycode == KEY_W)
		move_player(game, game->map.player.x, game->map.player.y - 1);
	else if (keycode == KEY_A)
		move_player(game, game->map.player.x - 1, game->map.player.y);
	else if (keycode == KEY_S)
		move_player(game, game->map.player.x, game->map.player.y + 1);
	else if (keycode == KEY_D)
		move_player(game, game->map.player.x + 1, game->map.player.y);
	return (0);
}
