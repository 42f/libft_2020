# Libft
Student's own C library for 42 School. It's the result of work on different project and an ever growing library to be used in future projects and showcase the current one's current ability.

`make` to compile the library

### bits
|function		| 	comment |
|:--------------|:----------|
ft_reversebits	|Change endianness.

### char

|function		| 	comment |
|:--------------|:----------|
ft_isalnum		|Returns 1 if the char passed as parameter is alphabetic or numeric.
ft_isalpha		|Returns 1 if the char passed as parameter is alphabetic.
ft_isprint		|Returns 1 if the char passed as parameter is numeric.
ft_isascii		|Returns 1 if the char passed as parameter is in the ascii table.
ft_isdigit		|Returns 1 if the char passed as parameter is a number.
ft_tolower		|Minimize the char passed as parameter.
ft_toupper		|Capitalize the char passed as parameter.

### conversion
|function		| 	comment |
|:--------------|:----------|
ft_atoi			|Convert the string passed as parameter to an integer.
ft_atoi_base	|Convert the strong passed as parameter to an integer according to the base passed as parameter.
ft_convert_base	|Convert a string containing a number in a base passed as two first parameters to a string in a base passed as third parameter.
ft_itoa			|Convert an integer to a string.
ft_itoa_base	|Convert an inteher to a string in a based passed as parameter.

### gnl
|function		| 	comment |
|:--------------|:----------|
get_next_line	|Fill the buffer (with malloc) passed as parameter with the next line in a file descriptor passe as parameter. The buffer must be freed. Returns 1 if a line is read, 0 if the EOF is reached, -1 if an error occured.

### list
|function		| 	comment |
|:--------------|:----------|
ft_lstnew		|Create a new linked-list element.
ft_lstadd_back	|Add a linked-list element at the end of a linked-list.
ft_lstadd_front	|Add a linked-list element at the begining of a linked-list.
ft_lstsize		|Return the number of elements in a list passed as parameter.
ft_lstclear		|Delete every elements of a linked-list and free their content.
ft_lstdelone	|Delete an elements of a linked-list and free its content.
ft_lstiter		|Travers a linked-list while applying the function passed as a parameter to the content of each element.
ft_lstlast		|Return a pointer to the last element of a linked-list passed as parameter.
ft_lstmap		|Copy and delete the original of a linked-list passed as parameter while applying the function f passed as parameter to the content of the original list.

### memory
|function		| 	comment |
|:--------------|:----------|
ft_bzero		|Set a given memory location to 0.
ft_calloc		|Allocate with malloc a region of memory of a size and count passed as parameter and set it to 0.
ft_memccpy		|Copy source memory to destination up n bytes or until the character c passed as parameter is met in srcs if it occurs before n bytes. If the c character is found while copying, it is returned, otherwise a NULL pointer is returned.
ft_memchr		|Return a pointer to the c character if found in the string s, or a NULL pointer if not found.
ft_memcmp		|Return the difference between the first different bytes when comparing s1 and s2 in the first n bytes.
ft_memcpy		|Copy the n first bytes of src to dest and return a pointer to dest.
ft_memmove		|Copy n bytes of src to dst and allow overlapping of src and dst. Returns a pointer to dst.
ft_memset		|Set a value c to n bytes of the memory region pointed. Returns a pointer to the memory region.

### math
|function		| 	comment |
|:--------------|:----------|
ft_pow			|Return the result of number to the power of numbers passed as parameter. Will return 0 for negative power, 1 for 0 to the power of 0. Int overflow of the result is undefined.

### put
|function		| 	comment |
|:--------------|:----------|
ft_putchar		|Put the char passed as parameter to stdout.
ft_putchar_fd	|Put the char passed as parameter to the fd passed as parameter.
ft_putendl_fd	|Put the string passed as parameter to the fd passed as parameter, then put a new line. 
ft_putmem		|Put n bytes of the memory region passed as parameter to the stdout in hexadecimal.
ft_putnbr		|Put the integer passed as parameter to stdout.
ft_putnbr_fd	|Put the integer passed as parameter to the fd passed as parameter.
ft_putnbr_base	|Put the long long int passed as parameter in the base passed as parameter to the stdout.
ft_putstr		|Put the string passed as parameter to stdout.
ft_putstr_fd	|Put the string passed as parameter to the fd passed as parameter.

### str
|function		| 	comment |
|:--------------|:----------|
ft_split		|Return a pointer to an array of strings resulting of the string passed as parameter being split at each char c passed as parameter.
ft_strchr		|Return a pointer to the first occurence of the value c passed as parameter in the string passed as parameter, or NULL if not found.
ft_strdup		|Allocate with malloc a new string which is a copy of the string passed as parameter.
ft_strjoin		|Allocate with malloc a new string made up of the two strings passed as parameter.
ft_strlcat		|libc identical
ft_strlcpy		|libc identical
ft_strlen		|libc identical
ft_strmapi		|Allocates with malloc and copy the string passed as parameter while applying the f function passed as parameter to each character.
ft_strncmp		|libc identical
ft_strnstr		|libc identical
ft_strrchr		|libc identical
ft_strtrim		|Trim a string passed as parameter from the first occurence of a set of char.
ft_substr		|Allocates with malloc and copy a section of the string passed as parameter between start and len.
