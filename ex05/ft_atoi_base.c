/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 01:30:09 by coder             #+#    #+#             */
/*   Updated: 2021/10/14 03:24:06 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// int	ft_first_minus(char *str)
// {
// 	int	count;
// 	int	flag;

// 	count = 0;
// 	flag = 0;
// 	while (str[count] != '\0' && flag == 0)
// 	{
// 		if ((str[count] >= 9 && str[count] <= 13) || str[count] == 32)
// 			count ++;
// 		else
// 			flag ++;
// 	}
// 	return (count);
// }

int	ft_check(char *str)
{
	int	i_count;
	int	o_count;
	int	flag;

	o_count = 0;
	flag = 0;
	while (str[o_count] != '\0' && flag == 0)
	{
		i_count = 0;
		if (str[o_count] == '-' || str[o_count] == '+')
			flag ++;
		while (str[i_count] != '\0' && flag == 0)
		{
			if (i_count != o_count && str[i_count] == str[o_count])
				flag ++;
			i_count ++;
		}
		o_count ++;
	}
	return (flag);
}

int	ft_minus(char *str, int count, int check)
{
	int	flag;

	flag = 0;
	if (check == 0)
	{	
		while (str[count] != '\0' && flag == 0)
		{
			if ((str[count] >= 9 && str[count] <= 13) || str[count] == 32)
				count ++;
			else
				flag ++;
		}
		return (count);
	}
	else
	{
		while (str[count] != '\0' && flag == 0)
		{
			if (str[count] == '-' || str[count] == '+')
				count ++;
			else
				flag ++;
		}
		return (count);
	}
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

int	ft_atoi_base(char *str, char *base)
{
	int	count;
	int	minus;
	int	last_min;
	int	first_min;
	int	flag;

	first_min = ft_minus(str, 0, 0);
	last_min = ft_minus(str, first_min, 1);
	minus = fr_count_minus(str, first_min, last_min);
	count = last_min;
	flag = 0;
	while (str[last_min] != '\0' && flag == 0)
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

// int	ft_atoi_base(char *str, char *base);

// int	main(void)
// {
// 	int	num;
// char	base[] = "0123456789abcdef";
// 	char str[] = "  \n  \f  \r   \t  \v  ---++-+-++--+23456789ab567";

// 	num = ft_atoi_base(str, base);
// 	printf("%d\n", num);
// 	return (0);
// }
