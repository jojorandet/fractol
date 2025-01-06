/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:35:33 by jrandet           #+#    #+#             */
/*   Updated: 2025/01/06 17:05:22 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_exit_fractol(t_m_struct *data, char *error)
{
	if (data)
	{
		if (data->image.data)
			mlx_destroy_image(data->mlx_ptr, data->image.data);
		if (data->win)
			mlx_destroy_window(data->mlx_ptr, data->win);
	}
	if (error)
	{
		printf("Error: %s!", error);
		exit(EXIT_SUCCESS);
	}
	exit(EXIT_SUCCESS);
}

void	init_fractol(t_m_struct *data)
{
	init_data(data);
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		ft_exit_fractol(data, "Error: Mlx unitialized, SGV!\n");
	data->win = mlx_new_window(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "test");
	if (!data->win)
		ft_exit_fractol(data, "Error: Win not initialized, SGV\n!");
	init_img(data);
}

void	help()
{

}

int	parse_arguments(t_m_struct *data, int argc, char **argv)
{
	if (argc < 2 || argc > 4)
		return (1);
	data->
	
	
	
	
	//what variables to I need to store the value of the fractal? do i need a local varuiable or should I send it over to my struct and then according to the struct value i change it 
	
	//preliminary check,if argc < 2 or argc > 4 then send the help 
	// if the code is 0, then I expect Julia,
		//a.out, julia, 2, 3  so I need 4 arguments 
		//once I receive the arguments, I need to do an 
			//atoi of the number sent by the client (0 1 2)
			// once atoi done, I send it to fractal->type so that I can then reuse it in the view init
				//my view init will depend on the type of fractal because the centers are not the same // so in my viuew init, I will send them 
			// if i am in the case of julia then I need to do an atof of the two numbers (real and im in my struct)
				//these two complex values become the new "complex julia values in real and im"
		//in the case of the mandelbrot the center needs to be placed a bit to the left of the center 
			//atoi the number to check 
			// if the atoi is different than something then you send the help
			//then you set the max iter and center to the center to th left as said above
			//send the help to the output explaining what you need to do if it does not work out
			

	//the atoi of the arguments is the thing that coul indicate if i need help or not so i need to teceive an int 



	//separate fuunction for the setting of the fractals in "fractal_set" for the centert ect
}


int	main(int argc, char **argv)
{
	t_m_struct	data;

	if (argc < 2)
		ft_exit_fractol(NULL, "Please enter a valid number of arguments!");
	if (parse_arguments(&data, argc, argv))
		return(output_help());
	init_fractol(&data);
	event_mouse_init(&data);
	events_keys_init(&data);
	view_init(&data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
