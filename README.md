# get_next_line()
## Creating a function that reads a file one line at a time and saves its position in the file
In this project, I had to build the get_next_line() function.

# 🤔 Understanding (phase 1)
## The problem: what am I solving?
I want to read a file one line of text at a time and remember my position in the file while it is still opened.

## The data: what am I given?
A File Descriptor, which is an integer that uniquely identifies an open file of the process.
To access and manipulate the content of any file in C, we need its file descriptor. 

We get the file descriptor of a file by calling the open() function which is in the <code>fcntl.h</code> library.

open() takes two arguments, open(<filename>, <mode>)
1. the first is the absolute path of the file you want to open. If that file is in your current directory, you can simply write its need
2. the mode in which to open the file
	- O_RDONLY: read only
	- O_WRONLY: write only
	- O_RDWR: read and write
	- O_CREAT: create file if it doesn’t exist

When given these informations, open() will return a file descriptor
- **-1 i**f something wrong happened
- a **positive number** if successful

N.B: the file descriptor is an int, so handle all cases in the range of an int..

## The conditions: what constrains or details do I need to be aware of?

# 🗺️ Planning (phase 2)

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
