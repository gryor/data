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
	// Simple test
	data_t data;

	if(data_string(&data, "Hello World!"))
		die("Could not create a data from a string");

	printf("Test data\nData: %*s\n", data.size, data.content);

	data_destroy(&data);


	// Join all
	size_t i;
	data_t data_multi[4];
	data_t data_joined;
	data_t data_joined_separated;


	for (i = 0; i < 4; i++)
		data_zero(&data_multi[i]);

	data_zero(&data_joined);
	data_zero(&data_joined_separated);

	data_string(&data_multi[0], "Drop");
	data_string(&data_multi[1], "me");
	data_string(&data_multi[2], "from");
	data_string(&data_multi[3], "space!");

	data_join_all(data_multi, 4, &data_joined);
	data_join_all_separated(data_multi, 4, ' ', &data_joined_separated);

	printf("\nTest data join all\nData: %*s\n", data_joined.size, data_joined.content);
	printf("\nTest data join all separated\nData: %*s\n", data_joined_separated.size, data_joined_separated.content);

	for (i = 0; i < 4; i++)
		data_destroy(&data_multi[i]);

	data_destroy(&data_joined);
	data_destroy(&data_joined_separated);

	return 0;
}
