# Standard Libraries


## CMSIS


### Basic Concepts

The [Cortex Microcontroller Software Interface Standard (CMSIS)](https://developer.arm.com/tools-and-software/embedded/cmsis) is a vendor-independent hardware abstraction layer for microcontrollers based on Arm Cortex processors. Of the CMSIS components, the Real Time Operating System (RTOS) defines a set of universal and standardized APIs to reduce the dependency of application developers on specific RTOS and facilitate software porting and reuse. The CMSIS provides CMSIS-RTOS v1 and CMSIS-RTOS v2. The OpenHarmony LiteOS-M supports only the implementation of CMSIS-RTOS v2.


### Development Guidelines


#### Available APIs

The following tables describe CMSIS-RTOS v2 APIs. For more details about the APIs, see the API reference.

  **Table 1** APIs for obtaining kernel information and controlling the kernel

| API| Description|
| -------- | -------- |
| osKernelGetInfo | Obtains RTOS kernel information.|
| osKernelGetState | Obtains the current RTOS kernel status.|
| osKernelGetSysTimerCount | Obtains the RTOS kernel system timer count.|
| osKernelGetSysTimerFreq | Obtains the RTOS kernel system timer frequency.|
| osKernelInitialize | Initializes the RTOS kernel.|
| osKernelLock | Locks the RTOS kernel scheduler.|
| osKernelUnlock | Unlocks the RTOS kernel scheduler.|
| osKernelRestoreLock | Restores the RTOS kernel scheduler to the locked state.|
| osKernelResume | Restores the RTOS kernel scheduler (not implemented yet).|
| osKernelStart | Starts the RTOS kernel scheduler.|
| osKernelSuspend | Suspends the RTOS kernel scheduler (not implemented yet).|
| osKernelGetTickCount | Obtains the RTOS kernel tick count.|
| osKernelGetTickFreq | Obtains the RTOS kernel tick frequency.|

  **Table 2** APIs for thread management

| API| Description|
| -------- | -------- |
| osThreadDetach | Detaches a thread to reclaim the thread storage when the thread terminates (not implemented yet).|
| osThreadEnumerate | Enumerates active threads (not implemented yet).|
| osThreadExit | Terminates a running thread.|
| osThreadGetCount | Obtains the number of active threads.|
| osThreadGetId | Obtains the ID of the running thread.|
| osThreadGetName | Obtains the thread name.|
| osThreadGetPriority | Obtains the current thread priority.|
| osThreadGetStackSize | Obtains the thread stack size.|
| osThreadGetStackSpace | Obtains the available stack space for a thread based on the stack waterline record during execution.|
| osThreadGetState | Obtains the current thread status.|
| osThreadJoin | Waits for the specified thread to terminate (not implemented yet).|
| osThreadNew | Creates a thread and adds it to active threads.|
| osThreadResume | Resumes the execution of a thread.|
| osThreadSetPriority | Changes the priority of a thread.|
| osThreadSuspend | Suspends a thread.|
| osThreadTerminate | Terminates a thread.|
| osThreadYield | Passes control to the next thread in the ready state.|

  **Table 3** APIs for thread flags

| API| Description|
| -------- | -------- |
| osThreadFlagsSet | Sets flags for a thread (not implemented yet).|
| osThreadFlagsClear | Clears the specified flags for the running thread (not implemented yet).|
| osThreadFlagsGet | Obtains the current flags of the running thread (not implemented yet).|
| osThreadFlagsWait | Waits for one or more thread flags of the running thread to signal (not implemented yet).|

  **Table 4** APIs for event flags

| API| Description|
| -------- | -------- |
| osEventFlagsGetName | Obtains the event flag names (not implemented yet).|
| osEventFlagsNew | Creates and initializes event flags.|
| osEventFlagsDelete | Deletes event flags.|
| osEventFlagsSet | Sets event flags.|
| osEventFlagsClear | Clears event flags.|
| osEventFlagsGet | Obtains the current event flags.|
| osEventFlagsWait | Waits for one or more event flags to be signaled.|

  **Table 5** General wait functions

| API| Description|
| -------- | -------- |
| osDelay | Waits for timeout (time delay).|
| osDelayUntil | Waits until the specified time.|

  **Table 6** APIs for timer management

| API| Description|
| -------- | -------- |
| osTimerDelete | Deletes a timer.|
| osTimerGetName | Obtains the timer name (not implemented yet).|
| osTimerIsRunning | Checks whether a timer is running.|
| osTimerNew | Creates and initializes a timer.|
| osTimerStart | Starts or restarts a timer.|
| osTimerStop | Stops a timer.|

  **Table 7** APIs for mutex management

| API| Description|
| -------- | -------- |
| osMutexAcquire | Acquires a mutex or times out (if locked).|
| osMutexDelete | Deletes a mutex.|
| osMutexGetName | Obtains the mutex name (not implemented yet).|
| osMutexGetOwner | Obtains the thread that acquires the mutex.|
| osMutexNew | Creates and initializes a mutex.|
| osMutexRelease | Releases the mutex obtained using **osMutexAcquire**.|

  **Table 8** APIs for semaphore management

| API| Description|
| -------- | -------- |
| osSemaphoreAcquire | Obtains the semaphore token or times out if no token is available.|
| osSemaphoreDelete | Deletes a semaphore.|
| osSemaphoreGetCount | Obtains the token count of the current semaphore.|
| osSemaphoreGetName | Obtains the name of a semaphore (not implemented yet).|
| osSemaphoreNew | Creates and initializes a semaphore.|
| osSemaphoreRelease | Releases semaphore tokens till the initial maximum count.|

  **Table 9** APIs for memory pool management 

| API| Description|
| -------- | -------- |
| osMemoryPoolAlloc | Allocates a memory block from the memory pool.|
| osMemoryPoolDelete | Deletes a memory pool object.|
| osMemoryPoolFree | Releases the allocated memory block to the memory pool.|
| osMemoryPoolGetBlockSize | Obtains the memory block size in the memory pool.|
| osMemoryPoolGetCapacity | Obtains the maximum number of memory blocks in the memory pool.|
| osMemoryPoolGetCount | Obtains the number of used memory blocks in the memory pool.|
| osMemoryPoolGetName | Obtains the memory pool name.|
| osMemoryPoolGetSpace | Obtains the number of available memory blocks in the memory pool.|
| osMemoryPoolNew | Creates and initializes a memory pool.|

  **Table 10** APIs for message queues

| API| Description|
| -------- | -------- |
| osMessageQueueDelete | Deletes a message queue.|
| osMessageQueueGet | Obtain a message from the queue or times out if the queue is empty.|
| osMessageQueueGetCapacity | Obtains the maximum number of messages in the message queue.|
| osMessageQueueGetCount | Obtains the number of queued messages in the message queue.|
| osMessageQueueGetMsgSize | Obtains the maximum message size in the memory pool.|
| osMessageQueueGetName | Obtains the message queue name (not implemented yet).|
| osMessageQueueGetSpace | Obtains the number of slots available for messages in the message queue.|
| osMessageQueueNew | Creates and initializes a message queue.|
| osMessageQueuePut | Puts the message into the queue or times out if the queue is full.|
| osMessageQueueReset | Resets the message queue to the initial empty state (not implemented yet).|


#### How to Develop

The CMSIS-RTOS v2 component can be provided as a library (shown in the figure) or source code. By adding the CMSIS-RTOS v2 component (typically configuration files), you can implement RTOS capabilities on CMSIS-based applications. You only need to include the **cmsis_os2.h** header file. RTOS APIs can then be called to process RTOS kernel-related events. You do not need to recompile the source code when the kernel is replaced.

The RTOS object control block definition needs to be called for static object allocation. The implementation header file (**os_xx.h** in the following figure) provides access to such control block definitions. In the OpenHarmony LiteOS-M kernel, the header files whose names start with **los_** provide the definitions of the kernel.

![](figures/how-to-develop.png)


#### Development Example


```
#include ...
#include "cmsis_os2.h"

/*----------------------------------------------------------------------------
 * Application main thread
 *---------------------------------------------------------------------------*/
void app_main (void *argument) {
  // ...
  for (;;) {}
}

int main (void) {
  // System initialization
  MySystemInit();
  // ...

  osKernelInitialize();                // Initialize CMSIS-RTOS.
  osThreadNew(app_main, NULL, NULL);   // Create the main thread of the application.
  osKernelStart();                     // Start to execute the thread.
  for (;;) {}
}
```

## POSIX


### Basic Concepts

The OpenHarmony kernel uses the **musl libc** library and self-developed APIs and supports the Portable Operating System Interface (POSIX). You can develop components and applications working on the kernel based on the POSIX.


### Development Guidelines


#### Available APIs

  **Table 11** APIs for process management

| Header File| API| Description|
| -------- | -------- | -------- |
| \#include &lt;stdlib.h&gt; | void abort(void); | Terminates the thread.|
| \#include &lt;assert.h&gt; | void assert(scalar expression); | Terminates the thread if the assertion is false.|
| \#include &lt;pthread.h&gt; | int pthread_cond_destroy(pthread_cond_t \*cond); | Destroys a condition variable.|
| \#include &lt;pthread.h&gt; | int pthread_cond_init(pthread_cond_t \*restrict cond, const pthread_condattr_t \*restrict attr); | Initializes a condition variable.|
| \#include &lt;pthread.h&gt; | int pthread_cond_timedwait(pthread_cond_t \*restrict cond, pthread_mutex_t \*restrict mutex, const struct timespec \*restrict abstime); | Waits for the condition.|
| \#include &lt;pthread.h&gt; | int pthread_condattr_init(pthread_condattr_t \*attr); | Initializes the condition variable attribute.|
| \#include &lt;pthread.h&gt; | int pthread_mutex_unlock(pthread_mutex_t \*mutex); | Unlocks a mutex.|
| \#include &lt;pthread.h&gt; | int pthread_create(pthread_t \*thread, const pthread_attr_t \*attr, void \*(\*start_routine)(void \*), void \*arg); | Creates a thread.|
| \#include &lt;pthread.h&gt; | int pthread_join(pthread_t thread, void \*\*retval); | Waits for a thread to terminate.|
| \#include &lt;pthread.h&gt; | pthread_t pthread_self(void); | Obtains the ID of the current thread.|
| \#include &lt;pthread.h&gt; | int pthread_getschedparam(pthread_t thread, int \*policy, struct sched_param \*param); | Obtains the scheduling policy and parameters of a thread.|
| \#include &lt;pthread.h&gt; | int pthread_setschedparam(pthread_t thread, intpolicy, const struct sched_param \*param); | Sets a scheduling policy and parameters for a thread.|
| \#include &lt;pthread.h&gt; | int pthread_mutex_init(pthread_mutex_t *\_restrict m, const pthread_mutexattr_t \*__restrict a); | Initializes a mutex.|
| \#include &lt;pthread.h&gt; | int pthread_mutex_lock(pthread_mutex_t \*m); | Locks a mutex.|
| \#include &lt;pthread.h&gt; | int pthread_mutex_trylock(pthread_mutex_t \*m); | Attempts to lock a mutex.|
| \#include &lt;pthread.h&gt; | int pthread_mutex_destroy(pthread_mutex_t \*m); | Destroys a mutex.|
| \#include &lt;pthread.h&gt; | int pthread_attr_init(pthread_attr_t \*attr); | Initializes a thread attribute object.|
| \#include &lt;pthread.h&gt; | int pthread_attr_destroy(pthread_attr_t \*attr); | Destroys a thread attribute object.|
| \#include &lt;pthread.h&gt; | int pthread_attr_getstacksize(const pthread_attr*t \*attr, size*t \*stacksize); | Obtains the stack size of a thread attribute object.|
| \#include &lt;pthread.h&gt; | int pthread_attr_setstacksize(pthread_attr_t \*attr, size_t stacksize); | Sets the stack size for a thread attribute object.|
| \#include &lt;pthread.h&gt; | int pthread_attr_getschedparam(const pthread_attr_t \*attr, struct sched_param \*param); | Obtains scheduling parameter attributes of a thread attribute object.|
| \#include &lt;pthread.h&gt; | int pthread_attr_setschedparam(pthread_attr_t \*attr, const struct sched_param \*param); | Sets scheduling parameter attributes for a thread attribute object.|
| \#include &lt;pthread.h&gt; | int pthread_getname_np(pthread_t pthread, char\*name, size_t len); | Obtains the thread name.|
| \#include &lt;pthread.h&gt; | int pthread_setname_np(pthread_t pthread, constchar \*name); | Sets the thread name.|
| \#include &lt;pthread.h&gt; | int pthread_cond_broadcast(pthread_cond_t \*c); | Unblocks all threads that are currently blocked on the condition variable **cond**.|
| \#include &lt;pthread.h&gt; | int pthread_cond_signal(pthread_cond_t \*c); | Unblocks a thread.|
| \#include &lt;pthread.h&gt; | int pthread_cond_wait(pthread_cond_t *\__restrictc, pthread_mutex_t \*__restrict m); | Waits for the condition.|

  **Table 12** APIs for file system management

| Header File| API| Description|
| -------- | -------- | -------- |
| \#include &lt;libgen.h&gt; | char \*dirname(char \*path); | Obtains the directory name.|
| \#include &lt;dirent.h&gt; | struct dirent \*readdir(DIR \*dirp); | Reads a directory.|
| \#include &lt;sys/stat.h&gt; | int stat(const char \*restrict path, struct stat \*restrict buf); | Obtains file information.|
| \#include &lt;unistd.h&gt; | int unlink(const char \*pathname); | Deletes a file.|
| \#include &lt;fcntl.h | int open(const char \*path, int oflags, ...); | Opens a file. If the file does not exist, create a file and open it.|
| \#include &lt;nistd.h&gt; | int close(int fd); | Closes a file.|
| \#include &lt;stdio.h&gt; | int rename(const char \*oldpath, const char \*newpath); | Renames a file.|
| \#include &lt;dirent.h&gt; | DIR  \*opendir(const char \*dirname); | Opens the specified directory.|
| \#include &lt;dirent.h&gt; | int closedir(DIR \*dir); | Closes the specified directory.|
| \#include &lt;sys/mount.h&gt; | int mount(const char \*source, const char \*target, const char \*filesystemtype, unsigned long mountflags, const void \*data); | Mounts a file system.|
| \#include &lt;sys/mount.h&gt; | int umount(const char \*target); | Unmounts a file system.|
| \#include &lt;sys/mount.h&gt; | int umount2(const char \*target, int flag); | Unmounts a file system.|
| \#include &lt;sys/stat.h&gt; | int fsync(int fd); | Synchronizes the file associated with the specified file descriptor to the storage device.|
| \#include &lt;sys/stat.h&gt; | int mkdir(const char \*pathname, mode_t mode); | Creates a directory.|
| \#include &lt;unistd.h&gt; | int rmdir(const char \*path); | Deletes a directory.|
| \#include &lt;sys/stat.h&gt; | int fstat(int fd, struct stat \*buf); | Obtains file status.|
| \#include &lt;sys/statfs.h&gt; | int statfs(const char \*path, struct statfs \*buf); | Obtains the file system information for a file in a specified path.|

  **Table 13** APIs for time management

| Header File| API| Description|
| -------- | -------- | -------- |
| \#include &lt;sys/time.h&gt; | int gettimeofday(struct timeval \*tv, struct timezone \*tz); | Obtains the time. Currently, time zone is not supported, and the return value of **tz** is empty.|
| \#include &lt;time.h&gt; | struct tm \*gmtime(const time_t \*timep); | Converts the date and time to broken-down time or ASCII.|
| \#include &lt;time.h&gt; | struct tm \*localtime(const time_t \*timep); | Obtains the local time.|
| \#include &lt;time.h&gt; | struct tm \*localtime_r(const time_t \*timep, struct tm \*result); | Obtains the local time.|
| \#include &lt;time.h&gt; | time_t mktime(struct tm \*tm); | Converts the date and time to broken-down time or ASCII.|
| \#include &lt;time.h&gt; | size_t strftime(char \*s, size_t max, const char \*format,const struct tm \*tm); | Formats the date and time.|
| \#include &lt;time.h&gt; | time_t time(time_t \*tloc); | Obtains the calendar time.|
| \#include &lt;sys/times.h&gt; | clock_t times(struct tms \*buf); | Obtains the thread time.|
| \#include &lt;unistd.h&gt; | int usleep(useconds_t usec); | Goes to hibernation, in microseconds.|
| \#include &lt;time.h&gt; | int nanosleep(const struct timespec \*tspec1, structtimespec \*tspec2); | Suspends the current thread till the specified time.|
| \#include &lt;time.h&gt; | int clock_gettime(clockid_t id, struct timespec \*tspec); | Obtains the clock time.|
| \#include &lt;time.h&gt; | int timer_create(clockid_t id, struct sigevent *\__restrict evp, timer_t \*__restrict t); | Creates a timer for a thread.|
| \#include &lt;time.h&gt; | int timer_delete(timer_t t); | Deletes the timer for a thread.|
| \#include &lt;time.h&gt; | int timer_settime(timer_t t, int flags, const struct itimerspec *\__restrict val, struct itimerspec \*_restrict old); | Sets a timer for a thread.|
| \#include &lt;time.h&gt; | time_t time (time_t \*t); | Obtains the time.|
| \#include &lt;time.h&gt; | char \*strptime(const char \*s, const char \*format, struct tm \*tm); | Converts the time string into the time **tm** structure.|

  **Table 14** APIs for util

| Header File| API| Description|
| -------- | -------- | -------- |
| \#include &lt;stdlib.h&gt; | int atoi(const char \*nptr); | Converts a string into an integer (**int** type).|
| \#include &lt;stdlib.h&gt; | long atol(const char \*nptr); | Converts the string into a long Integer (**long** type).|
| \#include &lt;stdlib.h&gt; | long long atoll(const char \*nptr); | Converts a string into a long longer integer (**long long** type).|
| \#include &lt;ctype.h&gt; | int isalnum(int c); | Checks whether the passed character is alphanumeric.|
| \#include &lt;ctype.h&gt; | int isascii(int c); | Checks whether the passed character is an ASCII character.|
| \#include &lt;ctype.h&gt; | int isdigit(int c); | Checks whether the passed character is a digit.|
| \#include &lt;ctype.h&gt; | int islower(int c); | Checks whether the passed character is in lowercase.|
| \#include &lt;ctype.h&gt; | int isprint(int c); | Checks whether the passed character is printable, including spaces.|
| \#include &lt;ctype.h&gt; | int isspace(int c); | Checks whether the passed character is a white-space character.|
| \#include &lt;ctype.h&gt; | int isupper(int c); | Checks whether the passed character is in uppercase.|
| \#include &lt;ctype.h&gt; | int isxdigit(int c); | Checks whether the passed character is a hexadecimal number.|
| \#include &lt;stdlib.h&gt; | long int random (void); | Generates a pseudo-random number.|
| \#include &lt;stdlib.h&gt; | void srandom(unsigned int seed); | Initializes the random number generator.|
| \#include &lt;ctype.h&gt; | int tolower(int c); | Converts the given letter to lowercase.|
| \#include &lt;ctype.h&gt; | int toupper(int c); | Converts the given letter to uppercase.|
| \#include &lt;stdarg.h&gt; | type va_arg(va_list ap, type); | Retrieves the next argument in the parameter list with **type**. |
| \#include &lt;stdarg.h&gt; | void va_copy(va_list dest, va_list src); | Copies parameters.|
| \#include &lt;stdarg.h&gt; | void va_end(va_list ap); | Clears the variable list.|
| \#include &lt;stdarg.h&gt; | void va_start(va_list ap, last); | Defines the beginning of the list of variable arguments.|
| \#include &lt;string.h&gt; | char \*strchr(const char \*s, int c); | Searches for a character in a string.|
| \#include &lt;string.h&gt; | int strcmp(const char \*s1, const char \*s2); | Compares two strings.|
| \#include &lt;string.h&gt; | size_t strcspn(const char \*s, const char \*reject); | Obtains the length of the initial segment of the string **s** which does not contain any of bytes in the string **reject**.|
| \#include &lt;string.h&gt; | char \*strdup(const char \*s); | Copies a string to a new position.|
| \#include &lt;string.h&gt; | size_t strlen(const char \*s); | Obtains the length of a string.|
| \#include &lt;strings.h&gt; | int strncasecmp(const char \*s1, const char \*s2, size_t n); | Compares the bytes of the specified length in two strings, ignoring case.|
| \#include &lt;strings.h&gt; | int strcasecmp(const char \*s1, const char \*s2); | Compares two strings, ignoring case.|
| \#include &lt;string.h&gt; | int strncmp(const char \*s1, const char \*s2, size_t n); | Compares the bytes of the specified length in two strings.|
| \#include &lt;string.h&gt; | char \*strrchr(const char \*s, int c); | Searches for a character in a string.|
| \#include &lt;string.h&gt; | char \*strstr(const char \*haystack, const char \*needle); | Searches for the specified substring in a string.|
| \#include &lt;stdlib.h&gt; | long int strtol(const char \*nptr, char \*\*endptr, int base); | Converts the string pointed to by **nptr** into a **long int** value according to the given **base**.|
| \#include &lt;stdlib.h&gt; | unsigned long int strtoul(const char \*nptr, char\*\*endptr, int base); | Converts a string into an unsigned long integer.|
| \#include &lt;stdlib.h&gt; | unsigned long long int strtoull(const char \*nptr,char \*\*endptr,int base); | Converts a string into an unsigned long long integer.|
| \#include &lt;regex.h&gt; | int regcomp(regex_t \*preg, const char \*regex,int cflags); | Compiles a regular expression.|
| \#include &lt;regex.h&gt; | int regexec(const regex_t \*preg, const char \*string, size_t nmatch, regmatch_t pmatch[], int eflags); | Executes the compiled regular expression.|
| \#include &lt;regex.h&gt; | void regfree(regex_t \*preg); | Releases the regular expression.|
| \#include &lt;string.h&gt; | char \*strerror(int errnum); | Obtains an error message string of the specified error code.|

  **Table 15** APIs for math operations

| Header File| API| Description|
| -------- | -------- | -------- |
| \#include &lt;stdlib.h&gt; | int abs(int i); | Obtains the absolute value.|
| \#include &lt;math.h&gt; | double log(double x); | Obtains the natural logarithm (base-e logarithm) of **x**.|
| \#include &lt;math.h&gt; | double pow(double x, double y); | Obtains **x** raised to the power of **y**.|
| \#include &lt;math.h&gt; | double round(double x); | Rounds off the value from zero to the nearest integer.|
| \#include &lt;math.h&gt; | double sqrt(double x); | Obtains the square root of **x**.|

  **Table 16** APIs for I/O operations

| Header File| API| Description|
| -------- | -------- | -------- |
| \#include &lt;stdio.h&gt; | void clearerr(FILE \*stream); | Clears the file end and error indication of a stream.|
| \#include &lt;stdio.h&gt; | int fclose(FILE \*stream); | Closes a file stream.|
| \#include &lt;stdio.h&gt; | FILE \*fdopen(int fd, const char \*mode); | Opens a file stream based on the file descriptor.|
| \#include &lt;stdio.h&gt; | int feof(FILE \*stream); | Checks the end-of-file indicator for a stream.|
| \#include &lt;stdio.h&gt; | int fflush(FILE \*stream); | Flushes a stream.|
| \#include &lt;stdio.h&gt; | char \*fgets(char \*s, int size, FILE \*stream); | Reads the next line of a stream.|
| \#include &lt;stdio.h&gt; | int fileno(FILE \*stream); | Obtains the file descriptor for a stream.|
| \#include &lt;stdio.h&gt; | FILE \*fopen(const char \*path, const char \*mode); | Opens a stream.|
| \#include &lt;stdio.h&gt; | int fputs(const char \*s, FILE \*stream); | Writes a line to the specified stream.|
| \#include &lt;stdio.h&gt; | size_t fread(void \*ptr, size_t size, size_t nmemb, FILE \*stream); | Reads a stream.|
| \#include &lt;stdio.h&gt; | int fseek(FILE \*stream, long offset, int whence); | Sets the position of the stream pointer.|
| \#include &lt;stdio.h&gt; | long ftell(FILE \*stream); | Obtains the position of the stream pointer.|
| \#include &lt;stdio.h&gt; | size_t fwrite(const void \*ptr, size_t size, size_tnmemb, FILE \*stream); | Writes data to a stream.|
| \#include &lt;stdio.h&gt; | void perror(const char \*s); | Prints system error information.|
| \#include &lt;stdio.h&gt; | void rewind(FILE \*stream); | Sets the position to the beginning of the file of the specified stream.|
| \#include &lt;unistd.h&gt; | ssize_t write(int fd, const void \*buf, size_t size); | Writes data a file.|
| \#include &lt;unistd.h&gt; | ssize_t read(int fd, void \*buf, size_t size); | Reads data from a file.|

  **Table 17** APIs for network

| Header File| API| Description|
| -------- | -------- | -------- |
| \#include &lt;sys/socket.h&gt; | void freeaddrinfo(struct addrinfo \*res); | Releases the dynamic memory allocated using **getaddrinfo**.|
| \#include &lt;sys/socket.h&gt; | int getaddrinfo(const char \*restrict nodename, constchar \*restrict servname, const struct addrinfo \*restricthints, struct addrinfo \*\*restrict res); | Obtains a list of IP addresses and port numbers for the specified host and service.|
| \#include &lt;sys/socket.h&gt; | int getnameinfo(const struct sockaddr \*restrict sa, socklen_t salen, char \*restrict node, socklen_t nodelen, char \*restrict service, socklen_t servicelen, int flags); | Converts a **socketaddr** structure to a pair of host name and service strings.|
| \#include &lt;net/if.h&gt; | unsigned int if_nametoindex(const char \*ifname); | Obtains the index based on the network port name.|
| \#include &lt;arpa/inet.h&gt; | in_addr_t inet_addr(const char \*cp); | Converts the network host address in dotted decimal notation to binary format.|
| \#include &lt;arpa/inet.h&gt; | char \*inet_ntoa(struct in_addr in); | Converts the network host address in binary format to dotted decimal notation.|
| \#include &lt;arpa/inet.h&gt; | const char \*inet_ntop(int af, const void \*src, char \*dst, socklen_t size); | Converts the network address in standard text format to numeric binary format.|
| \#include &lt;arpa/inet.h&gt; | int inet_pton(int af, const char \*src, void \*dst); | Converts the network address in standard text format to numeric binary format.|
| \#include &lt;sys/socket.h&gt; | int listen(int sockfd, int backlog); | Listens for connections on a socket.|
| \#include &lt;sys/socket.h&gt; | ssize_t recvmsg(int sockfd, struct msghdr \*msg, int flags); | Receives a message from a socket. Currently, only the scenario with **iov** of **1** is supported and ancillary messages are not supported.|
| \#include &lt;sys/socket.h&gt; | ssize_t send(int sockfd, const void \*buf, size_t len, int flags); | Sends a message on a socket.|
| \#include &lt;sys/socket.h&gt; | ssize_t sendmsg(int sockfd, const struct msghdr \*msg, int flags); | Sends a message on a socket. Ancillary messages are not supported.|
| \#include &lt;sys/socket.h&gt; | ssize_t sendto(int sockfd, const void \*buf, size_t len, intflags,const struct sockaddr \*dest_addr, socklen_t addrlen); | Sends a message on a socket.|
| \#include &lt;sys/socket.h&gt; | int setsockopt(int sockfd, int level, int optname,constvoid \*optval, socklen_t optlen); | Sets options associated with a socket.|

  **Table 18** APIs for memory management

| Header File| API| Description|
| -------- | -------- | -------- |
| \#include &lt;string.h&gt; | int memcmp(const void \*s1, const void \*s2, size_t n); | Compares successive elements from two arrays until it finds elements that are different.|
| \#include &lt;string.h&gt; | void \*memcpy(void \*dest, const void \*src, size_t n); | Copies *n* bytes from the source memory area pointed to by **src** to the destination memory area pointed to by **dest**.|
| \#include &lt;string.h&gt; | void \*memset(void \*s, int c, size_t n); | Initializes memory.|
| \#include &lt;stdlib.h&gt; | void \*realloc(void \*ptr, size_t size); | Reallocates memory.|
| \#include &lt;stdlib.h&gt; | void \*malloc(size_t size); | Dynamically allocates memory blocks.|
| \#include &lt;stdlib.h&gt; | void free(void \*ptr); | Release the memory space pointed to by **ptr**.|

  **Table 19** APIs for IPC

| Header File| API| Description|
| -------- | -------- | -------- |
| \#include &lt;semaphore.h&gt; | int sem_timedwait(sem_t \*sem, const struct timespec \*abs_timeout); | Locks the semaphore referenced by **sem** as in the **sem_wait()** function.|
| \#include &lt;semaphore.h&gt; | int sem_destroy(sem_t \*sem); | Destroys the specified unnamed semaphore.|
| \#include &lt;semaphore.h&gt; | int sem_init(sem_t \*sem, int pshared, unsigned int value); | Creates and initializes an unnamed semaphore.|
| \#include &lt;semaphore.h&gt; | int sem_post(sem_t \*sem); | Increments the semaphore count by 1.|
| \#include &lt;semaphore.h&gt; | int sem_wait(sem_t \*sem); | Obtains the semaphore.|
| \#include &lt;mqueue.h&gt; | mqd_t mq_open(const char \*mqName, int openFlag, ...); | Opens an existing message queue with the specified name or creates a message queue.|
| \#include &lt;mqueue.h&gt; | int mq_close(mqd_t personal); | Closes a message queue with the specified descriptor.|
| \#include &lt;mqueue.h&gt; | int mq_unlink(const char \*mqName); | Deletes the message queue of the specified name.|
| \#include &lt;mqueue.h&gt; | int mq_send(mqd_t personal, const char \*msg, size_t msgLen, unsigned int msgPrio); | Puts a message with the specified content and length into a message queue.|
| \#include &lt;mqueue.h&gt; | ssize_t mq_receive(mqd_t personal, char \*msg, size_t msgLen, unsigned int \*msgPrio); | Deletes the oldest message from a message queue and puts it in the buffer pointed to by **msg_ptr**.|
| \#include &lt;mqueue.h&gt; | int mq_timedsend(mqd_t personal, const char\*msg, size_t msgLen, unsigned int msgPrio, const struct timespec \*absTimeout) | Puts a message with the specified content and length into a message queue at the specified time.|
| \#include &lt;mqueue.h&gt; | ssize_t mq_timedreceive(mqd_t personal, char\*msg, size_t msgLen, unsigned int \*msgPrio, const struct timespec \*absTimeout); | Obtains a message with the specified content and length from a message queue.|
| \#include &lt;mqueue.h&gt; | int mq_setattr(mqd_t mqdes, const struct mq_attr \*\_\_restrict newattr, struct mq_attr *\__restrict oldattr); | Sets the message queue attributes specified by the descriptor.|
| \#include &lt;libc.h&gt; | const char \*libc_get_version_string(void); | Obtains the libc version string.|
| \#include &lt;libc.h&gt; | int libc_get_version(void); | Obtains the libc version.|


#### Error Codes

The table below lists common error codes.

| Error Code | Value| Description|
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
| ENFILE\* | 23 | File table overflow |
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


#### Development Example

Example:

Creates a thread, transfers the information in the parent thread to the child thread, and prints the transferred information and the thread ID in the child thread.

The sample code can be compiled and verified in **./kernel/liteos_m/testsuites/src/osTest.c**. The **DemoForTest** function is called in **TestTaskEntry**.


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

The execution result of **DemoForTest** is as follows:


```
++++++++++++++  Hello world  ThreadFn  tid = 48 ++++++++++++++

++++++++++++++  Hello world  ThreadFn  tid = 48 ++++++++++++++

++++++++++++++  Hello world  ThreadFn  tid = 48 ++++++++++++++
```
