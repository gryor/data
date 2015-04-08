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
	data_t data;

	if(data_string(&data, "Hello World!"))
		die("Could not create a data from a string");

	printf("Test data\nData: %*s\n", data.size, data.content);

	data_destroy(&data);

	return 0;
}
