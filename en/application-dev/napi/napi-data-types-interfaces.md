# Node-API Data Types and APIs
<!--Kit: NDK-->
<!--Subsystem: arkcompiler-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--Designer: @shilei123-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @fang-jinxu-->

## Data Types

### napi_status

Defines an enum for the execution statuses of a Node-API call.

Each time a Node-API function is called, a value of **napi_status** is returned indicating the execution result.

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

Defines a struct that represents detailed error information when a Node-API call fails.

```c
typedef struct {
    const char *error_message;
    void *engine_reserved;
    uint32_t engine_error_code;
    napi_status error_code;
} napi_extended_error_info;
```

### napi_value

A C struct pointer acting as a reference to an ArkTS or JS object. A **napi_value** holds a ArkTS/JS object. [napi_handle_scope](#memory-management-types) is used to manage the lifetime of **napi_value** handles. The JS object held by a **napi_value** in the scope will not be released. If the **napi_value** is out of the scope, it becomes invalid and will no longer hold the ArkTS/JS object.

### napi_env

- Context used by the underlying Node-API implementation. It is passed to the native functions when they are invoked, and must be passed back when Node-API calls are made.

- **napi_env** is bound to the context of the ArkTS/JS thread. Each **napi_env** has an independent runtime context. After an ArkTS/JS thread exits, the corresponding **napi_env** becomes invalid.

- **napi_env** cannot be cached, nor can it be passed between threads.

### napi_threadsafe_function

[Pointer](use-napi-thread-safety.md) that represents an ArkTS/JS function that can be called asynchronously from multiple threads. It can be used to pass the asynchronous (async for short) operation result to the ArkTS/JS environment, such as reading data from another thread or performing compute-intensive operations. The thread-safe function callback is executed only in the ArkTS thread that creates the thread-safe function. By using **napi_threadsafe_function**, you can implement efficient interaction between ArkTS/JS and C++ code while maintaining thread safety.

### napi_threadsafe_function_release_mode

Defines an enum for two constants that specify how thread-safe functions are released.

```c
typedef enum {
  napi_tsfn_release,
  napi_tsfn_abort
} napi_threadsafe_function_release_mode;
```

Its value is passed to **napi_release_threadsafe_function**.

```cpp
napi_release_threadsafe_function(napi_threadsafe_function func,
                                 napi_threadsafe_function_release_mode mode);
```

- If the **mode** value is **napi_tsfn_release**, the number of threads held by the thread-safe function is reduced by one. When the number of threads is reduced to 0, the thread-safe function is destroyed.

- If the value is **napi_tsfn_abort**, this thread-safe function is disabled and cannot be called.
  If **napi_tsfn_abort** is set, calling this thread-safe function using **napi_call_threadsafe_function** may cause a UAF issue. When **napi_tsfn_abort** is set, the thread-safe function is disabled and cannot be called. If **napi_call_threadsafe_function** is called, the system may return **napi_closing**, indicating that the thread-safe function is being disabled, and the data passed to the thread-safe function is not put into the queue. This means that the data may not be correctly processed. If the memory to which data points has been freed (for example, the thread-safe function resources have been freed), but the caller still tries to access or use data, a Use-After-Free(UAF) issue may occur.

### napi_threadsafe_function_call_mode

Defines an enum for whether the call should be blocked when the queue associated with the thread-safe function is full.

The data struct is as follows:

```c
typedef enum {
  napi_tsfn_nonblocking,
  napi_tsfn_blocking
} napi_threadsafe_function_call_mode;
```

- **napi_tsfn_nonblocking**: Leave **napi_call_threadsafe_function** unblocked. If the queue is full, **napi_queue_full** is returned to prevent data from being added to the queue.

- **napi_tsfn_blocking**: Block **napi_call_threadsafe_function** until there is available space in the queue.

### Memory Management Types

Node-API provides the following memory management types:

**napi_handle_scope**

Data used to manage the lifecycle of ArkTS/JS objects. It allows ArkTS/JS objects to remain active within a certain range for use in ArkTS/JS code. When **napi_handle_scope** is created, all ArkTS/JS objects created in this range remain active until the end. This minimizes their lifecycles and [prevents memory leaks](napi-guidelines.md#lifecycle-management). For details about **napi_handle_scope**, see <!--RP1-->Precautions for Lifecycle Management.<!--RP1End-->

**napi_escapable_handle_scope**

- It is created by **napi_open_escapable_handle_scope** and closed by **napi_close_escapable_handle_scope**.

- It is a special type of handle range used to return values created within the scope of **escapable_handle_scope** to a parent scope.

- It is used by **napi_escape_handle** to escape ArkTS/JS objects to a parent scope so that the objects are valid for the lifetime of the outer scope.

**napi_ref **

Reference to **napi_value**, which allows you to manage the lifecycle of ArkTS/JS values.

**napi_type_tag**

Defines a struct that contains two unsigned 64-bit integers to identify the type of a Node-API value.

```c
typedef struct {
  uint64_t lower;
  uint64_t upper;
} napi_type_tag;
```

- It is a 128-bit value stored as two unsigned 64-bit integers. It is used to tag ArkTS/JS objects to ensure that they are of a certain type.

- This is a stronger check than **napi_instanceof** because **napi_instanceof** may report a false positive if the object's prototype is manipulated.

- The combination of **type_tag** and **napi_wrap** is useful because it ensures that the pointer retrieved from a wrapped object can be safely converted to the native type corresponding to the type tag that had been previously applied to the JS object.

**napi_async_cleanup_hook_handle**

A mechanism used in Node-API to manage the lifecycle of asynchronous resources. It allows you to register a cleanup hook, which is called only when the lifecycle of the current **napi_env** ends. It ensures that some asynchronous resources are properly released before the environment is destroyed, thereby avoiding resource leaks. In addition, in the Node-API implementation, if the structure is not released, the destruction of the entire **napi_env** is delayed. In OpenHarmony, the behavior of this API is almost the same as that of the cleanup hook related to the env lifecycle, except that it allows the same context data to be repeatedly registered.

### Callback Types

Node-API provides the following callback types:

**napi_callback_info**

Data type passed to **napi_get_cb_info** to obtain JS input parameters.

**napi_callback**

User-defined native function exposed to ArkTS/JS. Specifically, no handle or callback scope is created in this callback.

The basic usage is as follows:

```c
typedef napi_value (*napi_callback)(napi_env, napi_callback_info);
```

**napi_finalize**

Function pointer passed to **napi_create_threadsafe_function**, **napi_set_instance_data**, **napi_wrap** and **napi_add_finalizer**. **napi_finalize** is called when an object is reclaimed.

**napi_async_execute_callback**

Function pointer used in **napi_create_async_work**.

- An async native function is called from a worker pool thread and can be executed in parallel with the event loop thread.

- Avoid calling non-thread-safe Node-APIs when implementing this callback.

- Node-API calls should be executed in **napi_async_complete_callback**.

**napi_async_complete_callback**

Function pointer used when an async operation is complete. When an async operation is required, you can use **napi_create_async_work** to create an async work and specify **napi_async_complete_callback**. When the async work is complete, the callback will be automatically invoked for subsequent processing. Parameters of the callback include the status of the async operation and a return value, based on which corresponding processing can be performed.

**napi_threadsafe_function_call_js**

Function pointer used in the event loop thread to interact with ArkTS/JS to implement more complex scenarios. It is used in **napi_create_threadsafe_function(napi_env env,…,napi_threadsafe_function_call_js call_js_cb,...)**.

**napi_cleanup_hook**

Function pointer used with **napi_add_env_cleanup_hook**. It will be called when the environment is destroyed.

**napi_async_cleanup_hook**

Function pointer used with **napi_add_async_cleanup_hook**. It will be called when the environment is destroyed.

### QoS

Defines an enum for the thread scheduling priority.

```c
typedef enum {
    napi_qos_background = 0,
    napi_qos_utility = 1,
    napi_qos_default = 2,
    napi_qos_user_initiated = 3,
} napi_qos_t;
```

| QoS| Use Scenario|
| -------- | -------- |
| napi_qos_background | Low priority for works invisible to users, such as data synchronization and backup.|
| napi_qos_utility | Medium priority for works that do not require immediate response, such as downloading or importing data.|
| napi_qos_default | Default priority.|
| napi_qos_user_initiated | High priority for user-triggered works with visible progress, for example, opening a file.|

### Event Loop Modes

Node-API provides two modes for running the underlying event loop. The two modes are defined as follows:

```c
typedef enum {
    napi_event_mode_default = 0,
    napi_event_mode_nowait = 1,
} napi_event_mode;
```

| Event Loop Mode| Description|
| -------- | -------- |
| napi_event_mode_default | Run the underlying event loop while blocking the current thread, and exit the event loop only when there is no active **uv_handle** in the loop.|
| napi_event_mode_nowait | Run the underlying event loop without blocking the current thread. Process a task and exit the event loop after the task is complete. If there is no task in the event loop, exit the event loop immediately.|

### Thread-safe Task Priority

Node-API defines the priorities of thread-safe tasks, as listed below. The tasks in the underlying task queue are executed in sequence based on their priorities.

```c
typedef enum {
    napi_priority_immediate = 0,
    napi_priority_high = 1,
    napi_priority_low = 2,
    napi_priority_idle = 3,
} napi_task_priority;
```

| Task Priority| Description|
| -------- | -------- |
| napi_priority_immediate | Highest priority.|
| napi_priority_high | Priority lower than **napi_priority_immediate**.|
| napi_priority_low | Priority lower than **napi_priority_high**.|
| napi_priority_idle | Lowest priority.|

## APIs

Node-API is extended based on the native modules provided by Node.js. The following lists the APIs supported currently.

### Async Thread-Safe APIs

| API| Description|
| -------- | -------- |
| napi_create_threadsafe_function | Creates a thread-safe function.|
| napi_get_threadsafe_function_context | Obtains the context of a thread-safe function.|
| napi_call_threadsafe_function | Calls a thread-safe function.|
| napi_acquire_threadsafe_function | Acquires a thread-safe function.|
| napi_release_threadsafe_function | Releases a thread-safe function.|
| napi_ref_threadsafe_function | Indicates that the event loop running on the main thread should not exit until the thread-safe function is destroyed.|
| napi_unref_threadsafe_function | Indicates that the event loop running on the main thread may exit before the thread-safe function is destroyed.|

### Buffer

| API| Description|
| -------- | -------- |
| napi_create_buffer | Creates an ArkTS Buffer instance of the specified size.|
| napi_create_buffer_copy | Creates an ArkTS Buffer instance of the specified size, and initializes it with data copied from the passed-in buffer.|
| napi_create_external_buffer | Creates an ArkTS Buffer instance of the specified size, and uses the specified data as its underlying buffer. You can use this API to add extra data to the buffer. |
| napi_get_buffer_info | Obtains the underlying data of a JS **Buffer** and its length.|
| napi_is_buffer | Checks whether the given JS value is a **Buffer** object.|
| napi_create_external_arraybuffer | Creates a JS **ArrayBuffer** with external data.|

### String

| API| Description|
| -------- | -------- |
| napi_create_string_utf16 | Creates an ArkTS string from a UTF16-encoded C string.|
| napi_get_value_string_utf16 | Obtains the UTF16-encoded string corresponding to the given ArkTS value.|
| napi_create_string_latin1 | Creates an ArkTS string from an ISO-8859-1-encoded C string.|
| napi_create_string_utf8 | Creates an ArkTS string from a UTF8-encoded C string.|
| napi_get_value_string_latin1 | Obtains the ISO-8859-1-encoded string corresponding to the given ArkTS value.|
| napi_get_value_string_utf8 | Obtains the UTF8-encoded string corresponding to the given ArkTS value.|

### Date

| API| Description|
| -------- | -------- |
| napi_create_date | Creates an ArkTS Date object from C double data.|
| napi_get_date_value | Obtains the C double equivalent of the given ArkTS Date object.|
| napi_is_date | Checks whether an ArkTS value is an ArkTS Date object.|

### ArrayBuffer

| API| Description|
| -------- | -------- |
| napi_get_arraybuffer_info | Obtains the underlying buffer of an ArrayBuffer and its length.|
| napi_is_arraybuffer | Checks whether the given ArkTS value is an ArrayBuffer object.|
| napi_detach_arraybuffer | Detaches the underlying data of the given **ArrayBuffer**.|
| napi_is_detached_arraybuffer | Checks whether the given **ArrayBuffer** has been detached.|
| napi_create_arraybuffer | Creates a JS **ArrayBuffer** object of the specified size.|

### Module

| API| Description|
| -------- | -------- |
| napi_module_register | Registers a native module.|

### Lifecycle Management

| API| Description|
| -------- | -------- |
| napi_open_handle_scope | Creates a **napi_handle_scope**. You can use **napi_close_handle_scope** to close it.|
| napi_close_handle_scope | Closes a **napi_handle_scope**. After it is closed, all **napi_value**s generated in it are closed.|
| napi_open_escapable_handle_scope | Opens an escapable handle scope, from which the declared values can be returned to the parent scope. You can use **napi_close_escapable_handle_scope** to close it.|
| napi_close_escapable_handle_scope | Closes the escapable handle scope passed in.|
| napi_escape_handle | Promotes the handle to the JS object so that it is valid for the lifetime of the parent scope.|
| napi_create_reference | Creates a **napi_ref** for an object. The caller needs to manage the **napi_ref** lifespan.|
| napi_delete_reference | Deletes a **napi_ref**.|
| napi_reference_ref | Increments the **napi_ref** count passed in and returns the new count.|
| napi_reference_unref | Decrements the **napi_ref** count passed in and returns the new count.|
| napi_get_reference_value | Obtains the JS object associated with **napi_ref**.|
| napi_add_finalizer | Adds a **napi_finalize** callback, which will be called when the ArkTS object is garbage-collected.|

### Promise

| API| Description|
| -------- | -------- |
| napi_create_promise | Creates a **Promise** object.|
| napi_resolve_deferred | Resolves a promise by using the **deferred** object associated with it.|
| napi_reject_deferred | Rejects a promise by using the **deferred** object associated with it.|
| napi_is_promise | Checks whether the given **napi_value** is a **Promise** object.|

### Array

| API| Description|
| -------- | -------- |
| napi_create_array | Creates an ArkTS array.|
| napi_create_array_with_length | Creates an ArkTS array of the specified length.|
| napi_get_array_length | Obtains the length of an array.|
| napi_is_array | Checks whether the given ArkTS value is an array.|
| napi_set_element | Sets the element value at the specified index of a given object.|
| napi_get_element | Obtains the element at the specified index of the given **Object**.|
| napi_has_element | Checks whether the given object has an element at the specified index.|
| napi_delete_element | Deletes the element at the specified index of the given **Object**.|
| napi_create_typedarray | Creates an ArkTS TypedArray from an existing ArrayBuffer.|
| napi_is_typedarray | Checks whether an ArkTS value is a TypeArray object.|
| napi_get_typedarray_info | Obtains the properties of a TypedArray, such as the type, length, byte offset, and ArrayBuffer.|
| napi_create_dataview | Creates an ArkTS **DataView** from an existing ArrayBuffer.|
| napi_is_dataview | Checks whether an ArkTS value is a **DataView** object.|
| napi_get_dataview_info | Obtains the properties of a **DataView**.|

### Primitives

| API| Description|
| -------- | -------- |
| napi_get_boolean | Obtains a JS Boolean object based on the given C Boolean value.|
| napi_get_global | Obtains the **global** object.|
| napi_get_null | Obtains the **null** object.|
| napi_get_undefined | Obtains the **undefined** object.|
| napi_coerce_to_bool | Forcibly converts a JS value into a JS Boolean value.|
| napi_coerce_to_number | Forcibly converts a JS value into a JS number.|
| napi_coerce_to_object | Forcibly converts a JS value into a JS object.|
| napi_coerce_to_string | Forcibly converts a JS value into a JS string.|

### Class

| API| Description|
| -------- | -------- |
| napi_new_instance | Creates an instance based on the given constructor.|
| napi_get_new_target | Obtains the **new.target** of the constructor call.|
| napi_define_class | Defines a JS class corresponding to the C++ class.|
| napi_wrap | Wraps a native object into an ArkTS object. This API allows the native methods and properties to be called from ArkTS.|
| napi_unwrap | Unwraps the native object from an ArkTS object.|
| napi_remove_wrap | Removes the wrapping after the native object is unwrapped from an ArkTS object.|

### Object

| API| Description|
| -------- | -------- |
| napi_get_prototype | Obtains the prototype of an ArkTS object.|
| napi_create_object | Creates a default ArkTS object.|
| napi_object_freeze | Freezes an object.|
| napi_object_seal | Seals an object.|
| napi_typeof | Obtains the type of an ArkTS value.|
| napi_instanceof | Checks whether the given object is an instance of the specified constructor.|
| napi_type_tag_object | Associates the value of the tag pointer with a JS object.|
| napi_check_object_type_tag | Checks whether a tag pointer is associated with an ArkTS object.|
| napi_create_symbol | Creates an ArkTS **Symbol** object.|
| napi_create_external | Creates an ArkTS external object, which can be used to pass custom data structs or objects in C/C++ to JS so that it can be accessible from ArkTS.|
| napi_get_value_external | Obtains the ArkTS data from the external object created by **napi_create_external**. This API can be used to pass data between ArkTS and C/C++.|

### Basic Data Types

| API| Description|
| -------- | -------- |
| napi_create_int32 | Creates a JS number from a C int32 value.|
| napi_create_uint32 | Creates a JS number from a C uint32 value.|
| napi_create_int64 | Creates a JS number from a C int64 value.|
| napi_create_double | Creates a JS number from a C double value.|
| napi_get_value_int32 | Obtains the C int32 equivalent of a JS number.|
| napi_get_value_uint32 | Obtains the C uint32 equivalent of a JS number.|
| napi_get_value_int64 | Obtains the C int64 equivalent of a JS number.|
| napi_get_value_double | Obtains the C double equivalent of a JS number.|
|napi_get_value_bool|Obtains the C bool equivalent of a JS Boolean value.|

### BigInt

| API| Description|
| -------- | -------- |
| napi_create_bigint_int64 | Creates a JS BigInt from C int64 data.|
| napi_create_bigint_uint64 | Creates a JS BigInt from C uint64 data.|
| napi_create_bigint_words | Creates a single JS BigInt from a C uint64 array.|
| napi_get_value_bigint_int64 | Obtains the C int64 equivalent of a JS BigInt.|
| napi_get_value_bigint_uint64 | Obtains the C uint64 equivalent of a JS BigInt.|
| napi_get_value_bigint_words | Obtains information from a JS BigInt, including the sign bit, 64-bit little-endian array, and number of elements in the array.|

### Exceptions and Errors

| API| Description|
| -------- | -------- |
| napi_throw | Throws a JS value.|
| napi_throw_error | Throws an ArkTS **Error** object with text information.|
| napi_throw_type_error | Throws an ArkTS type error with text information.|
| napi_throw_range_error | Throws an ArkTS range error with text information.|
| napi_is_error | Checks whether **napi_value** indicates an error object.|
| napi_create_error | Creates an ArkTS error object with text information.|
| napi_create_type_error | Creates an ArkTS error object with text information.|
| napi_create_range_error | Creates an ArkTS error object with text information.|
| napi_get_and_clear_last_exception | Obtains and clears the latest exception.|
| napi_is_exception_pending | Checks whether an exception occurs.|
| napi_fatal_error | Raises a fatal error to terminate the process immediately.|
| napi_get_last_error_info | Obtains the **napi_extended_error_info** struct, which contains the latest error information.|
| napi_fatal_exception | Throws a fatal exception, terminates the process, and generates a crash log.|

### Property

| API| Description|
| -------- | -------- |
| napi_get_property_names | Obtains the names of the enumerable properties of an object in an array of strings.|
| napi_set_property | Sets a property for an object.|
| napi_get_property | Obtains the requested property of an object.|
| napi_has_property | Checks whether an object has the specified property.|
| napi_delete_property | Deletes a property from an object.|
| napi_has_own_property | Checks whether an object has the own property specified by **key**.|
| napi_set_named_property | Sets a property with the specified name for an object.|
| napi_get_named_property | Obtains the property with the specified name in an object.|
| napi_has_named_property | Checks whether an object has the property with the specified name.|
| napi_define_properties | Defines multiple properties for an object.|
| napi_get_all_property_names | Obtains an array containing the names of all the available properties of this object.|

### Async Works

| API| Description|
| -------- | -------- |
| napi_create_async_work | Creates a work object that executes logic asynchronously.|
| napi_delete_async_work | Releases an async work object.|
| napi_queue_async_work | Adds an async work object to the queue so that it can be scheduled for execution.|
| napi_cancel_async_work | Cancels a queued async work if it has not been started.|

### Custom Async Operations

| API| Description|
| -------- | -------- |
| napi_async_init | Creates an async context. The capabilities related to **async_hook** are not supported.|
| napi_make_callback | Allows a JS function to be called in the async context. The capabilities related to **async_hook** are not supported.|
| napi_async_destroy | Destroys the previously created async context. The capabilities related to **async_hook** are not supported.|
| napi_open_callback_scope | Opens a callback scope. The capabilities related to **async_hook** are not supported.|
| napi_close_callback_scope | Closes the callback scope. The capabilities related to **async_hook** are not supported.|

### UV

| API| Description|
| -------- | -------- |
| napi_get_uv_event_loop | Obtains the current libuv loop instance.|

### Function Invocation

| API| Description|
| -------- | -------- |
| napi_call_function | Calls a JS function from a C/C++ addon.|
| napi_get_cb_info | Obtains detailed information about the call, such as the parameters and **this** pointer, from the given callback info.|

### Environment Lifecycle

| API| Description|
| -------- | -------- |
| napi_set_instance_data | Associates data with the currently running environment.|
| napi_get_instance_data | Retrieves the data that was previously associated with the currently running environment.|

### Object Lifetime Management

| API| Description|
| -------- | -------- |
| napi_add_env_cleanup_hook | Adds a cleanup hook function for releasing resources when the environment exits.|
| napi_remove_env_cleanup_hook | Removes a cleanup hook function.|
| napi_add_async_cleanup_hook | Adds an async cleanup hook function for releasing resources when the environment exits.|
| napi_remove_async_cleanup_hook | Removes an async cleanup hook function.|

### Extended Capabilities

[Node-API Extended Symbols](../reference/native-lib/napi.md#node-api-extended-symbols)

| API| Description|
| -------- | -------- |
| napi_queue_async_work_with_qos | Adds an async work object to the queue and schedules it based on the QoS passed in.|
| napi_run_script_path | Runs an .abc file.|
| napi_load_module | Loads an .abc file as a module. This API returns the namespace of the module.|
| napi_load_module_with_info | Loads an .abc file as a module. This API returns the namespace of the module, which can be used in the ArkTS runtime environment.|
| napi_create_object_with_properties | Creates a JS object using the given **napi_property_descriptor**. The key in **napi_property_descriptor** must be a string and cannot be converted into a number.|
| napi_create_object_with_named_properties | Creates a JS object using the given **napi_value**s and keys. The key must be a string and cannot be converted into a number.|
| napi_coerce_to_native_binding_object | Forcibly binds a JS object and a native object.|
| napi_create_ark_runtime|Creates an ArkTS runtime environment.|
| napi_destroy_ark_runtime|Destroys an ArkTS runtime environment.|
| napi_run_event_loop | Starts an underlying event loop.|
| napi_stop_event_loop | Stops the underlying event loop.|
| napi_serialize | Serializes an ArkTS object into native data.|
| napi_deserialize | Deserializes native data into an ArkTS object.|
| napi_delete_serialization_data | Deletes serialized data.|
| napi_call_threadsafe_function_with_priority| Delivers a task to the ArkTS main thread based on the specified priority and enqueuing policy.|
| napi_is_sendable| Checks whether the given JS value is sendable.|
| napi_define_sendable_class| Creates a sendable class.|
| napi_create_sendable_object_with_properties | Creates a sendable object with the given **napi_property_descriptor**.|
| napi_create_sendable_array | Creates a sendable array.|
| napi_create_sendable_array_with_length | Creates a sendable array of the specified length.|
| napi_create_sendable_arraybuffer | Creates a sendable ArrayBuffer.|
| napi_create_sendable_typedarray | Creates a sendable TypedArray.|
| napi_wrap_sendable | Wraps a native instance into an ArkTS object.|
| napi_wrap_sendable_with_size | Wraps a native instance into an ArkTS object with the specified size.|
| napi_unwrap_sendable | Unwraps the native instance from an ArkTS object.|
| napi_remove_wrap_sendable | Removes and obtains the native instance wrapped by an ArkTS object. After removal, the callback will no longer be triggered and must be manually deleted to free memory.|
| napi_wrap_enhance | Wraps a Node-API instance into an ArkTS object and specifies the instance size. You can specify whether to execute the registered callback asynchronously (if asynchronous, it must be thread-safe).|
|napi_create_ark_context| Creates a context.|
|napi_switch_ark_context| Switches to the specified runtime context environment.|
|napi_destroy_ark_context| Destroys the context created by **napi_create_ark_context**.|

**napi_queue_async_work_with_qos**

```c
napi_status napi_queue_async_work_with_qos(napi_env env,
                                           napi_async_work work,
                                           napi_qos_t qos);
```

This API has the same usage as **napi_queue_async_work**. The difference is you can specify the QoS for the work to run. For details about how to use **napi_queue_async_work_with_qos**, see "Prioritizing Asynchronous Tasks". For details about QoS, see [QoS Development](qos-guidelines.md).

**napi_run_script_path**

```c
napi_status napi_run_script_path(napi_env env,
                                 const char* abcPath,
                                 napi_value* result);
```
**Note**: For details about the restrictions, see [What should I observe when using napi_run_script_path() to execute the abc files in a package](https://developer.huawei.com/consumer/en/doc/harmonyos-faqs/faqs-ndk-65).
**napi_load_module**

```c
napi_status napi_load_module(napi_env env,
                             const char* path,
                             napi_value* result);
```

**napi_create_object_with_properties**

```c
napi_status napi_create_object_with_properties(napi_env env,
                                               napi_value* result,
                                               size_t property_count,
                                               const napi_property_descriptor* properties);
```

**napi_create_object_with_named_properties**

```c
napi_status napi_create_object_with_named_properties(napi_env env,
                                                     napi_value* result,
                                                     size_t property_count,
                                                     const char** keys,
                                                     const napi_value* values);
```

**napi_coerce_to_native_binding_object**

```c
napi_status napi_coerce_to_native_binding_object(napi_env env,
                                                 napi_value js_object,
                                                 napi_native_binding_detach_callback detach_cb,
                                                 napi_native_binding_attach_callback attach_cb,
                                                 void* native_object,
                                                 void* hint);
```

**napi_create_ark_runtime**

```c
napi_status napi_create_ark_runtime(napi_env *env);
```
[Creating an ArkTS Runtime Environment Using napi_create_ark_runtime and napi_destroy_ark_runtime](use-napi-ark-runtime.md)

**napi_destroy_ark_runtime**

```c
napi_status napi_destroy_ark_runtime(napi_env *env);
```

**napi_run_event_loop**

```c
napi_status napi_run_event_loop(napi_env env, napi_event_mode mode);
```

You can call the **napi_run_event_loop** and **napi_stop_event_loop** APIs only in the ArkTS runtime environment created using **napi_create_ark_runtime**. For details, see [Running or Stopping an Event Loop in an Asynchronous Thread Using Node-API Extension APIs](use-napi-event-loop.md).

**napi_stop_event_loop**

```c
napi_status napi_stop_event_loop(napi_env env);
```

**napi_serialize**

```c
napi_status napi_serialize(napi_env env,
                           napi_value object,
                           napi_value transfer_list,
                           napi_value clone_list,
                           void** result);
```

**napi_deserialize**

```c
napi_status napi_deserialize(napi_env env, void* buffer, napi_value* object);
```

**napi_delete_serialization_data**

```c
napi_status napi_delete_serialization_data(napi_env env, void* buffer);
```

**napi_call_threadsafe_function_with_priority**

```c
napi_status napi_call_threadsafe_function_with_priority(napi_threadsafe_function func,
                                                        void *data,
                                                        napi_task_priority priority,
                                                        bool isTail);
```

**napi_is_sendable**

```c
napi_status napi_is_sendable(napi_env env, napi_value value, bool* result);
```

**napi_define_sendable_class**

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

**napi_create_sendable_object_with_properties**

```c
napi_status napi_create_sendable_object_with_properties(napi_env env,
                                                        size_t property_count,
                                                        const napi_property_descriptor* properties,
                                                        napi_value* result);
```

**napi_create_sendable_array**

```c
napi_status napi_create_sendable_array(napi_env env, napi_value* result);
```

**napi_create_sendable_array_with_length**

```c
napi_status napi_create_sendable_array_with_length(napi_env env, size_t length, napi_value* result);
```

**napi_create_sendable_arraybuffer**

```c
napi_status napi_create_sendable_arraybuffer(napi_env env, size_t byte_length, void** data, napi_value* result);
```

**napi_create_sendable_typedarray**

```c
napi_status napi_create_sendable_typedarray(napi_env env,
                                            napi_typedarray_type type,
                                            size_t length,
                                            napi_value arraybuffer,
                                            size_t byte_offset,
                                            napi_value* result);
```

**napi_wrap_sendable**

```c
napi_status napi_wrap_sendable(napi_env env,
                               napi_value js_object,
                               void* native_object,
                               napi_finalize finalize_cb,
                               void* finalize_hint);
```

**napi_wrap_sendable_with_size**

```c
napi_status napi_wrap_sendable_with_size(napi_env env,
                                         napi_value js_object,
                                         void* native_object,
                                         napi_finalize finalize_cb,
                                         void* finalize_hint,
                                         size_t native_binding_size);
```

**napi_unwrap_sendable**

```c
napi_status napi_unwrap_sendable(napi_env env, napi_value js_object, void** result);
```

**napi_remove_wrap_sendable**

```c
napi_status napi_remove_wrap_sendable(napi_env env, napi_value js_object, void** result);
```

**napi_wrap_enhance**

```c
napi_status napi_wrap_enhance(napi_env env,
                              napi_value js_object,
                              void* native_object,
                              napi_finalize finalize_cb,
                              bool async_finalizer,
                              void* finalize_hint,
                              size_t native_binding_size,
                              napi_ref* result);
```

**napi_create_ark_context**
```c
napi_status napi_create_ark_context(napi_env env,
                                    napi_env* newEnv);
```

**napi_switch_ark_context**
```c
napi_status napi_switch_ark_context(napi_env env);
```

**napi_destroy_ark_context**
```c
napi_status napi_destroy_ark_context(napi_env env);
```

### Other Utilities

| API| Description|
| -------- | -------- |
| napi_get_version | Obtains the latest Node-API version supported by the node runtime.|
| node_api_get_module_file_name | Obtains the absolute path of the module to be loaded.|
| napi_strict_equals | Compares whether two values are strictly equal, that is, whether they are of the same type and have the same value.|
