# get_next_line()
## A function that reads a file one line at a time and saves its position in the file
In this project, I had to build the get_next_line() function.


It reads a text file and returns one line. 

When you call the function multiple times, it returns the following lines, hence the name "get_next_line".

## Usage
Let's say we have this text file:
```
Some say the world will end in fire,
Some say in ice.
From what I’ve tasted of desire
I hold with those who favor fire.
But if it had to perish twice,
I think I know enough of hate
To say that for destruction ice
Is also great
And would suffice.
```
If we called and printed the result of the <code>get_next_line()</code> function once, we would see (without the quotes):

	Some say the world will end in fire,

If we called it three times, we would have:

	Some say the world will end in fire,
	Some say in ice.
	From what I’ve tasted of desire

And our main would ressemble this.

```C
#include <fcntl.h> // Access: open(), close()
#include <stdio.h> // Access: printf()

int main(void)
{
	int		fd;
	char	*str;

	// Open a file and save its file descriptor
	fd = open("filename", O_RDONLY);
	// Repeat until the "break" condition
	while (1)
	{
		// Save the line returned by get_next_line()
		str = get_next_line(fd);
		// Exit if the is nothing more to read
		if (str == NULL)
			break ;
		// Print the line
		printf("%s\n",str);
		// Free the space allocated in get_next_line()
		free(str);
	}
	// Close the opened file
	close(fd);
	// Successful exit status
	return (0);
}
```
```

```

## FOPEN_MAX
### Potential limit of simultaneous open streams
```
#include <stdio.h>
```
This macro constant expands to an integral expression that represents the maximum number of files that can be opened simultaneously.

Particular library implementations may count files opened by tmpfile towards this limit. Implementations may also allow more files to be opened beyond this limit.

FOPEN_MAX shall be greater than 7 on all systems.
