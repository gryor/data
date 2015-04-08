# Data

A C library for data definition and functions relating to data.
In this library's context data means same as `std::string<uint8_t>` means in
C++.


## Definition

```c
typedef struct data
{
	void * content;
	size_t size;
} data;
```

## Return value

Each function returning an `int` returns 0 on success.
This makes it possible to write code like:

```c
if(data_create(&d, 12))
    die("Could not create a data structure.");
```

## Functions

```c
int data_create(data * d, size_t size);
```

Initialize a `data` structure.

```c
void data_destroy(data * d);
```

Free resources used by a `data` structure.

```c
int data_realloc(data * d, size_t size);
```

Resize memory allocated in a `data` structure.

```c
void data_zero(data * d);
```

Zero out a `data` structure.
This should be called for each `data` structure, which is not put through data_create.

```c
int data_copy_content(data * d, const void * content, size_t size);
```

Copy contents from a memory area into a `data` structure.

```c
int data_copy(data * dest, const data * src);
```

Copy contents from one `data` structure into another.

```c
void data_move_content(data * d, void ** content, size_t size);
```

Move contents from one memory area into a `data` structure.
This is done by moving the pointer and not actually copying any data.

```c
void data_move(data * dest, data * src);
```

Move contents from one `data` into another.
This is done by moving the pointer and not actually copying any data.

```c
void data_swap(data * d0, data * d1);
```

Swap the contents between two `data` structures.

```c
int data_string(data * d, const char * string);
```

Create a `data` structure from a string.

E.g. `data_string(&text, "Hello World!")`
will set text.content into "Hello World!" and text.size to 12.

```c
size_t data_count(const data * d, const uint8_t element);
```

Count `element`s in a `data` structure.

```c
int data_join(const data * first, const data * second, data * out);
```

Join the contents of `first` and `second` into `out`.

```c
int data_split(const data * d, const uint8_t separator, data * first, data * second);
```

Split the contents of a `data` structure by `separator` and place the results into `first` and `second`.
