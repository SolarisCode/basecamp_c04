/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 01:30:09 by coder             #+#    #+#             */
/*   Updated: 2021/10/14 15:24:08 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	ft_int_comput(char *str, char *base, int first, int last)
{
	int	num;
	int	n_base;
	int	count;
	int	val;
	int	power;
	int	exp;

	num = 0;
	n_base = 0;
	power = 0;
	while (base[n_base] != '\0')
		n_base ++;
	exp = n_base;
	while (last >= first)
	{
		count = 0;
		while (base[count] != '\0')
		{
			if (str[last] == base[count])
			{
				val = count;
			}
			count ++;
		}
		count = power;
		if (power == 0)
		{
			num = num + (val * 1);
		}
		else
		{
			while (count > 1)
			{
				exp = (exp * n_base);
				count --;
			}
			num += (val * exp);
			exp = n_base;
		}
		power ++;
		last --;
	}
	return (num);
}

int	ft_atoi_base(char *str, char *base)
{
	int	count;
	int	minus;
	int	last_min;
	int	first_min;
	int	n;

	first_min = ft_minus(str, 0, 0);
	last_min = ft_minus(str, first_min, 1);
	minus = fr_count_minus(str, first_min, last_min);
	count = last_min;
	if (ft_check(base))
		return (0);
	first_min = 0;
	while (str[count] != '\0' && first_min == 0)
	{
		n = 0;
		first_min = 1;
		while (base[n] != '\0')
		{
			if (str[count] == base[n])
			{
				count ++;
				first_min = 0;
			}
			n ++;
		}
	}
	str[count] = '\0';
	if (minus % 2 > 0)
		return (ft_int_comput(str, base, last_min, count - 1) * -1);
	else
		return (ft_int_comput(str, base, last_min, count - 1));
}

// #include <stdio.h>

// int	main(void)
// {
// 	int		num;
// 	char	base[] = "01";
// 	char 	str[] = "  \n  \f  \r   \t  \v  --+-+-+-++--+111001000";

// 	num = ft_atoi_base(str, base);
// 	printf("%d\n", num);
// 	return (0);
// }
