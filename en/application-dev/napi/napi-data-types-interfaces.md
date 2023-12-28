# Node-API Data Types and APIs 


## Node-API Data Types


### napi_status

Enum value indicating the success or failure of a Node-API call.

```
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

Struct that holds detailed error information when a Node-API call fails.

```
typedef struct {
    const char *error_message;
    void *engine_reserved;
    uint32_t engine_error_code;
    napi_status error_code;
} napi_extended_error_info;
```


### napi_value

Pointer used to represent a JavaScript (JS) value.


### napi_env

- Context used by the underlying Node-API implementation. It is passed to the Native functions when they are invoked, and must be passed back when Node-API calls are made.

- The **napi_env** becomes invalid when an instance of the Native addon is unloaded. A notification of this event is sent through the callbacks given to **napi_add_env_cleanup_hook** and **napi_set_instance_data**.

- Avoid caching **napi_env** or passing **napi_env** between instances of the same addon running on different worker threads.


### napi_threadsafe_function

Pointer that represents a JS function that can be called asynchronously from multiple threads. It can be used to pass the results of asynchronous operations to the JS environment, such as reading data from another thread or performing computationally intensive operations. 

In addition, it can be used to call functions in C++ code from a JS environment for execution in another thread. By using **napi_threadsafe_function**, you can implement efficient interaction between JS and C++ while maintaining thread security.


### napi_threadsafe_function_release_mode

Enum value that indicates when to release the callback of the thread-safe function.


```
typedef enum {
  napi_tsfn_release,
  napi_tsfn_abort
} napi_threadsafe_function_release_mode;
```


The value is passed to **napi_release_threadsafe_function**.
```
napi_release_threadsafe_function(napi_threadsafe_function func,
                                 napi_threadsafe_function_release_mode mode);
```


- If the value is **napi_tsfn_release**, the current thread does not call this thread-safe function.

- If the value is **napi_tsfn_abort**, only the current thread can call this thread-safe function.
  If this parameter is **napi_tsfn_abort**, using **napi_call_threadsafe_function** to call this thread-safe function will return **napi_closing**, and this function will not be placed in the queue.


### napi_threadsafe_function_call_mode

Enum value that indicates whether the call should be blocked when the queue associated with the thread-safe function is full.


The data struct is as follows:


```
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

Data used to manage the lifecycle of JS objects. It allows JS objects to remain active within a certain range for use in JS code. When **napi_handle_scope** is created, all JS objects created in this range remain active until the end. This can prevent released objects from being used in JS code, which improves code reliability and performance.

**napi_escapable_handle_scope**


- It is created by **napi_open_escapable_handle_scope** and closed by **napi_close_escapable_handle_scope**.

- It is a special type of handle range used to return values created within the **escapable_handle_scope** scope to a parent scope.

- You can use **napi_escape_handle** to promote **escape_handle_scope** to a JS object so that it is valid for the lifetime of the outer scope.


**napi_ref**


Reference to **napi_value**, which allows users to manage the lifecycle of JS values.


**napi_type_tag**


Struct containing two unsigned 64-bit integers to identify the type information of a Node-API value.


```
typedef struct {
  uint64_t lower;
  uint64_t upper;
} napi_type_tag;
```


- It is a 128-bit value stored as two unsigned 64-bit integers. It is used to tag JS objects to ensure that they are of a certain type.

- This is a stronger check than **napi_instanceof** because **napi_instanceof** may report a false positive if the object's prototype is manipulated.

- The combination of **type_tag** and **napi_wrap** is useful because it ensures that the pointer retrieved from a wrapped object can be safely converted to the Native type corresponding to type tag that had been previously applied to the JS object.


**napi_async_cleanup_hook_handle**


Value used to register a callback for asynchronous operations. It is mainly used to perform a cleanup operation when an asynchronous operation is complete or canceled, for example, releasing a resource or canceling an operation. Using **napi_async_cleanup_hook_handle** ensures that related resources are correctly released and cleaned up when an asynchronous operation is complete or canceled, thereby avoiding problems such as memory leakage.


### Callback Types

Node-API provides the following callback types:

**napi_callback_info**


Data type passed to **napi_get_cb_info** to obtain JS input parameter information.


**napi_callback**


User-defined Native function, which is exposed to JS via node-API. Generally, no handle or callback scope is created in this callback.


The basic usage is as follows:


```
typedef napi_value (*napi_callback)(napi_env, napi_callback_info);
```


**napi_finalize**


Function pointer passed to **napi_create_threadsafe_function** and **napi_set_instance_data**. **napi_finalize** is called when an object is reclaimed.


**napi_async_execute_callback**


Function pointer used in **napi_create_async_work**.


- The asynchronous Native function is called from a worker pool thread and can be executed in parallel with the main event loop thread.

- Avoid making Node-API calls that execute JS or interact with JS objects when implementing this callback.

- Node-API calls should be executed in **napi_async_complete_callback**.


**napi_async_complete_callback**


Function pointer used when an asynchronous operation is complete. It is usually used in C++ addon development of Node.js. When an asynchronous operation is required, you can use **napi_create_async_work** to create an asynchronous operation task and specify a **napi_async_complete_callback** callback. When the asynchronous operation is complete, the callback is automatically called for subsequent processing. Parameters of the callback include the status of the asynchronous operation and a return value. Corresponding processing can be performed based on this information.


**napi_threadsafe_function_call_js**


Function pointer used in the main thread to interact with the JS code in an independent thread to implement more complex functions. It is used in **napi_create_threadsafe_function(napi_env env, ..., napi_threadsafe_function_call_js call_js_cb, ...)**.


**napi_cleanup_hook**


Function pointer used with **napi_add_env_cleanup_hook**. It will be called when the environment is destroyed.


**napi_async_cleanup_hook**


Function pointer used with **napi_add_async_cleanup_hook**. It will be called when the environment is destroyed.


## Node-API APIs

Node-API is extended based on the native modules provided by Node.js. The following lists the APIs supported currently.


### Asynchronous Thread-safe APIs

| API| Description|
| -------- | -------- |
| napi_create_threadsafe_function | Creates a thread-safe function.|
| napi_get_threadsafe_function_context | Obtains the context of a thread-safe function.|
| napi_call_threadsafe_function | Calls a thread-safe function.|
| napi_acquire_threadsafe_function | Indicates that a thread starts to use a thread-safe function.|
| napi_release_threadsafe_function | Indicates that a thread releases a thread-safe function.|
| napi_ref_threadsafe_function | Indicates that the event loop running on the main thread should not exit until the thread-safe function is destroyed.|
| napi_unref_threadsafe_function | Indicates that the event loop running on the main thread may exit before the thread-safe function is destroyed.|


### Buffer

| API| Description|
| -------- | -------- |
| napi_create_buffer | Creates a JS **Buffer** instance of the specified size.|
| napi_create_buffer_copy | Creates a JS **Buffer** instance of the specified size, and initializes it with data copied from the passed-in buffer.|
| napi_create_external_buffer | Creates a JS **Buffer** instance of the specified size, and initializes it with the given data. The **Buffer** instance created can include extra.|
| napi_get_buffer_info | Obtains the underlying data and its length of the JS buffer.|
| napi_is_buffer | Checks whether the given JS value is a **Buffer** object.|


### UTF16 String 

| API| Description|
| -------- | -------- |
| napi_create_string_utf16 | Creates a JS **String** from a UTF16-encoded C string.|
| napi_get_value_string_utf16 | Obtains the UTF16-encoded string corresponding to the given JS value.|
| napi_create_string_latin1 | Creates a JS **String** from an ISO-8859-1-encoded C string.|
| napi_create_string_utf8 | Creates a JS **String** from a UTF8-encoded C string.|
| napi_get_value_string_latin1 | Obtains the ISO-8859-1-encoded string corresponding to the given JS value.|
| napi_get_value_string_utf8 | Obtains the UTF8-encoded string corresponding to the given JS value.|


### Date 

| API| Description|
| -------- | -------- |
| napi_create_date | Creates a JS **Date** from C **double** data.|
| napi_get_date_value | Obtains the C double equivalent of the given JS **Date**.|
| napi_is_date | Checks whether the given JS value is a JS **Date** object.|


### arraybuffer

| API| Description|
| -------- | -------- |
| napi_get_arraybuffer_info | Obtains the underlying data buffer of the **ArrayBuffer** and its length.|
| napi_is_arraybuffer | Checks whether the given JS value is **ArrayBuffer**.|
| napi_detach_arraybuffer | Detaches the underlying data of the given **ArrayBuffer**.|
| napi_is_detached_arraybuffer | Checks whether the given **ArrayBuffer** has been detached.|
| napi_create_arraybuffer | Creates a JS **Buffer** instance of the specified size.|


### Module

| API| Description|
| -------- | -------- |
| napi_module_register | Registers a Native module.|


### Lifecycle Management

| API| Description|
| -------- | -------- |
| napi_open_handle_scope | Opens a scope. You can use **napi_close_handle_scope** to close it.|
| napi_close_handle_scope | Closes the scope passed in. After a scope is closed, all references declared in it are closed.|
| napi_open_escapable_handle_scope | Opens a scope from which one object can be prompted to the outer scope. You can use **napi_close_escapable_handle_scope** to close it.|
| napi_close_escapable_handle_scope | Closes the escapable handle scope passed in.|
| napi_escape_handle | Promotes the handle to the JS object so that it is valid for the lifetime of the outer scope.|
| napi_create_reference | Creates a reference for an **Object** to extend its lifespan. The caller needs to manage the reference lifespan.|
| napi_delete_reference | Deletes the reference passed in.|
| napi_reference_ref | Increments the reference count of the reference passed in and returns the count.|
| napi_reference_unref | Decrements the reference count of the reference passed in and returns the count.|
| napi_get_reference_value | Obtains the JS object associated with the reference.|


### Promise

| API| Description|
| -------- | -------- |
| napi_create_promise | Creates a deferred object and a JS promise.|
| napi_resolve_deferred | Resolves the deferred object associated with a promise.|
| napi_reject_deferred | Rejects the deferred object associated with a promise.|
| napi_is_promise | Checks whether the given **napi_value** is a Native promise object.|


### Array

| API| Description|
| -------- | -------- |
| napi_create_array | Creates a JS **Array**.|
| napi_create_array_with_length | Creates a JS **Array** of the specified length.|
| napi_create_typedarray | Creates a JS **TypeArray** from an existing **ArrayBuffer**.|
| napi_create_dataview | Creates a JS **TypeArray** from an existing **ArrayBuffer**.|
| napi_get_array_length | Obtains the length of an array.|
| napi_get_typedarray_info | Obtains properties of the specified **TypedArray**.|
| napi_get_dataview_info | Obtains properties of the specified **DataView**.|
| napi_is_array | Checks whether the given JS value is an **array**.|
| napi_set_element | Sets an element at the specified index of the given **Object**.|
| napi_get_element | Obtains the element at the specified index of the given **Object**.|
| napi_has_element | Obtains the element if the given **Object** has an element at the specified index.|
| napi_delete_element | Deletes the element at the specified index of the given **Object**.|


### Primitive

| API| Description|
| -------- | -------- |
| napi_get_boolean | Obtains a JS Boolean object based on the given C boolean value.|
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
| napi_get_new_target | Obtains the **new.target** of the constructor call.|
| napi_define_class | Defines a JS class corresponding to the C++ class.|
| napi_new_instance | Creates an instance based on the given constructor.|


### Object

| API| Description|
| -------- | -------- |
| napi_get_prototype | Obtains the prototype of a JS object.|
| napi_create_object | Creates a default JS object.|
| napi_object_freeze | Freezes the given object.|
| napi_object_seal | Seals the given object.|
| napi_typeof | Obtains the JS type of the specified JS value.|
| napi_instanceof | Checks whether the given object is an instance of the specified constructor.|
| napi_type_tag_object | Associates the value of the tag pointer with **Object**.|
| napi_check_object_type_tag | Checks whether a tag pointer is associated with the JS **Object**.|


### bigint

| API| Description|
| -------- | -------- |
| napi_create_bigint_int64 | Creates a JS **BigInt** from C **int64** data.|
| napi_create_bigint_uint64 | Creates a JS **BigInt** from C **uint64** data.|
| napi_create_bigint_words | Creates a single JS **BigInt** from a C **uint64** array.|
| napi_get_value_bigint_int64 | Obtains the C **int64** equivalent of the given JS **BigInt**.|
| napi_get_value_bigint_uint64 | Obtains the C **uint64** equivalent of the given JS **BigInt**.|
| napi_get_value_bigint_words | Obtains information from the given JS **BigInt**, including the sign bit, 64-bit little-endian array, and number of elements in the array.|


### Exceptions and Errors

| API| Description|
| -------- | -------- |
| napi_throw | Throws a JS value.|
| napi_throw_type_error | Throws a JS **TypeError** with text information.|
| napi_throw_range_error | Throws a JS **RangeError** with text information.|
| napi_is_error | Checks whether **napi_value** indicates an error object.|
| napi_create_error | Creates a JS **Error** with text information.|
| napi_create_type_error | Creates a JS **TypeError** with text information.|
| napi_create_range_error | Creates a JS **RangeError** with text information.|
| napi_get_and_clear_last_exception | Obtains and clears the latest exception.|
| napi_is_exception_pending | Checks whether an exception occurs.|
| napi_fatal_error | Raises a fatal error to terminate the process immediately.|
| napi_get_last_error_info | Obtains the **napi_extended_error_info** struct, which contains the latest error information.|


### Property

| API| Description|
| -------- | -------- |
| napi_get_property_names | Obtains the names of the enumerable properties of **Object** in an array of strings.|
| napi_set_property | Sets a property for the given **Object**.|
| napi_get_property | Obtains the requested property of the given **Object**.|
| napi_has_property | Checks whether the given **Object** has the specified property.|
| napi_delete_property | Deletes the **key** property from the given **Object**.|
| napi_has_own_property | Checks whether the given **Object** has the own property named **key**.|
| napi_set_named_property | Sets a property with the specified name for the given **Object**.|
| napi_get_named_property | Obtains the property with the specified name in the given **Object**.|
| napi_has_named_property | Checks whether the given **Object** has the property with the specified name.|
| napi_define_properties | Defines multiple properties for the given **Object**.|
| napi_get_all_property_names | Obtains an array containing the names of all the available properties of this object.|


### Asynchronous Tasks

| API| Description|
| -------- | -------- |
| napi_create_async_work | Creates a work object that executes logic asynchronously.|
| napi_delete_async_work | Releases an asynchronous work object.|
| napi_queue_async_work | Adds an asynchronous work object to the queue so that it can be scheduled for execution.|
| napi_cancel_async_work | Cancels the queued asynchronous work if it has not been started.|


### Comparing JS Values

| API| Description|
| -------- | -------- |
| napi_strict_equals | Checks whether two JS values are strictly equal.|


### UV 

| API| Description|
| -------- | -------- |
| napi_get_uv_event_loop | Obtains the current libuv loop instance.|


### Function Invocation

| API| Description|
| -------- | -------- |
| napi_call_function | Calls a JS function from a C/C++ addon.|
| napi_get_cb_info | Obtains detailed information about the call, such as the parameters and **this** pointer, from the given callback info.|


### Extension

| API| Description|
| -------- | -------- |
| napi_queue_async_work_with_qos | Adds an asynchronous work object to the queue and schedules it based on the QoS priority passed in.|
| napi_run_script_path | Runs a .abc file.|
