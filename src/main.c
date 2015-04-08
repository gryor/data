#include <stdio.h>
#include <stdlib.h>
#include "data.h"


void die(const char * error)
{
	puts(error);
	exit(1);
}

int main(int argc, char * argv[])
{
	data d;

	if(data_string(&d, "Hello World!"))
		die("Could not create a data from a string");

	printf("Test data\nData: %*s\n", d.size, d.content);

	data_destroy(&d);

	return 0;
}
