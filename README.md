# get_next_line()
## Creating a function that reads a file one line at a time and saves its position in the file
In this project, I had to build the get_next_line() function.

# 🤔 Understanding (phase 1)
## The problem: what am I solving?
I want to read a file one line of text at a time and remember my position in 
the file while it is still opened.

## The data: what am I given?
A File Descriptor, which is an integer that uniquely identifies an open file of the process.
To access and manipulate the content of any file in C, we need its file descriptor. 

We get the file descriptor of a file by calling the open() function which is 
in the <code>fcntl.h</code> library.

open() takes two arguments, open(<filename>, <mode>)
1. the first is the absolute path of the file you want to open. If that file is 
in your current directory, you can simply write its need
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
### Common Instructions
- Your project must be written in C.
- Your project must be written in accordance with the [Norm](https://github.com/rurangiza/norm/blob/main/The%20Norm%20v3.pdf). If you have bonus
files/functions, they are included in the norm check and you will receive a 0 if there
is a norm error inside.
- Your functions should not quit unexpectedly (segmentation fault, bus error, double
free, etc) apart from undefined behaviors. If this happens, your project will be
considered non functional and will receive a 0 during the evaluation.
- All heap allocated memory space must be properly freed when necessary. No leaks
will be tolerated.
- If the subject requires it, you must submit a Makefile which will compile your
source files to the required output with the flags -Wall, -Wextra and -Werror, use
cc, and your Makefile must not relink.
- Your Makefile must at least contain the rules $(NAME), all, clean, fclean and
re.
- To turn in bonuses to your project, you must include a rule bonus to your Makefile,
which will add all the various headers, librairies or functions that are forbidden on
the main part of the project. Bonuses must be in a different file _bonus.{c/h} if
the subject does not specify anything else. Mandatory and bonus part evaluation
is done separately.
- If your project allows you to use your libft, you must copy its sources and its
associated Makefile in a libft folder with its associated Makefile. Your project’s
Makefile must compile the library by using its Makefile, then compile the project.
- We encourage you to create test programs for your project even though this work
won’t have to be submitted and won’t be graded. It will give you a chance
to easily test your work and your peers’ work. You will find those tests especially
useful during your defence. Indeed, during defence, you are free to use your tests
and/or the tests of the peer you are evaluating.
- Submit your work to your assigned git repository. Only the work in the git reposi-
tory will be graded. If Deepthought is assigned to grade your work, it will be done 
after your peer-evaluations. If an error happens in any section of your work during
Deepthought’s grading, the evaluation will stop.

### Mandatory
- Repeated calls (e.g., using a loop) to your get_next_line() function should let
you read the text file pointed to by the file descriptor, one line at a time.
- Your function should return the line that was read.
If there is nothing else to read or if an error occurred, it should return NULL.
- Make sure that your function works as expected both when reading a file and when
reading from the standard input.
- Please note that the returned line should include the terminating \n character,
except if the end of file was reached and does not end with a \n character.
- Your header file get_next_line.h must at least contain the prototype of the
get_next_line() function.
- Add all the helper functions you need in the get_next_line_utils.c file.
- Because you will have to read files in get_next_line(), add this option to your
compiler call: -D BUFFER_SIZE=n
It will define the buffer size for read().
The buffer size value will be modified by your peer-evaluators and the Moulinette
in order to test your code.
- You will compile your code as follows (a buffer size of 42 is used as an example):
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c
- We consider that get_next_line() has an undefined behavior if the file pointed to
by the file descriptor changed since the last call whereas read() didn’t reach the
end of file.
- We also consider that get_next_line() has an undefined behavior when reading
a binary file. However, you can implement a logical way to handle this behavior if
you want to.

### Bonus (only evaluated if mandatory part is perfect)
- Develop get_next_line() using only one static variable.
- Your get_next_line() can manage multiple file descriptors at the same time.
For example, if you can read from the file descriptors 3, 4 and 5, you should be
able to read from a different fd per call without losing the reading thread of each
file descriptor or returning a line from another fd.
It means that you should be able to call get_next_line() to read from fd 3, then
fd 4, then 5, then once again 3, once again 4, and so forth.

### Forbiden
- You are not allowed to use your libft in this project.
- lseek() is forbidden.
- Global variables are forbidden.

# 🗺️ Planning (phase 2)

It reads a text file and returns one line. 

When you call the function multiple times, it returns the following lines,
hence the name "get_next_line".

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
If we called and printed the result of the <code>get_next_line()</code> 
function once, we would see (without the quotes):

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
