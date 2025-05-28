# Function Flow Runtime开发指导

## 介绍

FFRT编程模型是一种基于任务和数据驱动的并发编程模型，允许开发者通过任务及其依赖关系描述的方式进行应用开发。
通过FFRT编程模型，开发者可专注于应用功能开发，由FFRT在运行时根据任务依赖状态和可用执行资源自动并发调度和执行任务。

本文用于指导开发者基于FFRT编程模型实现并行编程。

## 维测

### 超时监测

FFRT提供开发者队列级和任务级超时维测机制，用来监控用户业务中承载重要职责的队列和任务在FFRT调度的端到端时间。

- 当队列中任务发生超时，FFRT打印告警日志并通过回调接口通知到业务。
- 当任务发生超时，FFRT打印告警日志并调用进程级回调函数。

> **注意：**
>
> 任务超时时执行的回调函数进程范围内唯一，需要在任务提交之前由业务方配置到FFRT中，不支持在提交任务或任务超时检测过程中配置。

具体接口包括：

| C++接口                                                                                                                                   | C接口                                                                                | 描述                   |
| ----------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------ | ---------------------- |
| [queue_attr::timeout](https://gitee.com/openharmony/resourceschedule_ffrt/blob/master/docs/ffrt-api-guideline-cpp.md#set-queue-timeout)   | [ffrt_queue_attr_set_timeout](ffrt-api-guideline-c.md#ffrt_queue_attr_set_timeout)   | 设置队列超时时间。     |
| [queue_attr::callback](https://gitee.com/openharmony/resourceschedule_ffrt/blob/master/docs/ffrt-api-guideline-cpp.md#set-queue-callback) | [ffrt_queue_attr_set_callback](ffrt-api-guideline-c.md#ffrt_queue_attr_set_callback) | 设置队列超时回调函数。 |

### 长耗时任务监测

#### 机制

- 长耗时任务打印机制 当任务执行时间超过一秒时，会触发一次堆栈打印，后续该任务堆栈打印频率调整为一分钟。连续打印十次后，打印频率调整为十分钟。再触发十次打印后，打印频率固定为三十分钟。
- 该机制的堆栈打印调用的是DFX的`GetBacktraceStringByTid`接口，该接口会向阻塞线程发送抓栈信号，触发中断并抓取调用栈返回。

#### 样例

在对应进程日志中搜索RecordSymbolAndBacktrace关键字，对应的日志示例如下：

```txt
W C01719/ffrt: 60500:RecordSymbolAndBacktrace:159 Tid[16579] function occupies worker for more than [1]s.
W C01719/ffrt: 60501:RecordSymbolAndBacktrace:164 Backtrace:
W C01719/ffrt: #00 pc 00000000000075f0 /system/lib64/module/file/libhash.z.so
W C01719/ffrt: #01 pc 0000000000008758 /system/lib64/module/file/libhash.z.so
W C01719/ffrt: #02 pc 0000000000012b98 /system/lib64/module/file/libhash.z.so
W C01719/ffrt: #03 pc 000000000002aaa0 /system/lib64/platformsdk/libfilemgmt_libn.z.so
W C01719/ffrt: #04 pc 0000000000054b2c /system/lib64/platformsdk/libace_napi.z.so
W C01719/ffrt: #05 pc 00000000000133a8 /system/lib64/platformsdk/libuv.so
W C01719/ffrt: #06 pc 00000000000461a0 /system/lib64/chipset-sdk/libffrt.so
W C01719/ffrt: #07 pc 0000000000046d44 /system/lib64/chipset-sdk/libffrt.so
W C01719/ffrt: #08 pc 0000000000046a6c /system/lib64/chipset-sdk/libffrt.so
W C01719/ffrt: #09 pc 00000000000467b0 /system/lib64/chipset-sdk/libffrt.so
```

该维测会打印出Worker上执行时间超过阈值的任务堆栈、Worker线程号、执行时间，请自行根据堆栈找对应组件确认阻塞原因。

#### 注意事项

不涉及。

### 运行信息转储

#### 机制

FFRT提供一个对外的接口`ffrt_dump`以便转储FFRT子系统运行时的内部信息，主要包含：

1. FFRT统计信息：提交任务数，运行任务数，协程切换次数，任务完成数；
2. Worker线程信息：每个QoS下的Worker数量，Worker id，当前运行的任务id，任务名以及任务类型；
3. 普通任务信息：当前进程中还未释放的普通任务，dump每个任务的任务名，id及调用栈信息；
4. 队列任务信息：当前进程中还未释放的队列任务，dump每个任务的任务名，id及调用栈信息。

在当前进程发生freeze时，OH的DFX模块会主动调用`ffrt_dump`接口转储FFRT的信息，落盘到freeze文件中，存储到`/data/log/faultlog/faultlogger/`目录下，用户可以直接利用该文件中的任务调用栈信息定位对应任务的卡顿问题。

#### 样例

```txt
ready task ptr: qos 0 readptr 79 writeptr 79
ready task ptr: qos 1 readptr 360 writeptr 360
ready task ptr: qos 2 readptr 19 writeptr 19
ready task ptr: qos 3 readptr 0 writeptr 0
ready task ptr: qos 4 readptr 0 writeptr 0
ready task ptr: qos 5 readptr 65 writeptr 65
ready task ptr: qos 6 readptr 0 writeptr 0
ready task ptr: qos 7 readptr 0 writeptr 0
submit queue: readptr 24 writeptr 24
intr wake: status 255
proc status: taskCnt 23 vercnt 0sigCnt0
    |-> worker count
        qos 0: worker num:1 tid:31676
        qos 2: worker num:3 tid:51349, 28769, 28565
        qos 5: worker num:1 tid:30605
    |-> worker status
        qos 0: worker tid 31676 is running nothing
        qos 2: worker tid 51349 is running nothing
        qos 2: worker tid 28769 is running, task id 24591 name sq_CesSrvMain_12_PublishCommonEventDetailed_24591 fromTid 43928 createTime 2024-11-27 02:52:27.325248 executeTime 2024-11-27 02:52:27.326150
        qos 2: worker tid 28565 is running, task id 24611 name sq_dfx_freeze_task_queue_16_NotifyAppFaultTask_24611 fromTid 43833 createTime 2024-11-27 02:52:38.114787 executeTime 2024-11-27 02:52:38.115424
        qos 5: worker tid 30605 is running, task id 24595 name sq_AbilityManagerService_19_SubmitTaskInner_24595 fromTid 43610 createTime 2024-11-27 02:52:27.844237 executeTime 2024-11-27 02:52:27.844573
    |-> ready queue status
    |-> blocked by task dependence
        <1/1>stack: task id 3,qos 2,name AgingTask fromTid 43417 createTime 2024-11-27 01:21:39.641673 executeTime 2024-11-27 01:21:39.642290
#00 pc 0000000000065c5c /system/lib64/ndk/libffrt.so(CoYield()+560)(22be57f01a789a03813d26a19c3a4042)
#01 pc 00000000000a3268 /system/lib64/ndk/libffrt.so(ffrt::this_task::SleepUntilImpl(std::__h::chrono::time_point<std::__h::chrono::steady_clock, std::__h::chrono::duration<long long, std::__h::ratio<1l, 1000000000l>>> const&)+356)(22be57f01a789a03813d26a19c3a4042)
#02 pc 00000000000a39b4 /system/lib64/ndk/libffrt.so(ffrt_usleep+60)(22be57f01a789a03813d26a19c3a4042)
#03 pc 0000000000420de0 /system/lib64/libbms.z.so(2eb52bd03af1b9a31e14ffe60bfc39da)
#04 pc 00000000000a6a2c /system/lib64/ndk/libffrt.so(ffrt::CPUEUTask::Execute()+300)(22be57f01a789a03813d26a19c3a4042)
#05 pc 0000000000066d18 /system/lib64/ndk/libffrt.so(22be57f01a789a03813d26a19c3a4042)
```

#### 注意事项

由于OH DFX模块在freeze时有处理时间的要求，低概率会导致`ffrt_dump`中收集的信息不全，freeze处理时间耗尽，此时落盘的信息会有缺失。

### 黑匣子日志

#### 机制

进程Crash发生时，FFRT模块收到信号（`SIGABRT`、`SIGBUS`、`SIGFPE`、`SIGILL`、`SIGSTKFLT`、`SIGSTOP`、`SIGSYS`和`SIGTRAP`），将FFRT当前重要的运行时信息保存至faultlog中，包括：正在运行的task；当前Worker的运行信息和调用栈信息；当前普通任务信息；当前队列任务信息等。用户可利用这些信息中的内容辅助定位Crash问题。

#### 样例

```txt
C01719/CameraDaemon/ffrt: 9986:operator():254 <<<=== ffrt black box(BBOX) start ===>>>
C01719/CameraDaemon/ffrt: 9987:SaveCurrent:63 <<<=== current status ===>>>
C01719/CameraDaemon/ffrt: 9988:SaveCurrent:68 signal SIGABRT triggered: source tid 5962, task id 17, qos 2, name SvrWatchdog
C01719/CameraDaemon/ffrt: 9989:SaveWorkerStatus:94 <<<=== worker status ===>>>
C01719/CameraDaemon/ffrt: 9990:SaveWorkerStatus:100 qos 0: worker tid 6410 is running nothing
C01719/CameraDaemon/ffrt: 9991:SaveWorkerStatus:100 qos 2: worker tid 5968 is running nothing
C01719/CameraDaemon/ffrt: 9992:SaveWorkerStatus:100 qos 2: worker tid 5964 is running nothing
C01719/CameraDaemon/ffrt: 9993:SaveWorkerStatus:100 qos 2: worker tid 5963 is running nothing
C01719/CameraDaemon/ffrt: 9994:SaveWorkerStatus:105 qos 2: worker tid 5962 is running task id 17 name SvrWatchdog
C01719/CameraDaemon/ffrt: 9995:SaveWorkerStatus:100 qos 2: worker tid 5967 is running nothing
C01719/CameraDaemon/ffrt: 9996:SaveWorkerStatus:100 qos 2: worker tid 5965 is running nothing
C01719/CameraDaemon/ffrt: 9997:SaveWorkerStatus:100 qos 2: worker tid 5961 is running nothing
C01719/CameraDaemon/ffrt: 9998:SaveWorkerStatus:100 qos 2: worker tid 1146 is running nothing
C01719/CameraDaemon/ffrt: 9999:SaveWorkerStatus:100 qos 2: worker tid 1145 is running nothing
C01719/CameraDaemon/ffrt: 10000:SaveWorkerStatus:100 qos 2: worker tid 5966 is running nothing
```

#### 注意事项

不涉及。

### Trace打点

#### 机制

FFRT任务的调度和执行过程中，利用了OH系统的Trace打点能力，对任务在FFRT框架中的状态流转做了实时跟踪，用户可以借助Trace图形化工具来分析任务的行为是否符合预期。

#### 样例

1. 启动Trace抓取

    ```shell
    hdc shell "hitrace -t 10 -b 20480 -o /data/local/tmp/in_systrace.ftrace sched freq idle ffrt"
    # -t：指定trace采集时长，在采集过程中所有的trace记录会落盘保存
    # -b：指定trace记录缓存大小，buffer不足的情况下可能导致部分记录被覆盖没有落盘
    # -o：指定trace落盘存储路径
    ```

2. 图形化工具呈现

    将Trace落盘的文件从设备中取出来，借助图形化工具进行分析，例如：[Perfetto](https://perfetto.dev/)。

#### 注意事项

用户也可以在自己业务代码中加入Trace打点，以界定问题的范围。需注意在高频调用流程中，加入Trace打点会有系统开销，会对业务性能造成影响。

### Debug日志

#### 机制

- FFRT默认不开启Debug级别的日志，用户可以通过命令的方式打开，以获取更丰富的维测信息支撑开发阶段的问题定位。
- 打开FFRT Debug日志开关：

    ```shell
    hdc shell hilog -b DEBUG -D 0xD001719
    ```

- 恢复默认FFRT INFO日志级别:

    ```shell
    hdc shell hilog -b INFO -D 0xD001719
    ```

#### 样例

```txt
4190  5631 D C01719/neboard:EngineServiceAbility:1/ffrt: 275337:Detach:147 qos 3 thread not joinable
3257  6075 D C01719/com.ohos.sceneboard/ffrt: 513070:SetDefaultThreadAttr:148 qos apply tid[6075] level[3]
```

#### 注意事项

由于FFRT是系统底座，支撑大量上层业务及框架的运行，全局打开Debug日志会导致日志超限，影响其他模块日志的正常输出。

## 开发步骤

以下步骤描述了如何使用FFRT提供的Native API接口，创建并行任务和串行队列任务以及销毁相应资源。

1. 在项目`CMakeLists.txt`中添加动态链接库：

    ```txt
    libffrt.z.so
    ```

2. 在项目中包含对应的头文件：

    ```cpp
    #include "ffrt/task.h"
    #include "ffrt/mutex.h"
    #include "ffrt/shared_mutex.h"
    #include "ffrt/condition_variable.h"
    #include "ffrt/sleep.h"
    #include "ffrt/queue.h"
    #include "ffrt/loop.h"
    #include "ffrt/timer.h"
    ```

3. 对执行的函数进行封装：

    ```cpp
    // 第一种使用模板，支持C++
    template<class T>
    struct function {
        ffrt_function_header_t header;
        T closure;
    };

    template<class T>
    void exec_function_wrapper(void* t)
    {
        auto f = reinterpret_cast<function<std::decay_t<T>>*>(t);
        f->closure();
    }

    template<class T>
    void destroy_function_wrapper(void* t)
    {
        auto f = reinterpret_cast<function<std::decay_t<T>>*>(t);
        f->closure = nullptr;
    }

    template<class T>
    inline ffrt_function_header_t* create_function_wrapper(T&& func,
        ffrt_function_kind_t kind = ffrt_function_kind_general)
    {
        using function_type = function<std::decay_t<T>>;
        static_assert(sizeof(function_type) <= ffrt_auto_managed_function_storage_size,
            "size of function must be less than ffrt_auto_managed_function_storage_size");

        auto p = ffrt_alloc_auto_managed_function_storage_base(kind);
        auto f = new (p)function_type;
        f->header.exec = exec_function_wrapper<T>;
        f->header.destroy = destroy_function_wrapper<T>;
        f->closure = std::forward<T>(func);
        return reinterpret_cast<ffrt_function_header_t*>(f);
    }

    // 第二种创建方式
    typedef struct {
        ffrt_function_header_t header;
        ffrt_function_t func;
        ffrt_function_t after_func;
        void* arg;
    } ffrt_function_wrapper_t;

    static inline void ffrt_exec_function_wrapper(void* t)
    {
       ffrt_function_wrapper_t* f = (ffrt_function_wrapper_t *)t;
       if (f->func) {
           f->func(f->arg);
       }
    }

    static inline void ffrt_destroy_function_wrapper(void* t)
    {
        ffrt_function_wrapper_t* f = (ffrt_function_wrapper_t *)t;
        if (f->after_func) {
            f->after_func(f->arg);
        }
    }

    #define FFRT_STATIC_ASSERT(cond, msg) int x(int static_assertion_##msg[(cond) ? 1 : -1])
    static inline ffrt_function_header_t *ffrt_create_function_wrapper(ffrt_function_t func,
        ffrt_function_t after_func, void* arg, ffrt_function_kind_t kind)
    {
        FFRT_STATIC_ASSERT(sizeof(ffrt_function_wrapper_t) <= ffrt_auto_managed_function_storage_size,
            size_of_function_must_be_less_than_ffrt_auto_managed_function_storage_size);

        ffrt_function_wrapper_t* f = (ffrt_function_wrapper_t *)ffrt_alloc_auto_managed_function_storage_base(kind);
        f->header.exec = ffrt_exec_function_wrapper;
        f->header.destroy = ffrt_destroy_function_wrapper;
        f->func = func;
        f->after_func = after_func;
        f->arg = arg;
        return (ffrt_function_header_t *)f;
    }

    // 样例：待提交执行的函数
    void OnePlusForTest(void* arg)
    {
        (*static_cast<int*>(arg)) += 1;
    }
    ```

4. 设置任务属性值，包括QoS等级、任务名称等。

    ```cpp
    // ******初始化并行任务属性******
    ffrt_task_attr_t attr;
    ffrt_task_attr_init(&attr);

    // ******创建串行队列******

    // 创建串行队列的属性
    ffrt_queue_attr_t queue_attr;
    // 创建串行队列的handle
    ffrt_queue_t queue_handle;

    // 初始化队列属性
    (void)ffrt_queue_attr_init(&queue_attr);

    // 如有需要，设置指定QoS等级
    ffrt_queue_attr_set_qos(&queue_attr, static_cast<ffrt_qos_t>(ffrt_qos_inherit));
    // 如有需要，设置超时时间(ms)
    ffrt_queue_attr_set_timeout(&queue_attr, 10000);
    // 如有需要，设置超时回调
    int x = 0;
    ffrt_queue_attr_set_callback(&queue_attr, ffrt_create_function_wrapper(OnePlusForTest, NULL, &x,
        ffrt_function_kind_queue));

    // 基于属性，初始化队列
    queue_handle = ffrt_queue_create(ffrt_queue_serial, "test_queue", &queue_attr);
    ```

5. 提交任务。

    ```cpp
    int a = 0;
    // ******并行任务******
    // 提交不带handle返回值的并行任务
    ffrt_submit_base(
        ffrt_create_function_wrapper(OnePlusForTest, NULL, &a, ffrt_function_kind_general), NULL, NULL, &attr);
    // 提交带handle返回值的并行任务
    ffrt_task_handle_t task = ffrt_submit_h_base(
        ffrt_create_function_wrapper(OnePlusForTest, NULL, &a, ffrt_function_kind_general), NULL, NULL, &attr);

    // ******串行任务******
    // 提交不返回handle的串行队列任务
    ffrt_queue_submit(queue_handle,
        ffrt_create_function_wrapper(OnePlusForTest, NULL, &a, ffrt_function_kind_queue), NULL);
    // 提交带handle的串行队列任务
    ffrt_task_handle_t handle = ffrt_queue_submit_h(queue_handle,
        ffrt_create_function_wrapper(OnePlusForTest, NULL, &a, ffrt_function_kind_queue), NULL);

    // 如果需要等待执行结果，则调用wait
    const std::vector<ffrt_dependence_t> wait_deps = {{ffrt_dependence_task, task}};
    ffrt_deps_t wait{static_cast<uint32_t>(wait_deps.size()), wait_deps.data()};
    ffrt_wait_deps(&wait);

    ffrt_queue_wait(handle);
    ```

6. 在任务不需要任何销毁动作时可以通过简化接口提交任务（可选）。

    ```cpp
    int a = 0;
    // 在步骤3场景中的after_func函数指针为NULL时，可以使用简化接口提交任务，避免冗余的任务结构封装。
    // ******并行任务******
    // 通过简化接口提交不带handle返回值的并行任务
    ffrt_submit_f(OnePlusForTest, &a, NULL, NULL, &attr);
    // 通过简化接口提交带handle返回值的并行任务
    ffrt_task_handle_t task = ffrt_submit_h_f(OnePlusForTest, &a, NULL, NULL, &attr);

    // ******串行任务******
    // 通过简化接口提交不返回handle的串行队列任务
    ffrt_queue_submit_f(queue_handle, OnePlusForTest, &a, NULL);
    // 通过简化接口提交带handle的串行队列任务
    ffrt_task_handle_t handle = ffrt_queue_submit_h_f(queue_handle, OnePlusForTest, &a, NULL);

    // 如果需要等待执行结果，则调用wait
    const std::vector<ffrt_dependence_t> wait_deps = {{ffrt_dependence_task, task}};
    ffrt_deps_t wait{static_cast<uint32_t>(wait_deps.size()), wait_deps.data()};
    ffrt_wait_deps(&wait);

    ffrt_queue_wait(handle);
    ```

7. 任务提交完成后销毁相应资源。

    ```cpp
    // ******销毁并行任务******
    ffrt_task_attr_destroy(&attr);
    ffrt_task_handle_destroy(task);

    // ******销毁串行队列任务******
    // 先销毁任务handle，再销毁队列
    ffrt_queue_attr_destroy(&queue_attr);
    ffrt_task_handle_destroy(handle);
    ffrt_queue_destroy(queue_handle);
    ```

## 使用建议

### 建议1：函数化

- 程序过程各步骤以函数封装表达，函数满足类纯函数特性。
- 无全局数据访问。
- 无内部状态保留。
- 通过`ffrt_submit_base()`或`ffrt_submit_f()`接口以异步任务方式提交函数执行。
- 将函数访问的数据对象以及访问方式在`ffrt_submit_base()`接口中的`in_deps`和`out_deps`参数表达。
- 程序员通过`in_deps`和`out_deps`参数表达任务间依赖关系以保证程序执行的正确性。

> 做到纯函数的好处在于：1. 能够最大化挖掘并行度，2.避免DataRace和锁的问题。
>
> 在实际中，可以根据场景放松纯函数的约束，但前提是：
>
> - 确定添加的`in_deps`和`out_deps`可确保程序正确执行。
> - 通过FFRT提供的锁机制保护对全局变量的访问。

### 建议2：使用FFRT提供的替代API

- 禁止在FFRT任务中使用系统线程库API创建线程，使用`submit`提交任务。
- 使用FFRT提供的锁，条件变量，睡眠，IO等API代替系统线程库API。
  - 使用系统线程库API可能造成工作线程阻塞，引起额外性能开销。

### 建议3：Deadline机制

- 必须用于具备周期/重复执行特征的处理流程。
- 在有明确时间约束和性能关键的处理流程中使用，避免滥用。
- 在相对大颗粒度的处理流程中使用，例如具有16.6ms时间约束的帧处理流程。

### 建议4：从线程模型迁移

- 创建线程替代为创建FFRT任务。
  - 线程从逻辑上类似无`in_deps`的任务。
- 识别线程间的依赖关系，并将其表达在任务的依赖关系`in_deps`和`out_deps`上。
- 线程内计算过程分解为异步任务调用。
- 通过任务依赖关系和锁机制避免并发任务数据竞争问题。

### 建议5：推荐使用C++接口

- FFRT的C++接口是基于C接口实现，在使用API接口时可以手动添加C++相关头文件后配套使用。

## 约束限制

### 线程局部变量使用约束

FFRT Task中使用线程局部变量存在风险，说明如下：

- 线程局部变量包括C/C++语言提供的`thread_local`定义的变量和使用`pthread_key_create`创建的变量。
- FFRT支持任务调度，任务被调度到哪个线程是随机的，进而使用线程局部变量是有风险的，这一点和所有其他支持任务并发调度的框架一致。
- FFRT的任务默认以协程的方式运行，任务执行过程中可能发生协程退出，恢复执行时，执行该任务的线程可能发生变更。

### 线程绑定使用约束

- FFRT支持任务调度，任务调度到哪个线程是随机的，thread_idx/线程优先级/线程亲和性等与线程绑定的行为禁止在任务中使用。

### 标准库同步原语使用约束

FFRT任务中使用标准库的互斥锁可能发生死锁，需要更换为FFRT提供的互斥锁，说明如下：

- 互斥锁在`lock()`成功时记录调用者“执行栈”作为锁的所有者，在后续`lock()`时会判断调用者是否为当前执行栈，如果是则返回成功，以支持在同一个执行栈中嵌套获取锁。在标准库的实现中，“执行栈”以线程标识表示。
- 在FFRT任务中使用标准库的互斥锁，如果在外层和内层`lock()`之间，发生任务（协程）退出，任务恢复执行时在不同于首次调用`lock()`的FFRT Worker线程上，则判断当前线程不是所有者，`lock()`失败，FFRT Worker线程被挂起，后面的`unlock()`不会被执行，从而出现死锁。

### 对进程`fork()`场景的支持说明

- 在未使用FFRT的进程中，创建子进程，支持在该子进程中使用FFRT。
- 在已经使用FFRT的进程中，单独以`fork()`方式创建子进程，不支持在该子进程中使用FFRT。
- 在已经使用FFRT的进程中，同时以`fork()`和`exec()`方式创建子进程，支持在子进程中使用FFRT。

### 以动态库方式部署FFRT

- 只能以动态库方式部署FFRT，静态库部署可能有多实例问题，例如：当多个被同一进程加载的so都以静态库的方式使用FFRT时，FFRT会被实例化成多份，其行为是未知的，这也不是FFRT设计的初衷。

### 输入输出依赖数量的限制

- 使用`ffrt_submit_base`接口进行任务提交时，每个任务的输入依赖和输出依赖的数量之和不能超过8个。
- 使用`ffrt_submit_h_base`接口进行任务提交时，每个任务的输入依赖和输出依赖的数量之和不能超过7个。
- 参数既作为输入依赖又作为输出依赖的时候，统计依赖数量时只统计一次，如输入依赖是`{&x}`，输出依赖也是`{&x}`，实际依赖的数量是1。

### 进程或者线程退出时的限制

- 进程退出时，FFRT内部的线程池等进程内共享的资源已经释放，禁止调用FFRT任务提交等接口。
- 线程退出时，FFRT内部的thread local资源已经释放，正在退出的线程禁止调用FFRT任务提交等接口。

## 常见反模式

### C API中初始化FFRT对象后，对象的置空与销毁由用户负责

- 为保证较高的性能，FFRT的C API中内部不包含对对象的销毁状态的标记，用户需要合理地进行资源的释放，重复调用各个对象的销毁操作，其结果是未定义的。
- 错误示例1，重复调用销毁函数可能造成不可预知的数据损坏：

    ```cpp
    #include <stdio.h>
    #include "ffrt/cpp/task.h"

    void abnormal_case_1()
    {
        ffrt_task_handle_t h = ffrt_submit_h_base(
            ffrt::create_function_wrapper(std::function<void()>([](){ printf("Test task running...\n"); })),
            NULL, NULL, NULL);
        // ...
        ffrt_task_handle_destroy(h);
        ffrt_task_handle_destroy(h); // 重复释放
    }
    ```

- 错误示例2，未调用销毁函数会造成内存泄漏：

    ```cpp
    #include <stdio.h>
    #include "ffrt/cpp/task.h"

    void abnormal_case_2()
    {
        ffrt_task_handle_t h = ffrt_submit_h_base(
            ffrt::create_function_wrapper(std::function<void()>([](){ printf("Test task running...\n"); })),
            NULL, NULL, NULL);
        // ...
        // 内存泄露
    }
    ```

- 建议示例，仅调用一次销毁函数，如有必要可进行置空：

    ```cpp
    #include <stdio.h>
    #include "ffrt/cpp/task.h"

    void normal_case()
    {
        ffrt_task_handle_t h = ffrt_submit_h_base(
            ffrt::create_function_wrapper(std::function<void()>([](){ printf("Test task running...\n"); })),
            NULL, NULL, NULL);
        // ...
        ffrt_task_handle_destroy(h);
        h = nullptr; // 必要时置空任务句柄变量
    }
    ```

### 变量生命周期错误

- FFRT提交任务中应注意对象或资源在其生命周期内可能出现的误用，这些错误会导致程序崩溃、数据损坏或者难以调试的问题。
- 错误示例1，变量生命周期已结束导致的UAF问题：

    ```cpp
    #include <unistd.h>
    #include "ffrt/cpp/task.h"

    void abnormal_case_3()
    {
        int x = 0;
        ffrt::submit([&] {
            usleep(1000); // 模拟业务处理逻辑
            x++;          // 此时变量生命周期可能已结束，对变量的访问会发生UAF问题
        });
    }
    ```

- 错误示例2，互斥锁生命周期已结束继续使用导致功能异常：

    ```cpp
    #include <unistd.h>
    #include "ffrt/cpp/mutex.h"
    #include "ffrt/cpp/task.h"

    void abnormal_case_4()
    {
        ffrt::mutex lock;
        ffrt::submit([&] {
            lock.lock();   // 对FFRT锁进行操作时，要保证其生命周期
            usleep(1000);  // 模拟业务处理逻辑
            lock.unlock(); // 对FFRT锁进行操作时，要保证其生命周期
        });
    }
    ```

## Using FFRT in DevEco IDE

### Using FFRT C API

NDK（Native Development Kit）是系统提供的Native API的集合，方便开发者使用C或C++语言实现应用的关键功能。

FFRT C API已集成在NDK中，在DevEco IDE中可以直接使用对应的接口。

```c
#include "ffrt/task.h"
#include "ffrt/mutex.h"
#include "ffrt/shared_mutex.h"
#include "ffrt/condition_variable.h"
#include "ffrt/sleep.h"
#include "ffrt/queue.h"
#include "ffrt/loop.h"
#include "ffrt/timer.h"
#include "ffrt/type_def.h"
```

### Using FFRT C++ API

FFRT的部署依赖FFRT动态库`libffrt.so`和一组头文件，其中动态库仅导出C接口，C++接口调用C接口，并基于头文件的方式将API中的C++元素编译到用户的动态库中，从而保证了ABI兼容性。

![image](figures/ffrt_figure7.png)

如果要使用FFRT C++ API，需要使用FFRT C++接口三方库[@ppd/ffrt](https://ohpm.openharmony.cn/#/cn/detail/@ppd%2Fffrt)，该三方库是由FFRT官方维护的FFRT C++ API库。

在模块目录下执行三方库安装命令：

```shell
ohpm install @ppd/ffrt
```

也可以直接在`oh-package.json5`文件中配置对应的依赖，由IDE自动进行三方库下载安装。

在模块`CMakeLists.txt`文件中添加头文件搜索路径和链接依赖：

```cmake
# ${MODULES_PATH}表示三方库安装位置，需要开发者自己定义或者直接替换成绝对路径或者相对路径。
include_directories(${MODULES_PATH}/@ppd/ffrt/include)
target_link_libraries(${TARGET_NAME} PUBLIC libffrt.z.so)
```

至此就可以在代码中使用FFRT C++接口：

```cpp
// include all C or C++ header files
#include "ffrt/ffrt.h"

// include specified header files
#include "ffrt/cpp/task.h"
#include "ffrt/cpp/mutex.h"
#include "ffrt/cpp/shared_mutex.h"
#include "ffrt/cpp/condition_variable.h"
#include "ffrt/cpp/sleep.h"
#include "ffrt/cpp/queue.h"
```
