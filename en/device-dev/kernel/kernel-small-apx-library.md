# Standard Library


The OpenHarmony kernel uses the musl libc library that supports the Portable Operating System Interface \(POSIX\). You can develop components and applications working on the kernel based on the POSIX.

## Standard Library API Framework

**Figure  1**  POSIX framework<a name="fig153258541429"></a>  
![](figures/posix-framework.png "posix-framework")

The musl libc library supports POSIX standards. The OpenHarmony kernel adapts the related system call APIs to implement external functions.

For details about the APIs supported by the standard library, see the API document of the C library, which also covers the differences between the standard library and the POSIX standard library.

## Development Example

In this example, the main thread creates  **THREAD\_NUM**  child threads. Once a child thread is started, it enters the standby state. After the main thread successfully wakes up all child threads, they continue to execute until the lifecycle ends. The main thread uses the  **pthread\_join**  method to wait until all child threads are executed.

```
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

#define THREAD_NUM 3
int g_startNum = 0; /* Number of started threads */
int g_wakenNum = 0; /* Number of wakeup threads */

struct testdata {
    pthread_mutex_t mutex;
    pthread_cond_t cond;
} g_td;

/*
 * Entry function of child threads.
 */
static void *ChildThreadFunc(void *arg)
{
    int rc;
    pthread_t self = pthread_self();

    /* Acquire a mutex. */
    rc = pthread_mutex_lock(&g_td.mutex);
    if (rc != 0) {
        printf("ERROR:take mutex lock failed, error code is %d!\n", rc);
        goto EXIT;
    }

    /* The value of g_startNum is increased by 1. The value indicates the number of child threads that have acquired a mutex. */
    g_startNum++;

    /* Wait for the cond variable. */
    rc = pthread_cond_wait(&g_td.cond, &g_td.mutex);
    if (rc != 0) {
        printf("ERROR: pthread condition wait failed, error code is %d!\n", rc);
        (void)pthread_mutex_unlock(&g_td.mutex);
        goto EXIT;
    }

    /* Attempt to acquire a mutex, which is failed in normal cases. */
    rc = pthread_mutex_trylock(&g_td.mutex);
    if (rc == 0) {
        printf("ERROR: mutex gets an abnormal lock!\n");
        goto EXIT;
    }

    /* The value of g_wakenNum is increased by 1. The value indicates the number of child threads that have been woken up by the cond variable. */
    g_wakenNum++;

    /* Unlock a mutex. */
    rc = pthread_mutex_unlock(&g_td.mutex);
    if (rc != 0) {
        printf("ERROR: mutex release failed, error code is %d!\n", rc);
        goto EXIT;
    }
EXIT:
    return NULL;
}

static int testcase(void)
{
    int i, rc;
    pthread_t thread[THREAD_NUM];

    /* Initialize a mutex. */
    rc = pthread_mutex_init(&g_td.mutex, NULL);
    if (rc != 0) {
        printf("ERROR: mutex init failed, error code is %d!\n", rc);
        goto ERROROUT;
    }

    /* Initialize the cond variable. */
    rc = pthread_cond_init(&g_td.cond, NULL);
    if (rc != 0) {
        printf("ERROR: pthread condition init failed, error code is %d!\n", rc);
        goto ERROROUT;
    }

    /* Create child threads in batches. The number is specified by THREAD_NUM. */
    for (i = 0; i < THREAD_NUM; i++) {
        rc = pthread_create(&thread[i], NULL, ChildThreadFunc, NULL);
        if (rc != 0) {
            printf("ERROR: pthread create failed, error code is %d!\n", rc);
            goto ERROROUT;
        }
    }

    /* Wait until all child threads lock a mutex. */
    while (g_startNum < THREAD_NUM) {
        usleep(100);
    }

    /* Acquire a mutex and block all threads using pthread_cond_wait. */
    rc = pthread_mutex_lock(&g_td.mutex);
    if (rc != 0) {
        printf("ERROR: mutex lock failed, error code is %d\n", rc);
        goto ERROROUT;
    }

    /* Release a mutex. */
    rc = pthread_mutex_unlock(&g_td.mutex);
    if (rc != 0) {
        printf("ERROR: mutex unlock failed, error code is %d!\n", rc);
        goto ERROROUT;
    }

    for (int j = 0; j < THREAD_NUM; j++) {
        /* Broadcast signals on the cond variable. */
        rc = pthread_cond_signal(&g_td.cond);
        if (rc != 0) {
            printf("ERROR: pthread condition failed, error code is %d!\n", rc);
            goto ERROROUT;
        }
    }

    sleep(1);

    /* Check whether all child threads are woken up. */
    if (g_wakenNum != THREAD_NUM) {
        printf("ERROR: not all threads awaken, only %d thread(s) awaken!\n", g_wakenNum);
        goto ERROROUT;
    }

    /* Wait for all threads to terminate. */
    for (i = 0; i < THREAD_NUM; i++) {
        rc = pthread_join(thread[i], NULL);
        if (rc != 0) {
            printf("ERROR: pthread join failed, error code is %d!\n", rc);
            goto ERROROUT;
        }
    }

    /* Destroy the cond variable. */
    rc = pthread_cond_destroy(&g_td.cond);
    if (rc != 0) {
        printf("ERROR: pthread condition destroy failed, error code is %d!\n", rc);
        goto ERROROUT;
    }
    return 0;
ERROROUT:
    return -1;
}

/*
 * Main function
 */
int main(int argc, char *argv[])
{
    int rc;

    /* Start the test function. */
    rc = testcase();
    if (rc != 0) {
        printf("ERROR: testcase failed!\n");
    }

    return 0;
}
#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */
```

## Differences from the Linux Standard Library

This section describes the key differences between the standard library carried by the OpenHarmony kernel and the Linux standard library. For more differences, see the API document of the C library.

### Process

1.  The OpenHarmony user-mode processes support only static priorities, which range from 10 \(highest\) to 31 \(lowest\).
2.  The OpenHarmony user-mode threads support only static priorities, which range from 0 \(highest\) to 31 \(lowest\).
3.  The OpenHarmony process scheduling supports  **SCHED\_RR**  only, and thread scheduling supports  **SCHED\_RR**  or  **SCHED\_FIFO**.

### Memory

**h2****Difference with Linux mmap**

mmap prototype:  **void \*mmap \(void \*addr, size\_t length, int prot, int flags, int fd, off\_t offset\)**

The lifecycle implementation of  **fd**  is different from that of Linux glibc. glibc releases the  **fd**  handle immediately after successfully invoking  **mmap**  for mapping. In the OpenHarmony kernel, you are not allowed to close the  **fd**  immediately after the mapping is successful. You can close the  **fd**  only after  **munmap**  is called. If you do not close  **fd**, the OS reclaims the  **fd**  when the process exits.

**h2****Sample Code**

Linux OS:

```
int main(int argc, char *argv[])
{
    int fd;
    void *addr = NULL;
    ...
    fd = open(argv[1], O_RDONLY);
    if (fd == -1){
        perror("open");
        exit(EXIT_FAILURE);
    }
    addr = mmap(NULL, length, PROT_READ, MAP_PRIVATE, fd, offset);
    if (addr == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }
    close(fd); /*  OpenHarmony does not support close fd immediately after the mapping is successful. */ 
    ...
    exit(EXIT_SUCCESS);
}
```

OpenHarmony:

```
int main(int argc, char *argv[])
{
    int fd;
    void *addr = NULL;
    ...
    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }
    addr = mmap(NULL, length, PROT_READ, MAP_PRIVATE, fd, offset);
    if (addr == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }
    ...
    munmap(addr, length);
    close(fd); /* Close fd after the munmap is canceled. */
    exit(EXIT_SUCCESS);
}
```

### File System

**System directories**: You cannot modify system directories and device mount directories, which include  **/dev**,  **/proc**,  **/app**,  **/bin**,  **/data**,  **/etc**,  **/lib**,  **/system**  and  **/usr**.

**User directory**: The user directory refers to the  **/storage**  directory. You can create, read, and write files in this directory, but cannot mount devices.

Except in the system and user directories, you can create directories and mount devices. Note that nested mount is not allowed, that is, a mounted folder and its subfolders cannot be mounted repeatedly. A non-empty folder cannot be mounted.

### Signal

-   The default behavior for signals does not include  **STOP**,  **CONTINUE**, or  **COREDUMP**.
-   A sleeping process \(for example, a process enters the sleeping status by calling the sleep function\) cannot be woken up by a signal. The signal mechanism does not support the wakeup function. The behavior for a signal can be processed only when the process is scheduled by the CPU.
-   After a process exits,  **SIGCHLD**  is sent to the parent process. The sending action cannot be canceled.
-   Only signals 1 to 30 are supported. The callback is executed only once even if the same signal is received multiple times.

### Time

The OpenHarmony time precision is based on tick. The default value is 10 ms/tick. The time error of the  **sleep**  and  **timeout**  functions is less than or equal to 20 ms.

