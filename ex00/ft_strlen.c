/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:24:31 by coder             #+#    #+#             */
/*   Updated: 2021/10/12 15:35:26 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
		count ++;
	return (count);
}

// int	main(void)
// {
// 	int	num;
// 	char	str[]= "Hello World";

// 	num = ft_strlen(str);
// 	printf("%d\n", num);
// }
