## FFRT 用户编程指南

> Function Flow编程模型是一种基于任务和数据驱动的并发编程模型，允许开发者通过任务及其依赖关系描述的方式进行应用开发。FFRT（Function Flow运行时）是支持Function Flow编程模型的软件运行时库，用于调度执行开发者基于Function Flow编程模型开发的应用。通过Function Flow编程模型和FFRT，开发者可专注于应用功能开发，由FFRT在运行时根据任务依赖状态和可用执行资源自动并发调度和执行任务。
>
> 本文用于指导开发者基于Function Flow编程模型和FFRT实现并行编程。

<hr/>
# 版本

| 版本 | 编辑                                                         | 主要变更                                                     | 日期       |
| ---- | ------------------------------------------------------------ | ------------------------------------------------------------ | ---------- |
| V0.1 | linjiashu <br />zhangguowei <br />huangyouzhong  | 发布以下API：<br />1. task 管理，包括：submit，wait，task_attr, task_handle/submit_h<br />2. 同步原语，包括：mutex，condition_variable<br />3. Deadline 调度<br />4. 杂项：sleep，yield<br /> | 2022/09/26 |


<br/>

<hr/>

# C API

> C API采用接近C11/pthread (https://zh.cppreference.com/w/c) 的命名风格，并冠以`ffrt_`前缀，以`_base`为后缀的API是内部API，通常不被用户直接调用
>
> **出于易用性方面的考虑，除非必要，强烈建议你使用C++ API(亦满足二进制兼容要求)，调用C API将会使你的代码非常臃肿** 

## 任务管理

### ffrt_submit_base

* 该接口为ffrt动态库的导出接口，基于此可以封装出不同的C++ API ffrt::submit和C API ffrt_submit，满足二进制兼容

#### 声明

```{.cpp}
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

#### 参数

`kind`

* function子类型，用于优化内部数据结构，默认使用ffrt_function_kind_general类型

`func`

* CPU Function的指针，该指针执行的数据结构，按照`ffrt_function_header_t`定义的描述了该CPU Task如何执行和销毁的函数指针，FFRT通过这两个函数指针完成Task的执行和销毁

`in_deps`

* 同ffrt_submit


`out_deps`

* 同ffrt_submit

`attr`

* 同ffrt_submit

#### 返回值

* 不涉及

#### 描述

* ffrt_submit_base不建议用户直接调用，推荐使用基于此封装的C++接口（亦满足二进制兼容）
* **ffrt_submit_base作为底层能力，只有在用户需要自定义task类型时使用，使用时需要满足以下限制：**
  * ffrt_submit_base入参中的func指针只能通过ffrt_alloc_auto_managed_function_storage_base申请，且二者的调用需一一对应
  * ffrt_alloc_auto_managed_function_storage_base申请的内存为ffrt_auto_managed_function_storage_size字节，其生命周期归ffrt管理，在该task结束时，由FFRT自动释放，用户无需释放
* ffrt_function_header_t 中定义了两个函数指针：
  * exec：用于描述该Task如何被执行，当FFRT需要执行该Task时由FFRT调用
  * destroy：用于描述该Task如何被执行，当FFRT需要执行该Task时由FFRT调用



### ffrt_wait

<hr/>
* 同步等待，与ffrt_submit 配合使用
* 等待指定的数据被生产完成，或等待当前任务的所有子任务完成，在不满足条件之前，当前的执行上下文被suspend，在满足条件后恢复执行

#### 声明

```{.cpp}
void ffrt_wait_deps(ffrt_deps_t* deps);
void ffrt_wait();
```

#### 参数

`deps`

* 需要等待被生产完成的数据的虚拟地址，这些地址可能作为某些任务在submit 时的out_deps，该依赖的生成见ffrt_deps_t章节，空指针表示无依赖

#### 返回值

* 不涉及

#### 描述
* ffrt_wait_deps(deps) 用于等待deps指代的数据被生产完成才能执行后面的代码
* ffrt_wait() 用于等待当前上下文提交的所有子任务（`注意：不包括孙任务和下级子任务`）都完成才能执行后面的代码
* 该接口支持在FFRT task 内部调用，也支持在FFRT task 外部调用
* 在FFRT task 外部调用的wait 是OS 能够感知的等待，相对于FFRT task 内部调用的wait 是更加昂贵的，因此我们希望尽可能让更多的wait 发生在FFRT task 内部 ，而不是FFRT task 外部



### ffrt_deps_t

* C API中对依赖数组的抽象，逻辑上等同于C++ API中的`std::vector<void*>`

#### 声明

```{.cpp}
typedef struct {
    uint32_t len;
    const void* const * items;
} ffrt_deps_t;
```

#### 参数

`len`

* 所依赖的Signature的个数，取值大于等于0

`item`

* len个Signature的起始地址指针

#### 返回值

* 不涉及

#### 描述

* item为len个Signature的起始指针，该指针可以指向堆空间，也可以指向栈空间，但是要求分配的空间大于等于len * sizeof(void*)


### ffrt_task_attr_t

<hr/>
* 定义task 的属性的辅助类，与ffrt_submit 配合使用

#### 声明

```{.c}
typedef enum {
    ffrt_qos_inherent = -1,
    ffrt_qos_background,
    ffrt_qos_utility,
    ffrt_qos_default,
    ffrt_qos_user_initiated,
} ffrt_qos_t;

typedef struct {
    char storage[ffrt_task_attr_storage_size];
} ffrt_task_attr_t;
typedef void* ffrt_task_handle_t;

int ffrt_task_attr_init(ffrt_task_attr_t* attr);
void ffrt_task_attr_destroy(ffrt_task_attr_t* attr);
void ffrt_task_attr_set_qos(ffrt_task_attr_t* attr, ffrt_qos_t qos);
ffrt_qos_t ffrt_task_attr_get_qos(const ffrt_task_attr_t* attr);
void ffrt_task_attr_set_name(ffrt_task_attr_t* attr, const char* name);
const char* ffrt_task_attr_get_name(const ffrt_task_attr_t* attr);
```

#### 参数

`attr`

* 创建的tasks属性的句柄

`qos`

* qos 设定的枚举类型
* inherent 是一个qos 设定策略，代表即将ffrt_submit 的task 的qos 继承当前task 的qos

#### 返回值

* 不涉及

#### 描述
* `attr`所传递的内容会在ffrt_submit内部完成取存，ffrt_submit返回后用户即可销毁
* 约定
  * 在submit 时，如果不通过task_attr 设定qos，那么默认该提交的task的qos 为`ffrt_qos_default`
  * 在submit 时，如果通过task_attr 设定qos 为`ffrt_qos_inherent`，表示将该提交的task 的qos 与当前task 的qos 相同，在FFRT task 外部提交的属性为`ffrt_qos_inherent` 的task，其qos 为`ffrt_qos_default`
  * 其他情况下，该提交的task 的qos 被设定为指定的值
* ffrt_task_attr_t对象的置空和销毁由用户完成，对同一个ffrt_task_attr_t仅能调用一次`ffrt_task_attr_destroy`，重复对同一个ffrt_task_attr_t调用`ffrt_task_attr_destroy`，其行为是未定义的
* 在`ffrt_task_attr_destroy`之后再对task_attr进行访问，其行为是未定义的




### ffrt_submit_h

<hr/>

* 向调度器提交一个task，与ffrt_submit 的差别在于返回task 的句柄，该句柄可以用于建立task 之间的依赖，或用于在wait 语句中实现同步

#### 声明

```{.cpp}
typedef void* ffrt_task_handle_t;

ffrt_task_handle_t ffrt_submit_h(ffrt_function_t func, void* arg, const ffrt_deps_t* in_deps, const ffrt_deps_t* out_deps, const ffrt_task_attr_t* attr);
void ffrt_task_handle_destroy(ffrt_task_handle_t handle);
```

#### 参数

`func`

* 同ffrt_submit，详见[ffrt_submit](#ffrt_submit) 定义

`in_deps`

* 同ffrt_submit，详见[ffrt_submit](#ffrt_submit) 定义

`out_deps`

* 同ffrt_submit，详见[ffrt_submit](#ffrt_submit) 定义

`attr`

* 同ffrt_submit，详见[ffrt_submit](#ffrt_submit) 定义

#### 返回值

* task 的句柄，该句柄可以用于建立task 之间的依赖，或用于在wait 语句中实现同步

#### 描述

* C API中的ffrt_task_handle_t的使用与C++ API中的ffrt::task_handle相同
* **差异在于：C API中的ffrt_task_handle_t需要用户调用`ffrt_task_handle_destroy`显式销毁，而C++ API无需该操作**
* C API中的task_handle_t对象的置空和销毁由用户完成，对同一个ffrt_task_handle_t仅能调用一次`ffrt_task_handle_destroy`，重复对同一个ffrt_task_handle_t调用`ffrt_task_handle_destroy`，其行为是未定义的
* 在`ffrt_task_handle_destroy`之后再对ffrt_task_handle_t进行访问，其行为是未定义的




### ffrt_this_task_get_id

<hr/>

* 返回当前task的id标识，更多使用用于维测（原因是task name可能重名）

#### 声明

```{.c}
uint64_t ffrt_this_task_get_id();
```

#### 参数

* 不涉及

#### 返回值

* 当前task的id

#### 描述

* 该接口在task内部调用将返回当前task的id标识，在task外部调用将返回0
* 可以基于该接口在task外部调用返回0的特性来区分函数是运行在FFRT 工作线程上还是非FFRT工作线程上
* task id为从1开始编码，每提交一个task便增加1，被设计成64bit，即便是每秒百万次提交，也需要292471.2年才会发生翻转




### ffrt_this_task_update_qos

<hr/>

* 更新当前正在执行的task的优先级

#### 声明

```{.cpp}
int ffrt_this_task_update_qos(ffrt_qos_t qos);
```

#### 参数

* `qos` 新的优先级

#### 返回值

* 0表示成功，非0表示失败

#### 描述

* 该接口对当前task的qos调整会立即生效
* 如果新设定的qos与当前的qos不一致，则会block当前task的执行，再按照新的qos恢复执行
* 如果新设定的qos与当前的qos一致，则接口会立即返回0，不做任何处理
* **如果在非task内部调用该接口，则返回非0值，用户可以选择忽略或其他处理**


## 串行队列
<hr />
* FFRT提供queue来实现Andorid中类似WorkQueue能力，且在使用得当的情况下将有更好的性能

### ffrt_queue_attr_t

#### 声明
```{.c}
typedef struct {
    uint32_t storage[(ffrt_queue_attr_storage_size + sizeof(uint32_t) - 1) / sizeof(uint32_t)];
} ffrt_queue_attr_t;

int ffrt_queue_attr_init(ffrt_queue_attr_t* attr);
void ffrt_queue_attr_destroy(ffrt_queue_attr_t* attr);
```

### 参数

`attr`
* 该参数是指向未初始化的ffrt_queue_attr_t

### 返回值
* 若成功返回0，否则返回-1

### 描述
* ffrt_queue_attr_t用于创建ffrt_queue_t且不单独使用，因此必须在创建队列前先创建好队列属性
* ffrt_queue_attr_t对象的置空和销毁由用户完成，对同一个ffrt_queue_t仅能调用一次`ffrt_queue_attr_destroy`，重复对同一个ffrt_queue_t调用`ffrt_queue_attr_destroy`，其行为是未定义的
* 在`ffrt_queue_attr_destroy`之后再对ffrt_queue_t进行访问，其行为是未定义的



### ffrt_queue_t

#### 声明
```{.c}
typedef enum { ffrt_queue_serial, ffrt_queue_max } ffrt_queue_type_t;
typedef void* ffrt_queue_t;

ffrt_queue_t ffrt_queue_create(ffrt_queue_type_t type, const char* name, const ffrt_queue_attr_t* attr)
void ffrt_queue_destroy(ffrt_queue_t queue)
```

### 参数

`type`
* 该参数用于描述创建的队列类型

`name`
* 该参数用于描述创建队列的名字

`attr`
* 该参数用于描述queue的属性，详见ffrt_queue_attr_t章节

### 返回值
* 若成功则返回新创建的队列，否则返回空指针

### 描述
* 提交至该队列的任务将按照顺序执行，如果某个提交的任务中发生阻塞，则无法保证该任务的执行顺序
* ffrt_queue_t对象的置空和销毁由用户完成，对同一个ffrt_queue_t仅能调用一次`ffrt_queue_t`，重复对同一个ffrt_queue_t调用`ffrt_queue_destroy`，其行为是未定义的
* 在`ffrt_queue_destroy`之后再对ffrt_queue_t进行访问，其行为是未定义的


## 同步原语

### ffrt_mutex_t
<hr/>
* FFRT提供的类似pthread mutex 的性能实现

#### 声明

```{.cpp}
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

#### 参数

`attr`

* 当前FFRT只支持基础类型的mutex，因此attr必须为空指针

`mutex`

* 指向所操作的互斥锁的指针

#### 返回值

* 若成功则为 ffrt_success ，否则发生错误

#### 描述
* 该接口只能在FFRT task 内部调用，在FFRT task 外部调用存在未定义的行为
* 该功能能够避免pthread传统的pthread_mutex_t 在抢不到锁时陷入内核的问题，在使用得当的条件下将会有更好的性能
* **注意：目前暂不支持递归和定时功能**
* **注意：C API中的ffrt_mutex_t需要用户调用`ffrt_mutex_init`和`ffrt_mutex_destroy`显式创建和销毁，而C++ API无需该操作**
* **注意：C API中的ffrt_mutex_t对象的置空和销毁由用户完成，对同一个ffrt_mutex_t仅能调用一次`ffrt_mutex_destroy`，重复对同一个ffrt_mutex_t调用`ffrt_mutex_destroy`，其行为是未定义的**
* **注意：在`ffrt_mutex_destroy`之后再对ffrt_mutex_t进行访问，其行为是未定义的**




### ffrt_cond_t
<hr/>

* FFRT提供的类似pthread 信号量的性能实现

#### 声明

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
typedef enum {
    ffrt_clock_realtime = CLOCK_REALTIME,
    ffrt_clock_monotonic = CLOCK_MONOTONIC
} ffrt_clockid_t;

int ffrt_condattr_init(ffrt_condattr_t* attr);
int ffrt_condattr_destroy(ffrt_condattr_t* attr);
int ffrt_condattr_setclock(ffrt_condattr_t* attr, ffrt_clockid_t clock);
int ffrt_condattr_getclock(const ffrt_condattr_t* attr, ffrt_clockid_t* clock);

int ffrt_cond_init(ffrt_cond_t* cond, const ffrt_condattr_t* attr);
int ffrt_cond_signal(ffrt_cond_t* cond);
int ffrt_cond_broadcast(ffrt_cond_t* cond);
int ffrt_cond_wait(ffrt_cond_t*cond, ffrt_mutex_t* mutex);
int ffrt_cond_timedwait(ffrt_cond_t* cond, ffrt_mutex_t* mutex, const struct timespec* time_point);
int ffrt_cond_destroy(ffrt_cond_t* cond);
```

#### 参数

`cond`

* 指向所操作的信号量的指针

`attr`

* 属性设定，空指针表示使用默认属性

`mutex`

* 指向要在阻塞期间解锁的互斥锁的指针

`time_point`

* 指向指定等待时限时间的对象的指针


#### 返回值

* 若成功则为 ffrt_success，若在锁定互斥前抵达时限则为 ffrt_error_timedout

#### 描述
* 该接口只能在FFRT task 内部调用，在FFRT task 外部调用存在未定义的行为
* 该功能能够避免传统的pthread_cond_t在条件不满足时陷入内核的问题，在使用得当的条件下将会有更好的性能
* **注意：C API中的ffrt_cond_t需要用户调用`ffrt_cond_init`和`ffrt_cond_destroy`显式创建和销毁，而C++ API中依赖构造和析构自动完成**
* **注意：C API中的ffrt_cond_t对象的置空和销毁由用户完成，对同一个ffrt_cond_t仅能调用一次`ffrt_cond_destroy`，重复对同一个ffrt_cond_t调用`ffrt_cond_destroy`，其行为是未定义的**
* **注意：在`ffrt_cond_destroy`之后再对ffrt_cond_t进行访问，其行为是未定义的**



## 杂项

### ffrt_usleep

<hr/>
* FFRT提供的类似C11 sleep和linux usleep的性能实现

#### 声明

```{.c}
int ffrt_usleep(uint64_t usec);
```

#### 参数

`usec`

* 睡眠的us数

#### 返回值

* 不涉及

#### 描述
* 该接口只能在FFRT task 内部调用，在FFRT task 外部调用存在未定义的行为
* 该功能能够避免传统的sleep 睡眠时陷入内核的问题，在使用得当的条件下将会有更好的性能



### ffrt_yield
<hr/>
* 当前task 主动让出CPU 执行资源，让其他可以被执行的task 先执行，如果没有其他可被执行的task，yield 无效

#### 声明

```{.cpp}
void ffrt_yield();
```

#### 参数

* 不涉及

#### 返回值

* 不涉及

#### 描述
* 该接口只能在FFRT task 内部调用，在FFRT task 外部调用存在未定义的行为
* 此函数的确切行为取决于实现，特别是使用中的FFRT 调度程序的机制和系统状态


  
* **出于易用性方面的考虑，除非必要，强烈建议你使用C++ API，调用C API将会使你的代码非常臃肿或者更容易产生资源未释放问题**


<br/>
<br/>

<hr/>


}
```
