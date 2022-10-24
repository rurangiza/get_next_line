# Notes
## Process

### How does the open() function works?
```C
int	open(const char *pathname, int flags);
```
The open() function is used to open files and directories. After they are opened, their content can be manipulated then saved.

You give it:
1. The path to a file or directory
2. The flags or mode in which you want to open that file
And it returns the file descriptor of that file. Which is a reference number necessary to access opened files.

The basic file descriptors are:
- 0 : Standard Input
- 1 : Standard Output
- 2 : Standard Error

The flags include 3 main modes:
- O_RDONLY (read only)
- O_WRONLY (write only)
- O_RDWR (read and write)

### How does the read() function works?
```C
ssize_t  read(int fd, void *buf, size_t nbyte);
```
Attempts to read nbytes of data 
from the object referenced by the object referenced by the file descdriptor {fd}
into the buffer pointed to by {buf}


### How does the write() function works?
```C
size_t  write(int fd, cont void *buf, size_t count);
````
- 1st arg : the file descriptor of the file you want to write in
- 2nd arg : the content you want to write in that file
- 3rd arg : how many bytes you want to write to the buffer

### Qu'est ce qu'un file descriptor?
C'est une reference qui pointe vers un fichier ouvert sur l'ordinateur

### What are static variables?