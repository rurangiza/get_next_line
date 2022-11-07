## FOPEN_MAX
### Potential limit of simultaneous open streams
```
#include <stdio.h>
```
This macro constant expands to an integral expression that represents the maximum number of files that can be opened simultaneously.

Particular library implementations may count files opened by tmpfile towards this limit. Implementations may also allow more files to be opened beyond this limit.

FOPEN_MAX shall be greater than 7 on all systems.