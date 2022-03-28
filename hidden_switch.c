#include <stdio.h>
#include <string.h>
#include "binary_print_function.h"

struct S
{
	int x;
	short y;
	int z; // without it the short size would be 2 bytes, with it 4 bytes
};

int main()
{
	struct S s, *s_pointer;

	s_pointer = &s;

	memset(&s, 0, sizeof(s));

  char* w = (char *)&s; // for printing in bytes
  
	for (int i=0; i < 12; i++)
	{
		printf("%d. memory block:\t%p \tValue: ", i+1, w+i);
		binary_print(*(w+i), 8);
	}


	s.x = 1;
	s.y = 2;
	s.z = 3;


	printf("The size of the sctructure (int+short+int=10): %ld\n", sizeof(s));


	printf("Memory address of the the first int: %p\n", &s.x);
	printf("Its value: x =  %d\n", s.x);
	binary_print(s.x, 32);
	printf("Memory address of the short: %p\n", &s.y);
	printf("Is value: y =  %d\n", s.y);
	binary_print(s.y, 16);
	printf("Memory address of the second int: %p\n", &s.z);
	printf("Value: z =  %d\n", s.z);
	binary_print(s.z, 32);

	for (int i=0; i < 12; i++)
	{
		printf("%d. memory block:\t%p \tValue: ", i+1, w+i);
		binary_print(*(w+i), 8);
	}

	memset(&s, 0, sizeof(s));

	s.x = 1;
	s.y = 2;
	s.z = 3;

	int* p = (int *)&s.y;

	printf("We created a pointer p with 4 bytes size, and assigned to y. Its value will be the address of y. The value of *p will be the value of y.\n");
	printf("Memory address stored in p: %p\n", p);
	printf("The value of *p: %d\nIn binary format: \n", *p);
	binary_print(*p, 32);
	printf("The next is a binary operation in order to access the hidden 2 bytes in the structure (the 7th and 8th memory block). We will shift a bit (the 1st of the 5th memory block) to the left with 29\n");
	*p = *p ^ ((-*p ^ *p) & (*p << 29));
	printf("Value of *p: %d\nIn binary format:\n", *p);
	binary_print(*p, 32);

	for (int i=0; i < 12; i++)
	{
		printf("%d. memory block:\t%p \tValue: ", i+1, w+i);
		binary_print(*(w+i), 8);
	}
	printf("So, we switched in a bit (the 6th bit of 8th memory block) in the hidden part, and we can read it with our pointer. However, the point is the next: the value of y is still %d! The switch is invisible from the element's and the structure's viewpoint!\n", s.y);
	printf("The value of y from the structure: %d\n", s_pointer->y); 

}

