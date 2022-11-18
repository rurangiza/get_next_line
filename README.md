# get_next_line()
## Creating a function that reads a file one line at a time and saves its position in the file
In this project, I had to build the get_next_line() function.

# Table of contents
1. [Understanding](#phase1)
	1. [The problem](#problem)
	2. [The data](#data)
	3. [The conditions](#conditions)
2. [Planning](#phase2)
3. [Research](#phase3)
	1. [Questions](#questions)
	2. [Answers](#answers)

# 🤔 Understanding (phase 1) <a name="phase1"></a>
## The problem <a name="problem"></a>
| what am I solving?

I want to read a file one line of text at a time and remember my position in 
the file while it is still opened. So when I read that file again, 
it will return me the next line of that file and not one I've already read.

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

Calling it a second time would return:

	Some say in ice.
And so on.

## The data <a name="data"></a>
| what am I given?
A File Descriptor, which is an integer that uniquely identifies an open file.
To access and manipulate the content of any file in C, we need its file descriptor. 

We get the file descriptor of a file by calling the open() function.

open() takes two arguments

```C
int	open(<path-to-file>, <mode>)
```

1. the first is the absolute path of the file you want to open. If that file is 
in your current directory, you can simply write its name
2. the mode in which to open the file

	| Mode  | Description |
	|---|---|
	|O_RDONLY   | read only  |
	| O_WRONLY  | write only  |
	| O_RDWR  |  read and write |
	| O_CREAT | create file if it doesn’t exist |

When given these informations, open() will return a file descriptor
- **-1 i**f something wrong happened
- a **positive number** if successful

Exemple:
```C
int fd;

fd = open("file.txt", O_RDONLY);
```

N.B: the file descriptor is an int, so the function should handle all values an int can have (valid or not)..

## The conditions <a name="conditions"></a>
| what constrains or details do I need to be aware of?
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
- We consider that `get_next_line()` has an undefined behavior if the file pointed to
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

# 🗺️ Planning (phase 2) <a name="phase2"></a>

### Steps
1. Read file until I reach the new line character ('\n') or end of file
- If '\n' is found, return a string from first character read till '\n'
- else, return everything that was read until now (end of file)

# 🔎 Research (phase 3) <a name="phase3"></a>

### Questions <a name="questions"></a>
- How to read a file?
- How to know I reached the end of the file?
- How to remember the position where I was previously?

### Answers <a name="answers"></a>
> How to read a file

To read a file, we use the function read(), which takes 3 arguments:

```C
int	read(<file descriptor>, <buffer>, <size>)
```
1. a file descriptor: to access a file
2. a buffer: which is a variable that stores what was read
3. a size: the number of bytes to read at a time

read() goes through a file a certain number of bytes at a time
and saves that number of bytes in the given buffer.

It returns the number of bytes that were successfully read.



> How to know I reached the end of the file

Ex: if you say you want to read 5 bytes at a time, read() will advance in the file 5 bytes at a time, save those in your buffer and return :
- <code>5</code>, if there was 5 or more bytes remaining in the file
- <code>less than 5</code>, if the end of the file is less than 5 bytes away
- <code>0</code>, if we reached the end
- <code>-1</code>, if an error occured

```
Hello, my name is arsene
I like programming
And make music
```


> How to remember my position

Static variables!

Static variables are special kind of variables that preserve their value even after they are out of their scope (outside of the function they were declared in).

Exemple:
```C
#include<stdio.h>

int fun()
{
	// First time this function is called, count will be initialized to 0
	// After that, count will skip the initialization part and remember its previous state
	static int count = 0;
	count++;
	return count;
}

int main()
{
	printf("%d ", fun());
	printf("%d ", fun());
	return 0;
}

```
Output:
```
1 2
```

Facts about static variables in C:
1. A static int variable remains in memory while the program is running. A normal or auto variable is destroyed when a function call where the variable was declared is over
2. Static variables are allocated memory in data segment, not stack segment. See memory layout of C programs for details.
3. Static variables (like global variables) are initialized as 0 if not initialized explicitly
4. In C, static variables can only be initialized using constant literals.
5. Static global variables and functions are also possible in C/C++. The purpose of these is to limit scope of a variable or function to a file. Please refer Static functions in C for more details.
6. Static variables should not be declared inside structure. The reason is C compiler requires the entire structure elements to be placed together (i.e.) memory allocation for structure members should be contiguous. It is possible to declare structure inside the function (stack segment) or allocate memory dynamically(heap segment) or it can be even global (BSS or data segment). Whatever might be the case, all structure members should reside in the same memory segment because the value for the structure element is fetched by counting the offset of the element from the beginning address of the structure. Separating out one member alone to data segment defeats the purpose of static variable and it is possible to have an entire structure as static.
