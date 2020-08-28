# Libft
Student's own C library for 42 School. It's the result of work on different project and an ever growing library to be used in future projects and showcase the current one's current ability.

Given the fact the school doesn't allow no or very few external function (from libc or such) in most of the student's project, some function in this lib are simply my verison of libc's implementations. Some of them are improved (atoi managed signs better for example). 

## Usage

`make` to compile the library.
`make clean` will remove the object files.
`make install` will copy the compiled library and header to the right folders (mac os for sure, linux needs to be tested).
`make fclean` to remove everything.

## Functions list

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

### Binary Tree

|Prototype|Comment|
|:--------|:------|
`t_btree		*btree_create_node(void *item);`									|Allocate with malloc a new node of which the item is passed as parameter, with null left and right pointers.
`void			btree_free_suffix(t_btree *root);`									|For each elements of a tree passed as parameter, the function will free the item (which must me freeable) and the node.
`int btree_nodes_count(t_btree *root);`												|Returns the count of nodes contained in a the tree passed as parameter.
`int btree_level_count(t_btree *root);`												|Returns the count of level of the longuest branch on the tree passed as parameter.
`void			btree_apply_item_prefix(t_btree *root, void (*applyf)(void *));`	|Apply the function passed as parameter to the item of each node, following prefix/preorder order.
`void			btree_apply_item_infix(t_btree *root, void (*applyf)(void *));`		|Apply the function passed as parameter to the item of each node, following infinx/inorder order.
`void			btree_apply_item_suffix(t_btree *root, void (*applyf)(void *));`	|Apply the function passed as parameter to the item of each node, following suffix/postfix order.
`void			btree_apply_node_prefix(t_btree *root, void (*applyf)(t_btree *));`	|Apply the function passed as parameter to the node of each node, following prefix/preorder order.
`void			btree_apply_node_infix(t_btree *root, void (*applyf)(t_btree *));`	|Apply the function passed as parameter to the node of each node, following infix/inodred order.
`void			btree_apply_node_suffix(t_btree *root, void (*applyf)(t_btree *));`	|Apply the function passed as parameter to the node of each node, following suffix/postfix order.
`void			btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *));`			|Each call insert the item passed as parameter in the binary tree passed as parameter. The new node location will depend on the return of a function passed as parameter, which is expects to act as strcmp. The tree generated by multiple calls to the function will be sorted, meaning the right side of each node will only contain values lower than the given node, and the left side will only contain values higher or equale to the given node. (higher/lower/equal in the same way as considererd by strcmp, meaning a NULL parameter is undefined. If you whish to have an element of your binary tree with a null item, make sure the function passed as parameter has a defined behaviour for null parameters).
`void			*btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *, void *));`		|Return a pointer to the first occurence of the data passed as parameter in a tree passed as parameter. First occurence meant in a infix order. The function passed as parameter is considered to behave like strcmp (Meaning a NULL parameter is undefined. If you whish to have an element of your binary tree with a null item, make sure the function passed as parameter has a defined behaviour for null parameters). If none is found, a NULL pointer is returned. 
`void			btree_apply_by_level(t_btree *root,	void (*applyf)(void *node, int level, int is_first_elem))`	|Apply the function passed as parameter to each nodes, level after level, starting from the root passed as parameter and going from the most lefthand node to the most righthand node of each level. Uses malloc(3) and free(3) to generate a queue in order to improve performances.

## Binary Tree: potentiel additions

|Function |Comment|Status|
|:--------|:------|:-----|
btree_apply_by_level_spiral|Would work as the current `btree_apply_by_level` only it would go from right to left on odd levels and left to right on even levels|❌
btree_apply_by_level_spiral_reverse|Would work as the current `btree_apply_by_level` only it would go from left to right on odd levels and right to left on even levels|❌
btree_apply_to_specific_level|Apply the function passed as parameter to one level passed as parameter.|❌
btree_apply_to_n_nodes_specific_level|Apply the function passed as parameter on, at most, n nodes on the level passed as parameter. If the level has less nodes than n, it applies to all nodes on the level.|❌

