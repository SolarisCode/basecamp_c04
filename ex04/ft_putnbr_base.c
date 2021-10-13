/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 23:13:41 by coder             #+#    #+#             */
/*   Updated: 2021/10/13 03:53:52 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
		count ++;
	return (count);
}

int	ft_chdup(char *str)
{
	int	i_count;
	int	o_count;
	int	flag;

	o_count = 0;
	flag = 0;
	while (str[o_count] != '\0' && flag == 0)
	{
		i_count = 0;
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

int	ft_inval(char *str)
{
	int	count;
	int	flag;

	count = 0;
	flag = 0;
	while (str[count] != '\0')
	{
		if (str[count] == '-' || str[count] == '+')
			flag ++;
		count ++;
	}
	return (flag);
}

void	ft_pos_comput(int num, char *base, int val)
{
	int	div;
	int	mod;

	if (num > 0)
	{
		div = num / val;
		ft_pos_comput(div, base, val);
		mod = num % val;
		write(1, &base[mod], 1);
	}
}

void	ft_n_comput(int num, char *base, int val)
{
	int	div;
	int	mod;

	if (num > 0)
	{
		div = num / val;
		ft_n_comput(div, base, val);
		mod = num % val;
		val --;
		write(1, &base[val - mod], 1);
	}
}

void	ft_neg_comput(int num, char *base, int val)
{
	if (num == -2147483648)
		num = (num + 1) * 1;
	ft_n_comput(num, base, val);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	temp;
	int	n_base;

	n_base = ft_strlen(base);
	if (n_base < 2 || ft_chdup(base) > 0 ||ft_inval(base) > 0)
		return ;
	else if (nbr < n_base && nbr >= 0)
	{
		temp = nbr / n_base;
		write(1, &base[temp], 1);
		temp = nbr % n_base;
		write(1, &base[temp], 1);
	}
	else if (nbr > 0)
		ft_pos_comput(nbr, base, n_base);
	else
	{
		nbr *= -1;
		ft_neg_comput(nbr, base, n_base);
	}
}

int    main(void)
{
	int	num;
	char str[] = "01";
	
	num = -75;
	ft_putnbr_base(num, str);
	return (0);
}