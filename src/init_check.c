/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:07:01 by pcazac            #+#    #+#             */
/*   Updated: 2023/07/13 16:52:13 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int check_all(int argc)
{
	if (argc != 2)
	{
		perror("Wrong arguments!");
		exit(1);
	}
	return (EXIT_SUCCESS);
}

// Check that the file has a .ber type of extention 
