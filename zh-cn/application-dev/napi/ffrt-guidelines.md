# FFRT 开发指导

## 场景介绍

Function Flow编程模型是一种基于任务和数据驱动的并发编程模型，允许开发者通过任务及其依赖关系描述的方式进行应用开发。FFRT（Function Flow运行时）是支持Function Flow编程模型的软件运行时库，用于调度执行开发者基于Function Flow编程模型开发的应用。通过Function Flow编程模型和FFRT，开发者可专注于应用功能开发，由FFRT在运行时根据任务依赖状态和可用执行资源自动并发调度和执行任务。

本文用于指导开发者基于Function Flow编程模型和FFRT实现并行编程。

### 两种编程模型


|                | 线程编程模型                                                 | FFRT任务编程模型                                             |
| -------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| 并行度挖掘方式 | 程序员通过创建多线程并把任务分配到每个线程中执行来挖掘运行时的并行度。 | 程序员（编译器工具或语言特性配合）静态编程时将应用分解成任务及其数据依赖关系，运行时调度器分配任务到工作线程执行。 |
| 谁负责线程创建 | 程序员负责创建线程，线程编程模型无法约束线程的创建，滥用可能造成系统中大量线程。| 由调度器负责工作线程池的创建和管理，程序员无法直接创建线程。 |
| 负载均衡       | 程序员静态编程时将任务映射到线程，映射不合理或任务执行时间不确定造成线程负载不均。 | FFRT运行时根据线程执行状态调度就绪任务到空闲线程执行，减轻了线程负载不均问题。 |
| 调度开销       | 线程调度由内核态调度器完成，调度开销大。                       | FFRT运行时在用户态以协程方式调度执行，相比内核线程调度机制更为轻量，减小调度的开销，并可通过硬化调度卸载进一步减小调度开销。 |
| 依赖表达       | 线程创建时即处于可执行状态，执行时与其他线程同步操作，增加线程切换。 | FFRT运行时根据任务创建时显式表达的输入依赖和输出依赖关系判断任务可执行状态，当输入依赖不满足时，任务不被调度执行。 |

## 基本概念

### Function Flow 任务编程模型

Function Flow编程模型允许开发者通过任务及其依赖关系描述的方式进行应用开发，其主要特性包括`Task-Based` 和 `Data-Driven` 。

#### Task-Based 特性

`Task-Based` 指在Function Flow编程模型中开发者以任务方式来组织应用程序表达，运行时以任务粒度执行调度。

任务定义为一种面向开发者的编程线索和面向运行时的执行对象，通常包含一组指令序列及其操作的数据上下文环境。

Function Flow编程模型中的任务包含以下主要特征：

- 任务之间可指定依赖关系，依赖关系通过`Data-Driven`方式表达。
- 任务可支持嵌套，即任务在执行过程中可生成新的任务下发给运行时，形成父子任务关系。
- 多任务支持互同步操作，例如等待、锁、条件变量等。

> 注意
>
> 任务颗粒度影响应用执行性能，颗粒度过小增加调度开销，颗粒度过大降低并行度。Function Flow编程模型中任务的目标颗粒度最小为100us量级，开发者应注意合理控制任务颗粒度。

#### Data-Driven 特性

`Data-Driven`指任务之间的依赖关系通过数据依赖表达。

任务执行过程中对其关联的数据对象进行读写操作。在Function Flow编程模型中，数据对象表达抽象为数据签名，每个数据签名唯一对应一个数据对象。

数据依赖抽象为任务所操作的数据对象的数据签名列表，包括输入数据依赖`in_deps`和输出数据依赖`out_deps`。数据对象的签名出现在一个任务的`in_deps`中时，该任务称为数据对象的消费者任务，消费者任务执行不改变其输入数据对象的内容；数据对象的签名出现在任务的`out_deps`中时，该任务称为数据对象的生产者任务，生产者任务执行改变其输出数据对象的内容，从而生成该数据对象的一个新的版本。

一个数据对象可能存在多个版本，每个版本对应一个生产者任务和零个，一个或多个消费者任务，根据生产者任务和消费者任务的下发顺序定义数据对象的多个版本的顺序以及每个版本所对应的生产者和消费者任务。

数据依赖解除的任务进入就绪状态允许被调度执行，依赖解除状态指任务所有输入数据对象版本的生产者任务执行完成，且所有输出数据对象版本的所有消费者任务执行完成的状态。

通过上述`Data-Driven`的数据依赖表达，FFRT在运行时可动态构建任务之间的基于生产者/消费者的数据依赖关系并遵循任务数据依赖状态执行调度，包括：

- Producer-Consumer 依赖

  一个数据对象版本的生产者任务和该数据对象版本的消费者任务之间形成的依赖关系，也称为Read-after-Write依赖。

- Consumer-Producer 依赖

  一个数据对象版本的消费者任务和该数据对象的下一个版本的生产者任务之间形成的依赖关系，也称为Write-after-Read依赖。

- Producer-Producer 依赖

  一个数据对象版本的生产者任务和该数据对象的下一个版本的生产者任务之间形成的依赖关系，也称为Write-after-Write依赖。


例如，如果有这么一些任务，与数据A的关系表述为：
```{.c}
task1(OUT A);
task2(IN A);
task3(IN A);
task4(OUT A);
task5(OUT A);
```

<img src="figures/ffrtfigure3.png" style="zoom:40%" />

> 为表述方便，本文中的数据流图均以圆圈表示 Task，方块表示数据。

可以得出以下结论：
- task1 与task2/task3 构成Producer-Consumer 依赖，即：task2/task3 需要等到task1 写完A之后才能读A。
- task2/task3 与task4 构成Consumer-Producer 依赖，即：task4 需要等到task2/task3 读完A之后才能写A。
- task4 与task5 构成Producer-Producer 依赖，即：task5 需要等到task4 写完A之后才能写A。

## 接口说明

| 接口名                                                       | 描述                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| ffrt_condattr_init (ffrt_condattr_t* attr) | 初始化条件变量属性。 |
| ffrt_condattr_destroy(ffrt_condattr_t* attr)  | 销毁条件变量属性。 |
| ffrt_condattr_setclock(ffrt_condattr_t* attr, ffrt_clockid_t clock) | 设置条件变量的时钟属性。 |
| ffrt_condattr_getclock(const ffrt_condattr_t* attr, ffrt_clockid_t* clock)        | 获取条件变量的时钟属性。              |
| ffrt_cond_init(ffrt_cond_t* cond, const ffrt_condattr_t* attr)   | 初始化条件变量。      |
| ffrt_cond_signal(ffrt_cond_t* cond)         | 唤醒阻塞在条件变量上的一个任务。 |
| ffrt_cond_broadcast(ffrt_cond_t* cond) | 唤醒阻塞在条件变量上的所有任务。 |
| ffrt_cond_wait(ffrt_cond_t* cond, ffrt_mutex_t* mutex)            | 条件变量等待函数，条件变量不满足时阻塞当前任务。 |
| ffrt_cond_timedwait(ffrt_cond_t* cond, ffrt_mutex_t* mutex, const struct timespec* time_point)            | 条件变量超时等待函数，条件变量不满足时阻塞当前任务，超时等待返回。 |
| ffrt_cond_destroy(ffrt_cond_t* cond)            | 销毁条件变量。 |
| ffrt_mutex_init(ffrt_mutex_t* mutex, const ffrt_mutexattr_t* attr) | 初始化mutex。 |
| ffrt_mutex_lock(ffrt_mutex_t* mutex)   | 获取mutex。 |
| ffrt_mutex_unlock(ffrt_mutex_t* mutex)  | 释放mutex。 |
| ffrt_mutex_trylock(ffrt_mutex_t* mutex)   | 尝试获取mutex。 |
| ffrt_mutex_destroy(ffrt_mutex_t* mutex)   | 销毁mutex。 |
| ffrt_queue_attr_init(ffrt_queue_attr_t* attr)    | 初始化串行队列属性。 |
| ffrt_queue_attr_destroy(ffrt_queue_attr_t* attr)    | 销毁串行队列属性。 |
| ffrt_queue_attr_set_qos(ffrt_queue_attr_t* attr, ffrt_qos_t qos)    | 设置串行队列qos属性。 |
| ffrt_queue_attr_get_qos(const ffrt_queue_attr_t* attr)      | 获取串行队列qos属性。 |
| ffrt_queue_create(ffrt_queue_type_t type, const char* name, const ffrt_queue_attr_t* attr)   | 创建队列。 |
| ffrt_queue_destroy(ffrt_queue_t queue)   | 销毁队列。 |
| ffrt_queue_submit(ffrt_queue_t queue, ffrt_function_header_t* f, const ffrt_task_attr_t* attr)   | 提交一个任务到队列中调度执行。 |
| ffrt_queue_submit_h(ffrt_queue_t queue, ffrt_function_header_t* f, const ffrt_task_attr_t* attr)  | 提交一个任务到队列中调度执行，并返回任务句柄。 |
| ffrt_queue_wait(ffrt_task_handle_t handle)    | 等待队列中一个任务执行完成。 |
| ffrt_queue_cancel(ffrt_task_handle_t handle)     | 取消队列中一个任务。 |
| ffrt_usleep(uint64_t usec)   | 延迟usec微秒。 |
| ffrt_yield(void)     | 当前任务主动放权，让其他任务有机会调度执行。 |
| ffrt_task_attr_init(ffrt_task_attr_t* attr)     | 初始化任务属性。 |
| ffrt_task_attr_set_name(ffrt_task_attr_t* attr, const char* name)   | 设置任务名字。 |
| ffrt_task_attr_get_name(const ffrt_task_attr_t* attr)   | 获取任务名字。 |
| ffrt_task_attr_destroy(ffrt_task_attr_t* attr)    | 销毁任务属性。 |
| ffrt_task_attr_set_qos(ffrt_task_attr_t* attr, ffrt_qos_t qos)    | 设置任务qos。 |
| ffrt_task_attr_get_qos(const ffrt_task_attr_t* attr)      | 获取任务qos。 |
| ffrt_task_attr_set_delay(ffrt_task_attr_t* attr, uint64_t delay_us)    | 设置任务延迟时间。 |
| ffrt_task_attr_get_delay(const ffrt_task_attr_t* attr)      | 获取任务延迟时间。 |
| ffrt_this_task_update_qos(ffrt_qos_t qos)    | 更新任务qos。 |
| ffrt_this_task_get_id(void)    | 获取任务id。 |
| ffrt_alloc_auto_managed_function_storage_base(ffrt_function_kind_t kind)     | 申请函数执行结构的内存。 |
| ffrt_submit_base(ffrt_function_header_t* f, const ffrt_deps_t* in_deps, const ffrt_deps_t* out_deps, const ffrt_task_attr_t* attr)   | 提交任务调度执行。 |
| ffrt_submit_h_base(ffrt_function_header_t* f, const ffrt_deps_t* in_deps, const ffrt_deps_t* out_deps, const ffrt_task_attr_t* attr)    | 提交任务调度执行并返回任务句柄。 |
| ffrt_task_handle_destroy(ffrt_task_handle_t handle)    | 销毁任务句柄。 |
| ffrt_skip(ffrt_task_handle_t handle)     | 跳过指定任务。 |
| ffrt_wait_deps(const ffrt_deps_t* deps)    | 等待依赖的任务完成，当前任务开始执行。 |



## 函数介绍


### 任务管理

#### ffrt_submit_base

* 该接口为ffrt动态库的导出接口，基于此可以封装出C API ffrt_submit，满足二进制兼容。

##### 声明

```{.c}
const int ffrt_auto_managed_function_storage_size = 64 + sizeof(ffrt_function_header_t);
typedef enum {
    ffrt_function_kind_general,
    ffrt_function_kind_queue
} ffrt_function_kind_t;

void* ffrt_alloc_auto_managed_function_storage_base(ffrt_function_kind_t kind);

typedef void(*ffrt_function_t)(void*);
typedef struct {
    ffrt_function_t exec;
    ffrt_function_t destroy;
    uint64_t reserve[2];
} ffrt_function_header_t;

void ffrt_submit_base(ffrt_function_header_t* func, const ffrt_deps_t* in_deps, const ffrt_deps_t* out_deps, const ffrt_task_attr_t* attr);
```

##### 参数

`kind`

* function子类型，用于优化内部数据结构，默认使用ffrt_function_kind_general类型。

`func`

* CPU Function的指针，该指针执行的数据结构，按照`ffrt_function_header_t`定义的描述了该CPU Task如何执行和销毁的函数指针，FFRT通过这两个函数指针完成Task的执行和销毁。

`in_deps`

* 该参数是可选的。
* 该参数用于描述该任务的输入依赖，FFRT 通过数据的虚拟地址作为数据的Signature 来建立依赖。

`out_deps`

* 该参数是可选的。
* 该参数用于描述该任务的输出依赖。
* `注意`：该依赖值本质上是一个数值，ffrt没办法区分该值是合理的还是不合理的，会假定输入的值是合理的进行处理；但不建议采用NULL，1, 2 等值来建立依赖关系，建议采用实际的内存地址，因为前者使用不当会建立起不必要的依赖，影响并发。

`attr`

* 该参数是可选的。
* 该参数用于描述Task 的属性，比如qos 等，详见 [ffrt_task_attr_t](#ffrt_task_attr_t)章节。

##### 返回值

* 不涉及。

##### 描述
* 建议用户对ffrt_submit_base进行封装后调用，具体可参考样例。
* **ffrt_submit_base作为底层能力，使用时需要满足以下限制：**
  * ffrt_submit_base入参中的func指针只能通过ffrt_alloc_auto_managed_function_storage_base申请，且二者的调用需一一对应。
  * ffrt_alloc_auto_managed_function_storage_base申请的内存为ffrt_auto_managed_function_storage_size字节，其生命周期归ffrt管理，在该task结束时，由FFRT自动释放，用户无需释放。
* ffrt_function_header_t 中定义了两个函数指针：
  * exec：用于描述该Task如何被执行，当FFRT需要执行该Task时由FFRT调用。
  * destroy：用于描述该Task如何被销毁，当FFRT需要销毁该Task时由FFRT调用。

##### 样例


```{.c}
template<class T>
struct function {
    template<class CT>
    function(ffrt_function_header_t h, CT&& c) : header(h), closure(std::forward<CT>(c)) {}
    ffrt_function_header_t header;
    T closure;
};

template<class T>
void exec_function_wrapper(void* t)
{
    auto f = (function<std::decay_t<T>>*)t;
    f->closure();
}

template<class T>
void destroy_function_wrapper(void* t)
{
    auto f = (function<std::decay_t<T>>*)t;
    f->closure = nullptr;
}

template<class T>
inline ffrt_function_header_t* create_function_wrapper(T&& func)
{
    using function_type = function<std::decay_t<T>>;
    static_assert(sizeof(function_type) <= ffrt_auto_managed_function_storage_size,
        "size of function must be less than ffrt_auto_managed_function_storage_size");

    auto p = ffrt_alloc_auto_managed_function_storage_base(ffrt_function_kind_general);
    auto f = new (p) function_type(
        {exec_function_wrapper<T>, destroy_function_wrapper<T>},
        std::forward<T>(func));
    return (ffrt_function_header_t*)f;
}

static inline void submit(std::function<void()>&& func)
{
    return ffrt_submit_base(create_function_wrapper(std::move(func)), NULL, NULL, NULL);
}
```

#### ffrt_wait

<hr/>
* 同步等待，与ffrt_submit_base 配合使用。
* 等待指定的数据被生产完成，或等待当前任务的所有子任务完成，在不满足条件之前，当前的执行上下文被suspend，在满足条件后恢复执行。

##### 声明

```{.c}
void ffrt_wait_deps(ffrt_deps_t* deps);
void ffrt_wait();
```

##### 参数

`deps`

* 需要等待被生产完成的数据的虚拟地址，这些地址可能作为某些任务在submit 时的out_deps，该依赖的生成见ffrt_deps_t章节，空指针表示无依赖。

##### 返回值

* 不涉及。

##### 描述
* ffrt_wait_deps(deps) 用于等待deps指代的数据被生产完成才能执行后面的代码。
* ffrt_wait() 用于等待当前上下文提交的所有子任务（`注意：不包括孙任务和下级子任务`）都完成才能执行后面的代码。
* 该接口支持在FFRT task 内部调用，也支持在FFRT task 外部调用。
* 在FFRT task 外部调用的wait 是OS 能够感知的等待，相对于FFRT task 内部调用的wait 是更加昂贵的，因此我们希望尽可能让更多的wait 发生在FFRT task 内部 ，而不是FFRT task 外部。

##### 样例

**recursive fibonacci**

串行版的fibonacci 可以实现为：

```{.c}
#include <stdio.h>

void fib(int x, int* y) {
    if (x <= 1) {
        *y = x;
    } else {
        int y1, y2;
        fib(x - 1, &y1);
        fib(x - 2, &y2);
        *y = y1 + y2;
    }
}
int main(int narg, char** argv)
{
    int r;
    fib(10, &r);
    printf("fibonacci 10: %d\n", r);
    return 0;
}
```

若要使用 FFRT 实现并行（注，对于单纯的fibonacci，单个 Task 的计算量极小，不具有并行加速的意义，但这种调用pattern 对并行编程模型的灵活性考验是非常高的），其中1种可行的实现为：

```{.c}
#include <stdio.h>
#include "ffrt.h"  //包含所有ffrt涉及的头文件

typedef struct {
    int x;
    int* y;
} fib_ffrt_s;

typedef struct {
    ffrt_function_header_t header;
    ffrt_function_t func;
    ffrt_function_t after_func;
    void* arg;
} c_function;

static void ffrt_exec_function_wrapper(void* t)
{
    c_function* f = (c_function*)t;
    if (f->func) {
        f->func(f->arg);
    }
}

static void ffrt_destroy_function_wrapper(void* t)
{
    c_function* f = (c_function*)t;
    if (f->after_func) {
        f->after_func(f->arg);
    }
}

#define FFRT_STATIC_ASSERT(cond, msg) int x(int static_assertion_##msg[(cond) ? 1 : -1])
static inline ffrt_function_header_t* ffrt_create_function_wrapper(const ffrt_function_t func,
    const ffrt_function_t after_func, void* arg)
{
    FFRT_STATIC_ASSERT(sizeof(c_function) <= ffrt_auto_managed_function_storage_size,
        size_of_function_must_be_less_than_ffrt_auto_managed_function_storage_size);
    c_function* f = (c_function*)ffrt_alloc_auto_managed_function_storage_base(ffrt_function_kind_general);
    f->header.exec = ffrt_exec_function_wrapper;
    f->header.destroy = ffrt_destroy_function_wrapper;
    f->func = func;
    f->after_func = after_func;
    f->arg = arg;
    return (ffrt_function_header_t*)f;
}

static inline void ffrt_submit_c(ffrt_function_t func, const ffrt_function_t after_func,
    void* arg, const ffrt_deps_t* in_deps, const ffrt_deps_t* out_deps, const ffrt_task_attr_t* attr)
{
    ffrt_submit_base(ffrt_create_function_wrapper(func, after_func, arg), in_deps, out_deps, attr);
}

void fib_ffrt(void* arg)
{
    fib_ffrt_s* p = (fib_ffrt_s*)arg;
    int x = p->x;
    int* y = p->y;

    if (x <= 1) {
        *y = x;
    } else {
        int y1, y2;
        fib_ffrt_s s1 = {x - 1, &y1};
        fib_ffrt_s s2 = {x - 2, &y2};
        const std::vector<ffrt_dependence_t> dx_deps = {{ffrt_dependence_data, &x}};
        ffrt_deps_t dx{static_cast<uint32_t>(dx_deps.size()), dx_deps.data()};
        const std::vector<ffrt_dependence_t> dy1_deps = {{ffrt_dependence_data, &y1}};
        ffrt_deps_t dy1{static_cast<uint32_t>(dy1_deps.size()), dy1_deps.data()};
        const std::vector<ffrt_dependence_t> dy2_deps = {{ffrt_dependence_data, &y2}};
        ffrt_deps_t dy2{static_cast<uint32_t>(dy2_deps.size()), dy2_deps.data()};
        const std::vector<ffrt_dependence_t> dy12_deps = {{ffrt_dependence_data, &y1}, {ffrt_dependence_data, &y2}};
        ffrt_deps_t dy12{static_cast<uint32_t>(dy12_deps.size()), dy12_deps.data()};
        ffrt_submit_c(fib_ffrt, NULL, &s1, &dx, &dy1, NULL);
        ffrt_submit_c(fib_ffrt, NULL, &s2, &dx, &dy2, NULL);
        ffrt_wait_deps(&dy12);
        *y = y1 + y2;
    }
}

int main(int narg, char** argv)
{
    int r;
    fib_ffrt_s s = {10, &r};
    const std::vector<ffrt_dependence_t> dr_deps = {{ffrt_dependence_data, &r}};
    ffrt_deps_t dr{static_cast<uint32_t>(dr_deps.size()), dr_deps.data()};
    ffrt_submit_c(fib_ffrt, NULL, &s, NULL, &dr, NULL);
    ffrt_wait_deps(&dr);
    printf("fibonacci 10: %d\n", r);
    return 0;
}
```

`解析`：

1)   将fibonacci (x-1)和fibonacci (x-2) 作为2个Task 提交给FFRT，在两个Task 完成之后将结果累加；

2)   虽然单个Task 只能拆分成2个SubTask 但是子Task 可以继续拆分，因此，整个计算图的并行度是非常高的，Task 之间在FFRT 内部形成了一颗调用树；

<img src="figures/ffrtfigure2.png" style="zoom:100%" />

> 以上实现，因为需要用户显式管理数据生命周期和函数入参打包两个因素，所以使得代码实现异常复杂。



#### ffrt_deps_t

* C API中对依赖数组的抽象，逻辑上等同于C++ API中的`std::vector<void*>`

##### 声明

```{.c}
typedef enum {
    ffrt_dependence_data,
    ffrt_dependence_task,
} ffrt_dependence_type_t;

typedef struct {
    ffrt_dependence_type_t type;
    const void* ptr;
} ffrt_dependence_t;

typedef struct {
    uint32_t len;
    const ffrt_dependence_t* items;
} ffrt_deps_t;
```

##### 参数

`len`

* 所依赖的Signature的个数，取值大于等于0。

`item`

* len个Signature的起始地址指针。

`type`

* 当前依赖为数据依赖还是任务依赖。

`ptr`

* 所依赖对应Signature内容的实际地址。

##### 返回值

* 不涉及。

##### 描述

* item为len个Signature的起始指针，该指针可以指向堆空间，也可以指向栈空间，但是要求分配的空间大于等于len * sizeof(ffrt_dependence_t)。

##### 样例

* 创建数据依赖或者任务依赖：

```{.c}
// 创建数据依赖的ffrt_deps_t
int x = 0;
const std::vector<ffrt_dependence_t> in_deps = {{ffrt_dependence_data, &x}};
ffrt_deps_t in{static_cast<uint32_t>(in_deps.size()), in_deps.data()};

// 提交某个返回handle任务
ffrt_task_handle_t task = ffrt_submit_h_base(
        ffrt_create_function_wrapper(OnePlusForTest, NULL, &a), NULL, NULL, &attr);
// 创建任务依赖的ffrt_deps_t
const std::vector<ffrt_dependence_t> wait_deps = {{ffrt_dependence_task, task}};
ffrt_deps_t wait{static_cast<uint32_t>(wait_deps.size()), wait_deps.data()};
```

#### ffrt_task_attr_t

<hr/>
* 定义task 的属性的辅助类，与ffrt_submit_base 配合使用。

##### 声明

```{.c}
typedef enum {
    ffrt_qos_inherent = -1,
    ffrt_qos_background,
    ffrt_qos_utility,
    ffrt_qos_default,
    ffrt_qos_user_initiated,
} ffrt_qos_default_t;

typedef int ffrt_qos_t;

typedef struct {
    uint32_t storage[(ffrt_task_attr_storage_size + sizeof(uint32_t) - 1) / sizeof(uint32_t)];
} ffrt_task_attr_t;
typedef void* ffrt_task_handle_t;

int ffrt_task_attr_init(ffrt_task_attr_t* attr);
void ffrt_task_attr_destroy(ffrt_task_attr_t* attr);
void ffrt_task_attr_set_qos(ffrt_task_attr_t* attr, ffrt_qos_t qos);
ffrt_qos_t ffrt_task_attr_get_qos(const ffrt_task_attr_t* attr);
void ffrt_task_attr_set_name(ffrt_task_attr_t* attr, const char* name);
const char* ffrt_task_attr_get_name(const ffrt_task_attr_t* attr);
void ffrt_task_attr_set_delay(ffrt_task_attr_t* attr, uint64_t delay_us);
uint64_t ffrt_task_attr_get_delay(const ffrt_task_attr_t* attr);
```

##### 参数

`attr`

* 创建的tasks属性的句柄。

`qos`

* qos 设定的枚举类型。
* inherent 是一个qos 设定策略，代表即将ffrt_submit 的task 的qos 继承当前task 的qos。

`delay_us`

* 任务延迟执行的时间，单位为us。

##### 返回值

* 不涉及。

##### 描述
* `attr`所传递的内容会在ffrt_submit内部完成取存，ffrt_submit返回后用户即可销毁。
* 约定：
  * 在submit 时，如果不通过task_attr 设定qos，那么默认该提交的task的qos 为`ffrt_qos_default`。
  * 在submit 时，如果通过task_attr 设定qos 为`ffrt_qos_inherent`，表示将该提交的task 的qos 与当前task 的qos 相同，在FFRT task 外部提交的属性为`ffrt_qos_inherent` 的task，其qos 为`ffrt_qos_default`。
  * 其他情况下，该提交的task 的qos 被设定为指定的值。
* ffrt_task_attr_t对象的置空和销毁由用户完成，对同一个ffrt_task_attr_t仅能调用一次`ffrt_task_attr_destroy`，重复对同一个ffrt_task_attr_t调用`ffrt_task_attr_destroy`，其行为是未定义的。
* 在`ffrt_task_attr_destroy`之后再对task_attr进行访问，其行为是未定义的。

##### 样例

* 提交一个qos 级别为background 的任务：

```{.c}
#include <stdio.h>
#include "ffrt.h"

void my_print(void* arg)
{
    printf("hello ffrt\n");
}

typedef struct {
    ffrt_function_header_t header;
    ffrt_function_t func;
    ffrt_function_t after_func;
    void* arg;
} c_function;

static void ffrt_exec_function_wrapper(void* t)
{
    c_function* f = (c_function*)t;
    if (f->func) {
        f->func(f->arg);
    }
}

static void ffrt_destroy_function_wrapper(void* t)
{
    c_function* f = (c_function*)t;
    if (f->after_func) {
        f->after_func(f->arg);
    }
}

#define FFRT_STATIC_ASSERT(cond, msg) int x(int static_assertion_##msg[(cond) ? 1 : -1])
static inline ffrt_function_header_t* ffrt_create_function_wrapper(const ffrt_function_t func,
    const ffrt_function_t after_func, void* arg)
{
    FFRT_STATIC_ASSERT(sizeof(c_function) <= ffrt_auto_managed_function_storage_size,
        size_of_function_must_be_less_than_ffrt_auto_managed_function_storage_size);
    c_function* f = (c_function*)ffrt_alloc_auto_managed_function_storage_base(ffrt_function_kind_general);
    f->header.exec = ffrt_exec_function_wrapper;
    f->header.destroy = ffrt_destroy_function_wrapper;
    f->func = func;
    f->after_func = after_func;
    f->arg = arg;
    return (ffrt_function_header_t*)f;
}

static inline void ffrt_submit_c(ffrt_function_t func, const ffrt_function_t after_func,
    void* arg, const ffrt_deps_t* in_deps, const ffrt_deps_t* out_deps, const ffrt_task_attr_t* attr)
{
    ffrt_submit_base(ffrt_create_function_wrapper(func, after_func, arg), in_deps, out_deps, attr);
}

int main(int narg, char** argv)
{
    ffrt_task_attr_t attr;
    ffrt_task_attr_init(&attr);
    ffrt_task_attr_set_qos(&attr, ffrt_qos_background);
    ffrt_task_attr_set_delay(&attr, 10000);
    ffrt_submit_c(my_print, NULL, NULL, NULL, NULL, &attr);
    ffrt_task_attr_destroy(&attr);
    ffrt_wait();
    return 0;
}
```




#### ffrt_submit_h_base

<hr/>

* 向调度器提交一个task，与ffrt_submit_base 的差别在于返回task 的句柄，该句柄可以用于建立task 之间的依赖，或用于在wait 语句中实现同步。

##### 声明

```{.c}
typedef void* ffrt_task_handle_t;

ffrt_task_handle_t ffrt_submit_h_base(ffrt_function_t func, void* arg, const ffrt_deps_t* in_deps, const ffrt_deps_t* out_deps, const ffrt_task_attr_t* attr);
void ffrt_task_handle_destroy(ffrt_task_handle_t handle);
```

##### 参数

`func`

* CPU Function的指针，该指针执行的数据结构，按照`ffrt_function_header_t`定义的描述了该CPU Task如何执行和销毁的函数指针，FFRT通过这两个函数指针完成Task的执行和销毁。

`in_deps`

* 该参数是可选的。
* 该参数用于描述该任务的输入依赖，FFRT 通过数据的虚拟地址作为数据的Signature 来建立依赖。

`out_deps`

* 该参数是可选的。
* 该参数用于描述该任务的输出依赖。
* `注意`：该依赖值本质上是一个数值，ffrt没办法区分该值是合理的还是不合理的，会假定输入的值是合理的进行处理；但不建议采用NULL，1, 2 等值来建立依赖关系，建议采用实际的内存地址，因为前者使用不当会建立起不必要的依赖，影响并发。

`attr`

* 该参数是可选的。
* 该参数用于描述Task 的属性，比如qos 等，详见 [ffrt_task_attr_t](#ffrt_task_attr_t)章节。

##### 返回值

* task 的句柄，该句柄可以用于建立task 之间的依赖，或用于在wait 语句中实现同步。

##### 描述

* **C API中的ffrt_task_handle_t需要用户调用`ffrt_task_handle_destroy`显式销毁。**
* C API中的task_handle_t对象的置空和销毁由用户完成，对同一个ffrt_task_handle_t仅能调用一次`ffrt_task_handle_destroy`，重复对同一个ffrt_task_handle_t调用`ffrt_task_handle_destroy`，其行为是未定义的。
* 在`ffrt_task_handle_destroy`之后再对ffrt_task_handle_t进行访问，其行为是未定义的。

##### 样例

```{.c}
#include <stdio.h>
#include "ffrt.h"

void func0(void* arg)
{
    printf("hello ");
}

void func1(void* arg)
{
    (*(int*)arg)++;
}

void func2(void* arg)
{
    printf("world, x = %d\n", *(int*)arg);
}

void func3(void* arg)
{
    printf("handle wait");
    (*(int*)arg)++;
}

typedef struct {
    ffrt_function_header_t header;
    ffrt_function_t func;
    ffrt_function_t after_func;
    void* arg;
} c_function;

static void ffrt_exec_function_wrapper(void* t)
{
    c_function* f = (c_function*)t;
    if (f->func) {
        f->func(f->arg);
    }
}

static void ffrt_destroy_function_wrapper(void* t)
{
    c_function* f = (c_function*)t;
    if (f->after_func) {
        f->after_func(f->arg);
    }
}

#define FFRT_STATIC_ASSERT(cond, msg) int x(int static_assertion_##msg[(cond) ? 1 : -1])
static inline ffrt_function_header_t* ffrt_create_function_wrapper(const ffrt_function_t func,
    const ffrt_function_t after_func, void* arg)
{
    FFRT_STATIC_ASSERT(sizeof(c_function) <= ffrt_auto_managed_function_storage_size,
        size_of_function_must_be_less_than_ffrt_auto_managed_function_storage_size);
    c_function* f = (c_function*)ffrt_alloc_auto_managed_function_storage_base(ffrt_function_kind_general);
    f->header.exec = ffrt_exec_function_wrapper;
    f->header.destroy = ffrt_destroy_function_wrapper;
    f->func = func;
    f->after_func = after_func;
    f->arg = arg;
    return (ffrt_function_header_t*)f;
}

static inline ffrt_task_handle_t ffrt_submit_h_c(ffrt_function_t func, const ffrt_function_t after_func,
    void* arg, const ffrt_deps_t* in_deps, const ffrt_deps_t* out_deps, const ffrt_task_attr_t* attr)
{
    return ffrt_submit_h_base(ffrt_create_function_wrapper(func, after_func, arg), in_deps, out_deps, attr);
}

static inline void ffrt_submit_c(ffrt_function_t func, const ffrt_function_t after_func,
    void* arg, const ffrt_deps_t* in_deps, const ffrt_deps_t* out_deps, const ffrt_task_attr_t* attr)
{
    ffrt_submit_base(ffrt_create_function_wrapper(func, after_func, arg), in_deps, out_deps, attr);
}


int main(int narg, char** argv)
{  
    // handle work with submit
    ffrt_task_handle_t h = ffrt_submit_h_c(func0, NULL, NULL, NULL, NULL, NULL); // not need some data in this task
    int x = 1;
    const std::vector<ffrt_dependence_t> in_deps = {{ffrt_dependence_data, &x}};
    ffrt_deps_t d2{static_cast<uint32_t>(in_deps.size()), in_deps.data()};

    const std::vector<ffrt_dependence_t> out_deps = {{ffrt_dependence_data, &x}};
    ffrt_deps_t d1{static_cast<uint32_t>(out_deps.size()), out_deps.data()};

    ffrt_submit_c(func1, NULL, &x, NULL, &d1, NULL);
    ffrt_submit_c(func2, NULL, &x, &d2, NULL, NULL); // this task depend x and h
    ffrt_task_handle_destroy(h);
    
    // handle work with wait
    ffrt_task_handle_t h2 = ffrt_submit_h_c(func3, NULL, &x, NULL, NULL, NULL);

    const std::vector<ffrt_dependence_t> wait_deps = {{ffrt_dependence_task, h2}};
    ffrt_deps_t d3{static_cast<uint32_t>(wait_deps.size()), wait_deps.data()};
    ffrt_wait_deps(&d3);
    ffrt_task_handle_destroy(h2);
    printf("x = %d", x);
    ffrt_wait();
    return 0;
}
```

* 预期的输出为：

```
hello 
handle wait
x = 2
world, x = 3
```



#### ffrt_this_task_get_id

<hr/>

* 返回当前task的id标识，更多使用用于维测（原因是task name可能重名）。

##### 声明

```{.c}
uint64_t ffrt_this_task_get_id();
```

##### 参数

* 不涉及。

##### 返回值

* 当前task的id。

##### 描述

* 该接口在task内部调用将返回当前task的id标识，在task外部调用将返回0。
* 可以基于该接口在task外部调用返回0的特性来区分函数是运行在FFRT 工作线程上还是非FFRT工作线程上。
* task id为从1开始编码，每提交一个task便增加1，被设计成64bit，即便是每秒百万次提交，也需要292471.2年才会发生翻转。

##### 样例

* 忽略。



#### ffrt_this_task_update_qos

<hr/>

* 更新当前正在执行的task的优先级。

##### 声明

```{.c}
int ffrt_this_task_update_qos(ffrt_qos_t qos);
```

##### 参数

* `qos` 新的优先级。

##### 返回值

* 0表示成功，非0表示失败。

##### 描述

* 该接口对当前task的qos调整会立即生效。
* 如果新设定的qos与当前的qos不一致，则会block当前task的执行，再按照新的qos恢复执行。
* 如果新设定的qos与当前的qos一致，则接口会立即返回0，不做任何处理。
* **如果在非task内部调用该接口，则返回非0值，用户可以选择忽略或其他处理。**

##### 样例

* 忽略。

### 串行队列
<hr />
* FFRT提供queue来实现Andorid中类似WorkQueue能力，且在使用得当的情况下将有更好的性能。

#### ffrt_queue_attr_t

##### 声明
```{.c}
typedef struct {
    uint32_t storage[(ffrt_queue_attr_storage_size + sizeof(uint32_t) - 1) / sizeof(uint32_t)];
} ffrt_queue_attr_t;

int ffrt_queue_attr_init(ffrt_queue_attr_t* attr);
void ffrt_queue_attr_destroy(ffrt_queue_attr_t* attr);
```

##### 参数

`attr`
* 该参数是指向未初始化的ffrt_queue_attr_t。

##### 返回值
* 若成功返回0，否则返回-1。

##### 描述
* ffrt_queue_attr_t用于创建ffrt_queue_t且不单独使用，因此必须在创建队列前先创建好队列属性。
* ffrt_queue_attr_t对象的置空和销毁由用户完成，对同一个ffrt_queue_attr_t仅能调用一次`ffrt_queue_attr_destroy`，重复对同一个ffrt_queue_attr_t调用`ffrt_queue_attr_destroy`，其行为是未定义的。
* 在`ffrt_queue_attr_destroy`之后再对ffrt_queue_attr_t进行访问，其行为是未定义的。

##### 样例
参考ffrt_queue_t章节的样例。

#### ffrt_queue_t

##### 声明
```{.c}
typedef enum { ffrt_queue_serial, ffrt_queue_max } ffrt_queue_type_t;
typedef void* ffrt_queue_t;

ffrt_queue_t ffrt_queue_create(ffrt_queue_type_t type, const char* name, const ffrt_queue_attr_t* attr)
void ffrt_queue_destroy(ffrt_queue_t queue)
```

##### 参数

`type`
* 该参数用于描述创建的队列类型。

`name`
* 该参数用于描述创建队列的名字。

`attr`
* 该参数用于描述queue的属性，详见ffrt_queue_attr_t章节。

##### 返回值
* 若成功则返回新创建的队列，否则返回空指针。

##### 描述
* 提交至该队列的任务将按照顺序执行，如果某个提交的任务中发生阻塞，则无法保证该任务的执行顺序。
* ffrt_queue_t对象的置空和销毁由用户完成，对同一个ffrt_queue_t仅能调用一次`ffrt_queue_destroy`，重复对同一个ffrt_queue_t调用`ffrt_queue_destroy`，其行为是未定义的。
* 在`ffrt_queue_destroy`之后再对ffrt_queue_t进行访问，其行为是未定义的。

##### 样例
```
#include <stdio.h>
#include "ffrt.h"

using namespace std;

template<class T>
struct Function {
    ffrt_function_header_t header;
    T closure;
};

template<class T>
void ExecFunctionWrapper(void* t)
{
    auto f = reinterpret_cast<Function<std::decay_t<T>>*>(t);
    f->closure();
}

template<class T>
void DestroyFunctionWrapper(void* t)
{
    auto f = reinterpret_cast<Function<std::decay_t<T>>*>(t);
    f = nullptr;
}

template<class T>
static inline ffrt_function_header_t* create_function_wrapper(T&& func,
    ffrt_function_kind_t kind = ffrt_function_kind_general)
{
    using function_type = Function<std::decay_t<T>>;
    auto p = ffrt_alloc_auto_managed_function_storage_base(kind);
    auto f = new (p)function_type;
    f->header.exec = ExecFunctionWrapper<T>;
    f->header.destroy = DestroyFunctionWrapper<T>;
    f->closure = std::forward<T>(func);
    return reinterpret_cast<ffrt_function_header_t*>(f);
}

int main(int narg, char** argv)
{
    ffrt_queue_attr_t queue_attr;
    (void)ffrt_queue_attr_init(&queue_attr);
    ffrt_queue_t queue_handle = ffrt_queue_create(ffrt_queue_serial, "test_queue", &queue_attr);
    std::function<void()>&& queueFunc = [] () {printf("Task done.\n");};
    ffrt_function_header_t* queueFunc_t = create_function_wrapper((queueFunc), ffrt_function_kind_queue);
    ffrt_queue_submit(queue_handle, queueFunc_t, nullptr);

    ffrt_queue_attr_destroy(&queue_attr);
    ffrt_queue_destroy(queue_handle);
}
```
### 同步原语

#### ffrt_mutex_t
<hr/>
* FFRT提供的类似pthread mutex 的性能实现。

##### 声明

```{.c}
typedef enum {
    ffrt_error = -1,
    ffrt_success = 0,
    ffrt_error_nomem = ENOMEM,
    ffrt_error_timedout = ETIMEDOUT,
    ffrt_error_busy = EBUSY,
    ffrt_error_inval = EINVAL
} ffrt_error_t;

struct ffrt_mutex_t;

int ffrt_mutex_init(ffrt_mutex_t* mutex, const ffrt_mutexattr_t* attr);
int ffrt_mutex_lock(ffrt_mutex_t* mutex);
int ffrt_mutex_unlock(ffrt_mutex_t* mutex);
int ffrt_mutex_trylock(ffrt_mutex_t* mutex);
int ffrt_mutex_destroy(ffrt_mutex_t* mutex);
```

##### 参数

`attr`

* 当前FFRT只支持基础类型的mutex，因此attr必须为空指针。

`mutex`

* 指向所操作的互斥锁的指针。

##### 返回值

* 若成功则为 ffrt_success ，否则发生错误。

##### 描述
* 该接口只能在FFRT task 内部调用，在FFRT task 外部调用存在未定义的行为。
* 该功能能够避免pthread传统的pthread_mutex_t 在抢不到锁时陷入内核的问题，在使用得当的条件下将会有更好的性能。
* **注意：目前暂不支持递归和定时功能。**
* **注意：C API中的ffrt_mutex_t需要用户调用`ffrt_mutex_init`和`ffrt_mutex_destroy`显式创建和销毁。**
* **注意：C API中的ffrt_mutex_t对象的置空和销毁由用户完成，对同一个ffrt_mutex_t仅能调用一次`ffrt_mutex_destroy`，重复对同一个ffrt_mutex_t调用`ffrt_mutex_destroy`，其行为是未定义的。**
* **注意：在`ffrt_mutex_destroy`之后再对ffrt_mutex_t进行访问，其行为是未定义的。**

##### 样例

```{.c}
#include <stdio.h>
#include "ffrt.h"

typedef struct {
    int* sum;
    ffrt_mutex_t* mtx;
} tuple;

void func(void* arg)
{
    tuple* t = (tuple*)arg;
    
    int ret = ffrt_mutex_lock(t->mtx);
    if (ret != ffrt_success) {
        printf("error\n");
    }
    (*t->sum)++;
    ret = ffrt_mutex_unlock(t->mtx);
    if (ret != ffrt_success) {
        printf("error\n");
    }
}

typedef struct {
    ffrt_function_header_t header;
    ffrt_function_t func;
    ffrt_function_t after_func;
    void* arg;
} c_function;

static void ffrt_exec_function_wrapper(void* t)
{
    c_function* f = (c_function*)t;
    if (f->func) {
        f->func(f->arg);
    }
}

static void ffrt_destroy_function_wrapper(void* t)
{
    c_function* f = (c_function*)t;
    if (f->after_func) {
        f->after_func(f->arg);
    }
}

#define FFRT_STATIC_ASSERT(cond, msg) int x(int static_assertion_##msg[(cond) ? 1 : -1])
static inline ffrt_function_header_t* ffrt_create_function_wrapper(const ffrt_function_t func,
    const ffrt_function_t after_func, void* arg)
{
    FFRT_STATIC_ASSERT(sizeof(c_function) <= ffrt_auto_managed_function_storage_size,
        size_of_function_must_be_less_than_ffrt_auto_managed_function_storage_size);
    c_function* f = (c_function*)ffrt_alloc_auto_managed_function_storage_base(ffrt_function_kind_general);
    f->header.exec = ffrt_exec_function_wrapper;
    f->header.destroy = ffrt_destroy_function_wrapper;
    f->func = func;
    f->after_func = after_func;
    f->arg = arg;
    return (ffrt_function_header_t*)f;
}

static inline void ffrt_submit_c(ffrt_function_t func, const ffrt_function_t after_func,
    void* arg, const ffrt_deps_t* in_deps, const ffrt_deps_t* out_deps, const ffrt_task_attr_t* attr)
{
    ffrt_submit_base(ffrt_create_function_wrapper(func, after_func, arg), in_deps, out_deps, attr);
}

void ffrt_mutex_task(void *)
{
    int sum = 0;
    ffrt_mutex_t mtx;
    tuple t = {&sum, &mtx};
    int ret = ffrt_mutex_init(&mtx, NULL);
    if (ret != ffrt_success) {
        printf("error\n");
    }
    for (int i = 0; i < 10; i++) {
        ffrt_submit_c(func, NULL, &t, NULL, NULL, NULL);
    }
    ffrt_mutex_destroy(&mtx);
    ffrt_wait();
    printf("sum = %d\n", sum);
}

int main(int narg, char** argv)
{
    int r;
    ffrt_submit_c(ffrt_mutex_task, NULL, NULL, NULL, NULL, NULL);
    ffrt_wait();
    return 0;
}
```

预期输出为：

```
sum=10
```

* 该例子为功能示例，实际中并不鼓励这样使用。


#### ffrt_cond_t
<hr/>

* FFRT提供的类似pthread 信号量的性能实现。

##### 声明

```{.c}
typedef enum {
    ffrt_error = -1,
    ffrt_success = 0,
    ffrt_error_nomem = ENOMEM,
    ffrt_error_timedout = ETIMEDOUT,
    ffrt_error_busy = EBUSY,
    ffrt_error_inval = EINVAL
} ffrt_error_t;

struct ffrt_cond_t;

int ffrt_cond_init(ffrt_cond_t* cond, const ffrt_condattr_t* attr);
int ffrt_cond_signal(ffrt_cond_t* cond);
int ffrt_cond_broadcast(ffrt_cond_t* cond);
int ffrt_cond_wait(ffrt_cond_t*cond, ffrt_mutex_t* mutex);
int ffrt_cond_timedwait(ffrt_cond_t* cond, ffrt_mutex_t* mutex, const struct timespec* time_point);
int ffrt_cond_destroy(ffrt_cond_t* cond);
```

##### 参数

`cond`

* 指向所操作的信号量的指针。

`attr`

* 属性设定，空指针表示使用默认属性。

`mutex`

* 指向要在阻塞期间解锁的互斥锁的指针。

`time_point`

* 指向指定等待时限时间的对象的指针。


##### 返回值

* 若成功则为 ffrt_success，若在锁定互斥前抵达时限则为 ffrt_error_timedout。

##### 描述
* 该接口只能在FFRT task 内部调用，在FFRT task 外部调用存在未定义的行为。
* 该功能能够避免传统的pthread_cond_t在条件不满足时陷入内核的问题，在使用得当的条件下将会有更好的性能。
* **注意：C API中的ffrt_cond_t需要用户调用`ffrt_cond_init`和`ffrt_cond_destroy`显式创建和销毁。**
* **注意：C API中的ffrt_cond_t对象的置空和销毁由用户完成，对同一个ffrt_cond_t仅能调用一次`ffrt_cond_destroy`，重复对同一个ffrt_cond_t调用`ffrt_cond_destroy`，其行为是未定义的。**
* **注意：在`ffrt_cond_destroy`之后再对ffrt_cond_t进行访问，其行为是未定义的。**

##### 样例

```{.c}
#include <stdio.h>
#include "ffrt.h"

typedef struct {
    ffrt_cond_t* cond;
    int* a;
    ffrt_mutex_t* lock_;
} tuple;

void func1(void* arg)
{
    tuple* t = (tuple*)arg;
    int ret = ffrt_mutex_lock(t->lock_);
    if (ret != ffrt_success) {
        printf("error\n");
    }
    while (*t->a != 1) {
        ret = ffrt_cond_wait(t->cond, t->lock_);
        if (ret != ffrt_success) {
            printf("error\n");
        }
    }
    ret = ffrt_mutex_unlock(t->lock_);
    if (ret != ffrt_success) {
        printf("error\n");
    }
    printf("a = %d\n", *(t->a));
}

void func2(void* arg)
{
    tuple* t = (tuple*)arg;
    int ret = ffrt_mutex_lock(t->lock_);
    if (ret != ffrt_success) {
        printf("error\n");
    }
    *(t->a) = 1;
    ret = ffrt_cond_signal(t->cond);
    if (ret != ffrt_success) {
        printf("error\n");
    }
    ret = ffrt_mutex_unlock(t->lock_);
    if (ret != ffrt_success) {
        printf("error\n");
    }
}

typedef struct {
    ffrt_function_header_t header;
    ffrt_function_t func;
    ffrt_function_t after_func;
    void* arg;
} c_function;

static void ffrt_exec_function_wrapper(void* t)
{
    c_function* f = (c_function*)t;
    if (f->func) {
        f->func(f->arg);
    }
}

static void ffrt_destroy_function_wrapper(void* t)
{
    c_function* f = (c_function*)t;
    if (f->after_func) {
        f->after_func(f->arg);
    }
}

#define FFRT_STATIC_ASSERT(cond, msg) int x(int static_assertion_##msg[(cond) ? 1 : -1])
static inline ffrt_function_header_t* ffrt_create_function_wrapper(const ffrt_function_t func,
    const ffrt_function_t after_func, void* arg)
{
    FFRT_STATIC_ASSERT(sizeof(c_function) <= ffrt_auto_managed_function_storage_size,
        size_of_function_must_be_less_than_ffrt_auto_managed_function_storage_size);
    c_function* f = (c_function*)ffrt_alloc_auto_managed_function_storage_base(ffrt_function_kind_general);
    f->header.exec = ffrt_exec_function_wrapper;
    f->header.destroy = ffrt_destroy_function_wrapper;
    f->func = func;
    f->after_func = after_func;
    f->arg = arg;
    return (ffrt_function_header_t*)f;
}

static inline void ffrt_submit_c(ffrt_function_t func, const ffrt_function_t after_func,
    void* arg, const ffrt_deps_t* in_deps, const ffrt_deps_t* out_deps, const ffrt_task_attr_t* attr)
{
    ffrt_submit_base(ffrt_create_function_wrapper(func, after_func, arg), in_deps, out_deps, attr);
}

void ffrt_cv_task(void *)
{
    ffrt_cond_t cond;
    int ret = ffrt_cond_init(&cond, NULL);
    if (ret != ffrt_success) {
        printf("error\n");
    }
    int a = 0;
    ffrt_mutex_t lock_;
    tuple t = {&cond, &a, &lock_};
    ret = ffrt_mutex_init(&lock_, NULL);
    if (ret != ffrt_success) {
        printf("error\n");
    }
    ffrt_submit_c(func1, NULL, &t, NULL, NULL, NULL);
    ffrt_submit_c(func2, NULL, &t, NULL, NULL, NULL);
    ffrt_wait();
    ffrt_cond_destroy(&cond);
    ffrt_mutex_destroy(&lock_);
}

int main(int narg, char** argv)
{
    ffrt_submit_c(ffrt_cv_task, NULL, NULL, NULL, NULL, NULL);
    ffrt_wait();
    return 0;
}
```

预期输出为：

```
a=1
```

* 该例子为功能示例，实际中并不鼓励这样使用。

### 杂项

#### ffrt_usleep

<hr/>
* FFRT提供的类似C11 sleep和linux usleep的性能实现。

##### 声明

```{.c}
int ffrt_usleep(uint64_t usec);
```

##### 参数

`usec`

* 睡眠的us数。

##### 返回值

* 不涉及。

##### 描述
* 该接口只能在FFRT task 内部调用，在FFRT task 外部调用存在未定义的行为。
* 该功能能够避免传统的sleep 睡眠时陷入内核的问题，在使用得当的条件下将会有更好的性能。

##### 样例

```{.c}
#include <time.h>
#include <stdio.h>
#include "ffrt.h"

void func(void* arg)
{
    time_t current_time = time(NULL);
    printf("Time: %s", ctime(&current_time));
    ffrt_usleep(2000000); // 睡眠 2 秒
    current_time = time(NULL);
    printf("Time: %s", ctime(&current_time));
}

typedef struct {
    ffrt_function_header_t header;
    ffrt_function_t func;
    ffrt_function_t after_func;
    void* arg;
} c_function;

static void ffrt_exec_function_wrapper(void* t)
{
    c_function* f = (c_function*)t;
    if (f->func) {
        f->func(f->arg);
    }
}

static void ffrt_destroy_function_wrapper(void* t)
{
    c_function* f = (c_function*)t;
    if (f->after_func) {
        f->after_func(f->arg);
    }
}

#define FFRT_STATIC_ASSERT(cond, msg) int x(int static_assertion_##msg[(cond) ? 1 : -1])
static inline ffrt_function_header_t* ffrt_create_function_wrapper(const ffrt_function_t func,
    const ffrt_function_t after_func, void* arg)
{
    FFRT_STATIC_ASSERT(sizeof(c_function) <= ffrt_auto_managed_function_storage_size,
        size_of_function_must_be_less_than_ffrt_auto_managed_function_storage_size);
    c_function* f = (c_function*)ffrt_alloc_auto_managed_function_storage_base(ffrt_function_kind_general);
    f->header.exec = ffrt_exec_function_wrapper;
    f->header.destroy = ffrt_destroy_function_wrapper;
    f->func = func;
    f->after_func = after_func;
    f->arg = arg;
    return (ffrt_function_header_t*)f;
}

static inline void ffrt_submit_c(ffrt_function_t func, const ffrt_function_t after_func,
    void* arg, const ffrt_deps_t* in_deps, const ffrt_deps_t* out_deps, const ffrt_task_attr_t* attr)
{
    ffrt_submit_base(ffrt_create_function_wrapper(func, after_func, arg), in_deps, out_deps, attr);
}

int main(int narg, char** argv)
{
    ffrt_submit_c(func, NULL, NULL, NULL, NULL, NULL);
    ffrt_wait();
    return 0;
}
```

一种输出情况为：

```
Time: Tue Aug 13 15:45:30 2024
Time: Tue Aug 13 15:45:32 2024
```

#### ffrt_yield
<hr/>
* 当前task 主动让出CPU 执行资源，让其他可以被执行的task 先执行，如果没有其他可被执行的task，yield 无效。

##### 声明

```{.c}
void ffrt_yield();
```

##### 参数

* 不涉及。

##### 返回值

* 不涉及。

##### 描述
* 该接口只能在FFRT task 内部调用，在FFRT task 外部调用存在未定义的行为。
* 此函数的确切行为取决于实现，特别是使用中的FFRT 调度程序的机制和系统状态。

##### 样例

* 省略。


## 开发步骤

以下步骤描述了如何使用`FFRT`提供的Native API接口，创建并行任务和串行队列任务以及销毁相应资源。

**添加动态链接库**

CMakeLists.txt中添加以下lib：
```txt
libffrt.z.so
```

**头文件**
```c++
#include "ffrt/task.h"
#include "ffrt/type_def.h"
#include "ffrt/condition_variable.h"
#include "ffrt/mutex.h"
#include "ffrt/queue.h"
#include "ffrt/sleep.h"
```

1. **首先需要对执行的函数进行封装**。
    ```c++
    // 第一种使用模板，支持C++
    template<class T>
    struct Function {
        ffrt_function_header_t header;
        T closure;
    };

    template<class T>
    void ExecFunctionWrapper(void* t)
    {
        auto f = reinterpret_cast<Function<std::decay_t<T>>*>(t);
        f->closure();
    }

    template<class T>
    void DestroyFunctionWrapper(void* t)
    {
        auto f = reinterpret_cast<Function<std::decay_t<T>>*>(t);
        f->closure = nullptr;
    }

    template<class T>
    static inline ffrt_function_header_t* create_function_wrapper(T&& func,
        ffrt_function_kind_t kind = ffrt_function_kind_general)
    {
        using function_type = Function<std::decay_t<T>>;
        auto p = ffrt_alloc_auto_managed_function_storage_base(kind);
        auto f = new (p)function_type;
        f->header.exec = ExecFunctionWrapper<T>;
        f->header.destroy = DestroyFunctionWrapper<T>;
        f->closure = std::forward<T>(func);
        return reinterpret_cast<ffrt_function_header_t*>(f);
    }

    // 第二种创建方式
    typedef struct {
        ffrt_function_header_t header;
        ffrt_function_t func;
        ffrt_function_t after_func;
        void* arg;
    } CFunction;

    static void FfrtExecFunctionWrapper(void* t)
    {
        CFunction* f = static_cast<CFunction*>(t);
        if (f->func) {
            f->func(f->arg);
        }
    }

    static void FfrtDestroyFunctionWrapper(void* t)
    {
        CFunction* f = static_cast<CFunction*>(t);
        if (f->after_func) {
            f->after_func(f->arg);
        }
    }

    #define FFRT_STATIC_ASSERT(cond, msg) int x(int static_assertion_##msg[(cond) ? 1 : -1])
    static inline ffrt_function_header_t* ffrt_create_function_wrapper(const ffrt_function_t func,
        const ffrt_function_t after_func, void* arg, ffrt_function_kind_t kind_t = ffrt_function_kind_general)
    {
        FFRT_STATIC_ASSERT(sizeof(CFunction) <= ffrt_auto_managed_function_storage_size,
            size_of_function_must_be_less_than_ffrt_auto_managed_function_storage_size);
        CFunction* f = static_cast<CFunction*>(ffrt_alloc_auto_managed_function_storage_base(kind_t));
        f->header.exec = FfrtExecFunctionWrapper;
        f->header.destroy = FfrtDestroyFunctionWrapper;
        f->func = func;
        f->after_func = after_func;
        f->arg = arg;
        return reinterpret_cast<ffrt_function_header_t*>(f);
    }

    // 样例：待提交执行的函数
    void OnePlusForTest(void* arg)
    {
        (*static_cast<int*>(arg)) += 1;
    }
    ```
   
2. **设置task属性值**。

    用户提交任务时可以设置任务属性，包括qos优先级，名称等，具体可参考接口文档。
    ```c++
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

    // 如有需要，设置指定优先级
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

3. **提交任务**。
    ```c++
    int a = 0;
    // ******并行任务******
    // 提交不带handle返回值的并行任务
    ffrt_submit_base(ffrt_create_function_wrapper(OnePlusForTest, NULL, &a), NULL, NULL, &attr);
    // 提交带handle返回值的并行任务
    ffrt_task_handle_t task = ffrt_submit_h_base(
        ffrt_create_function_wrapper(OnePlusForTest, NULL, &a), NULL, NULL, &attr);

    // ******串行任务******
    // 提交不返回handle的串行队列任务
    ffrt_queue_submit(queue_handle, ffrt_create_function_wrapper(OnePlusForTest, nullptr, &a,
        ffrt_function_kind_queue), nullptr);
    // 提交带handle的串行队列任务
    ffrt_task_handle_t handle = ffrt_queue_submit_h(queue_handle,
        ffrt_create_function_wrapper(OnePlusForTest, nullptr, &a, ffrt_function_kind_queue), nullptr);

    // 如果需要等待执行结果，则调用wait
    const std::vector<ffrt_dependence_t> wait_deps = {{ffrt_dependence_task, task}};
    ffrt_deps_t wait{static_cast<uint32_t>(wait_deps.size()), wait_deps.data()};
    ffrt_wait_deps(&wait);

    ffrt_queue_wait(handle);
    ```

4. **任务提交完成后销毁相应资源**。
    ```c++
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

### 建议1: 函数化

**基本思想：计算过程函数化**

* 程序过程各步骤以函数封装表达，函数满足类纯函数特性。
* 无全局数据访问。
* 无内部状态保留。
* 通过ffrt_submit_base()接口以异步任务方式提交函数执行。
* 将函数访问的数据对象以及访问方式在ffrt_submit_base()接口中的in_deps/out_deps参数表达。
* 程序员通过inDeps/outDeps参数表达任务间依赖关系以保证程序执行的正确性。

> 做到纯函数的好处在于：1. 能够最大化挖掘并行度，2.避免DataRace和锁的问题。



**在实际中，可以根据场景放松纯函数的约束，但前提是：**

* 确定添加的in_deps/out_deps可确保程序正确执行。
* 通过FFRT提供的锁机制保护对全局变量的访问。


### 建议2: 使用FFRT提供的替代API

* 禁止在FFRT任务中使用系统线程库API创建线程，使用submit提交任务。
* 使用FFRT提供的锁，条件变量，睡眠，IO等API代替系统线程库API。
  * 使用系统线程库API可能造成工作线程阻塞，引起额外性能开销。



### 建议3: Deadline机制

* **必须用于具备周期/重复执行特征的处理流程。**
* 在有明确时间约束和性能关键的处理流程中使用，避免滥用。
* 在相对大颗粒度的处理流程中使用，例如具有16.6ms时间约束的帧处理流程。



### 建议4: 从线程模型迁移

* 创建线程替代为创建FFRT任务。
  * 线程从逻辑上类似无in_deps的任务。
* 识别线程间的依赖关系，并将其表达在任务的依赖关系in_deps/out_deps上。
* 线程内计算过程分解为异步任务调用。
* 通过任务依赖关系和锁机制避免并发任务数据竞争问题。



## 已知限制


### C API中初始化ffrt对象后，对象的置空与销毁由用户负责

* 为保证较高的性能，ffrt的C API中内部不包含对对象的销毁状态的标记，用户需要合理地进行资源的释放，重复调用各个对象的destroy操作，其结果是未定义的。
* 错误示例1，重复调用destroy可能造成不可预知的数据损坏。

```{.c}
#include "ffrt.h"
void abnormal_case_1()
{
    ffrt_task_handle_t h = ffrt_submit_h_base([](){printf("Test task running...\n");}, NULL, NULL, NULL, NULL, NULL);
    ...
    ffrt_task_handle_destroy(h);
    ffrt_task_handle_destroy(h); // double free
}
```

* 错误示例2，未调用destroy会造成内存泄漏

```{.c}
#include "ffrt.h"
void abnormal_case_2()
{
    ffrt_task_handle_t h = ffrt_submit_h_base([](){printf("Test task running...\n");}, NULL, NULL, NULL, NULL, NULL);
    ...
    // memory leak
}
```

* 建议示例，仅调用一次destroy，如有必要可进行置空

```{.c}
#include "ffrt.h"
void normal_case()
{
    ffrt_task_handle_t h = ffrt_submit_h_base([](){printf("Test task running...\n");}, NULL, NULL, NULL, NULL, NULL);
    ...
    ffrt_task_handle_destroy(h);
    h = nullptr; // if necessary
}
```
