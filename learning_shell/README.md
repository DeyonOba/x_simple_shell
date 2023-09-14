# Simple Shell Learning Documentation

### How does the `wait` function work in C

`wait`: The wait function wait for a process to change state. This very useful when you do not want the parent process to continue before the child has completed. This is a very used tool found in the C standard library that helps to create and manage process.

**Prototype of the `wait` function:**
```c
#include <sys/types.h>
#includd <sys/wait.h>

pid_t wait(int *wstatus)
```

**`wait` Arguments**

`wstatus`: This is a pointer to an integer value where the status infomation of the an ended/ terminated child process would be stored. If you're not intrested in the exist status of the child process, yoou can pass 'NULL' to `wstatus` on declaration.

From ChatGPT: (Summary)

> This is how the wait function works:
> 1. When the wait function is called on the parent process, the parent process suspends execution and enters a waiting state until the child process terminates.
> 2. If there are more than one child process the PID of any of child process in returned. Therefore, you cannot predict which child process ID was returned.
> 3. The status of the terminated child process is evaluated by the parent, if was an error or success. Depending on the exit status, if the status in "NULL" the status is ignored.
> 4. If there are no child processes that have terminated, the wait function may block (wait) until a child process does terminate. If the parent process has no child processes, wait immediately returns with an error.

Sample code based on ALX curriculum is found in filenamed `wait.c`.

### How `stat` function in C work

`stat`: This function is used to retrieve information about a file or directory, such as it's attributes and status. This is a standard C library that can be used to obtain information like file permission, time stamp, size, and more.

**Prototype of the `stat` function:**

```c
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int stat(const char *pathname, struct stat *statbuf);
```
- `pathname`: A pointer to a null terminated string containing the path to the or directory you want to get information about.
- `statbuf`: A pointer to a `struct stat` where the file information will be stored.
