/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.extension.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:25:47 by anamedin          #+#    #+#             */
/*   Updated: 2024/08/06 14:52:56 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Contiene funciones para leer y validar el archivo de mapa
#include "../includes/so_long.h"

static int	validate_path(char *argv)
{
	char	*file_extension;
	int		len_file_extension;
	int		len_argv;
	int		i;

	file_extension = ".ber";
	len_file_extension = ft_strlen (file_extension);
	len_argv = ft_strlen(argv);
	i = len_file_extension;
	while (i >= 0)
	{
		if (argv[len_argv] != file_extension[i])
			return (1);
		i--;
		len_argv--;
	}
	return (0);
}

static int	check_first_and_last_line(t_map *copy_map)
{
	int	j;

	j = 0;
	while (copy_map->matrix[0][j] != '\0')
	{
		if (copy_map->matrix[0][j] != '1')
			handle_error(ERROR_WALLS, 31, copy_map);
		j++;
	}
	j = 0;
	while (copy_map->matrix[copy_map->rows - 1][j] != '\0')
	{
		if (copy_map->matrix[copy_map->rows - 1][j] != '1')
			handle_error(ERROR_WALLS, 31, copy_map);	
		j++;
	}
	return (1);
}

static int 	check_laterals_map(t_map *copy_map)
{
	int	i;

	i = 0;
	while (i < copy_map->rows)
	{
		if (copy_map->matrix[i][0] != '1' 
			|| copy_map->matrix[i][copy_map->cols - 1] != '1')
			handle_error(ERROR_WALLS, 31, copy_map);
		i++;
	}
	i = 0;
	while (i < copy_map->rows)
	{
		if (copy_map->matrix[i][copy_map->cols - 1] != '1')
			handle_error(ERROR_WALLS, 31, copy_map);
		i++;
	}
	return (1);
}

void	map_format_border_check(char *path, t_map *copy_map)
{
	if (validate_path(path) == 0)
	{
		printf("file is valid\n");
		read_map(path, copy_map);
		if (check_first_and_last_line(copy_map) == 1 && check_laterals_map(copy_map) == 1)
			printf("validacion mapa paredes correctas\n");
	}
	else
		printf("error file\n");
}
