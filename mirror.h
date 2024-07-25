/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mirror.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:12:15 by samartin          #+#    #+#             */
/*   Updated: 2024/07/25 19:24:04 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRADIENT_H
# define  GRADIENT_H
# include <stdlib.h>
# include <unistd.h>
# include "mlx42/MLX42.h"
# ifndef WINW
#  define WINW 1280
# endif
# ifndef WINH
#  define WINH 720
# endif
# ifndef SPRW
#  define SPRW 128
# endif
# ifndef SPRH
#  define SPRH 128
# endif
# ifndef BPP
#  define BPP sizeof(int32_t)
# endif

typedef struct	s_gradient_win
{
	int				w;
	int				h;
	unsigned int	col1;
	unsigned int	col2;
}	t_gradient_win;

int	ft_atoib(char *str, int base);

#endif