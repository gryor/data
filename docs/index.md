# Data

A C library for a generic data_t structure.

## Install

```sh
make lib
sudo make install
```

## Definition

```c
typedef struct data
{
	void * content;
	size_t size;
} data_t;
```

## Return value

Each function returning an `int` returns 0 on success.
This makes it possible to write code like:

```c
if(data_create(&data, 12))
    die("Could not create a data_t structure.");
```

## Functions

```c
int data_create(data_t * data, size_t size);
```

Initialize a `data` structure.

```c
void data_destroy(data_t * data);
```

Free resources used by a `data` structure.

```c
int data_realloc(data_t * data, size_t size);
```

Resize memory allocated in a `data` structure.

```c
void data_zero(data_t * data);
```

Zero out a `data` structure.
This should be called for each `data` structure, which is not put through data_create.

```c
int data_copy_content(data_t * data, const void * content, size_t size);
```

Copy contents from a memory area into a `data` structure.

```c
int data_copy(data_t * dest, const data_t * src);
```

Copy contents from one `data` structure into another.

```c
void data_move_content(data_t * data, void ** content, size_t size);
```

Move contents from one memory area into a `data` structure.
This is done by moving the pointer and not actually copying any data.

```c
void data_move(data_t * dest, data_t * src);
```

Move contents from one `data` into another.
This is done by moving the pointer and not actually copying any data.

```c
void data_swap(data_t * d0, data_t * d1);
```

Swap the contents between two `data` structures.

```c
int data_string(data_t * data, const char * string);
```

Create a `data` structure from a string.

E.g. `data_string(&text, "Hello World!")`
will set text.content into "Hello World!" and text.size to 12.

```c
size_t data_count(const data_t * data, const uint8_t element);
```

Count `element`s in a `data` structure.

```c
int data_join(const data_t * first, const data_t * secondata, data_t * out);
```

Join the contents of `first` and `second` into `out`.

```c
int data_split(const data_t * data, const uint8_t separator, data_t * first, data_t * secondata);
```

Split the contents of a `data` structure by `separator` and place the results into `first` and `second`.
