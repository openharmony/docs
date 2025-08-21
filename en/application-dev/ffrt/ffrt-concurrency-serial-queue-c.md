# Function Flow Runtime Serial Queue (C)

<!--Kit: Function Flow Runtime Kit-->
<!--Subsystem: Resourceschedule-->
<!--Owner: @chuchihtung; @yanleo-->
<!--Designer: @geoffrey_guo; @huangyouzhong-->
<!--Tester: @lotsof; @sunxuhao-->
<!--Adviser: @foryourself-->

## Overview

The FFRT serial queue is implemented based on the coroutine scheduling model. It provides efficient message queue functions and supports multiple service scenarios, such as asynchronous communication, mobile data peak clipping, lock-free status and resource management, and architecture decoupling. The following functions are supported:

- **Queue creation and destruction**: The queue name and priority can be specified during creation. Each queue is equivalent to an independent thread. Tasks in the queue are executed asynchronously compared with user threads.
- **Task delay**: The `delay` can be set when a task is submitted. The unit is `μs`. The delayed task will be scheduled and executed after `uptime` (submission time + delay time).
- **Serial scheduling**: Tasks in the same queue are sorted in ascending order of `uptime` and executed in serial mode. Ensure that the next task starts to be executed only after the previous task in the queue is complete.
- **Task canceling**: You can cancel a task that is not dequeued based on the task handle. The task cannot be canceled if it has been started or completed.
- **Task waiting**: You can wait for a task to complete based on the task handle. When a specified task is complete, all tasks whose `uptime` is earlier than the specified task in the queue have been executed.
- **Task priority**: You can set the priority of a single task when submitting the task. Priorities take effect only after a task is dequeued relative to other system loads, and do not affect the serial task order in the same queue. If the task priority is not set, the priority of the queue is inherited by default.

## Example: Asynchronous Log System

The following is an example of implementing an asynchronous log system. The main thread submits the log task to the queue, and the background thread obtains the task from the queue and writes the task to the file. It ensures the log sequence and prevents the main thread from being blocked by the file write operation.

With FFRT APIs, you only need to focus on service logic implementation and do not need to pay attention to asynchronous thread management, thread security, and scheduling efficiency.

The example simplifies the logic for handling exceptions and ensuring thread security. The code is as follows:

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "ffrt/ffrt.h" // From the OpenHarmony third-party library "@ppd/ffrt"

typedef struct {
    FILE *logFile;          // Pointer to a log file.
    ffrt_queue_t queue;     // Task queue.
} logger_t;

// Global logger variable.
logger_t* g_logger = NULL;

// Initialize the log system.
logger_t *logger_create(const char *filename)
{
    logger_t *logger = (logger_t *)malloc(sizeof(logger_t));
    if (!logger) {
        perror("Failed to allocate memory for logger_t");
        return NULL;
    }

    // Open the log file.
    logger->logFile = fopen(filename, "a");
    if (!logger->logFile) {
        perror("Failed to open log file");
        free(logger);
        return NULL;
    }
    printf("Log file opened: %s\n", filename);

    // Create a task queue.
    logger->queue = ffrt_queue_create(ffrt_queue_serial, "logger_queue_c", NULL);
    if (!logger->queue) {
        perror("Failed to create queue");
        fclose(logger->logFile);
        free(logger);
        return NULL;
    }

    return logger;
}

// Destroy the log system.
void logger_destroy(logger_t *logger)
{
    if (logger) {
        // Destroy the queue.
        if (logger->queue) {
            ffrt_queue_destroy(logger->queue);
        }

        // Close the log file.
        if (logger->logFile) {
            fclose(logger->logFile);
            printf("Log file closed\n");
        }

        free(logger);
    }
}

// Log task.
void write_task(void *arg)
{
    char *message = (char *)arg;
    if (g_logger && g_logger->logFile) {
        fprintf(g_logger->logFile, "%s\n", message);
        fflush(g_logger->logFile);
    }

    free(message);
}

// Add a log task.
void logger_log(logger_t *logger, const char *message)
{
    if (!logger || !logger->queue) {
        return;
    }

    // Copy the message string.
    char *messageCopy = strdup(message);
    if (!messageCopy) {
        perror("Failed to allocate memory for message");
        return;
    }

    ffrt_queue_submit_f(logger->queue, write_task, messageCopy, NULL);
}

int main()
{
    // Initialize the global logger.
    g_logger = logger_create("log_c.txt");
    if (!g_logger) {
        return -1;
    }

    // Use the global logger to add a log task.
    logger_log(g_logger, "Log message 1");
    logger_log(g_logger, "Log message 2");
    logger_log(g_logger, "Log message 3");

    // Simulate the main thread to continue executing other tasks.
    sleep(1);

    // Destroy the global logger.
    logger_destroy(g_logger);
    g_logger = NULL;
    return 0;
}
```

## Available APIs

The main FFRT APIs involved in the preceding example are as follows:

| Name                                                              | Description                |
| ------------------------------------------------------------------ | -------------------- |
| [ffrt_queue_create](ffrt-api-guideline-c.md#ffrt_queue_t)     | Creates a queue.          |
| [ffrt_queue_destroy](ffrt-api-guideline-c.md#ffrt_queue_t)   | Destroys a queue.          |
| [ffrt_queue_submit_f](ffrt-api-guideline-c.md#ffrt_queue_t) | Submits a task to a queue.|

> **NOTE**
>
> - For details about how to use FFRT C++ APIs, see [Using FFRT C++ APIs](ffrt-development-guideline.md#using-ffrt-c-api-1).
> - When using FFRT C or C++ APIs, you can use the FFRT C++ API third-party library to simplify the header file inclusion, that is, use the `#include "ffrt/ffrt.h"` header file to include statements.

## Constraints

- **Avoid submitting ultra-long tasks.** The FFRT has a built-in process-level queue task timeout detection mechanism. When the execution time of a serial task exceeds the preset threshold (30 seconds by default), the system prints and reports exception logs and triggers the preset process timeout callback function (if configured).
- **Use synchronization primitives correctly.** Do not use `std::mutex`, `std::condition_variable`, or `std::recursive_mutex` in the task closure submitted to FFRT. As synchronization primitives in the standard library will occupy the FFRT Worker thread for a long time, you should use the synchronization primitives provided by FFRT: `ffrt::mutex`, `ffrt::condition_variable`, or `ffrt::recursive_mutex`. The usage is the same as that of the standard library.
- **Manage queues in global variables.** If serial queues are managed in global variables and destroyed with service processes, pay attention to lifecycle decoupling in the test program. When the test is complete, the serial queue needs to be explicitly released. Other resources can be released with global variables. The reason is that global variables are destructed after the main function ends, and the release of serial queues depends on other resources in the FFRT framework, and the resources may have been destroyed.
