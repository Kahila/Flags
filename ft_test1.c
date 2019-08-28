/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 16:51:19 by nmncube           #+#    #+#             */
/*   Updated: 2019/08/28 17:03:07 by nmncube          ###   ########.fr       */
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

void ft_output(struct here *flags)
{
	if (flags->a == 1)
		printf("-a activated \n");
	if (flags->t == 1)
		printf("-t activated\n");
	if (flags->l == 1)
		printf("-l view Display\n");
	if (flags->r == 1)
		printf("-r activated\n");
	if (flags->R == 1)
		printf("-R actived\n");
	if (flags->l != 1)
		printf("Display in standard output");
}

void	ft_display(int bfound,struct here *flags,char *s1)
{
	printf("%d\n" , bfound);
	if (ft_strcmp(s1, "ls") == 0
			&& (flags->l !=  1 && flags->a != 1 && flags->t != 1 && flags->r != 1 && flags->R != 1))
		printf("Normal display");
	else
		if (bfound > 0 || (flags->l !=  1 && flags->a != 1 && flags->t != 1))
			printf("Issue");
		else
			ft_output(flags);
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
//Issue with ls - 
int main(int argc,char **argv)
{
	int k;
	int j;
	static int bfound;
	struct here *owner;

	owner = (struct here*)malloc(sizeof(struct here));
	k = 2;
	while(argc > 2 && argv[1][0] == 'l' && argv[1][1] == 's')
	{
		j = 1;
		while (argv[k][j] != '\0')
		{
			/*if ( argv[k][0] == '-' && argv[k][j] == 'a')
				owner->a = 1;
			else
				if (argv[k][0] == '-' && argv[k][j] == 'l')
					owner->l = 1;
			else
				if (argv[k][0] == '-' && argv[k][j] == 't')
					owner->t = 1;
			else
				bfound = bfound + 1;*/
			bfound = bfound + ft_check(argv[k][0] , argv[k][j] , owner);
			j++;
		}
		argc--;
		k++;
	}
	ft_display(bfound, owner,argv[1]);
	return (0);
}
