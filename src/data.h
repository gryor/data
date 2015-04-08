#ifndef data_H_3U6PNADX
#define data_H_3U6PNADX

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>


typedef struct data
{
	void * content;
	size_t size;
} data;


int data_create(data * d, size_t size);
void data_destroy(data * d);
int data_realloc(data * d, size_t size);
void data_zero(data * d);
int data_copy_content(data * d, const void * content, size_t size);
int data_copy(data * dest, const data * src);
void data_move_content(data * d, void ** content, size_t size);
void data_move(data * dest, data * src);
void data_swap(data * d0, data * d1);
int data_join(const data * first, const data * second, data * out);
int data_string(data * d, const char * string);


#ifdef __cplusplus
}
#endif

#endif // end of include guard: data_H_3U6PNADX
