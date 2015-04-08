#include "data.h"
#include <stdlib.h>
#include <string.h>

int data_create(data_t * data, size_t size)
{
	data->size = 0;
	data->content = malloc(size);

	if(!data->content)
		return 1;

	data->size = size;
	return 0;
}

void data_destroy(data_t * data)
{
	free(data->content);
	data->content = NULL;
	data->size = 0;
}

int data_realloc(data_t * data, size_t size)
{
	data->size = 0;
	data->content = realloc(data->content, size);

	if(!data->content)
		return 1;

	data->size = size;
	return 0;
}

void data_zero(data_t * data)
{
	data->content = NULL;
	data->size = 0;
}

int data_copy_content(data_t * data, const void * content, size_t size)
{
	data->size = 0;
	data->content = realloc(data->content, size);

	if(!data->content)
		return 1;

	memcpy(data->content, content, size);
	data->size = size;
	return 0;
}

int data_copy(data_t * dest, const data_t * src)
{
	dest->size = 0;
	dest->content = realloc(dest->content, src->size);

	if(!dest->content)
		return 1;

	memcpy(dest->content, src->content, src->size);
	dest->size = src->size;
	return 0;
}

void data_move_content(data_t * data, void ** content, size_t size)
{
	data->content = *content;
	data->size = size;
	*content = NULL;
}

void data_move(data_t * dest, data_t * src)
{
	*dest = *src;
	src->content = NULL;
	src->size = 0;
}

void data_swap(data_t * d0, data_t * d1)
{
	data_t dt = *d0;
	*d0 = *d1;
	*d1 = dt;
}

int data_string(data_t * data, const char * string)
{
	size_t size = strlen(string);

	if(data_create(data, size))
		return 1;

	if(data_copy_content(data, string, size))
	{
		data_destroy(data);
		return 1;
	}

	return 0;
}

size_t data_count(const data_t * data, const uint8_t element)
{
	size_t count = 0;

	for (size_t i = 0; i < data->size; i++)
	{
		if(((uint8_t *)data->content)[i] == element)
			count++;
	}

	return count;
}

int data_join(const data_t * first, const data_t * secondata, data_t * out)
{
	if(data_create(out, first->size + secondata->size))
		return 1;

	memcpy(out->content, first->content, first->size);
	memcpy(out->content + first->size, secondata->content, secondata->size);
	return 0;
}

int data_split(const data_t * data, const uint8_t separator, data_t * first, data_t * secondata)
{
	for (size_t i = 0; i < data->size; i++)
	{
		if(((uint8_t *)data->content)[i] == separator)
		{
			if(i)
			{
				data_copy_content(first, data->content, i);
			} else
				data_zero(first);

			if(i < data->size)
			{
				data_copy_content(secondata, ((uint8_t *)data->content)+i+1, data->size-i-1);
			} else
				data_zero(secondata);
		}
	}
}
