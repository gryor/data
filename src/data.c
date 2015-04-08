#include "data.h"
#include <stdlib.h>
#include <string.h>

int data_create(data * d, size_t size)
{
	d->size = 0;
	d->content = malloc(size);

	if(!d->content)
		return 1;

	d->size = size;
	return 0;
}

void data_destroy(data * d)
{
	free(d->content);
	d->content = NULL;
	d->size = 0;
}

int data_realloc(data * d, size_t size)
{
	d->size = 0;
	d->content = realloc(d->content, size);

	if(!d->content)
		return 1;

	d->size = size;
	return 0;
}

void data_zero(data * d)
{
	d->content = NULL;
	d->size = 0;
}

int data_copy_content(data * d, const void * content, size_t size)
{
	d->size = 0;
	d->content = realloc(d->content, size);

	if(!d->content)
		return 1;

	memcpy(d->content, content, size);
	d->size = size;
	return 0;
}

int data_copy(data * dest, const data * src)
{
	dest->size = 0;
	dest->content = realloc(dest->content, src->size);

	if(!dest->content)
		return 1;

	memcpy(dest->content, src->content, src->size);
	dest->size = src->size;
	return 0;
}

void data_move_content(data * d, void ** content, size_t size)
{
	d->content = *content;
	d->size = size;
	*content = NULL;
}

void data_move(data * dest, data * src)
{
	*dest = *src;
	src->content = NULL;
	src->size = 0;
}

void data_swap(data * d0, data * d1)
{
	data dt = *d0;
	*d0 = *d1;
	*d1 = dt;
}

int data_string(data * d, const char * string)
{
	size_t size = strlen(string);

	if(data_create(d, size))
		return 1;

	if(data_copy_content(d, string, size))
	{
		data_destroy(d);
		return 1;
	}

	return 0;
}

size_t data_count(const data * d, const uint8_t element)
{
	size_t count = 0;

	for (size_t i = 0; i < d->size; i++)
	{
		if(((uint8_t *)d->content)[i] == element)
			count++;
	}

	return count;
}

int data_join(const data * first, const data * second, data * out)
{
	if(data_create(out, first->size + second->size))
		return 1;

	memcpy(out->content, first->content, first->size);
	memcpy(out->content + first->size, second->content, second->size);
	return 0;
}

int data_split(const data * d, const uint8_t separator, data * first, data * second)
{
	for (size_t i = 0; i < d->size; i++)
	{
		if(((uint8_t *)d->content)[i] == separator)
		{
			if(i)
			{
				data_copy_content(first, d->content, i);
			} else
				data_zero(first);

			if(i < d->size)
			{
				data_copy_content(second, ((uint8_t *)d->content)+i+1, d->size-i-1);
			} else
				data_zero(second);
		}
	}
}
