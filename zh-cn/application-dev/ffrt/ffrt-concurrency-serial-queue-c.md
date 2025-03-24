# Function Flow Runtime串行队列(C)

## 概述

FFRT串行队列基于协程调度模型实现，提供高效的消息队列功能，支持异步通信、流量削峰、无锁化状态和资源管理以及架构解耦等多种业务场景。FFRT串行队列支持以下功能：

- **​队列创建销毁**​，支持创建和销毁队列，创建时可指定队列名称和优先级。每个队列功能上相当于一个单独的线程，队列中的任务相对于用户线程异步执行。
- **任务延迟**​，支持在任务提交时设置延迟时间（`delay`），单位为微秒（`us`）。延迟任务将在`uptime`（提交时刻+延迟时间）后调度执行。
- **​串行调度**​，同一队列中的任务按照`uptime`升序排列，严格串行执行。确保队列中上一个任务完成后，下一个任务才会开始执行。
- **​任务取消**​，支持根据任务句柄取消未出队的任务。若任务已开始执行或执行完成，则无法取消。
- **​任务等待**​，支持根据任务句柄等待任务完成。指定任务完成时，队列中所有`uptime`早于该任务的任务均已执行完成。
- **任务优先级**​，支持在任务提交时设置单个任务的优先级。优先级仅在任务出队后相对于系统其他负载生效，不影响同一队列内任务的串行顺序。若未设置任务优先级，则默认继承队列的优先级。

## 示例：异步日志系统

举例实现一个异步日志系统，主线程将日志任务提交到队列，后台线程从队列中取出任务并写入文件。这种方式既能保证日志的顺序性，又能避免文件写入操作阻塞主线程。

借助FFRT并行化框架API，开发者只需专注于业务逻辑的实现，无需关注异步线程管理、线程安全及调度效率等问题。

用例简化了异常处理和线程安全相关的一些逻辑，实现代码如下所示：

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "ffrt/queue.h"
#include "ffrt/task.h"

typedef struct {
    FILE *logFile;          // 日志文件指针
    ffrt_queue_t queue;     // 任务队列
} logger_t;

// 全局Logger变量
logger_t* g_logger = NULL;

// 初始化日志系统
logger_t *logger_create(const char *filename)
{
    logger_t *logger = (logger_t *)malloc(sizeof(logger_t));
    if (!logger) {
        perror("Failed to allocate memory for logger_t");
        return NULL;
    }

    // 打开日志文件
    logger->logFile = fopen(filename, "a");
    if (!logger->logFile) {
        perror("Failed to open log file");
        free(logger);
        return NULL;
    }
    printf("Log file opened: %s\n", filename);

    // 创建任务队列
    logger->queue = ffrt_queue_create(ffrt_queue_serial, "logger_queue_c", NULL);
    if (!logger->queue) {
        perror("Failed to create queue");
        fclose(logger->logFile);
        free(logger);
        return NULL;
    }

    return logger;
}

// 销毁日志系统
void logger_destroy(logger_t *logger)
{
    if (logger) {
        // 销毁队列
        if (logger->queue) {
            ffrt_queue_destroy(logger->queue);
        }

        // 关闭日志文件
        if (logger->logFile) {
            fclose(logger->logFile);
            printf("Log file closed\n");
        }

        free(logger);
    }
}

// 日志任务
void write_task(void *arg)
{
    char *message = (char *)arg;
    if (g_logger && g_logger->logFile) {
        fprintf(g_logger->logFile, "%s\n", message);
        fflush(g_logger->logFile);
    }

    free(message);
}

// 添加日志任务
void logger_log(logger_t *logger, const char *message)
{
    if (!logger || !logger->queue) {
        return;
    }

    // 复制消息字符串
    char *messageCopy = strdup(message);
    if (!messageCopy) {
        perror("Failed to allocate memory for message");
        return;
    }

    ffrt_queue_submit(logger->queue, ffrt_create_function_wrapper(write_task, NULL, messageCopy), NULL);
}

int main()
{
    // 初始化全局logger
    g_logger = logger_create("log_c.txt");
    if (!g_logger) {
        return -1;
    }

    // 使用全局logger添加日志任务
    logger_log(g_logger, "Log message 1");
    logger_log(g_logger, "Log message 2");
    logger_log(g_logger, "Log message 3");

    // 模拟主线程继续执行其他任务
    sleep(1);

    // 销毁全局logger
    logger_destroy(g_logger);
    g_logger = NULL;
    return 0;
}
```

C风格构建FFRT任务需要一些额外的封装，封装方式为公共代码，与具体业务场景无关，使用方可以考虑用公共机制封装管理。

```c
typedef struct {
    ffrt_function_header_t header;
    ffrt_function_t func;
    ffrt_function_t after_func;
    void* arg;
} c_function_t;

static inline void ffrt_exec_function_wrapper(void* t)
{
    c_function_t* f = (c_function_t *)t;
    if (f->func) {
        f->func(f->arg);
    }
}

static inline void ffrt_destroy_function_wrapper(void* t)
{
    c_function_t* f = (c_function_t *)t;
    if (f->after_func) {
        f->after_func(f->arg);
    }
}

#define FFRT_STATIC_ASSERT(cond, msg) int x(int static_assertion_##msg[(cond) ? 1 : -1])
static inline ffrt_function_header_t *ffrt_create_function_wrapper(const ffrt_function_t func,
    const ffrt_function_t after_func, void *arg)
{
    FFRT_STATIC_ASSERT(sizeof(c_function_t) <= ffrt_auto_managed_function_storage_size,
        size_of_function_must_be_less_than_ffrt_auto_managed_function_storage_size);

    c_function_t* f = (c_function_t *)ffrt_alloc_auto_managed_function_storage_base(ffrt_function_kind_queue);
    f->header.exec = ffrt_exec_function_wrapper;
    f->header.destroy = ffrt_destroy_function_wrapper;
    f->func = func;
    f->after_func = after_func;
    f->arg = arg;
    return (ffrt_function_header_t *)f;
}
```

## 接口说明

上述样例中涉及到主要的FFRT的接口包括：

| 名称                                                             | 描述                           |
| ---------------------------------------------------------------- | ------------------------------ |
| [ffrt_queue_create](ffrt-api-guideline-c.md#ffrt_queue_create)   | 创建队列。                     |
| [ffrt_queue_destroy](ffrt-api-guideline-c.md#ffrt_queue_destroy) | 销毁队列。                     |
| [ffrt_queue_submit](ffrt-api-guideline-c.md#ffrt_queue_submit)   | 提交一个任务到队列中调度执行。 |

## 约束限制

- **避免提交超长任务** FFRT内置进程级队列任务超时检测机制。当串行任务执行时间超过预设阈值（默认30秒）时，系统将打印和上报异常日志，并触发预设的进程超时回调函数（如已配置）。
- **同步原语使用规范** 在提交给FFRT的任务闭包中，避免使用`std::mutex`、`std::condition_variable`和`std::recursive_mutex`，标准库同步原语会长时间占用FFRT Worker线程。请替换为FFRT提供的同步原语：`ffrt::mutex`、`ffrt::condition_variable`或`ffrt::recursive_mutex`，其用法与标准库相同。
- **全局变量中的队列管理** 若在全局变量中管理串行队列，随业务进程销毁，测试程序中需注意生命周期解耦问题。在测试用例结束时，需显式释放串行队列，其他资源可随全局变量释放。原因是全局变量在主函数结束后析构，而串行队列的释放依赖于FFRT框架中的其他资源，此时这些资源可能已被销毁。
