/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:37:38 by coder             #+#    #+#             */
/*   Updated: 2021/10/12 15:49:54 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <unistd.h>
void	ft_putstr(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		write(1, &str[count], 1);
		count ++;
	}
}

// int	main(void)
// {
// 	char	str[] = "Hello World";
// 	ft_putstr(str);
// 	return (0);
// }
