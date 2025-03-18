# 标准库


OpenHarmony内核使用[musl libc库](../../application-dev/reference/native-lib/musl.md)，支持标准POSIX接口，开发者可基于POSIX标准接口开发内核之上的组件及应用。


## 标准库接口框架

  **图1** POSIX接口框架

  ![zh-cn_image_0000001172904117](figures/zh-cn_image_0000001172904117.png)

musl libc库支持POSIX标准，涉及的系统调用相关接口由OpenHarmony内核适配支持 ，以满足接口对外描述的功能要求。

标准库支持接口的详细情况请参考[C库的API文档](../../application-dev/reference/native-lib/musl.md)，其中也涵盖了与POSIX标准之间的差异说明。


### 编程实例


####  实例描述

在本示例中，主线程创建了THREAD_NUM个子线程，每个子线程启动后等待被主线程唤醒，主线程成功唤醒所有子线程后，子线程继续执行直至生命周期结束，同时主线程通过pthread_join方法等待所有线程执行结束。

####  编程示例

本演示代码在./kernel/liteos_a/testsuites/kernel/src/osTest.c中编译验证，在TestTaskEntry中调用验证入口函数ExamplePosix。

示例代码如下：  

```
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define THREAD_NUM 3
int g_startNum = 0; /* 启动的线程数 */
int g_wakenNum = 0; /* 唤醒的线程数 */

struct testdata {
    pthread_mutex_t mutex;
    pthread_cond_t cond;
} g_td;

/* 子线程入口函数 */
static VOID *ChildThreadFunc(VOID *arg)
{
    int rc;
    pthread_t self = pthread_self();

    /* 获取mutex锁 */
    rc = pthread_mutex_lock(&g_td.mutex);
    if (rc != 0) {
        dprintf("ERROR:take mutex lock failed, error code is %d!\n", rc);
        goto EXIT;
    }

    /* g_startNum计数加一，用于统计已经获得mutex锁的子线程个数 */
    g_startNum++;

    /* 等待cond条件变量 */
    rc = pthread_cond_wait(&g_td.cond, &g_td.mutex);
    if (rc != 0) {
        dprintf("ERROR: pthread condition wait failed, error code is %d!\n", rc);
        (void)pthread_mutex_unlock(&g_td.mutex);
        goto EXIT;
    }

    /* 尝试获取mutex锁，正常场景，此处无法获取锁 */
    rc = pthread_mutex_trylock(&g_td.mutex);
    if (rc == 0) {
        dprintf("ERROR: mutex gets an abnormal lock!\n");
        goto EXIT;
    }

    /* g_wakenNum计数加一，用于统计已经被cond条件变量唤醒的子线程个数 */
    g_wakenNum++;

    /* 释放mutex锁 */
    rc = pthread_mutex_unlock(&g_td.mutex);
    if (rc != 0) {
        dprintf("ERROR: mutex release failed, error code is %d!\n", rc);
        goto EXIT;
    }
EXIT:
    return NULL;
}

static int ExamplePosix(VOID)
{
    int i, rc;
    pthread_t thread[THREAD_NUM];

    /* 初始化mutex锁 */
    rc = pthread_mutex_init(&g_td.mutex, NULL);
    if (rc != 0) {
        dprintf("ERROR: mutex init failed, error code is %d!\n", rc);
        goto ERROROUT;
    }

    /* 初始化cond条件变量 */
    rc = pthread_cond_init(&g_td.cond, NULL);
    if (rc != 0) {
        dprintf("ERROR: pthread condition init failed, error code is %d!\n", rc);
        goto ERROROUT;
    }

    /* 批量创建THREAD_NUM个子线程 */
    for (i = 0; i < THREAD_NUM; i++) {
        rc = pthread_create(&thread[i], NULL, ChildThreadFunc, NULL);
        if (rc != 0) {
            dprintf("ERROR: pthread create failed, error code is %d!\n", rc);
            goto ERROROUT;
        }
    }
    dprintf("pthread_create ok\n");

    /* 等待所有子线程都完成mutex锁的获取 */
    while (g_startNum < THREAD_NUM) {
        usleep(100);
    }

    /* 获取mutex锁，确保所有子线程都阻塞在pthread_cond_wait上 */
    rc = pthread_mutex_lock(&g_td.mutex);
    if (rc != 0) {
        dprintf("ERROR: mutex lock failed, error code is %d\n", rc);
        goto ERROROUT;
    }

    /* 释放mutex锁 */
    rc = pthread_mutex_unlock(&g_td.mutex);
    if (rc != 0) {
        dprintf("ERROR: mutex unlock failed, error code is %d!\n", rc);
        goto ERROROUT;
    }

    for (int j = 0; j < THREAD_NUM; j++) {
        /* 在cond条件变量上广播信号 */
        rc = pthread_cond_signal(&g_td.cond);
        if (rc != 0) {
            dprintf("ERROR: pthread condition failed, error code is %d!\n", rc);
            goto ERROROUT;
        }
    }

    sleep(1);

    /* 检查是否所有子线程都已被唤醒 */
    if (g_wakenNum != THREAD_NUM) {
        dprintf("ERROR: not all threads awaken, only %d thread(s) awaken!\n", g_wakenNum);
        goto ERROROUT;
    }
    dprintf("all threads awaked\n");

    /* join所有子线程，即等待其结束 */
    for (i = 0; i < THREAD_NUM; i++) {
        rc = pthread_join(thread[i], NULL);
        if (rc != 0) {
            dprintf("ERROR: pthread join failed, error code is %d!\n", rc);
            goto ERROROUT;
        }
    }
    dprintf("all threads join ok\n");

    /* 销毁cond条件变量 */
    rc = pthread_cond_destroy(&g_td.cond);
    if (rc != 0) {
        dprintf("ERROR: pthread condition destroy failed, error code is %d!\n", rc);
        goto ERROROUT;
    }
    return 0;
ERROROUT:
    return -1;
}
```

#### 验证结果

  输出结果如下：

```
pthread_create ok
all threads awaked
all threads join ok
```

## 与Linux标准库差异

本节描述了OpenHarmony内核承载的标准库与Linux标准库之间存在的关键差异。更多差异详见C库API文档说明。


### 进程

1. OpenHarmony用户态**进程**优先级只支持静态优先级且用户态可配置的优先级范围为10(最高优先级)-31(最低优先级）。

2. OpenHarmony用户态**线程**优先级只支持静态优先级且用户态可配置的优先级范围为0(最高优先级)-31(最低优先级）。

3. OpenHarmony进程调度策略只支持SCHED_RR， 线程调度策略支持SCHED_RR和SCHED_FIFO。


### 内存

**与Linux mmap的差异**

mmap接口原型为：void \*mmap (void \*addr, size_t length, int prot, int flags, int fd, off_t offset)。

其中，参数fd的生命周期实现与Linux glibc存在差异。具体体现在，glibc在成功调用mmap进行映射后，可以立即释放fd句柄。在OpenHarmony内核中，不允许用户在映射成功后立即关闭相关fd，只允许在取消映射munmap后再进行fd的close操作。如果用户不进行fd的close操作，操作系统将在进程退出时对该fd进行回收。

**代码举例**


Linux目前支持的情况如下：

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
    close(fd);  /* OpenHarmony does not support closing fd immediately after the mapping is successful. */ 
    ...
    exit(EXIT_SUCCESS);
}
```


  OpenHarmony支持的情况如下：

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
    close(fd);  /* Close fd after the munmap is canceled. */
    exit(EXIT_SUCCESS);
}
```


### 文件系统

**系统目录**：用户无权限修改系统目录和设备挂载目录。包含/dev，/proc，/app，/bin，/data，/etc，/lib，/system，/usr目录。

**用户目录**：用户可以在该目录下进行文件创建、读写，但**不能进行设备挂载**。用户目录指/storage目录。

除**系统目录**与**用户目录**之外，用户可以自行创建文件夹进行设备的挂载。但是要注意，已挂载的文件夹及其子文件夹不允许重复或者嵌套挂载，非空文件夹不允许挂载。


### 信号

- 信号默认行为不支持STOP、CONTINUE、COREDUMP功能。

- 无法通过信号唤醒正在睡眠状态（举例：进程调用sleep函数进入睡眠）的进程。原因：信号机制无唤醒功能，当且仅当进程被CPU调度运行时才能处理信号内容。

- 进程退出后会发送SIGCHLD给父进程，发送动作无法取消。

- 信号仅支持1-30号信号，接收方收到多次同一信号，仅执行一次回调函数。


### Time

OpenHarmony当前时间精度以tick计算，系统默认10ms/tick。sleep、timeout系列函数时间误差&lt;=20ms。
