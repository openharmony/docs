# Node-API支持的数据类型和接口

## Node-API的数据类型

### napi_status

是一个枚举数据类型，表示Node-API接口返回的状态信息。

每当调用一个Node-API函数，都会返回该值，表示操作成功与否的相关信息。

```c
typedef enum {
    napi_ok,
    napi_invalid_arg,
    napi_object_expected,
    napi_string_expected,
    napi_name_expected,
    napi_function_expected,
    napi_number_expected,
    napi_boolean_expected,
    napi_array_expected,
    napi_generic_failure,
    napi_pending_exception,
    napi_cancelled,
    napi_escape_called_twice,
    napi_handle_scope_mismatch,
    napi_callback_scope_mismatch,
    napi_queue_full,
    napi_closing,
    napi_bigint_expected,
    napi_date_expected,
    napi_arraybuffer_expected,
    napi_detachable_arraybuffer_expected,
    napi_would_deadlock, /* unused */
    napi_no_external_buffers_allowed,
    napi_cannot_run_js
} napi_status;
```

### napi_extended_error_info

一个结构体，在调用函数不成功时存储了较为详细的错误信息。

```c
typedef struct {
    const char *error_message;
    void *engine_reserved;
    uint32_t engine_error_code;
    napi_status error_code;
} napi_extended_error_info;
```

### napi_value

napi_value是一个C的结构体指针，表示一个JavaScript对象的引用。napi_value持有了JS对象，同时，napi_value受handle_scope管理，scope中napi_value持有的JS对象不会被释放；出scope后，napi_value将失效，不再持有对应的JS对象。

### napi_env

- 用于表示Node-API执行时的上下文，Native侧函数入参，并传递给函数中的Node-API接口。

- napi_env与JS线程绑定，JS线程退出后，napi_env将失效。

- 禁止缓存napi_env，禁止在不同Worker中传递napi_env。

### napi_threadsafe_function

napi_threadsafe_function用来创建一个线程安全的JavaScript函数，可以在不同的线程中调用。可以用于将异步操作的结果传递给JavaScript环境，例如从另一个线程中读取数据或执行计算密集型操作。此外，它还可以用于从JavaScript环境中调用C++代码中的函数，以便在另一个线程中执行。通过使用napi_threadsafe_function，可以实现JavaScript和C++之间的高效通信，同时保持线程安全性。

### napi_threadsafe_function_release_mode

该枚举类型定义了两个常量，用于指定在何时释放线程安全函数的回调函数。

```c
typedef enum {
  napi_tsfn_release,
  napi_tsfn_abort
} napi_threadsafe_function_release_mode;
```

该值会传给napi_release_threadsafe_function。

```cpp
napi_release_threadsafe_function(napi_threadsafe_function func,
                                 napi_threadsafe_function_release_mode mode);
```

- mode值为napi_tsfn_release时：表示当前线程不再调用此tsfn。

- mode值为napi_tsfn_abort时：表示除了当前线程，其他线程不能再调用此tsfn。
  如果设置为napi_tsfn_abort，利用napi_call_threadsafe_function接口调用此tsfn时将返回napi_closing，tsfn函数并不会被放入queue中。

### napi_threadsafe_function_call_mode

该枚举类型定义了两个常量，用于指定线程安全函数的调用模式。

数据结构如下所示：

```c
typedef enum {
  napi_tsfn_nonblocking,
  napi_tsfn_blocking
} napi_threadsafe_function_call_mode;
```

- napi_tsfn_nonblocking：napi_call_threadsafe_function是非阻塞的，如果队列已满，则返回napi_queue_full，从而阻止数据添加到队列中。

- napi_tsfn_blocking：napi_call_threadsafe_function是阻塞的，直至队列中有空间可用。

### 内存管理类型

Node-API包含以下内存管理类型：

**napi_handle_scope**

napi_handle_scope数据类型是用来管理JavaScript对象的生命周期的。它允许JavaScript对象在一定范围内保持活动状态，以便在JavaScript代码中使用。在创建napi_handle_scope时，所有在该范围内创建的JavaScript对象都会保持活动状态，直到结束。这样可以避免在JavaScript代码中使用已经被释放的对象，从而提高代码的可靠性和性能。

**napi_escapable_handle_scope**

- 由napi_open_escapable_handle_scope接口创建，由napi_close_escapable_handle_scope接口关闭。

- 表示一种特殊类型的句柄范围，用于将在escapable_handle_scope范围内创建的值返回给父scope。

- 用于napi_escape_handle接口，将escape_handle_scope提升到JS对象，以便在外部作用域使用。

**napi_ref**

指向napi_value，允许用户管理JavaScript值的生命周期。

**napi_type_tag**

该结构体定义了一个包含两个无符号64位整数的类型标签，用于标识一个Node-API值的类型信息。

```c
typedef struct {
  uint64_t lower;
  uint64_t upper;
} napi_type_tag;
```

- 存储了两个无符号64位整数的128位值，用它来标记JavaScript对象，确保它们属于某种类型。

- 比napi_instanceof更强的类型检查，如果对象的原型被操纵，napi_instanceof可能会报告误报。

- type_tag与napi_wrap结合非常有用，因为它确保从包装对象检索的指针可以安全地转换为与先前应用于JavaScript对象的类型标记相对应的Native类型。

**napi_async_cleanup_hook_handle**

napi_async_cleanup_hook_handle用于注册异步操作的回调函数。它主要用于在异步操作完成或被取消时执行清理操作，例如释放资源或撤销操作。使用napi_async_cleanup_hook_handle可以确保在异步操作完成或被取消时，相关资源得到正确的释放和清理，从而避免内存泄漏等问题。

### 回调类型

Node-API包含以下回调类型：

**napi_callback_info**

Native侧获取JS侧参数信息，传递给napi_get_cb_info，用于获取JS侧入参信息。

**napi_callback**

表示用户定义的Native函数，暴露给JavaScript，即JS侧调用的接口；一般不在此callback中创建handle或者callback scope。

基本用法如下：

```c
typedef napi_value (*napi_callback)(napi_env, napi_callback_info);
```

**napi_finalize**

函数指针，用于传入napi_create_threadsafe_function和napi_set_instance_data接口。napi_finalize在对象被回收时会被调用。

**napi_async_execute_callback**

函数指针，用于napi_create_async_work接口。

- 异步执行的Native函数，从工作池线程调用，可与主事件循环线程并行执行。

- 函数实现中必须避免执行JavaScript或与JavaScript对象交互的Node-API调用。

- Node-API调用可以在napi_async_complete_callback中执行。

**napi_async_complete_callback**

napi_async_complete_callback用于异步操作完成后的回调。当需要进行异步操作时，可以使用napi_create_async_work函数创建一个异步操作任务，并指定一个napi_async_complete_callback回调函数，在异步操作完成后会自动调用该回调函数，以便进行后续的处理。该回调函数的参数包括当前异步操作任务的状态和返回值等信息，可以根据这些信息进行相应的处理。

**napi_threadsafe_function_call_js**

函数指针，在主线程中与独立线程中的JavaScript代码进行交互，从而实现更加复杂的功能，用于napi_create_threadsafe_function(napi_env env,…,napi_threadsafe_function_call_js call_js_cb,...)接口。

**napi_cleanup_hook**

函数指针，用于napi_add_env_cleanup_hook接口，当环境销毁时会被执行。

**napi_async_cleanup_hook**

函数指针，用于napi_add_async_cleanup_hook接口，当环境销毁时会被执行。

### 调度优先级

QoS决定了线程调度的优先级，等级定义如下：

```c
typedef enum {
  napi_qos_background = 0,
  napi_qos_utility = 1,
  napi_qos_default = 2,
  napi_qos_user_initiated = 3,
} napi_qos_t;
```

| QoS等级 | 适用场景 |
| -------- | -------- |
| napi_qos_background | 低等级，用户不可见任务，例如数据同步、备份。 |
| napi_qos_utility | 中低等级，不需要立即看到响应效果的任务，例如下载或导入数据。 |
| napi_qos_default | 默认。 |
| napi_qos_user_initiated | 高等级，用户触发并且可见进展，例如打开文档。 |

### 事件循环模式

napi提供了运行底层事件循环的两种模式, 其定义如下：

```c
typedef enum {
    napi_event_mode_default = 0,
    napi_event_mode_nowait = 1,
} napi_event_mode;
```

| 事件循环运行模式 | 解释说明 |
| -------- | -------- |
| napi_event_mode_default | 阻塞式的运行底层事件循环，直到循环中没有任何任务时退出事件循环。 |
| napi_event_mode_nowait | 非阻塞式的运行底层事件循环，尝试去处理一个任务，处理完之后退出事件循环；如果事件循环中没有任务，立刻退出事件循环。 |

### 线程安全任务优先级

napi提供了线程安全任务的优先级, 底层任务队列中的任务会根据其优先级被依次执行, 优先级的定义如下：

```c
typedef enum {
    napi_priority_immediate = 0,
    napi_priority_high = 1,
    napi_priority_low = 2,
    napi_priority_idle = 3,
} napi_task_priority;
```

| 任务优先级 | 解释说明 |
| -------- | -------- |
| napi_priority_immediate | 该优先级的级别最高。|
| napi_priority_high | 该优先级的级别低于napi_priority_immediate。|
| napi_priority_low | 该优先级的级别低于napi_priority_immediate和napi_priority_high。|
| napi_priority_idle | 该优先级的级别最低。 |

## 支持的Node-API接口

Node-API接口在Node.js提供的原生模块基础上扩展，目前支持部分接口，具体可见下文。

### 异步安全线程相关

| 接口 | 功能说明 |
| -------- | -------- |
| napi_create_threadsafe_function | 创建线程安全函数。 |
| napi_get_threadsafe_function_context | 获取线程安全函数中的context。 |
| napi_call_threadsafe_function | 调用线程安全函数。 |
| napi_acquire_threadsafe_function | 指示线程安全函数可以开始使用。 |
| napi_release_threadsafe_function | 指示线程安全函数将停止使用。 |
| napi_ref_threadsafe_function | 指示在主线程上运行的事件循环在线程安全函数被销毁之前不应退出。 |
| napi_unref_threadsafe_function | 指示在主线程上运行的事件循环可能会在线程安全函数被销毁之前退出。 |

### buffer相关

| 接口 | 功能说明 |
| -------- | -------- |
| napi_create_buffer | 创建并获取一个指定大小的JS Buffer。 |
| napi_create_buffer_copy | 创建并获取一个指定大小的JS Buffer，并以给定数据进行初始化。 |
| napi_create_external_buffer | 创建并获取一个指定大小的JS Buffer，并以给定数据进行初始化，该接口可为Buffer附带额外数据。 |
| napi_get_buffer_info | 获取JS Buffer底层data及其长度。 |
| napi_is_buffer | 判断给定JS value是否为Buffer对象。 |
| napi_create_external_arraybuffer | 分配一个附加有外部数据的JS ArrayBuffer。 |

### string相关

| 接口 | 功能说明 |
| -------- | -------- |
| napi_create_string_utf16 | 通过UTF16编码的C字符串数据创建JS String。 |
| napi_get_value_string_utf16 | 获取给定JS vaule对应的UTF16编码的字符串。 |
| napi_create_string_latin1 | 通过ISO-8859-1编码的C字符串数据创建JS String。 |
| napi_create_string_utf8 | 通过UTF8编码的C字符串数据创建JS String。 |
| napi_get_value_string_latin1 | 获取给定JS vaule对应的ISO-8859-1编码的字符串。 |
| napi_get_value_string_utf8 | 获取给定JS vaule对应的UTF8编码的字符串。 |

### date相关

| 接口 | 功能说明 |
| -------- | -------- |
| napi_create_date | 通过一个C的double数据创建JS Date。 |
| napi_get_date_value | 获取给定JS Date对应的C double值。 |
| napi_is_date | 判断给定JS value是否为JS Date对象。 |

### arraybuffer相关

| 接口 | 功能说明 |
| -------- | -------- |
| napi_get_arraybuffer_info | 获取ArrayBuffer的底层data buffer及其长度。 |
| napi_is_arraybuffer | 判断给定JS value是否为ArrayBuffer。 |
| napi_detach_arraybuffer | 分离给定ArrayBuffer的底层数据。 |
| napi_is_detached_arraybuffer | 判断给定的ArrayBuffer是否已被分离。 |
| napi_create_arraybuffer | 创建并获取一个指定大小的JS ArrayBuffer。 |

### module相关

| 接口 | 功能说明 |
| -------- | -------- |
| napi_module_register | native模块注册接口。 |

### 生命周期相关

| 接口 | 功能说明 |
| -------- | -------- |
| napi_open_handle_scope | 创建一个上下文环境使用。需要使用napi_close_handle_scope进行关闭。 |
| napi_close_handle_scope | 关闭传入的上下文环境，关闭后，全部在其中声明的引用都将被关闭。 |
| napi_open_escapable_handle_scope | 创建出一个可逃逸的handle scope，可将范围内声明的值返回到父作用域。需要使用napi_close_escapable_handle_scope进行关闭。 |
| napi_close_escapable_handle_scope | 关闭传入的可逃逸的handle scope。 |
| napi_escape_handle | 提升传入的JS Object的生命周期到其父作用域。 |
| napi_create_reference | 为Object创建一个reference，以延长其生命周期。调用者需要自己管理reference生命周期。 |
| napi_delete_reference | 删除传入的reference。 |
| napi_reference_ref | 增加传入的reference的引用计数，并获取新的计数。 |
| napi_reference_unref | 减少传入的reference的引用计数，并获取新的计数。 |
| napi_get_reference_value | 获取与reference相关联的JS Object。 |
| napi_add_finalizer | 当js Object中的对象被垃圾回收时调用注册的napi_finalize回调。 |

### promise相关

| 接口 | 功能说明 |
| -------- | -------- |
| napi_create_promise | 创建一个promise对象。 |
| napi_resolve_deferred | 对promise关联的deferred对象进行resolve。 |
| napi_reject_deferred | 对promise关联的deferred对象进行reject。 |
| napi_is_promise | 判断给定napi_value是否为promise对象。 |

### array相关

| 接口 | 功能说明 |
| -------- | -------- |
| napi_create_array | 创建并获取一个JS Array。 |
| napi_create_array_with_length | 创建并获取一个指定长度的JS Array。 |
| napi_get_array_length | 获取array的length。 |
| napi_is_array | 判断给定JS value是否为array。 |
| napi_set_element | 在给定Object的指定索引处，设置元素。 |
| napi_get_element | 获取给定Object指定索引处的元素。 |
| napi_has_element | 若给定Object的指定索引处拥有属性，获取该元素。 |
| napi_delete_element | 尝试删除给定Object的指定索引处的元素。 |
| napi_create_typedarray | 通过现有的ArrayBuffer创建一个JS TypeArray。 |
| napi_is_typedarray | 判断给定JS value是否为TypeArray。|
| napi_get_typedarray_info | 获取给定TypedArray的各种属性。 |
| napi_create_dataview | 通过现有的ArrayBuffer创建一个JS DataView。 |
| napi_is_dataview | 判断给定JS value是否为DataView。|
| napi_get_dataview_info | 获取给定DataView的各种属性。|

### primitive相关

| 接口 | 功能说明 |
| -------- | -------- |
| napi_get_boolean | 根据给定的C boolean值，获取JS Boolean对象。 |
| napi_get_global | 获取global对象。 |
| napi_get_null | 获取null对象。 |
| napi_get_undefined | 获取undefined对象。 |
| napi_coerce_to_bool | 将给定的JS value强转成JS Boolean。 |
| napi_coerce_to_number | 将给定的JS value强转成JS Number。 |
| napi_coerce_to_object | 将给定的JS value强转成JS Object。 |
| napi_coerce_to_string | 将给定的JS value强转成JS String。 |

### class相关

| 接口 | 功能说明 |
| -------- | -------- |
| napi_new_instance | 通过给定的构造函数，构建一个实例。 |
| napi_get_new_target | 获取构造函数调用的new.target。 |
| napi_define_class | 定义与C++类相对应的JavaScript类。 |
| napi_wrap | 在ArkTS对象上绑定一个Node-API模块对象实例。这个函数通常在将Node-API模块对象与ArkTS对象进行绑定时使用，以便在ArkTS中使用本地对象的方法和属性。 |
| napi_unwrap | 从ArkTS对象上获取之前绑定的Node-API模块对象实例。 |
| napi_remove_wrap | 从ArkTS对象上获取之前绑定的Node-API模块对象实例，并解除绑定。 |

### object相关

| 接口 | 功能说明 |
| -------- | -------- |
| napi_get_prototype | 获取给定JS Object的prototype。 |
| napi_create_object | 创建一个默认的JS Object。 |
| napi_object_freeze | 冻结给定的对象。 |
| napi_object_seal | 密封给定的对象。 |
| napi_typeof | 获取给定JS value的JS Type。 |
| napi_instanceof | 判断给定object是否为给定constructor的实例。 |
| napi_type_tag_object | 将tag指针的值与Object关联。 |
| napi_check_object_type_tag | 判断给定的tag指针是否被关联到了JS Object上。 |
| napi_create_symbol | 创建一个JS Symbol对象。 |
| napi_create_external | 用于创建一个JS外部对象，该对象可以用于将C/C++中的自定义数据结构或对象传递到JS中，并且可以在JS中访问其属性和方法。 |
| napi_get_value_external | 用于获得napi_create_external创建的绑定了外部数据的JS值，此函数可以在JS和C/C++之间传递数据。 |

### 基本数据类型相关

| 接口 | 功能说明 |
| -------- | -------- |
| napi_create_int32 | 通过一个C的int32数据创建JS number。 |
| napi_create_uint32 | 通过一个C的uint32数据创建JS number。 |
| napi_create_int64 | 通过一个C的int64数据创建JS number。 |
| napi_create_double | 通过一个C的double数据创建JS number。 |
| napi_get_value_int32 | 获取给定JS number对应的C int32值。 |
| napi_get_value_uint32 | 获取给定JS number对应的C uint32值。 |
| napi_get_value_int64 | 获取给定JS number对应的C int64值。 |
| napi_get_value_double | 获取给定JS number对应的C double值。 |
|napi_get_value_bool|获取给定js Boolean对应的C bool值。|

### bigint相关

| 接口 | 功能说明 |
| -------- | -------- |
| napi_create_bigint_int64 | 通过一个C的int64数据创建JS BigInt。 |
| napi_create_bigint_uint64 | 通过一个C的uint64数据创建JS BigInt。 |
| napi_create_bigint_words | 通过一个C的uint64数组创建单个JS BigInt。 |
| napi_get_value_bigint_int64 | 获取给定JS BigInt对应的C int64值。 |
| napi_get_value_bigint_uint64 | 获取给定JS BigInt对应的C uint64值。 |
| napi_get_value_bigint_words | 获取给定JS BigInt对应的信息，包括符号位、64位小端序数组和数组中的元素个数。 |

### 异常和错误相关

| 接口 | 功能说明 |
| -------- | -------- |
| napi_throw | 抛出一个JS value。 |
| napi_throw_error | 用于抛出一个带文本信息的ArkTS Error。|
| napi_throw_type_error | 抛出一个带文本信息的JS TypeError。 |
| napi_throw_range_error | 抛出一个带文本信息的JS RangeError。 |
| napi_is_error | 判断napi_value是否表示为一个error对象。 |
| napi_create_error | 创建并获取一个带文本信息的JS Error。 |
| napi_create_type_error | 创建并获取一个带文本信息的JS TypeError。 |
| napi_create_range_error | 创建并获取一个带文本信息的JS RangeError。 |
| napi_get_and_clear_last_exception | 获取并清除最近一次出现的异常。 |
| napi_is_exception_pending | 判断是否出现了异常。 |
| napi_fatal_error | 引发致命错误以立即终止进程。 |
| napi_get_last_error_info | 获取napi_extended_error_info结构体，其中包含最近一次出现的error信息。 |
| napi_fatal_exception | 抛出一个致命异常并终止进程, 同时产生相应的crash日志。 |

### 属性相关

| 接口 | 功能说明 |
| -------- | -------- |
| napi_get_property_names | 以字符串数组的形式获取对象的可枚举属性的名称。 |
| napi_set_property | 对给定Object设置属性。 |
| napi_get_property | 获取给定Object的给定属性。 |
| napi_has_property | 判断给定对象中是否存在给定属性。 |
| napi_delete_property | 尝试从给定Object中删除给定key属性。 |
| napi_has_own_property | 判断给定Object中是否有名为key的own property。 |
| napi_set_named_property | 对给定Object设置一个给定名称的属性。 |
| napi_get_named_property | 获取给定Object中指定名称的属性。 |
| napi_has_named_property | 判断给定Object中是否有给定名称的属性。 |
| napi_define_properties | 批量的向给定Object中定义属性。 |
| napi_get_all_property_names | 获取一个数组，其中包含此对象过滤后的属性名称。 |

### 异步任务相关

| 接口 | 功能说明 |
| -------- | -------- |
| napi_create_async_work | 创建一个异步工作对象。 |
| napi_delete_async_work | 释放先前创建的异步工作对象。 |
| napi_queue_async_work | 将异步工作对象加到队列，由底层去调度执行。 |
| napi_cancel_async_work | 取消入队的异步任务。 |

### 自定义异步操作

| 接口 | 功能说明 |
| -------- | -------- |
| napi_async_init | 创建一个异步资源上下文环境（不支持与async_hook相关能力）。 |
| napi_make_callback | 在异步资源上下文环境中回调JS函数（不支持与async_hook相关能力）。|
| napi_async_destroy | 销毁先前创建的异步资源上下文环境（不支持与async_hook相关能力）。|
| napi_open_callback_scope | 创建一个回调作用域（不支持与async_hook相关能力）。 |
| napi_close_callback_scope | 关闭先前创建的回调作用域（不支持与async_hook相关能力）。|

### uv相关

| 接口 | 功能说明 |
| -------- | -------- |
| napi_get_uv_event_loop | 获取当前libuv loop实例。 |

### 函数调用

| 接口 | 功能说明 |
| -------- | -------- |
| napi_call_function | 在C/C++侧调用JS方法。 |
| napi_get_cb_info | 从给定的callback info中获取有关调用的详细信息，如参数和this指针。 |

### 扩展能力

[Node-API组件扩展的符号列表](../reference/native-lib/napi.md#node-api组件扩展的符号列表)

| 接口 | 功能说明 |
| -------- | -------- |
| napi_queue_async_work_with_qos | 将异步工作对象加到队列，由底层根据传入的qos优先级去调度执行。 |
| napi_run_script_path | 运行指定abc文件。 |
| napi_load_module | 将abc文件作为模块加载，返回模块的命名空间。 |
| napi_load_module_with_info | 将abc文件作为模块加载，返回模块的命名空间，可在新创建的ArkTS基础运行时环境中使用。 |
| napi_create_object_with_properties | 使用给定的napi_property_descriptor创建js Object。descriptor的键名必须为 string，且不可转为number。 |
| napi_create_object_with_named_properties | 使用给定的napi_value和键名创建js Object。键名必须为 string，且不可转为number。 |
| napi_coerce_to_native_binding_object | 强制将js Object和Native对象绑定。 |
| napi_create_ark_runtime|创建基础运行时环境。|
| napi_destroy_ark_runtime|销毁基础运行时环境。|
| napi_run_event_loop | 触发底层的事件循环。|
| napi_stop_event_loop | 停止底层的事件循环。|
| napi_serialize | 将ArkTS对象转换为native数据。|
| napi_deserialize | 将native数据转为ArkTS对象。|
| napi_delete_serialization_data | 删除序列化数据。|
| napi_call_threadsafe_function_with_priority|将指定优先级和入队方式的任务投递到ArkTS主线程。|
| napi_is_sendable|判断给定JS value是否是Sendable的。|
| napi_define_sendable_class|创建一个sendable类。|
| napi_create_sendable_object_with_properties | 使用给定的napi_property_descriptor创建一个sendable对象。|
| napi_create_sendable_array | 创建一个sendable数组。|
| napi_create_sendable_array_with_length | 创建一个指定长度的sendable数组。|
| napi_create_sendable_arraybuffer | 创建一个sendable ArrayBuffer。|
| napi_create_sendable_typedarray | 创建一个sendable TypedArray。|
| napi_wrap_sendable | 包裹一个native实例到ArkTS对象中。|
| napi_wrap_sendable_with_size | 包裹一个native实例到ArkTS对象中并指定大小。|
| napi_unwrap_sendable | 获取ArkTS对象包裹的native实例。|
| napi_remove_wrap_sendable | 移除并获取ArkTS对象包裹的native实例。|

#### napi_queue_async_work_with_qos

```c
napi_status napi_queue_async_work_with_qos(napi_env env,
                                           napi_async_work work,
                                           napi_qos_t qos);
```

用法同napi_queue_async_work，但可以指定QoS等级。

#### napi_run_script_path

```c
napi_status napi_run_script_path(napi_env env,
                                 const char* abcPath,
                                 napi_value* result);
```

#### napi_load_module

```c
napi_status napi_load_module(napi_env env,
                             const char* path,
                             napi_value* result);
```

#### napi_create_object_with_properties

```c
napi_status napi_create_object_with_properties(napi_env env,
                                               napi_value* result,
                                               size_t property_count,
                                               const napi_property_descriptor* properties);
```

#### napi_create_object_with_named_properties

```c
napi_status napi_create_object_with_named_properties(napi_env env,
                                                     napi_value* result,
                                                     size_t property_count,
                                                     const char** keys,
                                                     const napi_value* values);
```

#### napi_coerce_to_native_binding_object

```c
napi_status napi_coerce_to_native_binding_object(napi_env env,
                                                 napi_value js_object,
                                                 napi_native_binding_detach_callback detach_cb,
                                                 napi_native_binding_attach_callback attach_cb,
                                                 void* native_object,
                                                 void* hint);
```

#### napi_run_event_loop

```c
napi_status napi_run_event_loop(napi_env env, napi_event_mode mode);
```

#### napi_stop_event_loop

```c
napi_status napi_stop_event_loop(napi_env env);
```

#### napi_serialize

```c
napi_status napi_serialize(napi_env env,
                           napi_value object,
                           napi_value transfer_list,
                           napi_value clone_list,
                           void** result);
```

#### napi_deserialize

```c
napi_status napi_deserialize(napi_env env, void* buffer, napi_value* object);
```

#### napi_delete_serialization_data

```c
napi_status napi_delete_serialization_data(napi_env env, void* buffer);
```

#### napi_call_threadsafe_function_with_priority

```c
napi_status napi_call_threadsafe_function_with_priority(napi_threadsafe_function func,
                                                        void *data,
                                                        napi_task_priority priority,
                                                        bool isTail);
```

#### napi_is_sendable

```c
napi_status napi_is_sendable(napi_env env, napi_value value, bool* result);
```

#### napi_define_sendable_class

```c
napi_status napi_define_sendable_class(napi_env env,
                                       const char* utf8name,
                                       size_t length,
                                       napi_callback constructor,
                                       void* data,
                                       size_t property_count,
                                       const napi_property_descriptor* properties,
                                       napi_value parent,
                                       napi_value* result);

```

#### napi_create_sendable_object_with_properties

```c
napi_status napi_create_sendable_object_with_properties(napi_env env,
                                                        size_t property_count,
                                                        const napi_property_descriptor* properties,
                                                        napi_value* result);
```

#### napi_create_sendable_array

```c
napi_status napi_create_sendable_array(napi_env env, napi_value* result);
```

#### napi_create_sendable_array_with_length

```c
napi_status napi_create_sendable_array_with_length(napi_env env, size_t length, napi_value* result);
```

#### napi_create_sendable_arraybuffer

```c
napi_status napi_create_sendable_arraybuffer(napi_env env, size_t byte_length, void** data, napi_value* result);
```

#### napi_create_sendable_typedarray

```c
napi_status napi_create_sendable_typedarray(napi_env env,
                                            napi_typedarray_type type,
                                            size_t length,
                                            napi_value arraybuffer,
                                            size_t byte_offset,
                                            napi_value* result);
```

#### napi_wrap_sendable

```c
napi_status napi_wrap_sendable(napi_env env,
                               napi_value js_object,
                               void* native_object,
                               napi_finalize finalize_cb,
                               void* finalize_hint);
```

#### napi_wrap_sendable_with_size

```c
napi_status napi_wrap_sendable_with_size(napi_env env,
                                         napi_value js_object,
                                         void* native_object,
                                         napi_finalize finalize_cb,
                                         void* finalize_hint,
                                         size_t native_binding_size);
```

#### napi_unwrap_sendable

```c
napi_status napi_unwrap_sendable(napi_env env, napi_value js_object, void** result);
```

#### napi_remove_wrap_sendable

```c
napi_status napi_remove_wrap_sendable(napi_env env, napi_value js_object, void** result);
```

### 环境生命周期

| 接口 | 功能说明 |
| -------- | -------- |
| napi_set_instance_data | 绑定与当前运行的环境相关联的数据项。 |
| napi_get_instance_data | 检索与当前运行的环境相关联的数据项。|

### 对象生命周期管理

| 接口 | 功能说明 |
| -------- | -------- |
| napi_add_env_cleanup_hook | 注册环境清理钩子函数。 |
| napi_remove_env_cleanup_hook | 取消环境清理钩子函数。|
| napi_add_async_cleanup_hook | 注册清理异步钩子函数。 |
| napi_remove_async_cleanup_hook | 取消清理异步钩子函数。|

### ArkTS基础运行时环境

| 接口 | 功能说明 |
| -------- | -------- |
| napi_create_ark_runtime | 创建基础运行时环境。|
| napi_destroy_ark_runtime | 销毁基础运行时环境。|

### 其他实用工具

| 接口 | 功能说明 |
| -------- | -------- |
| napi_get_version | 获取Node运行时支持的最高 NAPI 版本。 |
| node_api_get_module_file_name | 用于获取加载项加载位置的绝对路径。|
| napi_strict_equals | 在某些情况下，希望确保两个值不仅具有相同的值，还具有相同的类型——例如正在处理一些需要特定类型的数据结构或算法——使用napi_strict_equals可以确保数据的一致性。 |
