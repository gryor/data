#ifndef data_H_3U6PNADX
#define data_H_3U6PNADX

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <stdint.h>


typedef struct data
{
	void * content;
	size_t size;
} data_t;


int data_create(data_t * data, const size_t size);
void data_destroy(data_t * data);
int data_realloc(data_t * data, const size_t size);
void data_zero(data_t * data);
int data_copy_content(data_t * data, const void * content, const size_t size);
int data_copy(data_t * dest, const data_t * src);
void data_move_content(data_t * data, void ** content, const size_t size);
void data_move(data_t * dest, data_t * src);
void data_swap(data_t * d0, data_t * d1);
int data_string(data_t * data, const char * string);
size_t data_count(const data_t * data, const uint8_t element);
int data_join(const data_t * first, const data_t * second, data_t * out);
int data_join_separated(const data_t * first, const data_t * second, const uint8_t separator, data_t * out);
int data_join_all(const data_t * data, const size_t size, data_t * out);
int data_join_all_separated(const data_t * data, const size_t size, const uint8_t separator, data_t * out);
int data_split(const data_t * data, const uint8_t separator, data_t * first, data_t * second);


#ifdef __cplusplus
}
#endif

#endif // end of include guard: data_H_3U6PNADX
