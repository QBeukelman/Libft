/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_realloc.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/11 13:19:41 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2024/12/11 13:30:05 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
	Reallocates memory for a previously allocated block, possibly moving it to a
	new location, and copies the old content to the new location. If necessary,
	it also allocates new memory or frees up memory.

	Parameters:
		ptr: A pointer to the previously allocated memory block.
					If NULL, behaves like malloc(size).
		size: The new size of the memory block, in bytes.

	Return Value:
		On success, returns a pointer to the reallocated memory block.
		On failure, returns NULL. In this case, the original block of
					memory is left unchanged.
*/

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;

	if (ptr == NULL)
	{
		ptr = malloc(size);
		if (ptr == NULL)
			return (NULL);
		return (ptr);
	}
	if (!size)
		return (free(ptr), NULL);
	new_ptr = malloc(size + 1);
	if (new_ptr == NULL)
		return (NULL);
	ft_memcpy(new_ptr, ptr, size);
	return (new_ptr);
}
