#include <stdio.h>

void binary_print(int number, int bit)
{
	bit = bit - 1;
	for (bit;bit>=0;bit--)
		if(((number >> bit) & 1) == 0)
			if (bit % 8 == 0)
				printf("0 ");
			else
				printf("0");
		else
			if (bit % 8 == 0)
				printf("1 ");
			else
				printf("1");
		printf("\n");
}
