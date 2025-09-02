# Function Flow Runtime C API

<!--Kit: Function Flow Runtime Kit-->
<!--Subsystem: Resourceschedule-->
<!--Owner: @chuchihtung; @yanleo-->
<!--Designer: @geoffrey_guo; @huangyouzhong-->
<!--Tester: @lotsof; @sunxuhao-->
<!--Adviser: @foryourself-->

## 任务管理

### ffrt_deps_t

**声明**

```c
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

**参数**

- `len`：数据依赖个数。
- `items`：数据依赖数组，数据长度等于`len`。
- `ptr`：数据地址。
- `type`：区分数据和`task_handle`。

**描述**

`ffrt_dependence_t`作用等同C++的`dependence`，`ffrt_deps_t`作用等同C++的`std::vector<dependence>`。

**样例**

```c
// 创建数据依赖
int x = 0;
ffrt_dependence_t data_dependence[1];
data_dependence[0].type = ffrt_dependence_data;
data_dependence[0].ptr = &x;
ffrt_deps_t data_deps;
data_deps.len = 1;
data_deps.items = data_dependence;

// 创建任务依赖
ffrt_task_handle_t task = ffrt_submit_h_base(user_function_header, NULL, NULL, &attr);
ffrt_dependence_t task_dependence[1];
task_dependence[0].type = ffrt_dependence_task;
task_dependence[0].ptr = task;
ffrt_deps_t task_deps;
task_deps.len = 1;
task_deps.items = task_dependence;
```

### ffrt_task_attr_t

**声明**

```c
typedef struct {
    uint32_t storage[(ffrt_task_attr_storage_size + sizeof(uint32_t) - 1) / sizeof(uint32_t)];
} ffrt_task_attr_t;
```

**描述**

任务的属性描述，在提交普通任务或者队列任务时，可以通过`ffrt_task_attr_t`来配置其属性。

**方法**

**ffrt_task_attr_init**

```c
FFRT_C_API int ffrt_task_attr_init(ffrt_task_attr_t* attr);
```

参数

- `attr`：`ffrt_task_attr_t`对象指针。

返回值

- 0表示成功，-1表示失败。

描述

- 初始化一个`ffrt_task_attr_t`对象。

**ffrt_task_attr_destroy**

```c
FFRT_C_API void ffrt_task_attr_destroy(ffrt_task_attr_t* attr);
```

参数

- `attr`：`ffrt_task_attr_t`对象指针。

描述

- 销毁一个`ffrt_task_attr_t`对象。

**ffrt_task_attr_set_name**

```c
FFRT_C_API void ffrt_task_attr_set_name(ffrt_task_attr_t* attr, const char* name);
```

参数

- `attr`：`ffrt_task_attr_t`对象指针。
- `name`：任务的名称。

描述

- 设置任务的名称，名称是用于维测信息打印的一种有效信息。

**ffrt_task_attr_get_name**

```c
FFRT_C_API const char* ffrt_task_attr_get_name(const ffrt_task_attr_t* attr);
```

参数

- `attr`：`ffrt_task_attr_t`对象指针。

返回值

- 任务的名称。

描述

- 获取设置的任务名称。

**ffrt_task_attr_set_qos**

```c
FFRT_C_API void ffrt_task_attr_set_qos(ffrt_task_attr_t* attr, ffrt_qos_t qos);
```

参数

- `attr`：`ffrt_task_attr_t`对象指针。
- `qos`：QoS等级。

描述

- 设置任务的QoS等级，QoS等级影响任务执行时的系统资源供给。不设置QoS的情况下，队列任务默认继承队列的QoS等级，普通任务默认设置为`ffrt_qos_default`。

**ffrt_task_attr_get_qos**

```c
FFRT_C_API ffrt_qos_t ffrt_task_attr_get_qos(const ffrt_task_attr_t* attr);
```

参数

- `attr`：`ffrt_task_attr_t`对象指针。

返回值

- QoS等级。

描述

- 获取设置的QoS等级。

**ffrt_task_attr_set_delay**

```c
FFRT_C_API void ffrt_task_attr_set_delay(ffrt_task_attr_t* attr, uint64_t delay_us);
```

参数

- `attr`：`ffrt_task_attr_t`对象指针。
- `delay_us`：调度时延，单位为微秒。

描述

- 设置任务的调度时延，任务会在时延间隔之后才调度执行。不设置的情况下，默认时延为零。

**ffrt_task_attr_get_delay**

```c
FFRT_C_API uint64_t ffrt_task_attr_get_delay(const ffrt_task_attr_t* attr);
```

参数

- `attr`：`ffrt_task_attr_t`对象指针。

返回值

- 调度时延。

描述

- 获取设置的调度时延。

**ffrt_task_attr_set_queue_priority**

```c
FFRT_C_API void ffrt_task_attr_set_queue_priority(ffrt_task_attr_t* attr, ffrt_queue_priority_t priority);
```

参数

- `attr`：`ffrt_task_attr_t`对象指针。
- `priority`：任务优先级。

描述

- 设置任务的优先级，目前仅并发队列任务支持优先级功能，同一个并发队列中按照优先级顺序来调度任务。不设置的情况下，任务默认优先级`ffrt_queue_priority_low`。

**ffrt_task_attr_get_queue_priority**

```c
FFRT_C_API ffrt_queue_priority_t ffrt_task_attr_get_queue_priority(const ffrt_task_attr_t* attr);
```

参数

- `attr`：`ffrt_task_attr_t`对象指针。

返回值

- 任务优先级。

描述

- 获取设置的优先级。

**ffrt_task_attr_set_stack_size**

```c
FFRT_C_API void ffrt_task_attr_set_stack_size(ffrt_task_attr_t* attr, uint64_t size);
```

参数

- `attr`：`ffrt_task_attr_t`对象指针。
- `size`：协程栈大小，单位为字节。

描述

- 设置任务的协程栈大小，影响任务执行过程中最大的调用栈使用空间上限。在不设置的情况下，默认的协程栈大小为1MB。

**ffrt_task_attr_get_stack_size**

```c
FFRT_C_API uint64_t ffrt_task_attr_get_stack_size(const ffrt_task_attr_t* attr);
```

参数

- `attr`：`ffrt_task_attr_t`对象指针。

返回值

- 协程栈大小。

描述

- 获取设置的协程栈大小。

**样例**

```c
// 提交一个普通任务，其名称为"sample_task"，QoS等级为background，调度时延为1ms，协程栈大小为2MB
ffrt_task_attr_t attr;
ffrt_task_attr_init(&attr);
ffrt_task_attr_set_name(&attr, "sample_task");
ffrt_task_attr_set_qos(&attr, ffrt_qos_background);
ffrt_task_attr_set_delay(&attr, 1000);
ffrt_task_attr_set_stack_size(&attr, 2 * 1024 * 1024);
ffrt_submit_base(user_function_header, NULL, NULL, &attr);
ffrt_task_attr_destroy(&attr);
```

### ffrt_alloc_auto_managed_function_storage_base

**声明**

```c
typedef enum {
    ffrt_function_kind_general,
    ffrt_function_kind_queue,
} ffrt_function_kind_t;

typedef void(*ffrt_function_t)(void*);
typedef struct {
    ffrt_function_t exec;
    ffrt_function_t destroy;
    uint64_t reserve[2];
} ffrt_function_header_t;

FFRT_C_API void *ffrt_alloc_auto_managed_function_storage_base(ffrt_function_kind_t kind);
```

**参数**

- `kind`：提交普通任务选择`ffrt_function_kind_general`，提交队列任务选择`ffrt_function_kind_queue`。
- `exec`：任务实际执行调用的函数指针。
- `destroy`：任务完成后调用的函数指针，可用于资源清理等用途。
- `reserve`：内部预留空间，用户请勿使用该成员。

**返回值**

- 返回存储用户任务执行体的指针。

**描述**

分配了一块内存空间，内存空间头部为`ffrt_function_header_t`结构体（返回指针可转换为`ffrt_function_header_t*`指针使用）。头部后留有64字节的可用空间，用户可自定义使用该空间，通常用于入参或返回值的存储。

**样例**

- 样例1：生成一个不带参数和返回值的任务执行体：

    ```c
    #include <stdio.h>
    #include "ffrt/task.h"

    void foo(void* data)
    {
        printf("foo\n");
    }

    void after_foo(void* data)
    {
        printf("after_foo\n");
    }

    int main()
    {
        ffrt_function_header_t* func = (ffrt_function_header_t*)ffrt_alloc_auto_managed_function_storage_base(ffrt_function_kind_general);

        func->exec = foo;
        func->destroy = after_foo;

        ffrt_submit_base(func, NULL, NULL, NULL);
        ffrt_wait();

        return 0;
    }
    ```

- 样例2：生成一个带参数和返回值的任务执行体：

    ```c
    #include <stdio.h>
    #include "ffrt/task.h"

    int foo(int x, int y)
    {
        printf("foo: x = %d, y = %d\n", x, y);
        return x + y;
    }

    void after_foo(void* data)
    {
        printf("after_foo\n");
    }

    // 用户自定义任务执行体，可携带参数和返回值
    typedef struct {
        ffrt_function_header_t header; // 头部内存为ffrt_function_header_t
        int arg1; // 参数1
        int arg2; // 参数2
        int ret; // 返回值
    } user_defined_function;

    // 将foo包装成void(*)(void*)的exec函数类型
    void exec_func_wrapper(void* header)
    {
        user_defined_function* func = (user_defined_function*)header;
        func->ret = foo(func->arg1, func->arg2); // 内部展开真正的foo函数，传递参数，获取返回值
    }

    int main()
    {
        user_defined_function* func = (user_defined_function*)ffrt_alloc_auto_managed_function_storage_base(ffrt_function_kind_general);

        func->header.exec = exec_func_wrapper;
        func->header.destroy = after_foo;
        func->arg1 = 1;
        func->arg2 = 2;

        ffrt_submit_base((ffrt_function_header_t*)func, NULL, NULL, NULL);
        ffrt_wait();

        printf("ret = %d\n", func->ret);
        return 0;
    }
    ```

### ffrt_submit_base

**声明**

```c
FFRT_C_API void ffrt_submit_base(ffrt_function_header_t* f, const ffrt_deps_t* in_deps, const ffrt_deps_t* out_deps, const ffrt_task_attr_t* attr);
```

**参数**

- `f`：用户的任务执行体，可以是原生的`ffrt_function_header_t`类型，也可以基于`ffrt_function_header_t`自定义拓展类型。
- `in_deps`：任务的输入数据依赖。输入数据依赖通常以实际数据的地址表达，也支持`ffrt_task_handle_t`作为一种特殊输入依赖。
- `out_deps`：任务的输出数据依赖。输出数据依赖通常以实际数据的地址表达，不支持`ffrt_task_handle_t`。
- `attr`：任务的属性设置。

**描述**

提交一个普通任务，任务支持相关属性设置，在输入依赖解除后任务可调度执行，任务执行完成后解除输出依赖。

**样例**

- 样例1：提交带属性的任务：

    ```c
    #include <stdio.h>
    #include "ffrt/task.h"

    void foo(void* data)
    {
        printf("foo\n");
    }

    void after_foo(void* data)
    {
        printf("after_foo\n");
    }

    int main()
    {
        // 提交一个任务
        ffrt_function_header_t* func = (ffrt_function_header_t*)ffrt_alloc_auto_managed_function_storage_base(ffrt_function_kind_general);
        func->exec = foo;
        func->destroy = after_foo;
        ffrt_submit_base(func, NULL, NULL, NULL);

        // 提交一个带属性的任务
        ffrt_task_attr_t attr;
        ffrt_task_attr_init(&attr);
        ffrt_task_attr_set_name(&attr, "sample_task");
        ffrt_task_attr_set_qos(&attr, ffrt_qos_background);
        ffrt_submit_base(func, NULL, NULL, &attr);

        return 0;
    }
    ```

- 样例2：提交带数据依赖的任务：

    ```c
    // 提交两个带数据依赖的任务，任务间存在Read-After-Write依赖关系
    #include <math.h>
    #include <stdio.h>
    #include "ffrt/task.h"

    void cos_func(float* x, float* y)
    {
        *y = cos(*x);
    }

    void tan_func(float* y, float* z)
    {
        *z = tan(*y);
    }

    typedef struct {
        ffrt_function_header_t header;
        float* arg1; // 参数1
        float* arg2; // 参数2
    } user_defined_function;

    void cos_func_wrapper(void* header)
    {
        user_defined_function* func = (user_defined_function*)header;
        cos_func(func->arg1, func->arg2);
    }

    void tan_func_wrapper(void* header)
    {
        user_defined_function* func = (user_defined_function*)header;
        tan_func(func->arg1, func->arg2);
    }

    void destroy(void* header) {}

    int main()
    {
        float x = 0.5f, y, z;

        user_defined_function* func1 = (user_defined_function*)ffrt_alloc_auto_managed_function_storage_base(ffrt_function_kind_general);
        func1->header.exec = cos_func_wrapper;
        func1->header.destroy = destroy;
        func1->arg1 = &x;
        func1->arg2 = &y;

        user_defined_function* func2 = (user_defined_function*)ffrt_alloc_auto_managed_function_storage_base(ffrt_function_kind_general);
        func2->header.exec = tan_func_wrapper;
        func2->header.destroy = destroy;
        func2->arg1 = &y;
        func2->arg2 = &z;

        ffrt_dependence_t dependence_x[1];
        dependence_x[0].type = ffrt_dependence_data;
        dependence_x[0].ptr = &x;
        ffrt_deps_t deps_x;
        deps_x.len = 1;
        deps_x.items = dependence_x;
        ffrt_dependence_t dependence_y[1];
        dependence_y[0].type = ffrt_dependence_data;
        dependence_y[0].ptr = &y;
        ffrt_deps_t deps_y;
        deps_y.len = 1;
        deps_y.items = dependence_y;
        ffrt_dependence_t dependence_z[1];
        dependence_z[0].type = ffrt_dependence_data;
        dependence_z[0].ptr = &z;
        ffrt_deps_t deps_z;
        deps_z.len = 1;
        deps_z.items = dependence_z;

        ffrt_submit_base((ffrt_function_header_t*)func1, &deps_x, &deps_y, NULL);
        ffrt_submit_base((ffrt_function_header_t*)func2, &deps_y, &deps_z, NULL);

        ffrt_wait();
        printf("x = %f, y = %f, z = %f\n", x, y, z);
        return 0;
    }
    ```

### ffrt_submit_f

**声明**

```c
FFRT_C_API void ffrt_submit_f(ffrt_function_t func, void* arg, const ffrt_deps_t* in_deps, const ffrt_deps_t* out_deps, const ffrt_task_attr_t* attr);
```

**参数**

- `func`：指定的任务函数。
- `arg`：传递给任务函数的参数。
- `in_deps`：任务的输入数据依赖。输入数据依赖通常以实际数据的地址表达，也支持`ffrt_task_handle_t`作为一种特殊输入依赖。
- `out_deps`：任务的输出数据依赖。输出数据依赖通常以实际数据的地址表达，不支持`ffrt_task_handle_t`。
- `attr`：任务的属性设置。

**描述**

`ffrt_submit_f`接口是`ffrt_submit_base`接口的简化包装形式。当任务不需要销毁回调函数时，接口内部将任务函数及其参数包装成通用任务结构，再调用`ffrt_submit_base`接口提交任务。

**样例**

```cpp
#include <stdio.h>
#include "ffrt/task.h"

// 待提交执行的函数
void OnePlusForTest(void* arg)
{
    (*static_cast<int*>(arg)) += 1;
}

int main()
{
    int a = 0;
    ffrt_submit_f(OnePlusForTest, &a, NULL, NULL, NULL);

    ffrt_wait();

    printf("a = %d\n", a);
    return 0;
}
```

### ffrt_submit_h_base

**声明**

```c
typedef void* ffrt_task_handle_t;

FFRT_C_API ffrt_task_handle_t ffrt_submit_h_base(ffrt_function_header_t* f, const ffrt_deps_t* in_deps, const ffrt_deps_t* out_deps, const ffrt_task_attr_t* attr);
```

**参数**

- `f`：用户的任务执行体，可以是原生的`ffrt_function_header_t`类型，也可以基于`ffrt_function_header_t`自定义拓展类型。
- `in_deps`：任务的输入数据依赖。输入数据依赖通常以实际数据的地址表达，也支持`ffrt_task_handle_t`作为一种特殊输入依赖。
- `out_deps`：任务的输出数据依赖。输出数据依赖通常以实际数据的地址表达，不支持`ffrt_task_handle_t`。
- `attr`：任务的属性设置。

**返回值**

- `ffrt_task_handle_t`任务的句柄。

**描述**

相比于`ffrt_submit_base`接口，增加了任务句柄的返回值。

**样例**

```c
// 提交一个任务，获取任务句柄
ffrt_function_header_t* func = (ffrt_function_header_t*)ffrt_alloc_auto_managed_function_storage_base(ffrt_function_kind_general);
func->exec = foo;
func->destroy = after_foo;
ffrt_task_handle_t t = ffrt_submit_h_base(func, NULL, NULL, NULL);
// 注意C API的ffrt_task_handle_t需要用户调用ffrt_task_handle_destroy显式销毁
ffrt_task_handle_destroy(t);
```

### ffrt_submit_h_f

**声明**

```c
typedef void* ffrt_task_handle_t;

FFRT_C_API ffrt_task_handle_t ffrt_submit_h_f(ffrt_function_t func, void* arg, const ffrt_deps_t* in_deps, const ffrt_deps_t* out_deps, const ffrt_task_attr_t* attr);
```

**参数**

- `func`：指定的任务函数。
- `arg`：传递给任务函数的参数。
- `in_deps`：任务的输入数据依赖。输入数据依赖通常以实际数据的地址表达，也支持`ffrt_task_handle_t`作为一种特殊输入依赖。
- `out_deps`：任务的输出数据依赖。输出数据依赖通常以实际数据的地址表达，不支持`ffrt_task_handle_t`。
- `attr`：任务的属性设置。

**返回值**

- `ffrt_task_handle_t`任务的句柄。

**描述**

相比于`ffrt_submit_f`接口，增加了任务句柄的返回值。

**样例**

```cpp
#include <stdio.h>
#include <vector>
#include "ffrt/task.h"

// 待提交执行的函数
void OnePlusForTest(void* arg)
{
    (*static_cast<int*>(arg)) += 1;
}

int main()
{
    int a = 0;
    ffrt_task_handle_t task = ffrt_submit_h_f(OnePlusForTest, &a, NULL, NULL, NULL);

    const std::vector<ffrt_dependence_t> wait_deps = {{ffrt_dependence_task, task}};
    ffrt_deps_t wait{static_cast<uint32_t>(wait_deps.size()), wait_deps.data()};
    ffrt_wait_deps(&wait);

    printf("a = %d\n", a);
    return 0;
}
```

### ffrt_task_handle_inc_ref

**声明**

```c
FFRT_C_API uint32_t ffrt_task_handle_inc_ref(ffrt_task_handle_t handle);
```

**参数**

- `handle`：任务句柄。

**返回值**

- 任务的引用计数。

**描述**

通过任务句柄增加对应任务的引用计数，每次调用引用计数加一。用于控制任务的生命周期使用，当引用计数不为零时，对应的任务资源不会被释放。注意`ffrt_submit_h_base`返回的`ffrt_task_handle_t`默认已有一个引用计数。通过`ffrt_task_handle_destroy`销毁`ffrt_task_handle_t`时默认减去一个引用计数。

### ffrt_task_handle_dec_ref

**声明**

```c
FFRT_C_API uint32_t ffrt_task_handle_dec_ref(ffrt_task_handle_t handle);
```

**参数**

- `handle`：任务句柄。

**返回值**

- 任务的引用计数。

**描述**

通过任务句柄减去对应任务的引用计数，每次调用引用计数减一。

### ffrt_task_handle_destroy

**声明**

```c
FFRT_C_API void ffrt_task_handle_destroy(ffrt_task_handle_t handle);
```

**参数**

- `handle`：任务句柄。

**描述**

销毁任务句柄，同时默认减去一个任务引用计数。

### ffrt_wait

**声明**

```c
FFRT_C_API void ffrt_wait(void);
```

**描述**

同步等待所有前序提交的同级任务完成。

**样例**

```c
// 同步三个任务完成
ffrt_submit_base(func1, NULL, NULL, NULL);
ffrt_submit_base(func2, NULL, NULL, NULL);
ffrt_submit_base(func3, NULL, NULL, NULL);
ffrt_wait();
```

### ffrt_wait_deps

**声明**

```c
FFRT_C_API void ffrt_wait_deps(const ffrt_deps_t* deps);
```

**参数**

- `deps`：需要同步的数据依赖。

**描述**

同步对应的数据依赖解除。

**样例**

```c
// 构建x的数据依赖
int x = 0;
ffrt_dependence_t dependence[1];
dependence[0].type = ffrt_dependence_data;
dependence[0].ptr = &x;
ffrt_deps_t deps;
deps.len = 1;
deps.items = dependence;

// 提交一个写任务
ffrt_submit_base(func, NULL, &deps, NULL);

// 同步写任务解除数据依赖
ffrt_wait_deps(&deps);
```

### ffrt_this_task_update_qos

**声明**

```c
FFRT_C_API int ffrt_this_task_update_qos(ffrt_qos_t qos);
```

**参数**

- `qos`：QoS等级。

**返回值**

- 0表示成功，1表示失败。

**描述**

在任务执行过程中，动态修改任务的QoS等级。注意该接口在任务的函数闭包内使用，修改的是当前正在执行的任务的QoS等级，接口调用会使任务先挂起一次再恢复执行。

**样例**

```c
// 一个qos_background的任务执行过程中动态修改QoS等级
ffrt::submit([]() {
    // ...
    int ret = ffrt_this_task_update_qos(ffrt_qos_user_initiated);
    // ...
}, ffrt::task_attr().qos(ffrt::qos_background));
```

### ffrt_this_task_get_qos

**声明**

```c
FFRT_C_API ffrt_qos_t ffrt_this_task_get_qos(void);
```

**返回值**

- QoS等级。

**描述**

获取当前正在执行任务的QoS等级。

**样例**

```c
// 一个任务执行过程中动态获取其QoS等级
ffrt::submit([]() {
    // ...
    // 获取的qos等于ffrt_qos_background
    ffrt_qos_t qos = ffrt_this_task_get_qos();
    // ...
}, ffrt::task_attr().qos(ffrt::qos_background));
```

### ffrt_this_task_get_id

**声明**

```c
FFRT_C_API uint64_t ffrt_this_task_get_id(void);
```

**返回值**

- 任务的id。

**描述**

获取当前正在执行任务的id。

**样例**

```c
// 一个任务执行过程中动态获取其任务id
ffrt::submit([]() {
    // ...
    // 获取的唯一任务id
    uint64_t task_id = ffrt_this_task_get_id();
    // ...
}, ffrt::task_attr().qos(ffrt::qos_background));
```

## 任务队列

### ffrt_queue_attr_t

**声明**

```c
typedef struct {
    uint32_t storage[(ffrt_queue_attr_storage_size + sizeof(uint32_t) - 1) / sizeof(uint32_t)];
} ffrt_queue_attr_t;
```

**描述**

用于配置队列的属性，如 QoS、超时时间、回调函数和最大并发数。

**方法**

**ffrt_queue_attr_init**

```c
int ffrt_queue_attr_init(ffrt_queue_attr_t* attr);
```

参数

- `attr`：队列属性指针。

返回值

- 返回0表示成功，其他值表示失败。

描述

- 初始化队列属性对象。

**ffrt_queue_attr_destroy**

```c
void ffrt_queue_attr_destroy(ffrt_queue_attr_t* attr);
```

参数

- `attr`：队列属性指针。

描述

- 销毁队列属性对象。

**ffrt_queue_attr_set_qos**

```c
void ffrt_queue_attr_set_qos(ffrt_queue_attr_t* attr, ffrt_qos_t qos);
```

参数

- `attr`：队列属性指针。
- `qos`：QoS等级。

描述

- 设置队列的QoS等级。

**ffrt_queue_attr_get_qos**

```c
ffrt_qos_t ffrt_queue_attr_get_qos(const ffrt_queue_attr_t* attr);
```

参数

- `attr`：队列属性指针。

返回值

- 返回当前QoS等级。

描述

- 获取当前属性中设置的QoS等级。

**ffrt_queue_attr_set_timeout**

```c
void ffrt_queue_attr_set_timeout(ffrt_queue_attr_t* attr, uint64_t timeout_us);
```

参数

- `attr`：队列属性指针。
- `timeout_us`：超时时间（微秒）。

描述

- 设置队列的超时时间（以微秒为单位）。

**ffrt_queue_attr_get_timeout**

```c
uint64_t ffrt_queue_attr_get_timeout(const ffrt_queue_attr_t* attr);
```

参数

- `attr`：队列属性指针。

返回值

- 返回当前超时阈值（微秒）。

描述

- 获取当前属性中设置的超时时间。

**ffrt_queue_attr_set_callback**

```c
void ffrt_queue_attr_set_callback(ffrt_queue_attr_t* attr, ffrt_function_header_t* f);
```

参数

- `attr`：队列属性指针。
- `f`：是任务执行器的指针，描述了该CPU任务如何执行和销毁。

描述

- 设置检测到队列任务超时后执行的回调函数。

**ffrt_queue_attr_get_callback**

```c
ffrt_function_header_t* ffrt_queue_attr_get_callback(const ffrt_queue_attr_t* attr);
```

参数

- `attr`：队列属性指针。

返回值

- 返回任务执行器的指针，描述了该CPU任务如何执行和销毁。

描述

- 获取当前属性中设置的超时回调函数。

**ffrt_queue_attr_set_max_concurrency**

```c
void ffrt_queue_attr_set_max_concurrency(ffrt_queue_attr_t* attr, const int max_concurrency);
```

参数

- `attr`：队列属性指针。
- `max_concurrency`：最大并发数。

描述

- 设置队列的最大并发数（仅支持并发队列）。

**ffrt_queue_attr_get_max_concurrency**

```c
int ffrt_queue_attr_get_max_concurrency(const ffrt_queue_attr_t* attr);
```

参数

- `attr`：队列属性指针。

返回值

- 返回当前最大并发数。

描述

- 获取当前属性中设置的最大并发数（仅支持并发队列）。

**ffrt_queue_attr_set_thread_mode**

```c
void ffrt_queue_attr_set_thread_mode(ffrt_queue_attr_t* attr, bool mode);
```

参数

- `attr`：队列属性指针。
- `mode`：设置队列任务运行方式。`true`表示以线程模式运行，`false`表示以协程模式运行。

描述

- 设置队列中的任务是以协程模式还是以线程模式运行。默认以协程模式运行。

> **说明：**

> 从API version 20开始，支持该接口。

**ffrt_queue_attr_get_thread_mode**

```c
bool ffrt_queue_attr_get_thread_mode(const ffrt_queue_attr_t* attr);
```

参数

- `attr`：队列属性指针。

返回值

- `true`表示以线程模式运行，`false`表示以协程模式运行。

描述

- 获取队列中的任务是以协程模式还是以线程模式运行。

> **说明：**

> 从API version 20开始，支持该接口。

**样例**

```cpp
#include <functional>
#include "ffrt/queue.h"
#include "ffrt/cpp/task.h"

int main()
{
    ffrt_queue_attr_t queue_attr;
    // 初始化队列属性，必需
    ffrt_queue_attr_init(&queue_attr);

    ffrt_queue_attr_set_qos(&queue_attr, static_cast<int>(ffrt_qos_utility));

    ffrt_queue_attr_set_timeout(&queue_attr, 10000);

    int x = 0;
    std::function<void()>&& basicFunc = [&x]() { x += 1; };
    ffrt_function_header_t* func = ffrt_queue_attr_get_callback(&queue_attr);

    ffrt_queue_attr_set_callback(&queue_attr, ffrt::create_function_wrapper(basicFunc, ffrt_function_kind_queue));
    // 销毁队列属性，必需
    ffrt_queue_attr_destroy(&queue_attr);
    return 0;
}
```

### ffrt_queue_t

**声明**

```c
typedef void* ffrt_queue_t;
```

**描述**

队列指针，提供一系列C接口支持队列任务的提交、取消、等待和排队任务数量查询。

**方法**

**ffrt_queue_create**

```c
ffrt_queue_t ffrt_queue_create(ffrt_queue_type_t type, const char* name, const ffrt_queue_attr_t* attr);
```

参数

- `type`：队列类型（如`ffrt_queue_serial`或`ffrt_queue_concurrent`）。
- `name`：队列名称。
- `attr`：队列属性。

返回值

- `ffrt_queue_t`：成功则返回一个非空的队列句柄；否则返回空指针。

描述

- 创建指定类型和名称的队列。

**ffrt_queue_destroy**

```c
void ffrt_queue_destroy(ffrt_queue_t queue);
```

参数

- `queue`：队列的句柄。

描述

- 销毁一个队列。

**ffrt_queue_submit**

```c
void ffrt_queue_submit(ffrt_queue_t queue, ffrt_function_header_t* f, const ffrt_task_attr_t* attr);
```

参数

- `queue`：队列的句柄。
- `f`：任务执行器的指针，描述了该CPU任务如何执行和销毁。
- `attr`：任务属性。

描述

- 提交任务到队列中。

**ffrt_queue_submit_f**

```c
void ffrt_queue_submit_f(ffrt_queue_t queue, ffrt_function_t func, void* arg, const ffrt_task_attr_t* attr);
```

参数

- `queue`：队列的句柄。
- `func`：指定的任务函数。
- `arg`：传递给任务函数的参数。
- `attr`：任务属性。

描述

- 当任务不需要销毁回调函数时，提交任务到队列中。

**ffrt_queue_submit_h**

```c
ffrt_task_handle_t ffrt_queue_submit_h(ffrt_queue_t queue, ffrt_function_header_t* f, const ffrt_task_attr_t* attr);
```

参数

- `queue`：队列的句柄。
- `f`：任务执行器的指针，描述了该CPU任务如何执行和销毁。
- `attr`：任务属性。

返回值

- `ffrt_task_handle_t`：成功则返回一个非空的任务句柄；否则返回空指针。

描述

- 提交任务到队列中，并返回任务句柄。

**ffrt_queue_submit_h_f**

```c
ffrt_task_handle_t ffrt_queue_submit_h_f(ffrt_queue_t queue, ffrt_function_t func, void* arg, const ffrt_task_attr_t* attr);
```

参数

- `queue`：队列的句柄。
- `func`：指定的任务函数。
- `arg`：传递给任务函数的参数。
- `attr`：任务属性。

返回值

- `ffrt_task_handle_t`：成功则返回一个非空的任务句柄；否则返回空指针。

描述

- 当任务不需要销毁回调函数时，提交任务到队列中，并返回任务句柄。

**ffrt_queue_wait**

```c
void ffrt_queue_wait(ffrt_task_handle_t handle);
```

参数

- `ffrt_task_handle_t`：任务句柄。

描述

- 等待一个队列任务完成。

**ffrt_queue_cancel**

```c
int ffrt_queue_cancel(ffrt_task_handle_t handle);
```

参数

- `ffrt_task_handle_t`：任务句柄。

返回值

- 返回0表示成功，其他值表示失败。

描述

- 取消一个队列任务。

**ffrt_get_main_queue**

```c
ffrt_queue_t ffrt_get_main_queue();
```

返回值

- 主线程队列。

描述

- 获取主线程队列，用于FFRT线程与主线程通信。

**ffrt_get_current_queue**

```c
ffrt_queue_t ffrt_get_current_queue();
```

返回值

- ArkTS Worker线程任务队列。

描述

- 此接口已于API 18版本后废弃，不建议继续使用。
- 获取ArkTS Worker线程队列，用于FFRT线程与ArkTS Worker线程通信。

**样例**

```cpp
#include "ffrt/queue.h"
#include "ffrt/cpp/task.h"

int main()
{
    ffrt_queue_attr_t queue_attr;
    // 1、初始化队列属性，必需
    (void)ffrt_queue_attr_init(&queue_attr);

    // 2、创建串行队列，并返回队列句柄queue_handle
    ffrt_queue_t queue_handle = ffrt_queue_create(ffrt_queue_serial, "test_queue", &queue_attr);

    int result = 0;
    std::function<void()>&& basicFunc = [&result]() { result += 1; };

    // 3、提交串行任务
    ffrt_queue_submit(queue_handle, ffrt::create_function_wrapper(basicFunc, ffrt_function_kind_queue), nullptr);

    // 4、提交串行任务，并返回任务句柄
    ffrt_task_handle_t t1 = ffrt_queue_submit_h(queue_handle, ffrt::create_function_wrapper(basicFunc, ffrt_function_kind_queue), nullptr);
    // 5、等待指定任务执行完成
    ffrt_queue_wait(t1);

    ffrt_task_handle_t t2 = ffrt_queue_submit_h(queue_handle, ffrt::create_function_wrapper(basicFunc, ffrt_function_kind_queue), nullptr);
    // 6、取消句柄为 t2 的任务
    ffrt_queue_cancel(t2);

    // 7、销毁提交给串行队列任务的句柄 t1 和 t2，必需
    ffrt_task_handle_destroy(t1);
    ffrt_task_handle_destroy(t2);
    // 8、销毁队列属性，必需
    ffrt_queue_attr_destroy(&queue_attr);
    // 9、销毁队列句柄，必需
    ffrt_queue_destroy(queue_handle);
    return 0;
}
```

## 同步原语

### ffrt_mutexattr_t

**声明**

```c
typedef enum {
    ffrt_error = -1,
    ffrt_success = 0,
    ffrt_error_nomem = ENOMEM,
    ffrt_error_timedout = ETIMEDOUT,
    ffrt_error_busy = EBUSY,
    ffrt_error_inval = EINVAL
} ffrt_error_t;

typedef enum {
    ffrt_mutex_normal = 0,
    ffrt_mutex_recursive = 2,
    ffrt_mutex_default = ffrt_mutex_normal
} ffrt_mutex_type;

struct ffrt_mutexattr_t;

int ffrt_mutexattr_init(ffrt_mutexattr_t* attr);
int ffrt_mutexattr_settype(ffrt_mutexattr_t* attr, int type);
int ffrt_mutexattr_gettype(ffrt_mutexattr_t* attr, int* type);
int ffrt_mutexattr_destroy(ffrt_mutexattr_t* attr);
```

**描述**

- FFRT提供的类似pthread mutexattr的性能实现。

**方法**

**ffrt_mutexattr_init**

```c
FFRT_C_API int ffrt_mutexattr_init(ffrt_mutexattr_t* attr);
```

参数

- `attr`：FFRT锁属性。

返回值

- `attr`不为空返回`ffrt_success`，否则返回`ffrt_error_inval`。

描述

- 初始化`mutexattr`。

**ffrt_mutexattr_destroy**

```c
FFRT_C_API int ffrt_mutexattr_destroy(ffrt_mutexattr_t* attr);
```

参数

- `attr`：FFRT锁属性。

返回值

- `attr`不为空返回`ffrt_success`，否则返回`ffrt_error_inval`。

描述

- 销毁mutexattr。

**ffrt_mutexattr_settype**

```c
FFRT_C_API int ffrt_mutexattr_settype(ffrt_mutexattr_t* attr, int type);
```

参数

- `attr`：FFRT锁属性。
- `type`：FFRT锁类型，当前仅支持互斥锁`ffrt_mutex_normal`和递归锁`ffrt_mutex_recursive`。

返回值

- `attr`不为空且`type`有效返回`ffrt_success`，否则返回`ffrt_error_inval`。

描述

- 设置FFRT锁属性。

**ffrt_mutexattr_gettype**

```c
FFRT_C_API int ffrt_mutexattr_gettype(ffrt_mutexattr_t* attr, int* type);
```

参数

- `attr`：FFRT锁属性。
- `type`：FFRT锁类型指针。

返回值

- `attr`和`type`均不为空返回`ffrt_success`，否则返回`ffrt_error_inval`。

描述

- 获取FFRT锁属性。

**样例**

```c
ffrt_mutexattr_t attr;
// 初始化锁属性
ffrt_mutexattr_init(&attr);
// 设置为互斥锁
ffrt_mutexattr_settype(&attr, ffrt_mutex_normal);
// 设置为递归锁
ffrt_mutexattr_settype(&attr, ffrt_mutex_recursive);
// 获取锁类型
int type = ffrt_mutex_default;
ffrt_mutexattr_gettype(&attr, &type);
// 销毁锁属性
ffrt_mutexattr_destroy(&attr);
```

### ffrt_mutex_t

- FFRT提供的类似`pthread_mutex_t`的性能实现，但不支持类似`PTHREAD_MUTEX_INITIALIZER`的初始化。

**声明**

```c
struct ffrt_mutex_t;
struct ffrt_mutexattr_t;

int ffrt_mutex_init(ffrt_mutex_t* mutex, const ffrt_mutexattr_t* attr);
int ffrt_mutex_lock(ffrt_mutex_t* mutex);
int ffrt_mutex_unlock(ffrt_mutex_t* mutex);
int ffrt_mutex_trylock(ffrt_mutex_t* mutex);
int ffrt_mutex_destroy(ffrt_mutex_t* mutex);
```

**描述**

- 该接口支持在FFRT任务内部调用，也支持在FFRT任务外部调用。
- 该接口能够避免pthread传统的`pthread_mutex_t`在抢不到锁时陷入内核态的问题，在使用得当的条件下将会有更好的性能。
- C API中的`ffrt_mutexattr_t`需要用户调用`ffrt_mutexattr_init`和`ffrt_mutexattr_destroy`显示创建和销毁，否则其行为是未定义的。
- C API中的`ffrt_mutex_t`需要用户调用`ffrt_mutex_init`和`ffrt_mutex_destroy`显式创建和销毁，否则其行为是未定义的。
- C API中的`ffrt_mutex_t`对象的置空和销毁由用户完成，对同一个`ffrt_mutex_t`仅能调用一次`ffrt_mutex_destroy`，重复对同一个`ffrt_mutex_t`调用`ffrt_mutex_destroy`，其行为是未定义的。
- C API中的同一个`ffrt_mutexattr_t`只能调用一次`ffrt_mutexattr_init`和`ffrt_mutexattr_destroy`，重复调用其行为是未定义的。
- 用户需要在调用`ffrt_mutex_init`之后和调用`ffrt_mutex_destroy`之前显示调用`ffrt_mutexattr_destroy`。
- 在`ffrt_mutex_destroy`之后再对`ffrt_mutex_t`进行访问，其行为是未定义的。

**方法**

**ffrt_mutex_init**

```c
FFRT_C_API int ffrt_mutex_init(ffrt_mutex_t* mutex, const ffrt_mutexattr_t* attr);
```

参数

- `mutex`：指向所操作的锁指针。
- `attr`：FFRT锁属性，attr的有效值范围是：空指针或等于`ffrt_mutex_normal`代表互斥锁，`ffrt_mutex_recursive`代表递归锁。

返回值

- 如果`mutex`不为空且`attr`在有效值范围内返回`ffrt_success`，否则返回`ffrt_error_inval`。

描述

- 初始化FFRT锁。

**ffrt_mutex_destroy**

```c
FFRT_C_API int ffrt_mutex_destroy(ffrt_mutex_t* mutex);
```

参数

- `mutex`：指向所操作的锁指针。

返回值

- `mutex`不为空返回`ffrt_success`，否则返回`ffrt_error_inval`。

描述

- 对指定的互斥锁/递归锁进行销毁操作。

**ffrt_mutex_lock**

```c
FFRT_C_API int ffrt_mutex_lock(ffrt_mutex_t* mutex);
```

参数

- `mutex`：指向所操作的锁指针。

返回值

- `mutex`不为空返回`ffrt_success`，否则返回`ffrt_error_inval`。

描述

- 对指定的互斥锁/递归锁进行加锁操作，该方法会阻塞当前任务直到能成功获得锁。

**ffrt_mutex_unlock**

```c
FFRT_C_API int ffrt_mutex_unlock(ffrt_mutex_t* mutex);
```

参数

- `mutex`：指向所操作的锁指针。

返回值

- `mutex`不为空返回`ffrt_success`，否则返回`ffrt_error_inval`。

描述

- 对指定的互斥锁/递归锁进行解锁操作。

**ffrt_mutex_trylock**

```c
FFRT_C_API int ffrt_mutex_trylock(ffrt_mutex_t* mutex);
```

参数

- `mutex`：指向所操作的锁指针。

返回值

- `mutex`为空返回ffrt_error_inval，`mutex`不为空且持锁成功返回`ffrt_success`，`mutex`不为空且持锁失败返回`ffrt_error_busy`。

描述

- 对指定的互斥锁/递归锁进行尝试加锁操作。

**样例**

```cpp
#include "ffrt/mutex.h"
#include "ffrt/cpp/task.h"

int main()
{
    ffrt_mutexattr_t attr;
    ffrt_mutex_t lock;
    int sum = 0;
    int type = ffrt_mutex_default;
    ffrt_mutexattr_init(&attr);
    ffrt_mutexattr_settype(&attr, ffrt_mutex_recursive);
    ffrt_mutexattr_gettype(&attr, &type);
    ffrt_mutex_init(&lock, &attr);
    ffrt::submit([&]() {
        ffrt_mutex_lock(&lock);
        ffrt_mutex_trylock(&lock);
        sum++;
        ffrt_mutex_lock(&lock);
        ffrt_mutex_trylock(&lock);
        sum++;
        ffrt_mutex_unlock(&lock);
        ffrt_mutex_unlock(&lock);
        ffrt_mutex_unlock(&lock);
        ffrt_mutex_unlock(&lock);
        }, {}, {});

    ffrt::wait();

    ffrt_mutexattr_destroy(&attr);
    ffrt_mutex_destroy(&lock);
    return 0;
}
```

### ffrt_rwlock_t

- FFRT提供的类似`pthread_rwlock_t`的性能实现。

**声明**

```c
struct ffrt_rwlock_t;
struct ffrt_rwlockattr_t;

int ffrt_rwlock_init(ffrt_rwlock_t* rwlock, const ffrt_rwlockattr_t* attr);
int ffrt_rwlock_wrlock(ffrt_rwlock_t* rwlock);
int ffrt_rwlock_rdlock(ffrt_rwlock_t* rwlock);
int ffrt_rwlock_trywrlock(ffrt_rwlock_t* rwlock);
int ffrt_rwlock_tryrdlock(ffrt_rwlock_t* rwlock);
int ffrt_rwlock_unlock(ffrt_rwlock_t* rwlock);
int ffrt_rwlock_destroy(ffrt_rwlock_t* rwlock);
```

**描述**

- 该接口支持在FFRT任务内部调用，也支持在FFRT任务外部调用。
- 该接口能够避免pthread传统的`pthread_rwlock_t`在ffrt使用场景下睡眠不释放线程的问题，在使用得当的条件下将会有更好的性能。
- C API中的`ffrt_rwlock_t`需要用户调用`ffrt_rwlock_init`和`ffrt_rwlock_destroy`显式创建和销毁，否则其行为是未定义的。
- C API中的`ffrt_rwlockattr_t`需要用户调用`ffrt_rwlock_init`时此参数传参必须为空指针。
- C API中的`ffrt_rwlock_t`对象的置空和销毁由用户完成，对同一个`ffrt_rwlock_t`仅能调用一次`ffrt_rwlock_destroy`，重复对同一个`ffrt_rwlock_t`调用`ffrt_rwlock_destroy`，其行为是未定义的。
- 在`ffrt_rwlock_destroy`之后再对`ffrt_rwlock_t`进行访问，其行为是未定义的。

**方法**

**ffrt_rwlock_init**

```c
FFRT_C_API int ffrt_rwlock_init(ffrt_rwlock_t* rwlock, const ffrt_rwlockattr_t* attr);
```

参数

- `rwlock`：指向所操作的读写锁指针。
- `attr`：指向所操作的读写锁属性指针，仅支持默认模式，即`attr`设定为空指针。

返回值

- `rwlock`不为空，且`attr`为空则返回`ffrt_success`，否则返回`ffrt_error_inval`。

描述

- 初始化读写锁。

**ffrt_rwlock_wrlock**

```c
FFRT_C_API int ffrt_rwlock_wrlock(ffrt_rwlock_t* rwlock);
```

参数

- `rwlock`：指向所操作的读写锁指针。

返回值

- `rwlock`不为空返回`ffrt_success`，否则返回`ffrt_error_inval`。

描述

- 对指定读写锁加写锁操作。

**ffrt_rwlock_rdlock**

```c
FFRT_C_API int ffrt_rwlock_rdlock(ffrt_rwlock_t* rwlock);
```

参数

- `rwlock`：指向所操作的读写锁指针。

返回值

- `rwlock`不为空返回`ffrt_success`，否则返回`ffrt_error_inval`。

描述

- 对指定读写锁加读锁操作。

**ffrt_rwlock_trywrlock**

```c
FFRT_C_API int ffrt_rwlock_trywrlock(ffrt_rwlock_t* rwlock);
```

参数

- `rwlock`：指向所操作的读写锁指针。

返回值

- `rwlock`不为空且没有其他线程持有读写锁返回`ffrt_success`，否则返回`ffrt_error_inval`。

描述

- 对指定的读写锁进行尝试加写锁操作。

**ffrt_rwlock_tryrdlock**

```c
FFRT_C_API int ffrt_rwlock_tryrdlock(ffrt_rwlock_t* rwlock);
```

参数

- `rwlock`：指向所操作的读写锁指针。

返回值

- `rwlock`不为空且没有其他线程持有写锁则返回`ffrt_success`，否则返回`ffrt_error_inval`。

描述

- 对指定的读写锁进行尝试加读锁操作。

**ffrt_rwlock_unlock**

```c
FFRT_C_API int ffrt_rwlock_unlock(ffrt_rwlock_t* rwlock);
```

参数

- `rwlock`：指向所操作的读写锁指针。

返回值

- `rwlock`不为空返回`ffrt_success`，否则返回`ffrt_error_inval`。

描述

- 对指定的读写锁进行解锁操作。

**ffrt_rwlock_destroy**

```c
FFRT_C_API int ffrt_rwlock_destroy(ffrt_rwlock_t* rwlock);
```

参数

- `rwlock`：指向所操作的读写锁指针。

返回值

- `rwlock`不为空返回`ffrt_success`，否则返回`ffrt_error_inval`。

描述

- 对指定的读写锁进行销毁操作。

**样例**

```cpp
#include "ffrt/shared_mutex.h"
#include "ffrt/sleep.h"
#include "ffrt/cpp/task.h"

int main()
{
    ffrt_rwlock_t rwlock;
    int x = 0;
    ffrt_rwlock_init(&rwlock, nullptr);
    ffrt::submit([&]() {
        ffrt_rwlock_wrlock(&rwlock);
        ffrt_usleep(10);
        x++;
        ffrt_rwlock_unlock(&rwlock);
    },{},{});

    ffrt::submit([&]() {
        ffrt_usleep(2);
        ffrt_rwlock_rdlock(&rwlock);
        ffrt_rwlock_unlock(&rwlock);
    },{},{});

    ffrt::submit([&]() {
        ffrt_usleep(2);
        if(ffrt_rwlock_trywrlock(&rwlock)){
            x++;
            ffrt_rwlock_unlock(&rwlock);
        }
    },{},{});

    ffrt::submit([&]() {
        ffrt_usleep(2);
        if(ffrt_rwlock_tryrdlock(&rwlock)){
            ffrt_rwlock_unlock(&rwlock);
        }
    },{},{});

    ffrt::wait();

    ffrt_rwlock_destroy(&rwlock);
    return 0;
}
```

### ffrt_cond_t

- FFRT提供的类似pthread信号量的性能实现，但不支持类似`PTHREAD_COND_INITIALIZER`的初始化。

**声明**

```c
typedef enum {
    ffrt_error = -1,
    ffrt_success = 0,
    ffrt_error_nomem = ENOMEM,
    ffrt_error_timedout = ETIMEDOUT,
    ffrt_error_busy = EBUSY,
    ffrt_error_inval = EINVAL
} ffrt_error_t;

typedef struct {
    uint32_t storage[(ffrt_cond_storage_size + sizeof(uint32_t) - 1) / sizeof(uint32_t)];
} ffrt_cond_t;

int ffrt_cond_init(ffrt_cond_t* cond, const ffrt_condattr_t* attr);
int ffrt_cond_signal(ffrt_cond_t* cond);
int ffrt_cond_broadcast(ffrt_cond_t* cond);
int ffrt_cond_wait(ffrt_cond_t*cond, ffrt_mutex_t* mutex);
int ffrt_cond_timedwait(ffrt_cond_t* cond, ffrt_mutex_t* mutex, const struct timespec* time_point);
int ffrt_cond_destroy(ffrt_cond_t* cond);
```

**描述**

- 该接口支持在FFRT任务内部调用，也支持在FFRT任务外部调用。
- 该功能能够避免传统的`pthread_cond_t`在条件不满足时陷入内核的问题，在使用得当的条件下将会有更好的性能。
- 注意：C API 中的`ffrt_cond_t`需要用户调用`ffrt_cond_init`和`ffrt_cond_destroy`显式创建和销毁，而C++ API 中依赖构造和析构自动完成。
- 注意：C API 中的`ffrt_cond_t`对象的置空和销毁由用户完成，对同一个`ffrt_cond_t`仅能调用一次`ffrt_cond_destroy`，重复对同一个`ffrt_cond_t`调用`ffrt_cond_destroy`，其行为是未定义的。
- 注意：在`ffrt_cond_destroy`之后再对`ffrt_cond_t`进行访问，其行为是未定义的。

**方法**

**ffrt_cond_init**

```c
FFRT_C_API int ffrt_cond_init(ffrt_cond_t* cond, const ffrt_condattr_t* attr);
```

参数

- `cond`：指向所操作的信号量的指针。
- `attr`：属性设定，空指针表示使用默认属性。

返回值

- `cond`不为空返回`ffrt_success`，否则返回`ffrt_error_inval`。

描述

- 初始化FFRT条件变量。

**ffrt_cond_destroy**

```c
FFRT_C_API int ffrt_cond_destroy(ffrt_cond_t* cond);
```

参数

- `cond`：指向所操作的信号量的指针。

返回值

- `cond`不为空返回`ffrt_success`，否则返回`ffrt_error_inval`。

描述

- 销毁FFRT条件变量。

**ffrt_cond_signal**

```c
FFRT_C_API int ffrt_cond_signal(ffrt_cond_t* cond);
```

参数

- `cond`：指向所操作的信号量的指针。

返回值

- `cond`不为空返回`ffrt_success`，否则返回`ffrt_error_inval`。

描述

- 该方法用于唤醒一个等待条件变量的任务。

**ffrt_cond_broadcast**

```c
FFRT_C_API int ffrt_cond_broadcast(ffrt_cond_t* cond);
```

参数

- `cond`：指向所操作的信号量的指针。

返回值

- `cond`不为空返回`ffrt_success`，否则返回`ffrt_error_inval`。

描述

- 该方法用于唤醒所有等待条件变量的任务。

**ffrt_cond_wait**

```c
FFRT_C_API int ffrt_cond_wait(ffrt_cond_t* cond, ffrt_mutex_t* mutex);
```

参数

- `cond`：指向所操作的信号量的指针。
- `mutex`：指向要在阻塞期间解锁的互斥锁的指针。

返回值

- `cond`和`mutex`均不为空返回`ffrt_success`，否则返回`ffrt_error_inval`。

描述

- 方法用于在条件变量上等待。任务在调用该方法时会释放传入的互斥量，并进入等待状态，直到另一个任务通知条件变量，才会重新获取互斥量并继续执行。
- 此方法通常与`ffrt_mutex_lock`或`ffrt_mutex_trylock`一起使用，确保在进入等待状态之前已经持有互斥量。

**ffrt_cond_timedwait**

```c
FFRT_C_API int ffrt_cond_timedwait(ffrt_cond_t* cond, ffrt_mutex_t* mutex, const struct timespec* time_point);
```

参数

- `cond`：指向所操作的信号量的指针。
- `mutex`：指向要在阻塞期间解锁的互斥锁的指针。
- `time_point`：指向指定等待时限时间的对象的指针。

返回值

- `cond`和`mutex`和`time_point`均不为空返回`ffrt_success`，否则返回`ffrt_error_inval`。

描述

- 该方法用于在条件变量上等待，直到指定的超时时间到达。
- 与`ffrt_cond_wait`不同，`ffrt_cond_timedwait`方法允许任务在条件变量上等待一段时间，如果在指定时间内没有收到通知，任务将被唤醒该函数返回。

**样例**

```cpp
#include <iostream>
#include "ffrt/condition_variable.h"
#include "ffrt/mutex.h"
#include "ffrt/sleep.h"
#include "ffrt/cpp/task.h"

struct timespec timeoutms_to_tm(int timeout_ms) {
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    ts.tv_sec += timeout_ms / 1000;
    ts.tv_nsec += (timeout_ms % 1000) * 1000000;
    if (ts.tv_nsec >= 1000000000) {
        ts.tv_sec += 1;
        ts.tv_nsec -= 1000000000;
    }
    return ts;
}

int main()
{
    int a = 0;
    ffrt_cond_t cond;
    ffrt_mutex_t lock_;
    ffrt_cond_init(&cond, nullptr);
    ffrt_mutex_init(&lock_, nullptr);

    for (int i = 0; i < 3; i++) {
        ffrt::submit([&]() {
            int timeout = 2000;
            struct timespec tm = timeoutms_to_tm(timeout);
            ffrt_mutex_lock(&lock_);
            auto start = std::chrono::high_resolution_clock::now();
            ffrt_cond_timedwait(&cond, &lock_, &tm);
            auto end = std::chrono::high_resolution_clock::now();
            a = 123;
            ffrt_mutex_unlock(&lock_);
            std::chrono::duration<double, std::milli> elapsed = end - start;
            double t = elapsed.count();
            std::cout << "ffrt_cond_timedwait " << t << " ms" << std::endl;
            }, {}, {});
    }

    ffrt::submit([&]() {
        ffrt_usleep(1000 * 1000);
        ffrt_mutex_lock(&lock_);
        a = 5;
        ffrt_cond_broadcast(&cond);
        ffrt_mutex_unlock(&lock_);
        }, {}, {});
    ffrt::wait();
    ffrt_cond_destroy(&cond);
    ffrt_mutex_destroy(&lock_);
    return 0;
}
```

## 阻塞原语

### ffrt_usleep

**声明**

```c
FFRT_C_API int ffrt_usleep(uint64_t usec);
```

**参数**

- `usec`：睡眠的微秒数。

**描述**

- FFRT提供的类似C11 sleep和Linux usleep的性能实现。
- 该接口只能在FFRT任务内部调用，在FFRT任务外部调用存在未定义的行为。
- 该接口睡眠精度为微秒。
- 该功能能够避免传统的`sleep`睡眠时陷入内核的问题，在使用得当的条件下将会有更好的性能。

**样例**

```cpp
#include "ffrt/sleep.h"
#include "ffrt/cpp/task.h"

int main()
{
    ffrt::submit([=]() { ffrt_usleep(10); }, {}, {});
    ffrt::wait();
    return 0;
}
```

## 协同原语

### ffrt_yield

**声明**

```c
FFRT_C_API void ffrt_yield();
```

**描述**

- 当前任务主动让出CPU执行资源，允许其他可执行的任务运行，如果没有其他可执行的任务，`yield`无效。
- 该接口只能在 FFRT任务内部调用，在FFRT任务外部调用存在未定义的行为。
- 此函数的确切行为取决于实现，特别是使用中的FFRT调度程序的机制和系统状态。

**样例**

```cpp
#include <iostream>
#include "ffrt/sleep.h"
#include "ffrt/cpp/task.h"

int main()
{
    int count = 12;
    for (int i = 0; i < count; i++) {
        ffrt::submit([&]() {
            ffrt_usleep(100);
            std::cout << "test" << std::endl;
            ffrt_yield();
        }, {}, {});
    }
    ffrt::wait();
    return 0;
}
```

## 定时器

### ffrt_timer_t

**声明**

```c
typedef int ffrt_timer_t;
typedef void (*ffrt_timer_cb)(void* data);
```

**描述**

提供定时器相关的功能。

**方法**

**ffrt_timer_start**

声明

```c
FFRT_C_API ffrt_timer_t ffrt_timer_start(ffrt_qos_t qos, uint64_t timeout, void* data, ffrt_timer_cb cb, bool repeat);
```

参数

- `qos`：QoS等级。
- `timeout`：定时器时间，单位是毫秒。
- `cb`：到期后的回调函数。
- `data`：回调函数的输入参数。
- `repeat`：是否循环定时器。

返回值

- `ffrt_timer_t`定时器句柄。

描述

- 启动一个定时器，定时器到期且未被取消的话，执行回调函数。如果设置`repeat`为`true`，定时器到期后会重复设置。

**ffrt_timer_stop**

声明

```c
FFRT_C_API int ffrt_timer_stop(ffrt_qos_t qos, ffrt_timer_t handle);
```

参数

- `qos`：QoS等级。
- `handle`：定时器句柄。

返回值

- 0表示成功，-1表示失败。

描述

- 取消一个定时器，和`ffrt_timer_start`配对使用。
- 为阻塞接口，请避免在回调函数callback内使用，防止死锁或同步问题，当传入的handle对应的callback正在执行时，该函数会等待callback完成后再继续执行。

**样例**

- 样例1：使用单次定时器：

    ```c
    #include <stdio.h>
    #include <unistd.h>
    #include "ffrt/timer.h"

    static void test_fun(void *data)
    {
        *(int *)data += 1;
    }

    void (*cb)(void *) = test_fun;

    int main()
    {
        static int x = 0;
        void *data = &x;
        uint64_t timeout = 200;
        // 启动定时器，在200ms后执行回调函数
        int handle = ffrt_timer_start(ffrt_qos_default, timeout, data, cb, false);
        usleep(300000);
        // 定时器已经执行，取消无效
        ffrt_timer_stop(ffrt_qos_default, handle);
        printf("data: %d\n", x); // x值变成1
        return 0;
    }
    ```

- 样例2：使用循环定时器：

    ```c
    #include <stdio.h>
    #include <unistd.h>
    #include "ffrt/timer.h"

    static void test_fun(void *data)
    {
        *(int *)data += 1;
    }

    void (*cb)(void *) = test_fun;

    int main()
    {
        static int x = 0;
        void *data = &x;
        uint64_t timeout = 200;
        // 启动循环定时器，每间隔200ms执行回调函数
        int handle = ffrt_timer_start(ffrt_qos_default, timeout, data, cb, true);
        usleep(500000);
        // 取消循环定时器
        ffrt_timer_stop(ffrt_qos_default, handle);
        printf("data: %d\n", x); // x的值变成2
        return 0;
    }
    ```

## 循环

### ffrt_loop_t

**声明**

```c
typedef void* ffrt_loop_t;
```

**描述**

提供循环相关的功能。

**方法**

**ffrt_loop_create**

声明

```c
FFRT_C_API ffrt_loop_t ffrt_loop_create(ffrt_queue_t queue);
```

参数

- `queue`：loop需要绑定一个FFRT并发队列使用。

返回值

- `ffrt_loop_t`对象。

描述

- 创建一个loop，需要绑定一个并发队列存储任务，用户可以向队列中提交任务使其在loop中执行。

**ffrt_loop_destroy**

声明

```c
FFRT_C_API int ffrt_loop_destroy(ffrt_loop_t loop);
```

参数

- `loop`：loop对象。

返回值

- 0表示成功，-1表示失败。

描述

- 销毁一个loop，同时和队列解除绑定。

**ffrt_loop_run**

声明

```c
FFRT_C_API int ffrt_loop_run(ffrt_loop_t loop);
```

参数

- `loop`：loop对象。

返回值

- 0表示成功，-1表示失败。

描述

- 启动一个loop，调用此方法的线程会同步执行loop，在loop中会执行队列的任务、监听poller事件触发、监听timer定时器触发。

**ffrt_loop_stop**

声明

```c
FFRT_C_API void ffrt_loop_stop(ffrt_loop_t loop);
```

参数

- `loop`：loop对象。

描述

- 停止一个loop，调用此方法使执行loop的线程退出循环。

**ffrt_loop_epoll_ctl**

声明

```c
int ffrt_loop_epoll_ctl(ffrt_loop_t loop, int op, int fd, uint32_t events, void *data, ffrt_poller_cb cb)
```

参数

- `loop`：loop对象。
- `op`：fd操作符，参考epoll_ctl的操作类型。
- `fd`：事件描述符。
- `events`：事件，参考epoll_ctl的事件类型。
- `data`：回调函数的入参。
- `cb`：回调函数。

返回值

- 0表示成功，-1表示失败。

描述

- 管理loop上的监听fd事件，事件的监听和回调执行在loop线程上处理。

**ffrt_loop_timer_start**

声明

```c
FFRT_C_API ffrt_timer_t ffrt_loop_timer_start(ffrt_loop_t loop, uint64_t timeout, void* data, ffrt_timer_cb cb, bool repeat);
```

参数

- `loop`：loop对象。
- `timeout`：定时器时间，单位是毫秒。
- `cb`：到期后的回调函数。
- `data`：回调函数的输入参数。
- `repeat`：是否循环定时器。

返回值

- `ffrt_timer_t`定时器句柄。

描述

- 在loop上启动一个定时器，用法和`ffrt_timer_start`一致，只是定时器的监听和回调执行在loop线程上处理。

**ffrt_loop_timer_stop**

声明

```c
FFRT_C_API int ffrt_loop_timer_stop(ffrt_loop_t loop, ffrt_timer_t handle);
```

参数

- `loop`：loop对象。
- `handle`：定时器句柄。

返回值

- 0表示成功，-1表示失败。

描述

- 取消一个定时器，用法和`ffrt_timer_stop`一致。

**样例**

- 样例1：循环与并发队列：

    ```c
    #include <pthread.h>
    #include <stdio.h>
    #include "ffrt/loop.h"

    void* ThreadFunc(void* p)
    {
        int ret = ffrt_loop_run(p);
        if (ret == 0) {
            printf("loop normal operation.");
        }
        return NULL;
    }

    int main()
    {
        // 创建并发队列
        ffrt_queue_attr_t queue_attr;
        (void)ffrt_queue_attr_init(&queue_attr);
        ffrt_queue_t queue_handle = ffrt_queue_create(ffrt_queue_concurrent, "test_queue", &queue_attr);

        // 创建loop
        ffrt_loop_t loop = ffrt_loop_create(queue_handle);

        // 启动独立线程来执行loop
        pthread_t thread;
        int ret = pthread_create(&thread, 0, ThreadFunc, loop);
        if (ret != 0) {
            printf("pthread_create failed!");
            ffrt_loop_destroy(loop);
            ffrt_queue_attr_destroy(&queue_attr);
            ffrt_queue_destroy(queue_handle);
            return 0;
        }

        // 终止并销毁loop
        ffrt_loop_stop(loop);
        ffrt_loop_destroy(loop);

        // 销毁并发队列
        ffrt_queue_attr_destroy(&queue_attr);
        ffrt_queue_destroy(queue_handle);
        return 0;
    }
    ```

- 样例2：循环、并发队列和定时器：

    ```cpp
    #include <pthread.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <functional>
    #include <sys/epoll.h>
    #include <sys/eventfd.h>
    #include "ffrt/loop.h"
    #include "ffrt/cpp/task.h"

    void* ThreadFunc(void* p)
    {
        ffrt_loop_run(p);
        return nullptr;
    }

    static void test_fun(void* data)
    {
        *(int*)data += 1;
    }

    static void (*cb)(void*) = test_fun;

    void testCallBack(void *data, unsigned int events) {}

    struct TestData {
        int fd;
        uint64_t expected;
    };

    int main()
    {
        // 创建并发队列
        ffrt_queue_attr_t queue_attr;
        (void)ffrt_queue_attr_init(&queue_attr);
        ffrt_queue_t queue_handle = ffrt_queue_create(ffrt_queue_concurrent, "test_queue", &queue_attr);

        // 创建loop
        auto loop = ffrt_loop_create(queue_handle);
        int result1 = 0;

        // 向loop队列提交一个任务
        std::function<void()> &&basicFunc1 = [&result1]() { result1 += 10; };
        ffrt_task_handle_t task = ffrt_queue_submit_h(queue_handle, ffrt::create_function_wrapper(basicFunc1, ffrt_function_kind_queue), nullptr);

        // 启动独立线程来执行loop
        pthread_t thread;
        int ret = pthread_create(&thread, 0, ThreadFunc, loop);
        if (ret != 0) {
            printf("pthread_create failed!");
            ffrt_loop_destroy(loop);
            ffrt_queue_attr_destroy(&queue_attr);
            ffrt_queue_destroy(queue_handle);
            return 0;
        }

        static int x = 0;
        int* xf = &x;
        void* data = xf;
        uint64_t timeout1 = 20;
        uint64_t timeout2 = 10;
        uint64_t expected = 0xabacadae;

        int testFd = eventfd(0, EFD_NONBLOCK | EFD_CLOEXEC);
        struct TestData testData {.fd = testFd, .expected = expected};

        // 向loop注册一个定时器
        ffrt_timer_t timeHandle = ffrt_loop_timer_start(loop, timeout1, data, cb, false);

        // 向loop注册一个fd监听
        int ret = ffrt_loop_epoll_ctl(loop, EPOLL_CTL_ADD, testFd, EPOLLIN, (void*)(&testData), testCallBack);
        if (ret == 0) {
            printf("ffrt_loop_epoll_ctl执行成功。\n");
        }
        ssize_t n = write(testFd, &expected, sizeof(uint64_t));
        usleep(25000);
        // 删除fd监听
        ffrt_loop_epoll_ctl(loop, EPOLL_CTL_DEL, testFd, 0, nullptr, nullptr);

        // 终止loop
        ffrt_loop_stop(loop);
        pthread_join(thread, nullptr);

        // 删除定时器
        ffrt_loop_timer_stop(loop, timeHandle);

        // 销毁loop
        ret = ffrt_loop_destroy(loop);

        // 销毁并发队列
        ffrt_queue_attr_destroy(&queue_attr);
        ffrt_queue_destroy(queue_handle);
        return 0;
    }
    ```

## 纤程

### ffrt_fiber_t

**声明**

```c
struct ffrt_fiber_t;
```

**描述**

- 纤程是一种轻量级的用户态线程，用于在用户空间内实现高效的任务调度和上下文切换。
- `ffrt_fiber_t`为纤程存储实体类型，用于保存和恢复执行上下文。

**方法**

**ffrt_fiber_init**

声明

```c
FFRT_C_API int ffrt_fiber_init(ffrt_fiber_t* fiber, void(*func)(void*), void* arg, void* stack, size_t stack_size);
```

参数

- `fiber`：纤程指针。
- `func`：纤程启动时的函数指针入口。
- `arg`：纤程启动时的函数入参。
- `stack`：纤程运行时使用的栈空间起始地址。
- `stack_size`：纤程栈大小，单位为字节。

返回值

- 初始化成功返回`ffrt_success`，否则返回`ffrt_error`。
- 返回错误的常见原因是`stack_size`不满足最小栈空间限制（不同平台存在差异），建议设置栈空间大小为4KB或以上。

描述

- 该函数用于初始化纤程，需要传入启动纤程的函数指针和入参，以及运行时使用的栈空间，纤程不管理任何的内存，栈的生命周期由调用方管理。

**ffrt_fiber_switch**

声明

```c
FFRT_C_API void ffrt_fiber_switch(ffrt_fiber_t* from, ffrt_fiber_t* to);
```

参数

- `from`：调用该函数的线程会暂停当前任务的执行，并保存当前上下文到`from`指向的纤程。
- `to`：将`to`指向的纤程恢复到当前上下文，调用该函数的线程将执行`to`对应的任务。

描述

- 切换纤程上下文时，调用该函数的线程会暂停当前任务，保存上下文到`from`纤程，并恢复`to`纤程上下文，执行`to`对应的任务。
- 注意：本接口不校验`from`、`to`的有效性，调用方需自行校验地址有效性，否则会导致该进程崩溃。
