# Function Flow Runtime C APIs

<!--Kit: Function Flow Runtime Kit-->
<!--Subsystem: Resourceschedule-->
<!--Owner: @chuchihtung; @yanleo-->
<!--Designer: @geoffrey_guo; @huangyouzhong-->
<!--Tester: @lotsof; @sunxuhao-->
<!--Adviser: @foryourself-->

## Task Management

### ffrt_deps_t

**Declaration**

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

**Parameters**

- `len`: number of data dependencies.
- `items`: data dependency array. The data length is equal to `len`.
- `ptr`: data address.
- `type`: data type. It is different from `task_handle`.

**Description**

The function of `ffrt_dependence_t` is the same as that of `dependence` in C++, and the function of `ffrt_deps_t` is the same as that of `std::vector<dependence>` in C++.

**Example**

```c
// Create a data dependency.
int x = 0;
ffrt_dependence_t data_dependence[1];
data_dependence[0].type = ffrt_dependence_data;
data_dependence[0].ptr = &x;
ffrt_deps_t data_deps;
data_deps.len = 1;
data_deps.items = data_dependence;

// Create a task dependency.
ffrt_task_handle_t task = ffrt_submit_h_base(user_function_header, NULL, NULL, &attr);
ffrt_dependence_t task_dependence[1];
task_dependence[0].type = ffrt_dependence_task;
task_dependence[0].ptr = task;
ffrt_deps_t task_deps;
task_deps.len = 1;
task_deps.items = task_dependence;
```

### ffrt_task_attr_t

**Declaration**

```c
typedef struct {
    uint32_t storage[(ffrt_task_attr_storage_size + sizeof(uint32_t) - 1) / sizeof(uint32_t)];
} ffrt_task_attr_t;
```

**Description**

Describes the task attribute, which can be configured using `ffrt_task_attr_t` when submitting a common task or queue task.

**Methods**

**ffrt_task_attr_init**

```c
FFRT_C_API int ffrt_task_attr_init(ffrt_task_attr_t* attr);
```

Parameters

- `attr`: pointer to the `ffrt_task_attr_t` object.

Return Values

- The value **0** indicates success, and the value **-1** indicates failure.

Description

- Initializes an `ffrt_task_attr_t` object.

**ffrt_task_attr_destroy**

```c
FFRT_C_API void ffrt_task_attr_destroy(ffrt_task_attr_t* attr);
```

Parameters

- `attr`: pointer to the `ffrt_task_attr_t` object.

Description

- Destroys an `ffrt_task_attr_t` object.

**ffrt_task_attr_set_name**

```c
FFRT_C_API void ffrt_task_attr_set_name(ffrt_task_attr_t* attr, const char* name);
```

Parameters

- `attr`: pointer to the `ffrt_task_attr_t` object.
- `name`: task name.

Description

- Sets the task name, which is valid for printing maintenance and test information.

**ffrt_task_attr_get_name**

```c
FFRT_C_API const char* ffrt_task_attr_get_name(const ffrt_task_attr_t* attr);
```

Parameters

- `attr`: pointer to the `ffrt_task_attr_t` object.

Return Values

- Task name.

Description

- Obtains the task name.

**ffrt_task_attr_set_qos**

```c
FFRT_C_API void ffrt_task_attr_set_qos(ffrt_task_attr_t* attr, ffrt_qos_t qos);
```

Parameters

- `attr`: pointer to the `ffrt_task_attr_t` object.
- `qos`: QoS.

Description

- Sets the task QoS, which determines the system resource supply during task execution. If QoS is not set, the queue QoS is inherited by default. The default QoS of a common task is `ffrt_qos_default`.

**ffrt_task_attr_get_qos**

```c
FFRT_C_API ffrt_qos_t ffrt_task_attr_get_qos(const ffrt_task_attr_t* attr);
```

Parameters

- `attr`: pointer to the `ffrt_task_attr_t` object.

Return Values

- QoS.

Description

- Obtains the configured QoS.

**ffrt_task_attr_set_delay**

```c
FFRT_C_API void ffrt_task_attr_set_delay(ffrt_task_attr_t* attr, uint64_t delay_us);
```

Parameters

- `attr`: pointer to the `ffrt_task_attr_t` object.
- `delay_us`: scheduling delay. The unit is μs.

Description

- Sets the scheduling delay of a task. The task is scheduled and executed after the delay interval. If delay is not set, the value is **0** by default.

**ffrt_task_attr_get_delay**

```c
FFRT_C_API uint64_t ffrt_task_attr_get_delay(const ffrt_task_attr_t* attr);
```

Parameters

- `attr`: pointer to the `ffrt_task_attr_t` object.

Return Values

- Scheduling delay.

Description

- Obtains the configured scheduling delay.

**ffrt_task_attr_set_queue_priority**

```c
FFRT_C_API void ffrt_task_attr_set_queue_priority(ffrt_task_attr_t* attr, ffrt_queue_priority_t priority);
```

Parameters

- `attr`: pointer to the `ffrt_task_attr_t` object.
- `priority`: task priority.

Description

- Sets the task priority. Currently, only concurrent queue tasks support the priority function. Tasks in the same concurrent queue are scheduled based on their priorities. If the priority is not set, `ffrt_queue_priority_low` is used by default.

**ffrt_task_attr_get_queue_priority**

```c
FFRT_C_API ffrt_queue_priority_t ffrt_task_attr_get_queue_priority(const ffrt_task_attr_t* attr);
```

Parameters

- `attr`: pointer to the `ffrt_task_attr_t` object.

Return Values

- Task priority.

Description

- Obtains the configured priority.

**ffrt_task_attr_set_stack_size**

```c
FFRT_C_API void ffrt_task_attr_set_stack_size(ffrt_task_attr_t* attr, uint64_t size);
```

Parameters

- `attr`: pointer to the `ffrt_task_attr_t` object.
- `size`: size of the coroutine stack, in bytes.

Description

- Sets the size of the coroutine stack, which affects the maximum space used by the call stack during task execution. If this parameter is not set, the default size of the coroutine stack is 1 MB.

**ffrt_task_attr_get_stack_size**

```c
FFRT_C_API uint64_t ffrt_task_attr_get_stack_size(const ffrt_task_attr_t* attr);
```

Parameters

- `attr`: pointer to the `ffrt_task_attr_t` object.

Return Values

- Size of the coroutine stack.

Description

- Obtains the size of the coroutine stack.

**Example**

```c
// Submit a common task. The task name is sample_task, the QoS is background, the scheduling delay is 1 ms, and the coroutine stack size is 2 MB.
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

**Declaration**

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

**Parameters**

- `kind`: `ffrt_function_kind_general` for submitting a common task; `ffrt_function_kind_queue` for submitting a queue task.
- `exec`: function pointer invoked during task execution.
- `destroy`: function pointer invoked after a task is complete. It can be used to destroy resources.
- `reserve`: internal reserved space. It cannot be used by users.

**Return Values**

- Pointer to the executor of the user task.

**Description**

Allocates memory space. The header of the memory space is in the `ffrt_function_header_t` structure. The return pointer can be converted into the `ffrt_function_header_t*` pointer. A 64-byte space is reserved after the header for customizing the space for storing input parameters or return values.

**Example**

- Example 1: Generate a task executor without parameters and return values.

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

- Example 2: Generate a task executor with parameters and return values.

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

    // Custom task executor, which can carry parameters and return values.
    typedef struct {
        ffrt_function_header_t header; // The header space is ffrt_function_header_t.
        int arg1; // Argument 1
        int arg2; // Argument 2
        int ret; // Return value
    } user_defined_function;

    // Wrap foo into the exec function type of void(*)(void*).
    void exec_func_wrapper(void* header)
    {
        user_defined_function* func = (user_defined_function*)header;
        func->ret = foo(func->arg1, func->arg2); // Expand the foo function, pass arguments, and obtain the return value.
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

**Declaration**

```c
FFRT_C_API void ffrt_submit_base(ffrt_function_header_t* f, const ffrt_deps_t* in_deps, const ffrt_deps_t* out_deps, const ffrt_task_attr_t* attr);
```

**Parameters**

- `f`: task executor of a user. The value can be of the native `ffrt_function_header_t` type or a custom extension type based on `ffrt_function_header_t`.
- `in_deps`: input data dependency of a task. It is usually expressed as the actual data address. `ffrt_task_handle_t` can also be used as a special input dependency.
- `out_deps`: output data dependency of a task. It is usually expressed as the actual data address. `ffrt_task_handle_t` is not supported.
- `attr`: task attribute.

**Description**

Submits a common task that supports attribute settings. After the input dependency is removed, the task can be scheduled and executed. After the task is executed, the output dependency is removed.

**Example**

- Example 1: Submit a task with attributes.

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
        // Submit a task.
        ffrt_function_header_t* func = (ffrt_function_header_t*)ffrt_alloc_auto_managed_function_storage_base(ffrt_function_kind_general);
        func->exec = foo;
        func->destroy = after_foo;
        ffrt_submit_base(func, NULL, NULL, NULL);

        // Submit a task with attributes.
        ffrt_task_attr_t attr;
        ffrt_task_attr_init(&attr);
        ffrt_task_attr_set_name(&attr, "sample_task");
        ffrt_task_attr_set_qos(&attr, ffrt_qos_background);
        ffrt_submit_base(func, NULL, NULL, &attr);

        return 0;
    }
    ```

- Example 2: Submit a task with data dependency.

    ```c
    // Submit two tasks with data dependency. The Read-After-Write dependency exists between tasks.
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
        float* arg1; // Argument 1
        float* arg2; // Argument 2
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

**Declaration**

```c
FFRT_C_API void ffrt_submit_f(ffrt_function_t func, void* arg, const ffrt_deps_t* in_deps, const ffrt_deps_t* out_deps, const ffrt_task_attr_t* attr);
```

**Parameters**

- `func`: specified task function.
- `arg`: parameter passed to the task function.
- `in_deps`: input data dependency of a task. It is usually expressed as the actual data address. `ffrt_task_handle_t` can also be used as a special input dependency.
- `out_deps`: output data dependency of a task. It is usually expressed as the actual data address. `ffrt_task_handle_t` is not supported.
- `attr`: task attribute.

**Description**

`ffrt_submit_f` is a simplified form of `ffrt_submit_base`. When the callback function does not need to be destroyed, the API packages the task function and its parameters into a common task structure. Then, `ffrt_submit_base` is called to submit the task.

**Example**

```cpp
#include <stdio.h>
#include "ffrt/task.h"

// Function to be submitted for execution.
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

**Declaration**

```c
typedef void* ffrt_task_handle_t;

FFRT_C_API ffrt_task_handle_t ffrt_submit_h_base(ffrt_function_header_t* f, const ffrt_deps_t* in_deps, const ffrt_deps_t* out_deps, const ffrt_task_attr_t* attr);
```

**Parameters**

- `f`: task executor of a user. The value can be of the native `ffrt_function_header_t` type or a custom extension type based on `ffrt_function_header_t`.
- `in_deps`: input data dependency of a task. It is usually expressed as the actual data address. `ffrt_task_handle_t` can also be used as a special input dependency.
- `out_deps`: output data dependency of a task. It is usually expressed as the actual data address. `ffrt_task_handle_t` is not supported.
- `attr`: task attribute.

**Return Values**

- `ffrt_task_handle_t` task handle.

**Description**

Compared with the `ffrt_submit_base` API, the return value of the task handle is added.

**Example**

```c
// Submit a task and obtain the task handle.
ffrt_function_header_t* func = (ffrt_function_header_t*)ffrt_alloc_auto_managed_function_storage_base(ffrt_function_kind_general);
func->exec = foo;
func->destroy = after_foo;
ffrt_task_handle_t t = ffrt_submit_h_base(func, NULL, NULL, NULL);
// Note that ffrt_task_handle_t of the C API needs to be explicitly destroyed by calling ffrt_task_handle_destroy.
ffrt_task_handle_destroy(t);
```

### ffrt_submit_h_f

**Declaration**

```c
typedef void* ffrt_task_handle_t;

FFRT_C_API ffrt_task_handle_t ffrt_submit_h_f(ffrt_function_t func, void* arg, const ffrt_deps_t* in_deps, const ffrt_deps_t* out_deps, const ffrt_task_attr_t* attr);
```

**Parameters**

- `func`: specified task function.
- `arg`: parameter passed to the task function.
- `in_deps`: input data dependency of a task. It is usually expressed as the actual data address. `ffrt_task_handle_t` can also be used as a special input dependency.
- `out_deps`: output data dependency of a task. It is usually expressed as the actual data address. `ffrt_task_handle_t` is not supported.
- `attr`: task attribute.

**Return Values**

- `ffrt_task_handle_t` task handle.

**Description**

Adds the return value of the task handle compared with `ffrt_submit_f`.

**Example**

```cpp
#include <stdio.h>
#include <vector>
#include "ffrt/task.h"

// Function to be submitted for execution.
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

**Declaration**

```c
FFRT_C_API uint32_t ffrt_task_handle_inc_ref(ffrt_task_handle_t handle);
```

**Parameters**

- `handle`: task handle.

**Return Values**

- Reference count of a task.

**Description**

Increases the reference count of the task through the task handle by one each time the task handle is invoked. It is used to control the task lifecycle. When the reference count is not 0, the corresponding task resources are not released. Note that `ffrt_task_handle_t` returned by `ffrt_submit_h_base` has a reference count by default. By default, you can subtract a reference count when using `ffrt_task_handle_destroy` to destroy `ffrt_task_handle_t`.

### ffrt_task_handle_dec_ref

**Declaration**

```c
FFRT_C_API uint32_t ffrt_task_handle_dec_ref(ffrt_task_handle_t handle);
```

**Parameters**

- `handle`: task handle.

**Return Values**

- Reference count of a task.

**Description**

Subtracts the reference count of the task through the task handle by one each time the task handle is invoked.

### ffrt_task_handle_destroy

**Declaration**

```c
FFRT_C_API void ffrt_task_handle_destroy(ffrt_task_handle_t handle);
```

**Parameters**

- `handle`: task handle.

**Description**

Destroys a task handle and subtracts a task reference count by default.

### ffrt_wait

**Declaration**

```c
FFRT_C_API void ffrt_wait(void);
```

**Description**

Waits until all tasks of the same level submitted earlier are complete.

**Example**

```c
// Wait until three tasks are complete.
ffrt_submit_base(func1, NULL, NULL, NULL);
ffrt_submit_base(func2, NULL, NULL, NULL);
ffrt_submit_base(func3, NULL, NULL, NULL);
ffrt_wait();
```

### ffrt_wait_deps

**Declaration**

```c
FFRT_C_API void ffrt_wait_deps(const ffrt_deps_t* deps);
```

**Parameters**

- `deps`: data dependency to be synchronized.

**Description**

Waits until the data dependency is removed.

**Example**

```c
// Build the data dependency of x.
int x = 0;
ffrt_dependence_t dependence[1];
dependence[0].type = ffrt_dependence_data;
dependence[0].ptr = &x;
ffrt_deps_t deps;
deps.len = 1;
deps.items = dependence;

// Submit a write task.
ffrt_submit_base(func, NULL, &deps, NULL);

// Wait until the data dependency of the write task is removed.
ffrt_wait_deps(&deps);
```

### ffrt_this_task_update_qos

**Declaration**

```c
FFRT_C_API int ffrt_this_task_update_qos(ffrt_qos_t qos);
```

**Parameters**

- `qos`: QoS.

**Return Values**

- The value **0** indicates success, and the value **1** indicates failure.

**Description**

Updates the task QoS dynamically during task execution. Note that this API is used in the function closure of a task to update the QoS of the task that is being executed. If this API is invoked, the task is suspended and then resumed.

**Example**

```c
// Dynamically update the QoS during the execution of a qos_background task.
ffrt::submit([]() {
    // ...
    int ret = ffrt_this_task_update_qos(ffrt_qos_user_initiated);
    // ...
}, ffrt::task_attr().qos(ffrt::qos_background));
```

### ffrt_this_task_get_qos

**Declaration**

```c
FFRT_C_API ffrt_qos_t ffrt_this_task_get_qos(void);
```

**Return Values**

- QoS.

**Description**

Obtains the QoS of the task that is being executed.

**Example**

```c
// Dynamically obtain the QoS during the execution of a task.
ffrt::submit([]() {
    // ...
    // The obtained QoS is ffrt_qos_background.
    ffrt_qos_t qos = ffrt_this_task_get_qos();
    // ...
}, ffrt::task_attr().qos(ffrt::qos_background));
```

### ffrt_this_task_get_id

**Declaration**

```c
FFRT_C_API uint64_t ffrt_this_task_get_id(void);
```

**Return Values**

- Task ID.

**Description**

Obtains the ID of the task that is being executed.

**Example**

```c
// Dynamically obtain the task ID during task execution.
ffrt::submit([]() {
    // ...
    // Obtain the unique task ID.
    uint64_t task_id = ffrt_this_task_get_id();
    // ...
}, ffrt::task_attr().qos(ffrt::qos_background));
```

## Task Queue

### ffrt_queue_attr_t

**Declaration**

```c
typedef struct {
    uint32_t storage[(ffrt_queue_attr_storage_size + sizeof(uint32_t) - 1) / sizeof(uint32_t)];
} ffrt_queue_attr_t;
```

**Description**

Configures queue attributes, such as the QoS, timeout, callback function, and maximum concurrency.

**Methods**

**ffrt_queue_attr_init**

```c
int ffrt_queue_attr_init(ffrt_queue_attr_t* attr);
```

Parameters

- `attr`: pointer to the queue attribute.

Return Values

- The value **0** indicates success while other values indicate failure.

Description

- Initializes a queue attribute object.

**ffrt_queue_attr_destroy**

```c
void ffrt_queue_attr_destroy(ffrt_queue_attr_t* attr);
```

Parameters

- `attr`: pointer to the queue attribute.

Description

- Destroys a queue attribute object.

**ffrt_queue_attr_set_qos**

```c
void ffrt_queue_attr_set_qos(ffrt_queue_attr_t* attr, ffrt_qos_t qos);
```

Parameters

- `attr`: pointer to the queue attribute.
- `qos`: QoS.

Description

- Sets the queue QoS.

**ffrt_queue_attr_get_qos**

```c
ffrt_qos_t ffrt_queue_attr_get_qos(const ffrt_queue_attr_t* attr);
```

Parameters

- `attr`: pointer to the queue attribute.

Return Values

- Current QoS.

Description

- Obtains the QoS set in the current attribute.

**ffrt_queue_attr_set_timeout**

```c
void ffrt_queue_attr_set_timeout(ffrt_queue_attr_t* attr, uint64_t timeout_us);
```

Parameters

- `attr`: pointer to the queue attribute.
- `timeout_us`: timeout (μs).

Description

- Sets the queue timeout (unit: μs).

**ffrt_queue_attr_get_timeout**

```c
uint64_t ffrt_queue_attr_get_timeout(const ffrt_queue_attr_t* attr);
```

Parameters

- `attr`: pointer to the queue attribute.

Return Values

- Current timeout threshold (μs).

Description

- Obtains the timeout set in the current attribute.

**ffrt_queue_attr_set_callback**

```c
void ffrt_queue_attr_set_callback(ffrt_queue_attr_t* attr, ffrt_function_header_t* f);
```

Parameters

- `attr`: pointer to the queue attribute.
- `f`: pointer to the task executor, which describes how to execute and destroy the CPU task.

Description

- Sets the callback function to be executed after a queue task times out.

**ffrt_queue_attr_get_callback**

```c
ffrt_function_header_t* ffrt_queue_attr_get_callback(const ffrt_queue_attr_t* attr);
```

Parameters

- `attr`: pointer to the queue attribute.

Return Values

- Pointer to the task executor, which describes how to execute and destroy the CPU task.

Description

- Obtains the timeout callback function set in the current attribute.

**ffrt_queue_attr_set_max_concurrency**

```c
void ffrt_queue_attr_set_max_concurrency(ffrt_queue_attr_t* attr, const int max_concurrency);
```

Parameters

- `attr`: pointer to the queue attribute.
- `max_concurrency`: maximum concurrency.

Description

- Sets the maximum queue concurrency. (Only concurrent queues are supported.)

**ffrt_queue_attr_get_max_concurrency**

```c
int ffrt_queue_attr_get_max_concurrency(const ffrt_queue_attr_t* attr);
```

Parameters

- `attr`: pointer to the queue attribute.

Return Values

- Maximum concurrency.

Description

- Obtains the maximum concurrency set in the current attribute. (Only concurrent queues are supported).

**ffrt_queue_attr_set_thread_mode**

```c
void ffrt_queue_attr_set_thread_mode(ffrt_queue_attr_t* attr, bool mode);
```

Parameters

- `attr`: pointer to the queue attribute.
- `mode`: running mode of the queue task. The value `true` indicates the thread mode, and the value `false` indicates the coroutine mode.

Description

- Sets the running mode of tasks in the queue. By default, the coroutine mode is used.

> **NOTE**

> This API is supported since API version 20.

**ffrt_queue_attr_get_thread_mode**

```c
bool ffrt_queue_attr_get_thread_mode(const ffrt_queue_attr_t* attr);
```

Parameters

- `attr`: pointer to the queue attribute.

Return Values

- The value `true` indicates the thread mode, and the value `false` indicates the coroutine mode.

Description

- Obtains the running mode of tasks in the queue.

> **NOTE**

> This API is supported since API version 20.

**Example**

```cpp
#include <functional>
#include "ffrt/queue.h"
#include "ffrt/cpp/task.h"

int main()
{
    ffrt_queue_attr_t queue_attr;
    // (Mandatory) Initialize the queue attribute.
    ffrt_queue_attr_init(&queue_attr);

    ffrt_queue_attr_set_qos(&queue_attr, static_cast<int>(ffrt_qos_utility));

    ffrt_queue_attr_set_timeout(&queue_attr, 10000);

    int x = 0;
    std::function<void()>&& basicFunc = [&x]() { x += 1; };
    ffrt_function_header_t* func = ffrt_queue_attr_get_callback(&queue_attr);

    ffrt_queue_attr_set_callback(&queue_attr, ffrt::create_function_wrapper(basicFunc, ffrt_function_kind_queue));
    // Destroy the queue attribute. This is mandatory.
    ffrt_queue_attr_destroy(&queue_attr);
    return 0;
}
```

### ffrt_queue_t

**Declaration**

```c
typedef void* ffrt_queue_t;
```

**Description**

Pointer to queues. It provides a series of C APIs for submitting, canceling, and waiting queue tasks and querying the number of queuing tasks.

**Methods**

**ffrt_queue_create**

```c
ffrt_queue_t ffrt_queue_create(ffrt_queue_type_t type, const char* name, const ffrt_queue_attr_t* attr);
```

Parameters

- `type`: queue type, for example, `ffrt_queue_serial` or `ffrt_queue_concurrent`.
- `name`: queue name.
- `attr`: pointer to the queue attribute.

Return Values

- `ffrt_queue_t`: If the function is called successfully, a non-null queue handle is returned. Otherwise, a null pointer is returned.

Description

- Creates a queue with a specified type and name.

**ffrt_queue_destroy**

```c
void ffrt_queue_destroy(ffrt_queue_t queue);
```

Parameters

- `queue`: queue handle.

Description

- Destroys a queue.

**ffrt_queue_submit**

```c
void ffrt_queue_submit(ffrt_queue_t queue, ffrt_function_header_t* f, const ffrt_task_attr_t* attr);
```

Parameters

- `queue`: queue handle.
- `f`: pointer to the task executor, which describes how to execute and destroy the CPU task.
- `attr`: task attribute.

Description

- Submits a task to a queue.

**ffrt_queue_submit_f**

```c
void ffrt_queue_submit_f(ffrt_queue_t queue, ffrt_function_t func, void* arg, const ffrt_task_attr_t* attr);
```

Parameters

- `queue`: queue handle.
- `func`: specified task function.
- `arg`: parameter passed to the task function.
- `attr`: task attribute.

Description

- Submits a task to the queue when the callback function does not need to be destroyed.

**ffrt_queue_submit_h**

```c
ffrt_task_handle_t ffrt_queue_submit_h(ffrt_queue_t queue, ffrt_function_header_t* f, const ffrt_task_attr_t* attr);
```

Parameters

- `queue`: queue handle.
- `f`: pointer to the task executor, which describes how to execute and destroy the CPU task.
- `attr`: task attribute.

Return Values

- `ffrt_task_handle_t`: If the function is called successfully, a non-null task handle is returned. Otherwise, a null pointer is returned.

Description

- Submits a task to a queue and returns a task handle.

**ffrt_queue_submit_h_f**

```c
ffrt_task_handle_t ffrt_queue_submit_h_f(ffrt_queue_t queue, ffrt_function_t func, void* arg, const ffrt_task_attr_t* attr);
```

Parameters

- `queue`: queue handle.
- `func`: specified task function.
- `arg`: parameter passed to the task function.
- `attr`: task attribute.

Return Values

- `ffrt_task_handle_t`: If the function is called successfully, a non-null task handle is returned. Otherwise, a null pointer is returned.

Description

- Submits a task to the queue and returns the task handle when the callback function does not need to be destroyed.

**ffrt_queue_wait**

```c
void ffrt_queue_wait(ffrt_task_handle_t handle);
```

Parameters

- `ffrt_task_handle_t`: task handle.

Description

- Waits for a queue task to complete.

**ffrt_queue_cancel**

```c
int ffrt_queue_cancel(ffrt_task_handle_t handle);
```

Parameters

- `ffrt_task_handle_t`: task handle.

Return Values

- The value **0** indicates success while other values indicate failure.

Description

- Cancels a queue task.

**ffrt_get_main_queue**

```c
ffrt_queue_t ffrt_get_main_queue();
```

Return Values

- Main thread queue.

Description

- Obtains the main thread queue for the FFRT thread to communicate with the main thread.

**ffrt_get_current_queue**

```c
ffrt_queue_t ffrt_get_current_queue();
```

Return Values

- ArkTS Worker thread queue.

Description

- This API has been deprecated since API version 18. You are not advised to use it.
- Obtains the ArkTS Worker thread queue for the FFRT thread to communicate with the ArkTS Worker thread.

**Example**

```cpp
#include "ffrt/queue.h"
#include "ffrt/cpp/task.h"

int main()
{
    ffrt_queue_attr_t queue_attr;
    // 1. Initialize the queue attribute. This is mandatory.
    (void)ffrt_queue_attr_init(&queue_attr);

    // 2. Create a serial queue and return queue_handle.
    ffrt_queue_t queue_handle = ffrt_queue_create(ffrt_queue_serial, "test_queue", &queue_attr);

    int result = 0;
    std::function<void()>&& basicFunc = [&result]() { result += 1; };

    // 3. Submit a serial task.
    ffrt_queue_submit(queue_handle, ffrt::create_function_wrapper(basicFunc, ffrt_function_kind_queue), nullptr);

    // 4. Submit the serial task and return the task handle.
    ffrt_task_handle_t t1 = ffrt_queue_submit_h(queue_handle, ffrt::create_function_wrapper(basicFunc, ffrt_function_kind_queue), nullptr);
    // 5. Wait until the specified task is complete.
    ffrt_queue_wait(t1);

    ffrt_task_handle_t t2 = ffrt_queue_submit_h(queue_handle, ffrt::create_function_wrapper(basicFunc, ffrt_function_kind_queue), nullptr);
    // 6. Cancel the task with handle t2.
    ffrt_queue_cancel(t2);

    // 7. Destroy the handles t1 and t2 submitted to the serial queue task. This is mandatory.
    ffrt_task_handle_destroy(t1);
    ffrt_task_handle_destroy(t2);
    // 8. Destroy the queue attribute. This is mandatory.
    ffrt_queue_attr_destroy(&queue_attr);
    // 9. Destroy the queue handle. This is mandatory.
    ffrt_queue_destroy(queue_handle);
    return 0;
}
```

## Synchronization Primitive

### ffrt_mutexattr_t

**Declaration**

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

**Description**

- Provides performance implementation similar to pthread mutex.

**Methods**

**ffrt_mutexattr_init**

```c
FFRT_C_API int ffrt_mutexattr_init(ffrt_mutexattr_t* attr);
```

Parameters

- `attr`: FFRT mutex attribute.

Return Values

- `ffrt_success` is returned if `attr` is not empty. Otherwise, `ffrt_error_inval` is returned.

Description

- Initializes `mutexattr`.

**ffrt_mutexattr_destroy**

```c
FFRT_C_API int ffrt_mutexattr_destroy(ffrt_mutexattr_t* attr);
```

Parameters

- `attr`: FFRT mutex attribute.

Return Values

- `ffrt_success` is returned if `attr` is not empty. Otherwise, `ffrt_error_inval` is returned.

Description

- Destroys `mutexattr`.

**ffrt_mutexattr_settype**

```c
FFRT_C_API int ffrt_mutexattr_settype(ffrt_mutexattr_t* attr, int type);
```

Parameters

- `attr`: FFRT mutex attribute.
- `type`: FFRT mutex type. Currently, only `ffrt_mutex_normal` and `ffrt_mutex_recursive` are supported.

Return Values

- `ffrt_success` is returned if `attr` is not empty and `type` is valid. Otherwise, `ffrt_error_inval` is returned.

Description

- Sets the FFRT mutex attribute.

**ffrt_mutexattr_gettype**

```c
FFRT_C_API int ffrt_mutexattr_gettype(ffrt_mutexattr_t* attr, int* type);
```

Parameters

- `attr`: FFRT mutex attribute.
- `type`: pointer to the FFRT mutex type.

Return Values

- `ffrt_success` is returned if neither `attr` nor `type` is empty. Otherwise, `ffrt_error_inval` is returned.

Description

- Obtains the FFRT mutex attribute.

**Example**

```c
ffrt_mutexattr_t attr;
// Initialize the mutex attribute.
ffrt_mutexattr_init(&attr);
// Set a mutex.
ffrt_mutexattr_settype(&attr, ffrt_mutex_normal);
// Set a recursive lock.
ffrt_mutexattr_settype(&attr, ffrt_mutex_recursive);
// Obtain the mutex type.
int type = ffrt_mutex_default;
ffrt_mutexattr_gettype(&attr, &type);
// Destroy the mutex attribute.
ffrt_mutexattr_destroy(&attr);
```

### ffrt_mutex_t

- Implements `pthread_mutex_t`, but does not supports initialization of `PTHREAD_MUTEX_INITIALIZER`.

**Declaration**

```c
struct ffrt_mutex_t;
struct ffrt_mutexattr_t;

int ffrt_mutex_init(ffrt_mutex_t* mutex, const ffrt_mutexattr_t* attr);
int ffrt_mutex_lock(ffrt_mutex_t* mutex);
int ffrt_mutex_unlock(ffrt_mutex_t* mutex);
int ffrt_mutex_trylock(ffrt_mutex_t* mutex);
int ffrt_mutex_destroy(ffrt_mutex_t* mutex);
```

**Description**

- This API can be called inside or outside an FFRT task.
- The traditional function `pthread_mutex_t` may cause unexpected kernel mode trap when it fails to lock a mutex. **ffrt_mutex_t** solves this problem and therefore provides better performance if used properly.
- `ffrt_mutexattr_t` in the C API needs to be created and destroyed by calling `ffrt_mutexattr_init` and `ffrt_mutexattr_destroy`. Otherwise, undefined behavior may occur.
- `ffrt_mutex_t` in the C API needs to be explicitly created and destroyed by calling `ffrt_mutex_init` and `ffrt_mutex_destroy`. Otherwise, undefined behavior may occur.
- You need to set the `ffrt_mutex_t` object in the C code to null or destroy the object. For the same `ffrt_mutex_t` object, `ffrt_mutex_destroy` can be called only once. Otherwise, undefined behavior may occur.
- The same `ffrt_mutexattr_t` in the C API can call `ffrt_mutexattr_init` and `ffrt_mutexattr_destroy` only once. Repeated calling may cause undefined behavior.
- You need to explicitly call `ffrt_mutex_destroy` after `ffrt_mutex_init` and before `ffrt_mutexattr_destroy`.
- If `ffrt_mutex_t` is accessed after `ffrt_mutex_destroy`, undefined behavior may occur.

**Methods**

**ffrt_mutex_init**

```c
FFRT_C_API int ffrt_mutex_init(ffrt_mutex_t* mutex, const ffrt_mutexattr_t* attr);
```

Parameters

- `mutex`: pointer to the operated mutex.
- `attr`: FFRT mutex attribute. Its valid value can be a null pointer, `ffrt_mutex_normal`, or `ffrt_mutex_recursive`.

Return Values

- `ffrt_success` is returned if `mutex` is not empty and `attr` is within the valid value range. Otherwise, `ffrt_error_inval` is returned.

Description

- Initializes the FFRT mutex.

**ffrt_mutex_destroy**

```c
FFRT_C_API int ffrt_mutex_destroy(ffrt_mutex_t* mutex);
```

Parameters

- `mutex`: pointer to the operated mutex.

Return Values

- `ffrt_success` is returned if `mutex` is not empty. Otherwise, `ffrt_error_inval` is returned.

Description

- Destroys a specified mutex or recursive lock.

**ffrt_mutex_lock**

```c
FFRT_C_API int ffrt_mutex_lock(ffrt_mutex_t* mutex);
```

Parameters

- `mutex`: pointer to the operated mutex.

Return Values

- `ffrt_success` is returned if `mutex` is not empty. Otherwise, `ffrt_error_inval` is returned.

Description

- Locks a specified mutex or recursive lock. This method blocks the current task until the mutex is successfully obtained.

**ffrt_mutex_unlock**

```c
FFRT_C_API int ffrt_mutex_unlock(ffrt_mutex_t* mutex);
```

Parameters

- `mutex`: pointer to the operated mutex.

Return Values

- `ffrt_success` is returned if `mutex` is not empty. Otherwise, `ffrt_error_inval` is returned.

Description

- Unlocks a specified mutex or recursive lock.

**ffrt_mutex_trylock**

```c
FFRT_C_API int ffrt_mutex_trylock(ffrt_mutex_t* mutex);
```

Parameters

- `mutex`: pointer to the operated mutex.

Return Values

- **ffrt_error_inval** is returned if `mutex` is empty. `ffrt_success` is returned if `mutex` is not empty and the mutex is successfully held. `ffrt_error_busy` is returned if `mutex` is not empty and the mutex fails to be held.

Description

- Locks a specified mutex or recursive lock.

**Example**

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

- Implements `pthread_rwlock_t`.

**Declaration**

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

**Description**

- This API can be called inside or outside an FFRT task.
- This API can avoid the issue that `pthread_rwlock_t` sleeps without releasing threads. The performance is better when the API is properly used.
- `ffrt_rwlock_t` in the C API needs to be explicitly created and destroyed by calling `ffrt_rwlock_init` and `ffrt_rwlock_destroy`. Otherwise, undefined behavior may occur.
- When `ffrt_rwlockattr_t` is called, the input parameter of `ffrt_rwlockattr_t` must be a null pointer.
- You need to set the `ffrt_rwlock_t` object in the C code to null or destroy the object. For the same `ffrt_rwlock_t` object, `ffrt_rwlock_destroy` can be called only once. Otherwise, undefined behavior may occur.
- If `ffrt_rwlock_t` is accessed after `ffrt_rwlock_destroy` is called, undefined behavior may occur.

**Methods**

**ffrt_rwlock_init**

```c
FFRT_C_API int ffrt_rwlock_init(ffrt_rwlock_t* rwlock, const ffrt_rwlockattr_t* attr);
```

Parameters

- `rwlock`: pointer to the operated read-write lock.
- `attr`: pointer to the attribute of the operated read-write lock. Only the default mode is supported. That is, `attr` must be set to a null pointer.

Return Values

- `ffrt_success` is returned if `rwlock` is not empty and `attr` is empty. Otherwise, `ffrt_error_inval` is returned.

Description

- Initializes the read-write lock.

**ffrt_rwlock_wrlock**

```c
FFRT_C_API int ffrt_rwlock_wrlock(ffrt_rwlock_t* rwlock);
```

Parameters

- `rwlock`: pointer to the operated read-write lock.

Return Values

- `ffrt_success` is returned if `rwlock` is not empty. Otherwise, `ffrt_error_inval` is returned.

Description

- Adds a write lock to the specified read-write lock.

**ffrt_rwlock_rdlock**

```c
FFRT_C_API int ffrt_rwlock_rdlock(ffrt_rwlock_t* rwlock);
```

Parameters

- `rwlock`: pointer to the operated read-write lock.

Return Values

- `ffrt_success` is returned if `rwlock` is not empty. Otherwise, `ffrt_error_inval` is returned.

Description

- Adds a read lock to the specified read-write lock.

**ffrt_rwlock_trywrlock**

```c
FFRT_C_API int ffrt_rwlock_trywrlock(ffrt_rwlock_t* rwlock);
```

Parameters

- `rwlock`: pointer to the operated read-write lock.

Return Values

- `ffrt_success` is returned if `rwlock` is not empty and no other thread holds the read-write lock. Otherwise, `ffrt_error_inval` is returned.

Description

- Adds a write lock to the specified read-write lock.

**ffrt_rwlock_tryrdlock**

```c
FFRT_C_API int ffrt_rwlock_tryrdlock(ffrt_rwlock_t* rwlock);
```

Parameters

- `rwlock`: pointer to the operated read-write lock.

Return Values

- `ffrt_success` is returned if `rwlock` is not empty and no other thread holds the write lock. Otherwise, `ffrt_error_inval` is returned.

Description

- Adds a read lock to the specified read-write lock.

**ffrt_rwlock_unlock**

```c
FFRT_C_API int ffrt_rwlock_unlock(ffrt_rwlock_t* rwlock);
```

Parameters

- `rwlock`: pointer to the operated read-write lock.

Return Values

- `ffrt_success` is returned if `rwlock` is not empty. Otherwise, `ffrt_error_inval` is returned.

Description

- Unlocks the specified read-write lock.

**ffrt_rwlock_destroy**

```c
FFRT_C_API int ffrt_rwlock_destroy(ffrt_rwlock_t* rwlock);
```

Parameters

- `rwlock`: pointer to the operated read-write lock.

Return Values

- `ffrt_success` is returned if `rwlock` is not empty. Otherwise, `ffrt_error_inval` is returned.

Description

- Destroys a specified read-write lock.

**Example**

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

- Implements the pthread semaphore function, but does not supports initialization of `PTHREAD_COND_INITIALIZER`.

**Declaration**

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

**Description**

- This API can be called inside or outside an FFRT task.
- The traditional function `pthread_cond_t` may cause unexpected kernel mode trap when the conditions are not met. **ffrt_cond_t** solves this problem and therefore provides better performance if being used properly.
- Note that `ffrt_cond_t` in the C API needs to be explicitly created and destroyed by calling `ffrt_cond_init` and `ffrt_cond_destroy`. However, in the C++ API, the dependency construction and destruction are automatically completed.
- You need to set the `ffrt_cond_t` object in the C code to null or destroy the object. For the same `ffrt_cond_t` object, `ffrt_cond_destroy` can be called only once. Otherwise, undefined behavior may occur.
- If `ffrt_cond_t` is accessed after `ffrt_cond_destroy` is called, undefined behavior may occur.

**Methods**

**ffrt_cond_init**

```c
FFRT_C_API int ffrt_cond_init(ffrt_cond_t* cond, const ffrt_condattr_t* attr);
```

Parameters

- `cond`: pointer to the target semaphore.
- `attr`: pointer to the attribute. A null pointer indicates that the default attribute is used.

Return Values

- `ffrt_success` is returned if `cond` is not empty. Otherwise, `ffrt_error_inval` is returned.

Description

- Initializes the FFRT condition variable.

**ffrt_cond_destroy**

```c
FFRT_C_API int ffrt_cond_destroy(ffrt_cond_t* cond);
```

Parameters

- `cond`: pointer to the target semaphore.

Return Values

- `ffrt_success` is returned if `cond` is not empty. Otherwise, `ffrt_error_inval` is returned.

Description

- Destroys an FFRT condition variable.

**ffrt_cond_signal**

```c
FFRT_C_API int ffrt_cond_signal(ffrt_cond_t* cond);
```

Parameters

- `cond`: pointer to the target semaphore.

Return Values

- `ffrt_success` is returned if `cond` is not empty. Otherwise, `ffrt_error_inval` is returned.

Description

- Unblocks at least one of the threads that are blocked on a condition variable.

**ffrt_cond_broadcast**

```c
FFRT_C_API int ffrt_cond_broadcast(ffrt_cond_t* cond);
```

Parameters

- `cond`: pointer to the target semaphore.

Return Values

- `ffrt_success` is returned if `cond` is not empty. Otherwise, `ffrt_error_inval` is returned.

Description

- Unblocks all threads currently blocked on a condition variable.

**ffrt_cond_wait**

```c
FFRT_C_API int ffrt_cond_wait(ffrt_cond_t* cond, ffrt_mutex_t* mutex);
```

Parameters

- `cond`: pointer to the target semaphore.
- `mutex`: pointer to the target mutex.

Return Values

- `ffrt_success` is returned if neither `cond` nor `mutex` is empty. Otherwise, `ffrt_error_inval` is returned.

Description

- Blocks a task on a condition variable. When using this method, a task releases the input mutex and enters the waiting state. The task obtains the mutex again and continues to execute until another task notifies the condition variable.
- This method is usually used together with `ffrt_mutex_lock` or `ffrt_mutex_trylock` to ensure that the mutex is held before entering the wait state.

**ffrt_cond_timedwait**

```c
FFRT_C_API int ffrt_cond_timedwait(ffrt_cond_t* cond, ffrt_mutex_t* mutex, const struct timespec* time_point);
```

Parameters

- `cond`: pointer to the target semaphore.
- `mutex`: pointer to the target mutex.
- `time_point`: pointer to the maximum duration during which the thread is blocked.

Return Values

- `ffrt_success` is returned if `cond`, `mutex`, and `time_point` are not empty. Otherwise, `ffrt_error_inval` is returned.

Description

- Blocks a task on a condition variable until the specified timeout is reached.
- Unlike `ffrt_cond_wait`, the `ffrt_cond_timedwait` method allows a task to wait for a period of time on a condition variable. If no notification is received within the specified period of time, the task is woken up and the function returns.

**Example**

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

## Blocking Primitive

### ffrt_usleep

**Declaration**

```c
FFRT_C_API int ffrt_usleep(uint64_t usec);
```

**Parameters**

- `usec`: sleep duration, in μs.

**Description**

- Provides performance implementation similar to C11 sleep and Linux usleep.
- This API can be called only inside an FFRT task. If it is called outside an FFRT task, undefined behavior may occur.
- The sleep precision of this API is μs.
- The traditional function `sleep` may cause unexpected kernel mode trap. **ffrt_usleep** solves this problem and therefore provides better performance if used properly.

**Example**

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

## Cooperative Primitive

### ffrt_yield

**Declaration**

```c
FFRT_C_API void ffrt_yield();
```

**Description**

- Yields CPU execution resources for other executable tasks. If there is no other executable task, `yield` is invalid.
- This API can be called only inside an FFRT task. If it is called outside an FFRT task, undefined behavior may occur.
- The exact behavior of this API depends on the implementation, especially the mechanism and system state of the FFRT scheduler in use.

**Example**

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

## Timer

### ffrt_timer_t

**Declaration**

```c
typedef int ffrt_timer_t;
typedef void (*ffrt_timer_cb)(void* data);
```

**Description**

Provides timer-related functions.

**Methods**

**ffrt_timer_start**

Declaration

```c
FFRT_C_API ffrt_timer_t ffrt_timer_start(ffrt_qos_t qos, uint64_t timeout, void* data, ffrt_timer_cb cb, bool repeat);
```

Parameters

- `qos`: QoS.
- `timeout`: timer timeout, in ms.
- `cb`: callback function after expiration.
- `data`: input parameter of the callback function.
- `repeat`: whether the timer is triggered repeatedly.

Return Values

- `ffrt_timer_t`, which indicates the timer handle.

Description

- Starts a timer. If the timer expires and is not stopped, the callback function is executed. If `repeat` is set to `repeat`, the timer is set again after it expires.

**ffrt_timer_stop**

Declaration

```c
FFRT_C_API int ffrt_timer_stop(ffrt_qos_t qos, ffrt_timer_t handle);
```

Parameters

- `qos`: QoS.
- `handle`: timer handle.

Return Values

- The value **0** indicates success, and the value **-1** indicates failure.

Description

- Stops a timer. It is used with `ffrt_timer_start`.
- This is a blocking API and should be avoided in the callback to prevent deadlock or synchronization problems. If the callback corresponding to the input handle is being executed, this function will wait until the callback is complete.

**Example**

- Example 1: Use a one-shot timer.

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
        // Start a timer and execute the callback function after 200 ms.
        int handle = ffrt_timer_start(ffrt_qos_default, timeout, data, cb, false);
        usleep(300000);
        // The timer has been executed and cannot be stopped.
        ffrt_timer_stop(ffrt_qos_default, handle);
        printf("data: %d\n", x); // Set the value of x to 1.
        return 0;
    }
    ```

- Example 2: Use a repeating timer.

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
        // Start a repeating timer and execute the callback function every 200 ms.
        int handle = ffrt_timer_start(ffrt_qos_default, timeout, data, cb, true);
        usleep(500000);
        // Stops the repeating timer.
        ffrt_timer_stop(ffrt_qos_default, handle);
        printf("data: %d\n", x); // Set the value of x to 2.
        return 0;
    }
    ```

## Loop

### ffrt_loop_t

**Declaration**

```c
typedef void* ffrt_loop_t;
```

**Description**

Provides loop-related functions.

**Methods**

**ffrt_loop_create**

Declaration

```c
FFRT_C_API ffrt_loop_t ffrt_loop_create(ffrt_queue_t queue);
```

Parameters

- `queue`: a concurrent queue that needs to be bound with a loop.

Return Values

- `ffrt_loop_t` object.

Description

- Creates a loop and bind a concurrent queue for storing tasks. You can submit a task to the queue so that the task can be executed in the loop.

**ffrt_loop_destroy**

Declaration

```c
FFRT_C_API int ffrt_loop_destroy(ffrt_loop_t loop);
```

Parameters

- `loop`: loop object.

Return Values

- The value **0** indicates success, and the value **-1** indicates failure.

Description

- Destroys a loop and unbinds it from the queue.

**ffrt_loop_run**

Declaration

```c
FFRT_C_API int ffrt_loop_run(ffrt_loop_t loop);
```

Parameters

- `loop`: loop object.

Return Values

- The value **0** indicates success, and the value **-1** indicates failure.

Description

- Runs a loop. The thread that invokes this method executes the loop at the same time, executes queue tasks, and listens for the poller and timer.

**ffrt_loop_stop**

Declaration

```c
FFRT_C_API void ffrt_loop_stop(ffrt_loop_t loop);
```

Parameters

- `loop`: loop object.

Description

- Stops a loop. This method is invoked to enable the thread that executes the loop to exit the loop.

**ffrt_loop_epoll_ctl**

Declaration

```c
int ffrt_loop_epoll_ctl(ffrt_loop_t loop, int op, int fd, uint32_t events, void *data, ffrt_poller_cb cb)
```

Parameters

- `loop`: loop object.
- `op`: FD operator. For details, see the operation type of **epoll_ctl**.
- `fd`: event descriptor.
- `events`: event. For details, see the event type of **epoll_ctl**.
- `data`: input parameter of the callback function.
- `cb`: callback function.

Return Values

- The value **0** indicates success, and the value **-1** indicates failure.

Description

- Manages FD listening on the loop. Event listening and callback are processed on the loop thread.

**ffrt_loop_timer_start**

Declaration

```c
FFRT_C_API ffrt_timer_t ffrt_loop_timer_start(ffrt_loop_t loop, uint64_t timeout, void* data, ffrt_timer_cb cb, bool repeat);
```

Parameters

- `loop`: loop object.
- `timeout`: timer timeout, in ms.
- `cb`: callback function after expiration.
- `data`: input parameter of the callback function.
- `repeat`: whether the timer is triggered repeatedly.

Return Values

- `ffrt_timer_t`, which indicates the timer handle.

Description

- Starts a timer on the loop. The usage is the same as that of `ffrt_timer_start`. The only difference is that the listening and callback execution of the timer are processed on the loop thread.

**ffrt_loop_timer_stop**

Declaration

```c
FFRT_C_API int ffrt_loop_timer_stop(ffrt_loop_t loop, ffrt_timer_t handle);
```

Parameters

- `loop`: loop object.
- `handle`: timer handle.

Return Values

- The value **0** indicates success, and the value **-1** indicates failure.

Description

- Stops a timer. The usage is the same as that of `ffrt_timer_stop`.

**Example**

- Example 1: loop and concurrent queue.

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
        // Create a concurrent queue.
        ffrt_queue_attr_t queue_attr;
        (void)ffrt_queue_attr_init(&queue_attr);
        ffrt_queue_t queue_handle = ffrt_queue_create(ffrt_queue_concurrent, "test_queue", &queue_attr);

        // Create a loop.
        ffrt_loop_t loop = ffrt_loop_create(queue_handle);

        // Create a separate thread to perform the loop.
        pthread_t thread;
        int ret = pthread_create(&thread, 0, ThreadFunc, loop);
        if (ret != 0) {
            printf("pthread_create failed!");
            ffrt_loop_destroy(loop);
            ffrt_queue_attr_destroy(&queue_attr);
            ffrt_queue_destroy(queue_handle);
            return 0;
        }

        // Stop and destroy the loop.
        ffrt_loop_stop(loop);
        ffrt_loop_destroy(loop);

        // Destroy the concurrent queue.
        ffrt_queue_attr_destroy(&queue_attr);
        ffrt_queue_destroy(queue_handle);
        return 0;
    }
    ```

- Example 2: loop, concurrent queue, and timer.

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
        // Create a concurrent queue.
        ffrt_queue_attr_t queue_attr;
        (void)ffrt_queue_attr_init(&queue_attr);
        ffrt_queue_t queue_handle = ffrt_queue_create(ffrt_queue_concurrent, "test_queue", &queue_attr);

        // Create a loop.
        auto loop = ffrt_loop_create(queue_handle);
        int result1 = 0;

        // Submit a task to the loop queue.
        std::function<void()> &&basicFunc1 = [&result1]() { result1 += 10; };
        ffrt_task_handle_t task = ffrt_queue_submit_h(queue_handle, ffrt::create_function_wrapper(basicFunc1, ffrt_function_kind_queue), nullptr);

        // Create a separate thread to perform the loop.
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

        // Register a timer with the loop.
        ffrt_timer_t timeHandle = ffrt_loop_timer_start(loop, timeout1, data, cb, false);

        // Register an FD listener with the loop.
        int ret = ffrt_loop_epoll_ctl(loop, EPOLL_CTL_ADD, testFd, EPOLLIN, (void*)(&testData), testCallBack);
        if (ret == 0) {
            printf("ffrt_loop_epoll_ctl executed successfully.\n");
        }
        ssize_t n = write(testFd, &expected, sizeof(uint64_t));
        usleep(25000);
        // Delete the FD listener.
        ffrt_loop_epoll_ctl(loop, EPOLL_CTL_DEL, testFd, 0, nullptr, nullptr);

        // Stop the loop.
        ffrt_loop_stop(loop);
        pthread_join(thread, nullptr);

        // Delete the timer.
        ffrt_loop_timer_stop(loop, timeHandle);

        // Destroy the loop.
        ret = ffrt_loop_destroy(loop);

        // Destroy the concurrent queue.
        ffrt_queue_attr_destroy(&queue_attr);
        ffrt_queue_destroy(queue_handle);
        return 0;
    }
    ```

## Fiber

### ffrt_fiber_t

**Declaration**

```c
struct ffrt_fiber_t;
```

**Description**

- A fiber is a lightweight user mode thread that enables efficient task scheduling and context switching within the user space.
- `ffrt_fiber_t` is used to save and restore the execution context of the fiber.

**Methods**

**ffrt_fiber_init**

Declaration

```c
FFRT_C_API int ffrt_fiber_init(ffrt_fiber_t* fiber, void(*func)(void*), void* arg, void* stack, size_t stack_size);
```

Parameters

- `fiber`: pointer to the fiber.
- `func`: pointer to the function when the fiber is started.
- `arg`: pointer to the argument when the fiber is started.
- `stack`: pointer to the start address of the stack space used by the fiber during execution.
- `stack_size`: size of the fiber stack, in bytes.

Return Values

- If the initialization is successful, `ffrt_success` is returned. Otherwise, `ffrt_error` is returned.
- The common reason of the error is that `stack_size` does not meet the minimum stack space limit that varies by platform. It is recommended that the stack space size be set to 4 KB or larger.

Description

- Initializes a fiber. The pointer and arguments for starting the fiber process, and the stack space used at runtime need to be transferred. The fiber does not manage any memory; the lifecycle of the stack is managed by the caller.

**ffrt_fiber_switch**

Declaration

```c
FFRT_C_API void ffrt_fiber_switch(ffrt_fiber_t* from, ffrt_fiber_t* to);
```

Parameters

- `from`: pointer to the saved fiber context. The thread that calls this function suspends the current task.
- `to`: pointer to the restored fiber context. The thread that calls this function executes the task specified by `to`.

Description

- When the fiber context is switched, the thread that calls this function suspends the current task, saves the context to the `from` fiber, restores the context of the `to` fiber, and executes the task specified by `to`.
- Note that `from` and `to` are not verified. The caller must ensure the validity of these addresses to prevent process crashes.
