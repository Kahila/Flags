/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 16:51:19 by nmncube           #+#    #+#             */
/*   Updated: 2019/08/30 13:36:08 by nmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "libft.h"
#include <stdlib.h>
typedef struct here
{
	int l;
	int a;
	int t;
	int r;
	int R;
}flags;

void ft_output(int bfound ,struct here *flags)
{
	if (flags->R == 1)
		printf("-R actived\n");
	if (flags->a == 1)
		printf("-a activated \n");
	if (flags->t == 1)
		printf("-t activated\n");
	if (flags->r == 1)
		printf("-r activated\n");
	if (flags->l == 1)
		printf("-l view Display\n");
	if (flags->l != 1 || bfound == -1)
		printf("-Display in standard output");
}

void	ft_display(int bfound,struct here *flags)
{
	printf("%d\n" , bfound);
	if (bfound == 0)
	{
		if (flags->l == 1)
			bfound = 0;
		else
			bfound = -1;
	}
	else
		bfound = 1;	
	if (bfound > 0)
		printf("Issue");
	else
		ft_output(bfound,flags);
}

int ft_check(char c1,char c2 , struct here *flags)
{
	if ( c1 == '-' && c2 == 'a')
		flags->a = 1;
	else
		if (c1 == '-' && c2== 'l')
			flags->l = 1;
		else
			if (c1 == '-' && c2 == 't')
				flags->t = 1;
			else
				if (c1 == '-' && c2 == 'r')
					flags->r = 1;
				else
				if (c1 == '-' && c2 == 'R')
					flags->R = 1;
				else
				return(1);
	return (0);
}
//Issue with l s
//Issue with --
//Issue with -a-a- --
//Issue with ls - 
int main(int argc,char **argv)
{
	int k;
	int j;
	static int bfound;
	struct here *owner;

	k = 1;
	owner = (struct here*)malloc(sizeof(struct here));
	while(argc > 1)
	{
		j = 1;
		if ((argv[k][0] == '-' && argv[k][j] == 0) || argv[k][0] != '-')
				bfound = bfound + 1;
		while (argv[k][j] != '\0')
		{
			bfound = bfound + ft_check(argv[k][0] , argv[k][j] , owner);
			j++;
		}
		argc--;
		k++;
	}
	if (argv[1] && argv[1][0] == '-' && argv[1][1] == '-' && bfound == 1)
		bfound = 0; 
	ft_display(bfound, owner);
	return (0);
}
