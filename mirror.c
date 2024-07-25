/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mirror.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:16:40 by samartin          #+#    #+#             */
/*   Updated: 2024/07/25 20:16:21 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mirror.h"


static void fatal_error(void)
{
	write(STDERR_FILENO, "Error loading something\n", 25);
	exit(EXIT_FAILURE);
}

void	mlx_h_mirror_img(mlx_image_t *img)
{
	uint32_t	y;
	uint32_t	x;
	uint32_t	swap;
	uint32_t	*pxm;

	pxm = (uint32_t *)img->pixels;
	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width / 2)
		{
			swap = pxm[(y * img->width) + x];
			pxm[(y * img->width) + x] = pxm[(y * img->width) + img->width - x];
			pxm[(y * img->width) + img->width - x] = swap;
			x++;
		}
		y++;
	}
}

mlx_image_t	*mlx_h_mirror_img_cpy(mlx_t *mlx, mlx_image_t *img)
{
	uint32_t	y;
	uint32_t	x;
	uint32_t	*pxm;
	mlx_image_t	*imgcpy;
	uint32_t	*pxmcpy;

	pxm = (uint32_t *)img->pixels;
	imgcpy = mlx_new_image(mlx, img->width, img->height);
	pxmcpy = (uint32_t *)imgcpy->pixels;
	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			pxmcpy[(y * img->width) + x] = pxm[(y * img->width) + img->width - x];
			x++;
		}
		y++;
	}
	return (imgcpy);
}

int	main()
{
	mlx_image_t		*img;
	mlx_image_t		*imgcpy1;
	mlx_t			*mlx;
	mlx_texture_t*	texture;

	mlx = mlx_init(WINW, WINH, "SPRITE MIRROR", false);
	if (!mlx)
		fatal_error();
	texture = mlx_load_png("pacman.png");
	if (!texture)
        fatal_error();
	img = mlx_texture_to_image(mlx, texture);
	if (!img)
        fatal_error();
	mlx_image_to_window(mlx, img, (WINW / 2) - SPRW, (WINH / 2) - SPRH);
	imgcpy1 = mlx_h_mirror_img_cpy (mlx, img);
	mlx_image_to_window(mlx, imgcpy1, (WINW / 2), (WINH / 2) - SPRH);
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_delete_texture(texture);
	mlx_terminate(mlx);
	return (0);
}
