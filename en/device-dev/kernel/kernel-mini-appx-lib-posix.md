# POSIX Support



## Basic Concepts

The OpenHarmony kernel uses the  **musl libc**  library and self-developed APIs and supports the Portable Operating System Interface \(POSIX\). You can develop components and applications working on the kernel based on the POSIX.

## Development Guidelines

### Available APIs

**Table  1**  Available APIs

| Category| Header File| API| Description|
| -------- | -------- | -------- | -------- |
| process | #include <stdlib.h> | void abort(void); | Terminates the thread.|
|  | #include <assert.h> | void assert(scalar expression); | Terminates the thread if the assertion is false.|
|  | #include <pthread.h> | int pthread_cond_destroy(pthread_cond_t *cond); | Destroys a condition variable.|
|  | #include <pthread.h> | int pthread_cond_init(pthread_cond_t *restrict cond, const pthread_condattr_t *restrict attr); | Initializes a condition variable.|
|  | #include <pthread.h> | int pthread_condattr_getpshared(const pthread_condattr_t *attr, int *shared); | Obtains condition variable attributes. Currently, only the attributes of **PTHREAD_PROCESS_PRIVATE** can be obtained.|
|  | #include <pthread.h> | int pthread_condattr_setpshared(pthread_condattr_t *attr, int shared); | Sets a condition variable attribute.|
|  | #include <pthread.h> | int pthread_condattr_getclock(const pthread_condattr_t *attr, clockid_t *clock); | Obtains the thread clock.|
|  | #include <pthread.h> | int pthread_condattr_destroy(pthread_condattr_t *attr); | Destroys a condition variable and invalidates the attribute object.|
|  | #include <pthread.h> | int pthread_cond_timedwait(pthread_cond_t *restrict cond, pthread_mutex_t *restrict mutex, const struct timespec *restrict abstime); | Waits for the condition.|
|  | #include <pthread.h> | int pthread_condattr_init(pthread_condattr_t *attr); | Initializes the condition variable attribute.|
|  | #include <pthread.h> | int pthread_mutex_unlock(pthread_mutex_t *mutex); | Unlocks a mutex.|
|  | #include <pthread.h> | int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg); | Creates a thread.|
|  | #include <pthread.h> | int pthread_join(pthread_t thread, void **retval); | Waits for a thread to terminate.|
|  | #include <pthread.h> | pthread_t pthread_self(void); | Obtains the ID of the current thread.|
|  | #include <pthread.h> | int pthread_getschedparam(pthread_t thread, int *policy, struct sched_param *param); | Obtains the scheduling policy and parameters of a thread.|
|  | #include <pthread.h> | int pthread_setschedparam(pthread_t thread, int policy, const struct sched_param *param); | Sets a scheduling policy and parameters for a thread.|
|  | #include <pthread.h> | int pthread_setschedprio(pthread_t thread, int prio); | Sets the thread priority.|
|  | #include <pthread.h> | int pthread_once(pthread_once_t *onceControl, void (*initRoutine)(void)); | Performs one-time initialization routine.|
|  | #include <pthread.h> | int pthread_setcancelstate(int state, int *oldState); | Sets the cancel switch for the thread.|
|  | #include <pthread.h> | int pthread_setcanceltype(int type, int *oldType); | Sets the thread cancel type.|
|  | #include <pthread.h> | int pthread_cancel(pthread_t thread); | Cancels a thread. Currently, a thread can be cancelled only by setting the **PTHREAD_CANCEL_ASYNCHRONOUS** status and then calling **pthread_cancel**.|
|  | #include <pthread.h> | void pthread_testcancel(void); | Cancels this thread.|
|  | #include <pthread.h> | int pthread_equal(pthread_t thread1, pthread_t thread2); | Checks whether the two thread IDs are equal.|
|  | #include <pthread.h> | int pthread_mutexattr_gettype(const pthread_mutexattr_t *attr, int *outType); | Obtains the mutex type attribute.|
|  | #include <pthread.h> | int pthread_mutex_init(pthread_mutex_t *__restrict m, const pthread_mutexattr_t *__restrict a); | Initializes a mutex.|
|  | #include <pthread.h> | int pthread_mutex_lock(pthread_mutex_t *m); | Locks a mutex.|
|  | #include <pthread.h> | int pthread_mutex_timedlock(pthread_mutex_t *mutex, const struct timespec *absTimeout); | Requests a mutex (blocked only within the specified period).|
|  | #include <pthread.h> | int pthread_mutex_trylock(pthread_mutex_t *m); | Attempts to lock a mutex.|
|  | #include <pthread.h> | int pthread_mutex_destroy(pthread_mutex_t *m); | Destroys a mutex.|
|  | #include <pthread.h> | int pthread_attr_init(pthread_attr_t *attr); | Initializes a thread attribute object.|
|  | #include <pthread.h> | int pthread_attr_destroy(pthread_attr_t *attr); | Destroys a thread attribute object.|
|  | #include <pthread.h> | int pthread_attr_getstacksize(const pthread_attr_t *attr, size_t *stacksize); | Obtains the stack size of a thread attribute object.|
|  | #include <pthread.h> | int pthread_attr_setstacksize(pthread_attr_t *attr, size_t stacksize); | Sets the stack size for a thread attribute object.|
|  | #include <pthread.h> | int pthread_attr_setstack(pthread_attr_t *attr, void *stackAddr, size_t stackSize); | Sets the stack attribute for a thread attribute object (not implemented yet).|
|  | #include <pthread.h> | int pthread_attr_getstack(const pthread_attr_t *attr, void **stackAddr, size_t *stackSize); | Obtains the stack of a thread attribute object (not implemented yet).|
|  | #include <pthread.h> | int pthread_attr_getschedparam(const pthread_attr_t *attr, struct sched_param *param); | Obtains scheduling parameter attributes of a thread attribute object.|
|  | #include <pthread.h> | int pthread_attr_setschedparam(pthread_attr_t *attr, const struct sched_param *param); | Sets scheduling parameter attributes for a thread attribute object.|
|  | #include <pthread.h> | int pthread_getname_np(pthread_t pthread, char *name, size_t len); | Obtains the thread name.|
|  | #include <pthread.h> | int pthread_setname_np(pthread_t pthread, const char *name); | Sets the thread name.|
|  | #include <pthread.h> | int pthread_cond_broadcast(pthread_cond_t *c); | Unblocks all threads that are currently blocked on the condition variable **cond**.|
|  | #include <pthread.h> | int pthread_cond_signal(pthread_cond_t *c); | Unblocks a thread.|
|  | #include <pthread.h> | int pthread_cond_wait(pthread_cond_t *__restrict c, pthread_mutex_t *__restrict m); | Waits for the condition.|
| fs | #include <libgen.h> | char *dirname(char *path); | Obtains the directory name.|
|  | #include <dirent.h> | struct dirent *readdir(DIR *dirp); | Reads a directory.|
|  | #include <sys/stat.h> | int stat(const char *restrict path, struct stat *restrict buf); | Obtains file information.|
|  | #include <unistd.h> | int unlink(const char *pathname); | Deletes a file.|
|  | #include <fcntl.h | int open(const char *path, int oflags, ...); | Opens a file. If the file does not exist, create a file and open it.|
|  | #include <nistd.h> | int close(int fd); | Closes a file.|
|  | #include <stdio.h> | int rename(const char *oldpath, const char *newpath); | Renames a file.|
|  | #include <dirent.h> | DIR  *opendir(const char *dirname); | Opens the specified directory.|
|  | #include <dirent.h> | int closedir(DIR *dir); | Closes the specified directory.|
|  | #include <sys/mount.h> | int mount(const char *source, const char *target, const char *filesystemtype, unsigned long mountflags, const void *data); | Mounts a file system.|
|  | #include <sys/mount.h> | int umount(const char *target); | Unmounts a file system.|
|  | #include <sys/mount.h> | int umount2(const char *target, int flag); | Unmounts a file system.|
|  | #include <sys/stat.h> | int fsync(int fd); | Synchronizes the file associated with the specified file descriptor to the storage device.|
|  | #include <sys/stat.h> | int mkdir(const char *pathname, mode_t mode); | Creates a directory.|
|  | #include <unistd.h> | int rmdir(const char *path); | Deletes a directory.|
|  | #include <sys/stat.h> | int fstat(int fd, struct stat *buf); | Obtains file status.|
|  | #include <sys/statfs.h> | int statfs(const char *path, struct statfs *buf); | Obtains the file system information for a file in a specified path.|
| time | #include <sys/time.h> | int gettimeofday(struct timeval *tv, struct timezone *tz); | Obtains the time. Currently, time zone is not supported, and the return value of **tz** is empty.|
|  | #include <time.h> | struct tm *gmtime(const time_t *timep); | Converts the date and time to broken-down time or ASCII.|
|  | #include <time.h> | struct tm *localtime(const time_t *timep); | Obtains the local time.|
|  | #include <time.h> | struct tm *localtime_r(const time_t *timep, struct tm *result); | Obtains the local time.|
|  | #include <time.h> | time_t mktime(struct tm *tm); | Converts the date and time to broken-down time or ASCII.|
|  | #include <time.h> | size_t strftime(char *s, size_t max, const char *format,const struct tm *tm); | Formats the date and time.|
|  | #include <time.h> | time_t time(time_t *tloc); | Obtains the calendar time.|
|  | #include <sys/times.h> | clock_t times(struct tms *buf); | Obtains the thread time.|
|  | #include <sys/times.h> | int timer_getoverrun(timer_t timerID); | Obtains the number of timer timeout times.|
|  | #include <unistd.h> | int usleep(useconds_t usec); | Goes to hibernation, in microseconds.|
|  | #include <time.h> | int nanosleep(const struct timespec *tspec1, struct timespec *tspec2); | Suspends the current thread till the specified time.|
|  | #include <time.h> | int clock_gettime(clockid_t id, struct timespec *tspec); | Obtains the clock time.|
|  | #include <time.h> | int timer_create(clockid_t id, struct sigevent *__restrict evp, timer_t *__restrict t); | Creates a timer for a thread.|
|  | #include <time.h> | int timer_delete(timer_t t); | Deletes the timer for a thread.|
|  | #include <time.h> | int timer_settime(timer_t t, int flags, const struct itimerspec *__restrict val, struct itimerspec *__restrict old); | Sets a timer for a thread.|
|  | #include <time.h> | time_t time (time_t *t); | Obtains the time.|
|  | #include <time.h> | char *strptime(const char *s, const char *format, struct tm *tm); | Converts the time string into the time **tm** structure.|
| util | #include <stdlib.h> | int atoi(const char *nptr); | Converts the string pointed to by **nptr** into an integer (**int** type).|
|  | #include <stdlib.h> | long atol(const char *nptr); | Converts the string pointed to by **nptr** into a long Integer (**long** type).|
|  | #include <stdlib.h> | long long atoll(const char *nptr); | Converts the string pointed to by **nptr** into a long long Integer (**long long** type).|
|  | #include <ctype.h> | int isalnum(int c); | Checks whether the passed character is alphanumeric.|
|  | #include <ctype.h> | int isascii(int c); | Checks whether the passed character is an ASCII character.|
|  | #include <ctype.h> | int isdigit(int c); | Checks whether the passed character is a digit.|
|  | #include <ctype.h> | int islower(int c); | Checks whether the passed character is in lowercase.|
|  | #include <ctype.h> | int isprint(int c); | Checks whether the passed character is printable, including spaces.|
|  | #include <ctype.h> | int isspace(int c); | Checks whether the passed character is a white-space character.|
|  | #include <ctype.h> | int isupper(int c); | Checks whether the passed character is in uppercase.|
|  | #include <ctype.h> | int isxdigit(int c); | Checks whether the passed character is a hexadecimal number.|
|  | #include <stdlib.h> | long int random (void); | Generates a pseudo-random number.|
|  | #include <stdlib.h> | void srandom(unsigned int seed); | Initializes the random number generator.|
|  | #include <ctype.h> | int tolower(int c); | Converts the given letter to lowercase.|
|  | #include <ctype.h> | int toupper(int c); | Converts the given letter to uppercase.|
|  | #include <stdarg.h> | type va_arg(va_list ap, type); | Retrieves the next argument in the parameter list with **type**. |
|  | #include <stdarg.h> | void va_copy(va_list dest, va_list src); | Copies parameters.|
|  | #include <stdarg.h> | void va_end(va_list ap); | Clears the variable list.|
|  | #include <stdarg.h> | void va_start(va_list ap, last); | Defines the beginning of the list of variable arguments.|
|  | #include <string.h> | char *strchr(const char *s, int c); | Searches for the first occurrence of a character in a string.|
|  | #include <string.h> | int strcmp(const char *s1, const char *s2); | Compares two strings.|
|  | #include <string.h> | size_t strcspn(const char *s, const char *reject); | Obtains the length of the initial segment of the string **s** which does not contain any of bytes in the string **reject**.|
|  | #include <string.h> | char *strdup(const char *s); | Copies a string to a new position.|
|  | #include <string.h> | size_t strlen(const char *s); | Obtains the length of a string.|
|  | #include <strings.h> | int strncasecmp(const char *s1, const char *s2, size_t n); | Compares the bytes of the specified length in two strings, ignoring case.|
|  | #include <strings.h> | int strcasecmp(const char *s1, const char *s2); | Compares two strings, ignoring case.|
|  | #include <string.h> | int strncmp(const char *s1, const char *s2, size_t n); | Compares the bytes of the specified length in two strings.|
|  | #include <string.h> | char *strrchr(const char *s, int c); | Searches for the last occurrence of a character in a string.|
|  | #include <string.h> | char *strstr(const char *haystack, const char *needle); | Searches for the specified substring in a string.|
|  | #include <stdlib.h> | long int strtol(const char *nptr, char **endptr, int base); | Converts the string pointed to by **nptr** into a **long int** value according to the given **base**.|
|  | #include <stdlib.h> | unsigned long int strtoul(const char *nptr, char **endptr, int base); | Converts the string pointed to by **nptr** into an unsigned **long int** value according to the given **base**.|
|  | #include <stdlib.h> | unsigned long long int strtoull(const char *nptr, char **endptr,int base); | Converts the string pointed to by **nptr** into an unsigned **long long int** value according to the given **base**.|
|  | #include <regex.h> | int regcomp(regex_t *preg, const char *regex, int cflags); | Compiles a regular expression.|
|  | #include <regex.h> | int regexec(const regex_t *preg, const char *string, size_t nmatch,regmatch_t pmatch[], int eflags); | Executes the compiled regular expression.|
|  | #include <regex.h> | void regfree(regex_t *preg); | Releases the regular expression.|
|  | #include <string.h> | char *strerror(int errnum); | Obtains an error message string of the specified error code.|
| math | #include <stdlib.h> | int abs(int i); | Obtains the absolute value.|
|  | #include <math.h> | double log(double x); | Obtains the natural logarithm (base-e logarithm) of **x**.|
|  | #include <math.h> | double pow(double x, double y); | Obtains **x** raised to the power of **y**.|
|  | #include <math.h> | double round(double x); | Rounds off the value from zero to the nearest integer.|
|  | #include <math.h> | double sqrt(double x); | Obtains the square root of **x**.|
| IO | #include <stdio.h> | void clearerr(FILE *stream); | Clears the file end and error indication of a stream.|
|  | #include <stdio.h> | int fclose(FILE *stream); | Closes a file stream.|
|  | #include <stdio.h> | FILE *fdopen(int fd, const char *mode); | Opens a file stream based on the file descriptor.|
|  | #include <stdio.h> | int feof(FILE *stream); | Checks the end-of-file indicator for a stream.|
|  | #include <stdio.h> | int fflush(FILE *stream); | Flushes a stream.|
|  | #include <stdio.h> | char *fgets(char *s, int size, FILE *stream); | Reads the next line of a stream.|
|  | #include <stdio.h> | int fileno(FILE *stream); | Obtains the file descriptor for a stream.|
|  | #include <stdio.h> | FILE *fopen(const char *path, const char *mode); | Opens a stream.|
|  | #include <stdio.h> | int fputs(const char *s, FILE *stream); | Writes a line to the specified stream.|
|  | #include <stdio.h> | size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream); | Reads a stream.|
|  | #include <stdio.h> | int fseek(FILE *stream, long offset, int whence); | Sets the position of the stream pointer.|
|  | #include <stdio.h> | long ftell(FILE *stream); | Obtains the position of the stream pointer.|
|  | #include <stdio.h> | size_t fwrite(const void *ptr, size_t size, size_t nmemb,FILE *stream); | Writes data to a stream.|
|  | #include <stdio.h> | void perror(const char *s); | Prints system error information.|
|  | #include <stdio.h> | void rewind(FILE *stream); | Sets the position to the beginning of the file of the specified stream.|
|  | #include <unistd.h> | ssize_t write(int fd, const void *buf, size_t size); | Writes data a file.|
|  | #include <unistd.h> | ssize_t read(int fd, void *buf, size_t size); | Reads data from a file.|
| net | #include <sys/socket.h> | void freeaddrinfo(struct addrinfo *res); | Releases the dynamic memory allocated using **getaddrinfo**.|
|  | #include <sys/socket.h> | int getaddrinfo(const char *restrict nodename,const char *restrict servname,const struct addrinfo *restrict hints,struct addrinfo **restrict res); | Obtains a list of IP addresses and port numbers for the specified host and service.|
|  | #include <sys/socket.h> | int getnameinfo(const struct sockaddr *restrict sa, socklen_t salen,char *restrict node, socklen_t nodelen, char *restrict service,socklen_t servicelen, int flags); | Converts a **socketaddr** structure to a pair of host name and service strings.|
|  | #include <net/if.h> | unsigned int if_nametoindex(const char *ifname); | Obtains the index based on the network port name.|
|  | #include <arpa/inet.h> | in_addr_t inet_addr(const char *cp); | Converts the network host address in dotted decimal notation to binary format.|
|  | #include <arpa/inet.h> | char *inet_ntoa(struct in_addr in); | Converts the network host address in binary format to dotted decimal notation.|
|  | #include <arpa/inet.h> | const char *inet_ntop(int af, const void *src,char *dst, socklen_t size); | Converts the network address in binary format to text.|
|  | #include <arpa/inet.h> | int inet_pton(int af, const char *src, void *dst); | Converts the network address in standard text format to numeric binary format.|
|  | #include <sys/socket.h> | int listen(int sockfd, int backlog); | Listens for connections on a socket.|
|  | #include <sys/socket.h> | ssize_t recvmsg(int sockfd, struct msghdr *msg, int flags); | Receives a message from a socket. Currently, only the scenario with **iov** of **1** is supported and ancillary messages are not supported.|
|  | #include <sys/socket.h> | ssize_t send(int sockfd, const void *buf, size_t len, int flags); | Sends a message on a socket.|
|  | #include <sys/socket.h> | ssize_t sendmsg(int sockfd, const struct msghdr *msg, int flags); | Sends a message on a socket. Ancillary messages are not supported.|
|  | #include <sys/socket.h> | ssize_t sendto(int sockfd, const void *buf, size_t len, int flags,const struct sockaddr *dest_addr, socklen_t addrlen); | Sends a message on a socket.|
|  | #include <sys/socket.h> | int setsockopt(int sockfd, int level, int optname,const void *optval, socklen_t optlen); | Sets options associated with a socket.|
| mem | #include <string.h> | int memcmp(const void *s1, const void *s2, size_t n); | Compares successive elements from two arrays until it finds elements that are different.|
|  | #include <string.h> | void *memcpy(void *dest, const void *src, size_t n); | Copies *n* bytes from the source memory area pointed to by **src** to the destination memory area pointed to by **dest**.|
|  | #include <string.h> | void *memset(void *s, int c, size_t n); | Initializes memory.|
|  | #include <stdlib.h> | void *realloc(void *ptr, size_t size); | Reallocates memory.|
|  | #include <stdlib.h> | void *malloc(size_t size); | Dynamically allocates memory blocks.|
|  | #include <stdlib.h> | void free(void *ptr); | Release the memory space pointed to by **ptr**.|
| IPC | #include <semaphore.h> | int sem_timedwait(sem_t *sem, const struct timespec *abs_timeout); | Locks the semaphore referenced by **sem** as in the **sem_wait()** function.|
|  | #include <semaphore.h> | int sem_destroy(sem_t *sem); | Destroys the specified unnamed semaphore.|
|  | #include <semaphore.h> | int sem_trywait(sem_t *sem); | Attempts to apply for a semaphore.|
|  | #include <semaphore.h> | int sem_init(sem_t *sem, int pshared, unsigned int value); | Creates and initializes an unnamed semaphore.|
|  | #include <semaphore.h> | int sem_post(sem_t *sem); | Increments the semaphore count by 1.|
|  | #include <semaphore.h> | int sem_wait(sem_t *sem); | Obtains the semaphore.|
|  | #include <mqueue.h> | mqd_t mq_open(const char *mqName, int openFlag, ...); | Opens an existing message queue with the specified name or creates a message queue.|
|  | #include <mqueue.h> | int mq_close(mqd_t personal); | Closes a message queue with the specified descriptor.|
|  | #include <mqueue.h> | int mq_unlink(const char *mqName); | Deletes the message queue of the specified name.|
|  | #include <mqueue.h> | int mq_send(mqd_t personal, const char *msg, size_t msgLen, unsigned int msgPrio); | Puts a message with the specified content and length into a message queue.|
|  | #include <mqueue.h> | ssize_t mq_receive(mqd_t personal, char *msg, size_t msgLen, unsigned int *msgPrio); | Deletes the oldest message from a message queue and puts it in the buffer pointed to by **msg_ptr**.|
|  | #include <mqueue.h> | int mq_timedsend(mqd_t personal, const char *msg, size_t msgLen, unsigned int msgPrio, const struct timespec *absTimeout) | Puts a message with the specified content and length into a message queue at the specified time.|
|  | #include <mqueue.h> | ssize_t mq_timedreceive(mqd_t personal, char *msg, size_t msgLen, unsigned int *msgPrio, const struct timespec *absTimeout); | Obtains a message with the specified content and length from a message queue.|
|  | #include <mqueue.h> | int mq_setattr(mqd_t mqdes, const struct mq_attr *__restrict newattr, struct mq_attr *__restrict oldattr); | Sets the message queue attributes specified by the descriptor.|
| version | #include <libc.h> | const char *libc_get_version_string(void); | Obtains the libc version string.|
|  | #include <libc.h> | int libc_get_version(void); | Obtains the libc version.|


### Important Notes

Error codes

| C Name | Value | Description |
| -------- | -------- | -------- |
| ENOERR | 0 | Success |
| EPERM | 1 | Operation not permitted |
| ENOENT | 2 | No such file or directory |
| ESRCH | 3 | No such process |
| EINTR | 4 | Interrupted system call |
| EIO | 5 | I/O error |
| ENXIO | 6 | No such device or address |
| E2BIG | 7 | Arg list too long |
| ENOEXEC | 8 | Exec format error |
| EBADF | 9 | Bad file number |
| ECHILD | 10 | No child processes |
| EAGAIN | 11 | Try again |
| ENOMEM | 12 | Out of memory |
| EACCES | 13 | Permission denied |
| EFAULT | 14 | Bad address |
| ENOTBLK | 15 | Block device required |
| EBUSY | 16 | Device or resource busy |
| EEXIST | 17 | File exists |
| EXDEV | 18 | Cross-device link |
| ENODEV | 19 | No such device |
| ENOTDIR | 20 | Not a directory |
| EISDIR | 21 | Is a directory |
| EINVAL | 22 | Invalid argument |
| ENFILE* | 23 | File table overflow |
| EMFILE | 24 | Too many open files |
| EFBIG | 27 | File too large |
| ENOSPC | 28 | No space left on device |
| ESPIPE | 29 | Illegal seek |
| EROFS | 30 | Read-only file system |
| EMLINK | 31 | Too many links |
| EDOM | 33 | Math argument out of domain |
| ERANGE | 34 | Math result not representable |
| EDEADLK | 35 | Resource deadlock would occur |
| ENAMETOOLONG | 36 | Filename too long |
| ENOLCK | 37 | No record locks available |
| ENOSYS | 38 | Function not implemented |
| ENOTEMPTY | 39 | Directory not empty |
| ELOOP | 40 | Too many symbolic links encountered |
| ENOMSG | 42 | No message of desired type |
| EIDRM | 43 | Identifier removed |
| ELNRNG | 48 | Link number out of range |
| EBADR | 53 | Invalid request descriptor |
| EBADRQC | 56 | Invalid request code |
| ENOSTR | 60 | Device not a stream |
| ENODATA | 61 | No data available |
| ETIME | 62 | Timer expired |
| EPROTO | 71 | Protocol error |
| EBADMSG | 74 | Not a data message |
| EOVERFLOW | 75 | Value too large for defined data type |
| EMSGSIZE | 90 | Message too long |

### Development Example

Demo:

Creates a thread, transfers the information in the parent thread to the child thread, and prints the transferred information and the thread ID in the child thread.

```
#include <stdio.h>
#include <pthread.h>

pthread_t ntid;

void *ThreadFn(void *arg)
{
    pthread_t tid;
    while(1) {
        tid = pthread_self();
        printf("\n++++++++++++++  %s  %s  tid = %d ++++++++++++++\n", (char*)arg, __FUNCTION__, tid);
    }
    return ((void *)0);
}

void DemoForTest()
{
    int err;
    char* str = "Hello world";
    err = pthread_create(&ntid, NULL, ThreadFn, (void*)str);
    if(err != 0) {
        printf("can't create thread\n");
    }
}

```

The execution result of  **DemoForTest**  is as follows:

```
++++++++++++++  Hello world  ThreadFn  tid = 48 ++++++++++++++

++++++++++++++  Hello world  ThreadFn  tid = 48 ++++++++++++++

++++++++++++++  Hello world  ThreadFn  tid = 48 ++++++++++++++
```
