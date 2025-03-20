/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finisih_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:11:08 by aingunza          #+#    #+#             */
/*   Updated: 2025/03/20 09:39:13 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	argc_checker(int argc)
{
	if (argc < 1)
	{
		ft_printf("Not enough arguments");
		return 0;
	}	
	else
		return 1;
}
