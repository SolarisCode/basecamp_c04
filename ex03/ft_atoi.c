/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:29:11 by coder             #+#    #+#             */
/*   Updated: 2021/10/15 02:29:13 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_first_minus(char *str)
{
	int	count;
	int	flag;

	count = 0;
	flag = 0;
	while (str[count] != '\0' && flag == 0)
	{
		if ((str[count] >= 9 && str[count] <= 13) || str[count] == 32)
			count ++;
		else
			flag ++;
	}
	return (count);
}

int	ft_last_minus(char *str, int count)
{
	int	flag;

	flag = 0;
	while (str[count] != '\0' && flag == 0)
	{
		if (str[count] == '-' || str[count] == '+')
			count ++;
		else
			flag ++;
	}
	return (count);
}

int	fr_count_minus(char *str, int first, int last)
{
	int	minus;
	int	flag;

	minus = 0;
	flag = 0;
	while (first < last && flag == 0)
	{
		if (str[first] == '-' || str[first] == '+')
		{
			if (str[first] == '-')
				minus ++;
			first ++;
		}
		else
			flag ++;
	}
	return (minus);
}

int	ft_int_comput(char *str, int count)
{
	int	num;

	num = 0;
	if (str[count + 1] != '\0')
		num = (str[count] - 48) * 10;
	else
		num = num + (str[count] - 48);
	count ++;
	while (str[count] != '\0')
	{
		if (str[count + 1] != '\0')
		{
			num = num + (str[count] - 48);
			num *= 10;
		}
		else
			num = num + (str[count] - 48);
		count ++;
	}
	return (num);
}

int	ft_atoi(char *str)
{
	int	count;
	int	minus;
	int	last_min;
	int	first_min;
	int	flag;

	first_min = ft_first_minus(str);
	last_min = ft_last_minus(str, first_min);
	minus = fr_count_minus(str, first_min, last_min);
	count = last_min;
	flag = 0;
	while (str[count] != '\0' && flag == 0)
	{
		if (str[count] >= 48 && str[count] <= 57)
			count ++;
		else
			flag ++;
	}
	str[count] = '\0';
	if (minus % 2 > 0)
		return (ft_int_comput(str, last_min) * -1);
	else
		return (ft_int_comput(str, last_min));
}

// #include <stdio.h>

// int	main(void)
// {
// 	int	num;
// 	char str[] = "  \n  \f  \r   \t  \v  --++-+-++--+23456789ab567";

// 	num = ft_atoi(str);
// 	printf("%d\n", num);
// 	return (0);
// }
