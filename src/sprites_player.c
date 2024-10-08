/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:26:04 by anamedin          #+#    #+#             */
/*   Updated: 2024/09/04 14:32:18 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	update_player_position(t_game *game, int new_x, int new_y)
{
	int	last_x;
	int	last_y;

	last_x = game->map->player_pos.x;
	last_y = game->map->player_pos.y;
	game->map->matrix[last_x][last_y] = FLOOR;
	game->map->player_pos.x = new_x;
	game->map->player_pos.y = new_y;
	game->map->matrix[new_x][new_y] = PLAYER;
	game->movements++;
	identify_images(game, 0, 0);
}

static void	handle_coin_pickup(t_game *game, int new_x, int new_y)
{
	if (game->map->matrix[new_x][new_y] == COINS)
	{
		game->map->coins--;
		ft_printf("coins: %d\n", game->map->coins);
	}
}

void	move_player(t_game *game, int new_x, int new_y, int player_sprite)
{
	if (new_y < 0 || new_y >= game->map->cols
		|| new_x < 0 || new_x >= game->map->rows)
		return ;
	if (game->map->matrix[new_x][new_y] == WALL)
		return ;
	game->player_sprite = player_sprite;
	if (game->map->matrix[new_x][new_y] == EXIT && game->map->coins == 0)
	{
		ft_victory(game);
		return ;
	}
	if (game->map->matrix[new_x][new_y] == FLOOR
		|| game->map->matrix[new_x][new_y] == COINS)
	{
		handle_coin_pickup(game, new_x, new_y);
		update_player_position(game, new_x, new_y);
		ft_printf("Movements:%d\n", game->movements);
	}
}

/*****************PRINCIPAL FUNCTION*******************/

int	handle_input(int keysym, t_game *game)
{
	if (keysym == KEY_W || keysym == KEY_UP)
		move_player (game, game->map->player_pos.x - 1, \
				game->map->player_pos.y, BACK);
	else if (keysym == KEY_A || keysym == KEY_LEFT)
		move_player(game, game->map->player_pos.x, \
				game->map->player_pos.y - 1, LEFT);
	else if (keysym == KEY_S || keysym == KEY_DOWN)
		move_player(game, game->map->player_pos.x + 1, \
				game->map->player_pos.y, FRONT);
	else if (keysym == KEY_D || keysym == KEY_RIGHT)
		move_player(game, game->map->player_pos.x, \
				game->map->player_pos.y + 1, RIGHT);
	else if (keysym == KEY_ESC || keysym == KEY_Q)
	{
		ft_printf("Exiting the game. You pressed Q or Escape. Goodbye!\n");
		ft_close_game(game);
	}
	return (0);
}
