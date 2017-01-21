/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 14:10:47 by tgauvrit          #+#    #+#             */
/*   Updated: 2017/01/18 15:38:12 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arraylist.h"
#include <stdio.h>

// ===================================
// TEST WITH NORMAL SITUATION: STRINGS
// ===================================

int		main(void)
{
	int		i, size;
	char	**strings;
	char	**tmp;

	printf("%s\n", "CREATION TEST");
	strings = al_create();

	printf("%s\n", "ADDITION TEST");
	al_add(&strings, "1");
	al_add(&strings, "2");
	al_add(&strings, "3");
	al_add(&strings, "4");
	al_add(&strings, "5");
	al_add(&strings, "6");
	al_add(&strings, "7");
	al_add(&strings, "8");
	al_add(&strings, "9");
	al_add(&strings, "10");
	al_add(&strings, "11");
	al_add(&strings, "12");
	al_add(&strings, "13");
	al_add(&strings, "14");
	al_add(&strings, "15");
	al_add(&strings, "16");
	al_add(&strings, "17");
	al_add(&strings, "18");
	al_add(&strings, "19");
	al_add(&strings, "20");
	al_add(&strings, "21");
	al_add(&strings, "22");

	printf("%s\n", "NORMAL TEST (WITH ITERATOR)");
	size = al_size(strings);
	for (i = 0; i < size; ++i)
		printf("%s ", strings[i]);
	printf("\n");

	printf("%s\n", "NORMAL TEST (WITHOUT ITERATOR)");
	// NORMAL TEST (WITHOUT ITERATOR)
	tmp = strings;
	while (tmp != al_end(strings))
		printf("%s ", *(tmp++));
	printf("\n");

	printf("%s\n", "REVERSE TEST (WITH ITERATOR)");
	i = al_size(strings);
	while (i-- > 0)
		printf("%s ", strings[i]);
	printf("\n");

	printf("%s\n", "REVERSE TEST (WITHOUT ITERATOR)");
	// REVERSE TEST
	tmp = al_end(strings);
	while (tmp != strings)
		printf("%s ", *(--tmp));
	printf("\n");

	printf("%s\n", "DESTRUCTION TEST");
	al_destroy(&strings);
	if (strings != NULL)
		printf("%s\n", "Destruction failed");
	return 0;
}

// ====================================
// TEST WITH NORMAL SITUATION: INTEGERS
// ====================================

// int		main(void)
// {
// 	int		i, size;
// 	int		*numbers;
// 	int		*tmp;

// 	printf("%s\n", "CREATION TEST");
// 	numbers = al_create();

// 	printf("%s\n", "ADDITION TEST");
// 	al_add(&numbers, 1);
// 	al_add(&numbers, 2);
// 	al_add(&numbers, 3);
// 	al_add(&numbers, 4);
// 	al_add(&numbers, 5);
// 	al_add(&numbers, 6);
// 	al_add(&numbers, 7);
// 	al_add(&numbers, 8);
// 	al_add(&numbers, 9);
// 	al_add(&numbers, 10);
// 	al_add(&numbers, 11);
// 	al_add(&numbers, 12);
// 	al_add(&numbers, 13);
// 	al_add(&numbers, 14);
// 	al_add(&numbers, 15);
// 	al_add(&numbers, 16);
// 	al_add(&numbers, 17);
// 	al_add(&numbers, 18);
// 	al_add(&numbers, 19);
// 	al_add(&numbers, 20);
// 	al_add(&numbers, 21);
// 	al_add(&numbers, 22);

// 	printf("%s\n", "NORMAL TEST (WITH ITERATOR)");
// 	size = al_size(numbers);
// 	for (i = 0; i < size; ++i)
// 		printf("%d ", numbers[i]);
// 	printf("\n");

// 	printf("%s\n", "NORMAL TEST (WITHOUT ITERATOR)");
// 	// NORMAL TEST (WITHOUT ITERATOR)
// 	tmp = numbers;
// 	while (tmp != al_end(numbers))
// 		printf("%d ", *(tmp++));
// 	printf("\n");

// 	printf("%s\n", "REVERSE TEST (WITH ITERATOR)");
// 	i = al_size(numbers);
// 	while (i-- > 0)
// 		printf("%d ", numbers[i]);
// 	printf("\n");

// 	printf("%s\n", "REVERSE TEST (WITHOUT ITERATOR)");
// 	// REVERSE TEST
// 	tmp = al_end(numbers);
// 	while (tmp != numbers)
// 		printf("%d ", *(--tmp));
// 	printf("\n");

// 	printf("%s\n", "DESTRUCTION TEST");
// 	al_destroy(&numbers);
// 	if (numbers != NULL)
// 		printf("%s\n", "Destruction failed");
// 	return 0;
// }

// ====================================
// TEST FOR ANY DATA TYPE, MORE OR LESS
// ====================================

// int		main(void)
// {
// 	int		i, size;
// 	t_data	*data_al;
// 	t_data	*tmp;

// 	printf("%s\n", "CREATION TEST");
// 	data_al = al_create();

// 	printf("%s\n", "ADDITION TEST");
// 	al_add(&data_al, 1);
// 	al_add(&data_al, 2);
// 	al_add(&data_al, 3);
// 	al_add(&data_al, 4);
// 	al_add(&data_al, 5);
// 	al_add(&data_al, 6);
// 	al_add(&data_al, 7);
// 	al_add(&data_al, 8);
// 	al_add(&data_al, 9);
// 	al_add(&data_al, 10);
// 	al_add(&data_al, 11);
// 	al_add(&data_al, 12);
// 	al_add(&data_al, 13);
// 	al_add(&data_al, 14);
// 	al_add(&data_al, 15);
// 	al_add(&data_al, 16);
// 	al_add(&data_al, 17);
// 	al_add(&data_al, 18);
// 	al_add(&data_al, 19);
// 	al_add(&data_al, 20);
// 	al_add(&data_al, 21);
// 	al_add(&data_al, 22);

// 	printf("%s\n", "NORMAL TEST (WITH ITERATOR)");
// 	size = al_size(data_al);
// 	for (i = 0; i < size; ++i)
// 		printf("%016zx ", *(unsigned long*)&(data_al[i]));
// 	printf("\n");

// 	printf("%s\n", "NORMAL TEST (WITHOUT ITERATOR)");
// 	// NORMAL TEST (WITHOUT ITERATOR)
// 	tmp = data_al;
// 	while (tmp != al_end(data_al))
// 		printf("%016zx ", *(unsigned long*)&(*(tmp++)));
// 	printf("\n");

// 	printf("%s\n", "REVERSE TEST (WITH ITERATOR)");
// 	i = al_size(data_al);
// 	while (i-- > 0)
// 		printf("%016zx ", *(unsigned long*)&(data_al[i]));
// 	printf("\n");

// 	printf("%s\n", "REVERSE TEST (WITHOUT ITERATOR)");
// 	// REVERSE TEST
// 	tmp = al_end(data_al);
// 	while (tmp != data_al)
// 		printf("%016zx ", *(unsigned long*)&(*(--tmp)));
// 	printf("\n");

// 	printf("%s\n", "DESTRUCTION TEST");
// 	al_destroy(&data_al);
// 	if (data_al != NULL)
// 		printf("%s\n", "Destruction failed");
// 	return 0;
// }
