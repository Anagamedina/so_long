/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:33:16 by anamedin          #+#    #+#             */
/*   Updated: 2024/09/05 14:33:13 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map2d(t_map *map)
{
	int	i;

	if (map == NULL)
		return ;
	if (map->matrix != NULL)
	{
		i = 0;
		while (i < map->rows)
		{
			if (map->matrix[i] != NULL)
			{
				free(map->matrix[i]);
				map->matrix[i] = NULL;
			}
			i++;
		}
		free(map->matrix);
		map->matrix = NULL;
	}
	//free(map);
}

void	handle_error(char *str, int size, t_map *map, t_game *game)
{
	if (str && size > 0)
		write(2, str, size);
	if (map != NULL)
	{
		free_map2d(map);
	}
	if (game != NULL)
		free_game(game);
	exit(EXIT_FAILURE);
}

void	handle_exit(char *str, int size)
{
	write(2, str, size);
	exit(EXIT_FAILURE);
}

void	free_game(t_game *game)
{
	if (game)
	{
		if (game->map)
			free_map2d(game->map);
		free(game);
	}
}
