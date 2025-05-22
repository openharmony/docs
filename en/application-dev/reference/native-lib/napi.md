# Node-API

## Introduction

Node-API provides APIs to encapsulate JavaScript (JS) capabilities as native addons. It is independent of the underlying JS and is maintained as part of Node.js.

## Supported Capabilities

Node-API insulates addons from changes in the underlying JS engine and allows the modules compiled for one major version to run on later major versions without recompilation.

The OpenHarmony Node-API component optimizes the Node-API implementation and provides interaction with underlying engines such as ArkJS. Currently, the OpenHarmony Node-API component does not support all Node-API APIs.

## Including Node-API Capabilities

To use Node-API, include the following header file:

```cpp
#include <napi/native_api.h>
```

Add the following dynamic link library to **CMakeLists.txt**:

```
libace_napi.z.so
```

## Symbols Exported from the Node-API Library

The APIs exported from the native Node-API library feature usage and behaviors based on [Node.js](https://nodejs.org/docs/latest-v12.x/api/n-api.html) and have incorporated [extended capabilities](#node-api-extended-symbols).

|Symbol Type|Symbol|Description|Start API Version|
| --- | --- | --- | --- |
|FUNC|napi_module_register|Registers a native module.|10|
|FUNC|napi_get_last_error_info|Obtains the **napi_extended_error_info** struct, which contains the latest error information.|10|
|FUNC|napi_throw|Throws a JS value.|10|
|FUNC|napi_throw_error|Throws a JS **Error** with text information.|10|
|FUNC|napi_throw_type_error|Throws a JS **TypeError** with text information.|10|
|FUNC|napi_throw_range_error|Throws a JS **RangeError** with text information.|10|
|FUNC|napi_is_error|Checks whether **napi_value** indicates an error object.|10|
|FUNC|napi_create_error|Creates a JS **Error** with text information.|10|
|FUNC|napi_create_type_error|Creates a JS **TypeError** with text information.|10|
|FUNC|napi_create_range_error|Creates a JS **RangeError** with text information.|10|
|FUNC|napi_get_and_clear_last_exception|Obtains and clears the latest exception.|10|
|FUNC|napi_is_exception_pending|Checks whether an exception occurs.|10|
|FUNC|napi_fatal_error|Raises a fatal error to terminate the process immediately.|10|
|FUNC|napi_open_handle_scope|Opens a scope.|10|
|FUNC|napi_close_handle_scope|Closes the scope passed in. After the scope is closed, all references declared in it are closed.|10|
|FUNC|napi_open_escapable_handle_scope|Opens an escapable handle scope, from which the declared values can be returned to the parent scope.|10|
|FUNC|napi_close_escapable_handle_scope|Closes the escapable handle scope passed in.|10|
|FUNC|napi_escape_handle|Promotes the handle to the input JS object so that it is valid for the lifespan of its outer scope.|10|
|FUNC|napi_create_reference|Creates a reference for an **Object** to extend its lifespan. The caller needs to manage the reference lifespan.|10|
|FUNC|napi_delete_reference|Deletes the reference passed in.|10|
|FUNC|napi_reference_ref|Increments the reference count for the reference passed in and returns the count.|10|
|FUNC|napi_reference_unref|Decrements the reference count for the reference passed in and returns the count.|10|
|FUNC|napi_get_reference_value|Obtains the JS **Object** associated with the reference.|10|
|FUNC|napi_create_array|Creates a JS array.|10|
|FUNC|napi_create_array_with_length|Creates a JS array of the specified length.|10|
|FUNC|napi_create_arraybuffer|Creates a JS **ArrayBuffer** of the specified size.|10|
|FUNC|napi_create_external|Allocates a JS value with external data.|10|
|FUNC|napi_create_external_arraybuffer|Allocates a JS **ArrayBuffer** with external data.|10|
|FUNC|napi_create_object|Creates a default JS object.|10|
|FUNC|napi_create_symbol|Creates a JS symbol.|10|
|FUNC|napi_create_typedarray|Creates a JS **TypeArray** from an existing **ArrayBuffer**.|10|
|FUNC|napi_create_dataview|Creates a JS **DataView** from an existing **ArrayBuffer**.|10|
|FUNC|napi_create_int32|Creates a JS number from C int32_t data.|10|
|FUNC|napi_create_uint32|Creates a JS number from C uint32_t data.|10|
|FUNC|napi_create_int64|Creates a JS number from C int64_t data.|10|
|FUNC|napi_create_double|Creates a JS number from C double data.|10|
|FUNC|napi_create_string_latin1|Creates a JS string from an ISO-8859-1-encoded C string.|10|
|FUNC|napi_create_string_utf8|Creates a JS string from a UTF8-encoded C string.|10|
|FUNC|napi_create_string_utf16|Creates a JS string from a UTF16-encoded C string.|10|
|FUNC|napi_get_array_length|Obtains the array length.|10|
|FUNC|napi_get_arraybuffer_info|Obtains the underlying data buffer of an **ArrayBuffer** and its length.|10|
|FUNC|napi_get_prototype|Obtains the prototype of a JS object.|10|
|FUNC|napi_get_typedarray_info|Obtains properties of a **TypedArray**.|10|
|FUNC|napi_get_dataview_info|Obtains properties of a **DataView**.|10|
|FUNC|napi_get_value_bool|Obtains the C Boolean equivalent of a JS Boolean value.|10|
|FUNC|napi_get_value_double|Obtains the C double equivalent of a JS number.|10|
|FUNC|napi_get_value_external|Obtains the external data pointer previously passed through **napi_create_external()**.|10|
|FUNC|napi_get_value_int32|Obtains the C int32 equivalent of a JS number.|10|
|FUNC|napi_get_value_int64|Obtains the C int64 equivalent of a JS number.|10|
|FUNC|napi_get_value_string_latin1|Obtains the ISO-8859-1-encoded string corresponding to the given JS value.|10|
|FUNC|napi_get_value_string_utf8|Obtains the UTF8-encoded string corresponding to the given JS value.|10|
|FUNC|napi_get_value_string_utf16|Obtains the UTF16-encoded string corresponding to the given JS value.|10|
|FUNC|napi_get_value_uint32|Obtains the C uint32 equivalent of a JS number.|10|
|FUNC|napi_get_boolean|Obtains a JS Boolean object based on a C Boolean value.|10|
|FUNC|napi_get_global|Obtains the **global** object.|10|
|FUNC|napi_get_null|Obtains the **null** object.|10|
|FUNC|napi_get_undefined|Obtains the **undefined** object.|10|
|FUNC|napi_coerce_to_bool|Forcibly converts a JS value to a JS Boolean value.|10|
|FUNC|napi_coerce_to_number|Forcibly converts a JS value to a JS number.|10|
|FUNC|napi_coerce_to_object|Forcibly converts a JS value to a JS object.|10|
|FUNC|napi_coerce_to_string|Forcibly converts a JS value to a JS string.|10|
|FUNC|napi_typeof|Obtains the JS type of a JS value.|10|
|FUNC|napi_instanceof|Checks whether an object is an instance of the specified constructor.|10|
|FUNC|napi_is_array|Checks whether a JS value is an array.|10|
|FUNC|napi_is_arraybuffer|Checks whether a JS value is an **ArrayBuffer**.|10|
|FUNC|napi_is_typedarray|Checks whether a JS value is a **TypedArray**.|10|
|FUNC|napi_is_dataview|Checks whether a JS value is a **DataView**.|10|
|FUNC|napi_is_date|Checks whether a JS value is a JS **Date** object.|10|
|FUNC|napi_strict_equals|Checks whether two JS values are strictly equal.|10|
|FUNC|napi_get_property_names|Obtains the names of the enumerable properties of an object in an array of strings.|10|
|FUNC|napi_set_property|Sets a property for an object.|10|
|FUNC|napi_get_property|Obtains the requested property of an object.|10|
|FUNC|napi_has_property|Checks whether an object has the specified property.|10|
|FUNC|napi_delete_property|Deletes the **key** property from an object.|10|
|FUNC|napi_has_own_property|Checks whether an object has the own property named **key**.|10|
|FUNC|napi_set_named_property|Sets a property with the given name for an object.|10|
|FUNC|napi_get_named_property|Obtains the property with the given name in an object.|10|
|FUNC|napi_has_named_property|Checks whether an object has the property with the given name.|10|
|FUNC|napi_set_element|Sets an element at the specified index of an object.|10|
|FUNC|napi_get_element|Obtains the element at the specified index of an object.|10|
|FUNC|napi_has_element|Obtains the element if the object has an element at the specified index.|10|
|FUNC|napi_delete_element|Deletes the element at the specified index of an object.|10|
|FUNC|napi_define_properties|Defines multiple properties for an object.|10|
|FUNC|napi_type_tag_object|Associates the value of a tag pointer with an object.|10|
|FUNC|napi_check_object_type_tag|Checks whether a tag pointer is associated with a JS object.|10|
|FUNC|napi_call_function|Calls a JS function object in a native method, that is, native calls JS.|10|
|FUNC|napi_create_function|Creates a function object in native code for JS to call.|10|
|FUNC|napi_get_cb_info|Obtains detailed information about the call, such as the parameters and **this** pointer, from the given callback information.|10|
|FUNC|napi_get_new_target|Obtains the **new.target** of the constructor call.|10|
|FUNC|napi_new_instance|Creates an instance based on the given constructor.|10|
|FUNC|napi_define_class|Defines a JS class corresponding to the C++ class.|10|
|FUNC|napi_wrap|Wraps a native instance in a JS object.|10|
|FUNC|napi_unwrap|Unwraps the native instance from a JS object.|10|
|FUNC|napi_remove_wrap|Removes the native instance from the JS object.|10|
|FUNC|napi_create_async_work|Creates a work object that executes logic asynchronously.|10|
|FUNC|napi_delete_async_work|Releases an async work object.|10|
|FUNC|napi_queue_async_work|Adds an async work object to the queue so that it can be scheduled for execution.|10|
|FUNC|napi_cancel_async_work|Cancels the queued async work if it has not been started.|10|
|FUNC|napi_async_init|Creates an async context. The capabilities related to **async_hook** are not supported.|11|
|FUNC|napi_make_callback|Allows a JS function to be called in the async context. The capabilities related to **async_hook** are not supported.|11|
|FUNC|napi_async_destroy|Destroys an async context. The capabilities related to **async_hook** are not supported.|11|
|FUNC|napi_open_callback_scope|Opens a callback scope. The capabilities related to **async_hook** are not supported.|11|
|FUNC|napi_close_callback_scope|Closes a callback scope. The capabilities related to **async_hook** are not supported.|11|
|FUNC|napi_get_node_version|Obtains the current Node-API version.|10|
|FUNC|napi_get_version|Obtains the latest Node-API version supported when the Node.js runtime.|10|
|FUNC|napi_create_promise|Creates a deferred object and a JS promise.|10|
|FUNC|napi_resolve_deferred|Resolves a deferred object that is associated with a JS promise.|10|
|FUNC|napi_reject_deferred|Rejects a deferred object that is associated with a JS promise.|10|
|FUNC|napi_is_promise|Checks whether the given JS value is a promise object.|10|
|FUNC|napi_get_uv_event_loop|Obtains the current libuv loop instance.|10|
|FUNC|napi_create_threadsafe_function|Creates a thread-safe function.|10|
|FUNC|napi_get_threadsafe_function_context|Obtains the context of a thread-safe function.|10|
|FUNC|napi_call_threadsafe_function|Calls a thread-safe function.|10|
|FUNC|napi_acquire_threadsafe_function|Acquires a thread-safe function.|10|
|FUNC|napi_release_threadsafe_function|Releases a thread-safe function.|10|
|FUNC|napi_ref_threadsafe_function|Creates a reference to a thread-safe function. The event loop running on the main thread should not exit until the thread-safe function is destroyed.|10|
|FUNC|napi_unref_threadsafe_function|Releases the reference to a thread-safe function. The event loop running on the main thread may exit before the thread-safe function is destroyed.|10|
|FUNC|napi_create_date|Creates a JS **Date** object from C double data.|10|
|FUNC|napi_get_date_value|Obtains the C double equivalent of the given JS **Date**.|10|
|FUNC|napi_create_bigint_int64|Creates a JS BigInt from C int64 data.|10|
|FUNC|napi_create_bigint_uint64|Creates a JS BigInt from C uint64 data.|10|
|FUNC|napi_create_bigint_words|Creates a single JS BigInt from a C uint64 array.|10|
|FUNC|napi_get_value_bigint_int64|Obtains the C int64 equivalent of the given JS BigInt.|10|
|FUNC|napi_get_value_bigint_uint64|Obtains the C uint64 equivalent of the given JS BigInt.|10|
|FUNC|napi_get_value_bigint_words|Obtains information from the given JS BigInt, including the sign bit, 64-bit little-endian array, and number of elements in the array.|10|
|FUNC|napi_create_buffer|Creates a JS **Buffer** instance of the specified size.|10|
|FUNC|napi_create_buffer_copy|Creates a JS **Buffer** instance of the specified size, and initializes it with data copied from the passed-in buffer.|10|
|FUNC|napi_create_external_buffer|Creates a JS **Buffer** instance of the specified size, and initializes it with the given data. The **Buffer** instance created can include extra.|10|
|FUNC|napi_get_buffer_info|Obtains the underlying data of **Buffer** and its length.|10|
|FUNC|napi_is_buffer|Checks whether the given JS value is a **Buffer** object.|10|
|FUNC|napi_object_freeze|Freezes the given object.|10|
|FUNC|napi_object_seal|Seals the given object.|10|
|FUNC|napi_get_all_property_names|Obtains an array containing the names of all the available properties of this object.|10|
|FUNC|napi_detach_arraybuffer|Detaches the underlying data of the given ArrayBuffer.|10|
|FUNC|napi_is_detached_arraybuffer|Checks whether the given ArrayBuffer has been detached.|10|
|FUNC|napi_run_script|Runs an object as JS code. Currently, this API is an empty implementation. For security purposes, you are advised to use **napi_run_script_path**.|10|
|FUNC|napi_set_instance_data|Associates data with the currently running environment.|11|
|FUNC|napi_get_instance_data|Retrieves the data that was previously associated with the currently running environment.|11|
|FUNC|napi_add_env_cleanup_hook|Registers a clean-up hook for releasing resources when the environment exits.|11|
|FUNC|napi_remove_env_cleanup_hook|Unregisters the clean-up hook.|11|
|FUNC|napi_add_async_cleanup_hook|Registers an async clean-up hook for releasing resources when the environment exits.|11|
|FUNC|napi_remove_async_cleanup_hook|Unregisters the async clean-up hook.|11|
|FUNC|node_api_get_module_file_name|Obtains the absolute path of the location, from which the addon is loaded.|11|
|FUNC|napi_add_finalizer|Adds a **napi_finalize** callback, which will be called when the JS object in **js_Object** is garbage-collected.|11|
|FUNC|napi_fatal_exception|Throws **UncaughtException** to JS.|12|

## Differences Between the Exported Symbols and the Symbols in the Native Library

> **NOTE**
>
> For ease of description, the symbol exported to OpenHarmony is referred to as "exported symbol" and the symbol in the native library is referred to as "native symbol".

### napi_throw_error

**Return value**

- If **code** is a null pointer, the native symbol returns **napi_invalid_arg**, whereas the exported symbol does not check the validity of **code**.

- The exported symbol permits a failure in setting **code**.

### napi_throw_type_error

**Return value**

- If **code** is a null pointer, the native symbol returns **napi_invalid_arg**, whereas the exported symbol does not check the validity of **code**.

- The exported symbol permits a failure in setting **code**.

### napi_throw_range_error

**Return value**

- If **code** is a null pointer, the native symbol returns **napi_invalid_arg**, whereas the exported symbol does not check the validity of **code**.

- The exported symbol permits a failure in setting **code**.

### napi_create_error

**Parameters**

- **code**: The value type can be string or number in the exported symbol.

**Return value**

- If the code type is incorrect, the exported symbol returns **napi_invalid_arg**.

- The exported symbol permits a failure in setting **code**.

### napi_create_type_error

**Parameters**

- **code**: The value type can be string or number in the exported symbol.

**Return value**

- If the code type is incorrect, the exported symbol returns **napi_invalid_arg**.

- The exported symbol permits a failure in setting **code**.

- The error type created in OpenHarmony is **Error**.

### napi_create_range_error

**Parameters**

- **code**: The value type can be string or number in the exported symbol.

**Return value**

- If the code type is incorrect, the exported symbol returns **napi_invalid_arg**.

- The exported symbol permits a failure in setting **code**.

- The error type created in OpenHarmony is **Error**.

### napi_create_reference

**Parameters**

- **value**: The value type can be object, function, or symbol in the native symbol, whereas there are no restrictions on the value type in the exported symbol.

### napi_delete_reference

**NOTE**

- In OpenHarmory, if the **napi_finalize** callback is registered when a strong reference is created, calling this API will trigger the **napi_finalize** callback.

### napi_create_symbol

**Return value**

- The exported symbol returns **napi_invalid_arg** if **description** is not empty and is not a string.

### napi_create_typedarray

**Return value**

- The exported symbol returns **napi_arraybuffer_expected** if **arraybuffer** is not empty and is not an **ArrayBuffer** object.

### napi_create_dataview

**Return value**

- The exported symbol returns **napi_arraybuffer_expected** if **arraybuffer** is not empty and is not an **ArrayBuffer** object.

- If the sum of **byte_offset** and **byte_length** is greater than the size of **arraybuffer**, the export API throws a **RangeError** exception and returns **napi_pending_exception**.

### napi_get_typedarray_info

**Parameters**

- **object**: The value type can be TypedArray or [Sendable TypedArray](../apis-arkts/js-apis-arkts-collections.md#collectionstypedarray) in the exported symbol.

**Return value**

- The native symbol returns the number of elements in TypedArray via the **length** parameter; while the exported symbol returns length of the elements in TypedArray, in bytes.

### napi_coerce_to_object

**Return value**

- If **value** is **undefined** or null, the exported symbol returns **napi_ok** and **undefined** in **result**.

### napi_instanceof

**Return value**

- If **object** is not an object, the exported symbol returns **napi_object_expected** with **result** unprocessed.

- If **constructor** is not a function object, the exported symbol returns **napi_function_expected** without throwing any exception.

### napi_is_typedarray

**Parameters**

- **value**: The exported symbol also supports the [Sendable TypedArray](../apis-arkts/js-apis-arkts-collections.md#collectionstypedarray) type for **value**.

### napi_get_property_names

**Return value**

- If **object** is not an object or a function, the exported symbol returns **napi_object_expected**.

### napi_set_property

**Return value**

- If **object** is not an object or a function, the exported symbol returns **napi_object_expected**.

### napi_get_property

**Return value**

- If **object** is not an object or a function, the exported symbol returns **napi_object_expected**.

### napi_has_property

**Return value**

- If **object** is not an object or a function, the exported symbol returns **napi_object_expected**.

### napi_delete_property

**Return value**

- If **object** is not an object or a function, the exported symbol returns **napi_object_expected**.

### napi_has_own_property

**Return value**

- If **object** is not an object or a function, the exported symbol returns **napi_object_expected**.

### napi_set_named_property

**Return value**

- If **object** is not an object or a function, the exported symbol returns **napi_object_expected**.

### napi_get_named_property

**Return value**

- If **object** is not an object or a function, the exported symbol returns **napi_object_expected**.

### napi_has_named_property

**Return value**

- If **object** is not an object or a function, the exported symbol returns **napi_object_expected**.

### napi_set_element

**Return value**

- If **object** is not an object or a function, the exported symbol returns **napi_object_expected**.

- If the **index** value is too large, the native symbol throws an exception and interrupts the process. OpenHarmony attempts to allocate memory. If the memory allocation fails, **object** will not be modified.

### napi_get_element

**Return value**

- If **object** is not an object or a function, the exported symbol returns **napi_object_expected**.

### napi_has_element

**Return value**

- If **object** is not an object or a function, the exported symbol returns **napi_object_expected**.

### napi_delete_element

**Return value**

- If **object** is not an object or a function, the exported symbol returns **napi_object_expected**.

### napi_define_properties

**Return value**

- If **object** is not an object or a function, the exported symbol returns **napi_object_expected**.

- If an exception is triggered during property traversal, the native symbol throws the exception, whereas the exported symbol clears the exception and continues the execution.

### napi_type_tag_object

**Return value**

- If **js_object** is not an object or a function, the exported symbol returns **napi_object_expected**.

### napi_check_object_type_tag

**Return value**

- If **js_object** is not an object or a function, the exported symbol returns **napi_object_expected**.

### napi_call_function

**Return value**

- The export symbol does not check whether the **recv** parameter is **nullptr**.

- If **func** is not a function, the export symbol returns **napi_function_expected**.

### napi_new_instance

**Return value**

- If **constructor** is not a function, the export symbol returns **napi_function_expected**.

### napi_define_class

**Return value**

- If **length** is not **NAPI_AUTO_LENGTH** and is greater than **INT_MAX**, the exported symbol returns **napi_object_expected**.

### napi_wrap

**Parameters**

- **finalize_cb**: It can be empty in the native symbol. If this parameter is empty, the exported symbol returns **napi_invalid_arg**.
- **result**: The native symbol returns a weak reference, whereas the exported symbol returns a strong reference if **result** is not empty.

**Return value**

- If **js_object** is not an object or a function, the exported symbol returns **napi_object_expected**.

### napi_unwrap

**Return value**

- If **js_object** is not an object or a function, the exported symbol returns **napi_object_expected**.

### napi_remove_wrap

**Return value**

- If **js_object** is not an object or a function, the exported symbol returns **napi_object_expected**.

**NOTE**

- If the wrap is associated with the **finalize** callback, the export symbol will call **finalize()** before removing the wrap.

### napi_create_async_work

**Parameters**

- The exported symbol does not support **async_hooks**.

- The exported symbol does not verify whether the input parameter **async_resource_name** is of the string type. A value of string type is recommended. If **async_resource_name** is of the string type, the trace information contains the string. Otherwise, the trace information does not contain it.

- The exported symbol does not process the input parameter **async_resource** because it does not support **async_hooks**.

### napi_delete_async_work

**Parameters**

- The exported symbol does not support **async_hooks**.

### napi_queue_async_work

**Parameters**

- The exported symbol does not support **async_hooks**.

### napi_cancel_async_work

**Return value**

- If the task fails to be canceled due to the underlying UV, the native symbol returns **napi_generic_failure**, **napi_invalid_arg**, or **napi_cancelled** based on the failure cause. The exported symbol does not verify the UV return value. You can check whether the task fails to be canceled based on log information.

### napi_async_init

**NOTE**

- Currently, OpenHarmony does not support **async_hooks**. After the exported symbol is called, operations related to **async_hooks** will not be performed.

### napi_make_callback

**NOTE**

- Currently, OpenHarmony does not support **async_hooks**. After the exported symbol is called, operations related to **async_hooks** will not be performed.

### napi_async_destroy

**NOTE**

- Currently, OpenHarmony does not support **async_hooks**. After the exported symbol is called, operations related to **async_hooks** will not be performed.

### napi_get_node_version

**NOTE**

- OpenHarmony does not need to obtain the node version. Therefore, the export symbol is an empty implementation.

### napi_resolve_deferred

**NOTE**

- When an exception occurs in the **resolve** or **reject** callback of the **then()** method of the promise, if the promise does not have a catch block, the code execution continues. If the promise has a catch block, the exception will be captured by the catch block.

### napi_reject_deferred

**NOTE**

- When an exception occurs in the **resolve** or **reject** callback of the **then()** method of the promise, if the promise does not have a catch block, the code execution continues. If the promise has a catch block, the exception will be captured by the catch block.

### napi_create_threadsafe_function

**Parameters**

- **initial_thread_count**: The maximum value is **128** in the exported symbol.

- **async_resource**: There is no type restriction for this parameter in the exported symbol.

- **async_resource_name**: There is no type restriction for this parameter in the exported symbol.

- **func**: There is no type restriction for this parameter in the exported symbol.

**NOTE**

- In OpenHarmony, the **cleanup hook** method is not registered when a thread-safe function is created. You can call **napi_add_env_cleanup_hook** if required.

### napi_call_threadsafe_function

**NOTE**

- Before **uv_async_send** is called in OpenHarmony, **env** is checked.

- If **uv_async_send** fails to be called, the exported symbol returns **napi_generic_failure**.

### napi_release_threadsafe_function

**NOTE**

- Before **uv_async_send** is called in OpenHarmony, **env** is checked.

- If **ThreadCount** is **0**, the exported symbol returns **napi_generic_failure**.

### napi_ref_threadsafe_function

**NOTE**

- The exported symbol checks whether **func** and **env** belong to the same ArkTS thread. If not, **napi_generic_failure** is returned.

### napi_unref_threadsafe_function

**NOTE**

- The exported symbol checks whether **func** and **env** belong to the same ArkTS thread. If not, **napi_generic_failure** is returned.

### napi_create_date

**Return value**

- If the input parameters are correct but **date** fails to be created, the native symbol returns **napi_generic_failure**. In OpenHarmony, an exception is thrown, and the exported symbol returns **napi_pending_exception**.

### napi_create_bigint_words

**Return value**

- If the input parameters are correct but bigInt fails to be created, the native symbol returns **napi_generic_failure**. In OpenHarmony, an exception is thrown, and the exported symbol returns **napi_pending_exception**.

### napi_get_value_bigint_words

**Return value**

- If **value** is not a BigInt object, the exported symbol returns **napi_object_expected**.

### napi_create_buffer

**Return value**

- The buffer created in OpenHarmony is of the ArrayBufferLike type.

- If **size** is less than or equal to **0**, the exported symbol returns **napi_invalid_arg**.

- If **size** is greater than **2097152**, the exported symbol returns **napi_invalid_arg** and logs an error.

- If **data** is **nullptr**, the exported symbol returns **napi_invalid_arg**.

- If an exception occurs before the native symbol is called or exited, **napi_pending_exception** is returned. There is no such verification in OpenHarmony.

### napi_create_buffer_copy

**Return value**

- The buffer created in OpenHarmony is of the ArrayBufferLike type.

- If **length** is less than or equal to **0**, the exported symbol returns **napi_invalid_arg**.

- If **length** is greater than **2097152**, the exported symbol returns **napi_invalid_arg** and logs an error.

- If **data** is **nullptr**, the exported symbol returns **napi_invalid_arg**.

- If an exception occurs before the native symbol is called or exited, **napi_pending_exception** is returned. There is no such verification in OpenHarmony.

### napi_create_external_buffer

**Return value**

- The buffer created in OpenHarmony is of the ArrayBufferLike type.

- If **length** is less than or equal to **0**, the exported symbol returns **napi_invalid_arg**.

- If **length** is greater than **2097152**, the exported symbol returns **napi_invalid_arg** and logs an error.

- If the buffer fails to be created due to an identified cause, the native symbol returns **napi_generic_failure**, whereas the exported symbol returns **napi_pending_exception**.

### napi_get_buffer_info

**Return value**

- OpenHarmony checks whether the value belongs to **buffer**. If not, **napi_arraybuffer_expected** is returned.

### napi_detach_arraybuffer

**Return value**

- If **arraybuffer** is not an object, the exported symbol returns **napi_object_expected**. If **arraybuffer** is an object but not an **ArrayBuffer** object, it returns **napi_invalid_arg**.

### napi_add_env_cleanup_hook

**NOTE**

- If data is registered with **env**, OpenHarmony prints only error logs.

### napi_add_finalizer

**Return value**

- If **js_object** is not an object, the exported symbol returns **napi_object_expected**.

**NOTE**

- In OpenHarmony, when a strong reference is deleted, this callback is directly invoked without waiting for the destruction of the object.

- If the callback throws an exception, OpenHarmony triggers JSCrash.

**NOTE**

- The native symbol returns a weak reference, whereas the exported symbol returns a strong reference if **result** is not empty.

### napi_fatal_exception

**Parameters**

- **err**: The exported symbol supports only the **Error** type. If the type does not match, **napi_invalid_arg** is returned.

### napi_get_uv_event_loop

**Return value**

- If **env** is not a valid **napi_env** (for example, it is a released **env**), the exported symbol returns **napi_generic_failure**.

### napi_create_array_with_length

**Return value**

- If **length** is too large, the native symbol throws an exception and interrupts the process. OpenHarmony attempts to allocate memory. If the memory allocation fails, an exception is thrown and an array with length of 0 is returned.

### napi_create_arraybuffer

**Return value**

- If **length** is too large, the native symbol throws an exception and interrupts the process. OpenHarmony attempts to allocate memory. If the memory allocation fails, an exception is thrown and **undefined** is returned.

## Symbols Not Exported from the Node-API Library

|Symbol Type|Symbol|Description|
| --- | --- | --- |
|FUNC|napi_adjust_external_memory|Adjusts the external memory held by a JS object.|

## Node-API Extended Symbols

|Symbol Type|Symbol|Description|Start API Version|
| --- | --- | --- | --- |
|FUNC|napi_queue_async_work_with_qos|Adds an async work object to the queue so that it can be scheduled for execution based on the QoS priority passed in.|10|
|FUNC|napi_run_script_path|Runs an ABC file.|10|
|FUNC|napi_load_module|Loads an .abc file as a module. This API returns the namespace of the module.|11|
|FUNC|napi_create_object_with_properties|Creates a JS object using the given **napi_property_descriptor**. The key of the descriptor must be a string and cannot be converted into a number.|11|
|FUNC|napi_create_object_with_named_properties|Creates a JS object using the given **napi_value** and key. The key must be a string and cannot be converted into a number.|11|
|FUNC|napi_coerce_to_native_binding_object|Forcibly binds a JS object and a native object.|11|
|FUNC|napi_create_ark_runtime|Creates an ArkTS runtime environment.|12|
|FUNC|napi_destroy_ark_runtime|Destroys the ArkTS runtime environment.|12|
|FUNC|napi_run_event_loop|Runs the underlying event loop.|12|
|FUNC|napi_stop_event_loop|Stops the underlying event loop.|12|
|FUNC|napi_load_module_with_info|Loads an .abc file as a module. This API returns the namespace of the module. It can be used in a newly created ArkTS runtime environment.|12|
|FUNC|napi_serialize|Converts an ArkTS object into native data.|12|
|FUNC|napi_deserialize|Converts native data into an ArkTS object.|12|
|FUNC|napi_delete_serialization_data|Deletes serialized data.|12|
|FUNC|napi_call_threadsafe_function_with_priority|Calls a task with the specified priority and enqueuing mode into the ArkTS main thread.|12|
|FUNC|napi_is_sendable|Checks whether the given JS value is sendable.|12|
|FUNC|napi_define_sendable_class|Creates a sendable class.|12|
|FUNC|napi_create_sendable_object_with_properties | Creates a sendable object with the given **napi_property_descriptor**.|12|
|FUNC|napi_create_sendable_array | Creates a sendable array.|12|
|FUNC|napi_create_sendable_array_with_length | Creates a sendable array of the specified length.|12|
|FUNC|napi_create_sendable_arraybuffer | Creates a sendable **ArrayBuffer**.|12|
|FUNC|napi_create_sendable_typedarray | Creates a sendable **TypedArray**.|12|
|FUNC|napi_wrap_sendable | Wraps a native instance into an ArkTS object.|12|
|FUNC|napi_wrap_sendable_with_size | Wraps a native instance into an ArkTS object with the specified size.|12|
|FUNC|napi_unwrap_sendable | Unwraps the native instance from an ArkTS object.|12|
|FUNC|napi_remove_wrap_sendable | Removes the native instance from an ArkTS object.|12|
|FUNC|napi_wrap_enhance | Wraps a Node-API instance into an ArkTS object and specifies the instance size. You can specify whether to execute the registered callback asynchronously (if asynchronous, it must be thread-safe).|18|

> **NOTE**
>
> For details about the sendable feature, see [Sendable Object Overview](../../arkts-utils/arkts-sendable.md).

### napi_qos_t

```cpp
typedef enum {
    napi_qos_background = 0,      // Low priority for works invisible to users, such as data synchronization and backup.
    napi_qos_utility = 1, // Medium priority for works that do not require immediate response, such as downloading or importing data.
    napi_qos_default = 2,  // Default priority.
    napi_qos_user_initiated = 3, // High priority for user-triggered works with visible progress, for example, opening a file.
} napi_qos_t;
```

**Description**
Enumerates the QoS levels, which determine the priority of thread scheduling.

### napi_event_mode

```cpp
typedef enum {
    napi_event_mode_default = 0, //  Run the underlying event loop while blocking the current thread, and exit the event loop only when there is no task in the loop.
    napi_event_mode_nowait = 1, // Run the underlying event loop without blocking the current thread. Process a task and exit the event loop after the task is complete. If there is no task in the event loop, exit the event loop immediately.
} napi_event_mode;
```

**Description**
Enumerates the modes for running the underlying event loop.

### napi_queue_async_work_with_qos

```cpp
napi_status napi_queue_async_work_with_qos(napi_env env,
                                           napi_async_work work,
                                           napi_qos_t qos);
```

**Description**

Adds an async work object to the queue so that it can be scheduled for execution based on the QoS priority passed in.

**Parameters**

- **env**: environment, in which the API is invoked.

- **work**: handle to the async work object to schedule. This object is created by **napi_create_async_work**.

- **qos**: priority of the task to schedule.

**Return value**

**napi_ok** if the operation is successful.

### napi_run_script_path

```cpp
napi_status napi_run_script_path(napi_env env,
                                 const char* abcPath,
                                 napi_value* result);
```

**Description**

Runs an .abc file.

**Parameters**

- **env**: environment, in which the API is invoked.

- **abcPath**: JS path of the script to run. The value is a string that specifies the location of the script file to run.

- **result**: pointer to **napi_value**, which holds the script execution result.

**Return value**

**napi_ok** if the operation is successful.

### napi_load_module

```cpp
napi_status napi_load_module(napi_env env,
                             const char* path,
                             napi_value* result);
```

**Description**

Loads a system module or a customized module. This API returns the namespace of the module loaded.

**Parameters**

- **env**: environment, in which the API is invoked.

- **path**: name of the system module to load or path of the customized module to load.

- **result**: pointer to **napi_value**, which holds the module loading result.

**Return value**

**napi_ok** if the operation is successful.

### napi_create_object_with_properties

```cpp
napi_status napi_create_object_with_properties(napi_env env,
                                               napi_value* result,
                                               size_t property_count,
                                               const napi_property_descriptor* properties);
```

**Description**

Creates a JS object using the given **napi_property_descriptor**.<br>**napi_property_descriptor** defines a property, including the property attributes and the methods used to obtain and set the property. By passing **napi_property_descriptor**, you can define the properties when creating an object.

 The key in **napi_property_descriptor** must be a string that cannot be converted into a number.

**Parameters**

- **env**: environment, in which the API is invoked.

- **result**: pointer to **napi_value**, which holds the created object.

- **property_count**: number of properties to be added to the object.

- **properties**: pointer to a **napi_property_descriptor** array containing information about the properties to be added to the object.

**Return value**

**napi_ok** if the operation is successful.

### napi_create_object_with_named_properties

```cpp
napi_status napi_create_object_with_named_properties(napi_env env,
                                                     napi_value* result,
                                                     size_t property_count,
                                                     const char** keys,
                                                     const napi_value* values);
```

**Description**

Creates a JS object using the given **napi_value**s and keys. The key must be a string and cannot be converted into a number.

**Parameters**

- **env**: environment, in which the API is invoked.

- **result**: pointer to **napi_value**, which holds the created object.

- **property_count**: number of properties to be added to the object.

- **keys**: pointer to a const char array containing the keys of the properties to add.

- **values**: pointer to a **napi_value** array containing the properties to add. The keys and properties are in one-to-one mapping.

**Return value**

**napi_ok** if the operation is successful.

### napi_coerce_to_native_binding_object

```cpp
napi_status napi_coerce_to_native_binding_object(napi_env env,
                                                 napi_value js_object,
                                                 napi_native_binding_detach_callback detach_cb,
                                                 napi_native_binding_attach_callback attach_cb,
                                                 void* native_object,
                                                 void* hint);
```

**Description**

Converts a JS object into an object carrying native information by forcibly binding callbacks and callback data to the JS object.

**Parameters**

- **env**: environment, in which the API is invoked.

- **js_object**: JS object to convert.

- **detach_cb**: callback to be invoked to perform cleanup operations when the object is detached during serialization.

- **attach_cb**: callback to be invoked when the object is attached during serialization.

- **native_object**: parameters to be passed to the callbacks. This object cannot be empty.

- **hint**: pointer to the additional information to be passed to the callbacks.

**Return value**

**napi_ok** if the operation is successful.

### napi_create_ark_runtime

```cpp
napi_status napi_create_ark_runtime(napi_env *env)
```

**Description**

Creates an ArkTS runtime environment. A process allows up to 64 instances, and the total number of subthreads, including those created by [Worker](../../arkts-utils/worker-introduction.md), cannot exceed 80.

**Parameters**

- **env**: environment, in which the API is invoked.

**Return value**

**napi_ok** if the operation is successful.

### napi_destroy_ark_runtime

```cpp
napi_status napi_destroy_ark_runtime(napi_env *env)
```

**Description**

Destroys an ArkTS runtime environment.

**Parameters**

- **env**: environment, in which the API is invoked.

**Return value**

**napi_ok** if the operation is successful.

### napi_run_event_loop

```cpp
napi_status napi_run_event_loop(napi_env env, napi_event_mode mode)
```

**Description**

Runs the underlying event loop.

**Parameters**

- **env**: environment, in which the API is invoked.
- **mode**: event mode for running the event loop.

**Return value**

**napi_ok** if the operation is successful.

### napi_stop_event_loop

```cpp
napi_status napi_stop_event_loop(napi_env env)
```

**Description**

Stops the underlying event loop.

**Parameters**

- **env**: environment, in which the API is invoked.

**Return value**

**napi_ok** if the operation is successful.

### napi_load_module_with_info

```cpp
napi_status napi_load_module_with_info(napi_env env,
                                       const char* path,
                                       const char* module_info,
                                       napi_value* result)
```

**Description**

Loads an .abc file as a module. This API returns the namespace of the module. It can be used in a newly created ArkTS runtime environment.

**Parameters**

- **env**: environment, in which the API is invoked.

- **path**: path of the module to load.

- **module_info**: module information. The value is a string containing module information. The module information contains detailed module information, such as the version, author, and related description.

- **result**: pointer to **napi_value**, which holds the module loading result.

**Return value**

**napi_ok** if the operation is successful.

### napi_serialize

```cpp
napi_status napi_serialize(napi_env env,
                           napi_value object,
                           napi_value transfer_list,
                           napi_value clone_list,
                           void** result)
```

**Description**

Converts an ArkTS object into native data.

**Parameters**

- **env**: environment, in which the API is invoked.

- **object**: JS object to be serialized.

- **transfer_list**: list of JS objects to be passed during serialization.

- **clone_list**: list of JS objects to be cloned during serialization.

- **result**: pointer to the serialization result. After the call is complete, the pointer to the native data converted is stored in this position.

**Return value**

**napi_ok** if the operation is successful.

### napi_deserialize

```cpp
napi_status napi_deserialize(napi_env env, void* buffer, napi_value* object)
```

**Description**

Converts native data into an ArkTS object.

**Parameters**

- **env**: environment, in which the API is invoked.

- **buffer**: pointer to the binary data, which needs to be deserialized into a JS object.

- **object**: pointer to the deserialized JS object.

**Return value**

**napi_ok** if the operation is successful.

### napi_delete_serialization_data

```cpp
napi_status napi_delete_serialization_data(napi_env env, void* buffer)
```

**Description**

Deletes serialized data.

**Parameters**

- **env**: environment, in which the API is invoked.

- **buffer**: pointer to the buffer that contains the serialized data to delete. If the serialized data is not longer required, you can use this API to delete the data and release the memory occupied.

**Return value**

**napi_ok** if the operation is successful.

### napi_call_threadsafe_function_with_priority

```cpp
napi_status napi_call_threadsafe_function_with_priority(napi_threadsafe_function func,
                                                        void *data,
                                                        napi_task_priority priority,
                                                        bool isTail)
```

**Description**

Calls a task with the specified priority and enqueuing mode into the ArkTS main thread.

**Parameters**

- **func**: thread-safe function object, which is returned when a thread-safe function is created.

- **data**: pointer to the data to be passed to the JS callback function.

- **priority**: priority of the task that calls the JS callback function.

- **isTail**: whether the task is added to the tail of the task queue. If the value is **true**, the task will be added to the tail of the event loop. If it is **false**, the task will be executed immediately.

**Return value**

**napi_ok** if the operation is successful.

### napi_is_sendable

```cpp
napi_status napi_is_sendable(napi_env env, napi_value value, bool* result)
```

**Description**

Checks whether the given JS value is sendable.

**Parameters**

- **env**: environment, in which the API is invoked.

- **value**: JS value to check.

- **result**: pointer of the bool type, indicating whether the JS value is sendable.

**Return value**

**napi_ok** if the operation is successful.


### napi_define_sendable_class

```cpp
napi_status napi_define_sendable_class(napi_env env,
                                       const char* utf8name,
                                       size_t length,
                                       napi_callback constructor,
                                       void* data,
                                       size_t property_count,
                                       const napi_property_descriptor* properties,
                                       napi_value parent,
                                       napi_value* result)


```

**Description**

Creates a sendable class.

**Parameters**

- **env**: environment, in which the API is invoked.

- **utf8name**: pointer to the name of the class to create. This parameter is of the const char* type.

- **length**: length of the class name, in bytes. This parameter is of the size_t type.

- **constructor**: constructor of the class. This parameter is of the napi_callback type.

- **data**: (optional) pointer to the additional data of the constructor. This parameter is of the void* type.

- **property_count**: number of properties of the class. This parameter is of the size_t type.

- **properties**: (optional) pointer to the descriptors of the properties. This parameter of the const napi_property_descriptor* type.

- **parent**: (optional) parent class of the class to create. This parameter is of the napi_value type.

- **result**: pointer to the sendable class created. This parameter is of the napi_value type.

**Return value**

**napi_ok** if the operation is successful.

### napi_create_sendable_object_with_properties

```cpp
napi_status napi_create_sendable_object_with_properties(napi_env env,
                                                        size_t property_count,
                                                        const napi_property_descriptor* properties,
                                                        napi_value* result)
```

**Description**

Creates a sendable object with the given **napi_property_descriptor**.

**Parameters**

- **env**: environment, in which the API is invoked.

- **property_count**: number of properties of the class. This parameter is of the size_t type.

- **properties**: pointer to the properties of the sendable object to create.

- **result**: pointer to the sendable class created. This parameter is of the napi_value type.

**Return value**

**napi_ok** if the operation is successful.

### napi_create_sendable_array

```cpp
napi_status napi_create_sendable_array(napi_env env, napi_value* result)
```

**Description**

Creates a sendable array.

**Parameters**

- **env**: environment, in which the API is invoked.

- **result**: pointer to the sendable array created. This parameter is of the napi_value type.

**Return value**

**napi_ok** if the operation is successful.

### napi_create_sendable_array_with_length

```cpp
napi_status napi_create_sendable_array_with_length(napi_env env, size_t length, napi_value* result)
```

**Description**

Creates a sendable array of the specified length.

**Parameters**

- **env**: environment, in which the API is invoked.

- **length**: length of the sendable array to create.

- **result**: pointer to the sendable array created. This parameter is of the napi_value type.

**Return value**

**napi_ok** if the operation is successful.

### napi_create_sendable_arraybuffer

```cpp
napi_status napi_create_sendable_arraybuffer(napi_env env, size_t byte_length, void** data, napi_value* result)
```

**Description**

Creates a sendable **ArrayBuffer**.

**Parameters**

- **env**: environment, in which the API is invoked.

- **byte_length**: length of the ArrayBuffer to create.

- **data**: pointer to the byte buffer for storing the ArrayBuffer created.

- **result**: pointer to the ArrayBuffer created. This parameter is of the napi_value type.

**Return value**

**napi_ok** if the operation is successful.

### napi_create_sendable_typedarray

```cpp
napi_status napi_create_sendable_typedarray(napi_env env,
                                            napi_typedarray_type type,
                                            size_t length,
                                            napi_value arraybuffer,
                                            size_t byte_offset,
                                            napi_value* result);
```

**Description**

Creates a sendable **TypedArray**.

**Parameters**

- **env**: environment, in which the API is invoked.

- **type**: type of the TypedArray to create.

- **length**: length of the TypedArray to create.

- **arraybuffer**: ArrayBuffer instance to create.

- **byte_offset**: offset of the ArrayBuffer.

- **result**: pointer to the TypedArray created. This parameter is of the napi_value type.

**Return value**

**napi_ok** if the operation is successful.

### napi_wrap_sendable

```cpp
napi_status napi_wrap_sendable(napi_env env,
                               napi_value js_object,
                               void* native_object,
                               napi_finalize finalize_cb,
                               void* finalize_hint);
```

**Description**

Wraps a native instance into an ArkTS object.

**Parameters**

- **env**: environment, in which the API is invoked.

- **js_object**: ArkTS object.

- **native_object**: pointer to the native instance to be wrapped in the ArkTS object.

- **napi_finalize**: (optional) callback to be invoked when the ArkTS object is destroyed.

- **finalize_hint**: (optional) pointer to the callback context, which will be passed to the callback.

**Return value**

**napi_ok** if the operation is successful.

### napi_wrap_sendable_with_size

```cpp
napi_status napi_wrap_sendable_with_size(napi_env env,
                                         napi_value js_object,
                                         void* native_object,
                                         napi_finalize finalize_cb,
                                         void* finalize_hint,
                                         size_t native_binding_size);
```

**Description**

Wraps a native instance into an ArkTS object with the specified size.

**Parameters**

- **env**: environment, in which the API is invoked.

- **js_object**: ArkTS object.

- **native_object**: pointer to the native instance to be wrapped in the ArkTS object.

- **napi_finalize**: (optional) callback to be invoked when the ArkTS object is destroyed.

- **finalize_hint**: (optional) pointer to the callback context, which will be passed to the callback.

- **native_binding_size**: (optional) size of the native instance wrapped.

**Return value**

**napi_ok** if the operation is successful.

### napi_unwrap_sendable

```cpp
napi_status napi_unwrap_sendable(napi_env env, napi_value js_object, void** result)
```

**Description**

Unwraps the native instance from an ArkTS object.

**Parameters**

- **env**: environment, in which the API is invoked.

- **js_object**: ArkTS object.

- **result**: double pointer to the native instance unwrapped.

**Return value**

**napi_ok** if the operation is successful.

### napi_remove_wrap_sendable

```cpp
napi_status napi_remove_wrap_sendable(napi_env env, napi_value js_object, void** result)
```

**Description**

Removes the native instance from an ArkTS object.

**Parameters**

- **env**: environment, in which the API is invoked.

- **js_object**: ArkTS object.

- **result**: double pointer to the native instance unwrapped.

**Return value**

**napi_ok** if the operation is successful.

### napi_wrap_enhance

```cpp
napi_status napi_wrap_enhance(napi_env env,
                              napi_value js_object,
                              void* native_object,
                              napi_finalize finalize_cb,
                              bool async_finalizer,
                              void* finalize_hint,
                              size_t native_binding_size,
                              napi_ref* result);
```

**Description**

Wraps a Node-API instance into an ArkTS object and specifies the instance size. You can specify whether to execute the registered callback asynchronously (if asynchronous, it must be thread-safe).

**Parameters**

- **env**: environment, in which the API is invoked.

- **js_object**: ArkTS object.

- **native_object**: pointer to the native instance to be wrapped in the ArkTS object.

- **finalize_cb**: (optional) callback to be called when the ArkTS object is destroyed. For details, see [napi_finalize](#napi_finalize callback function description).

- **async_finalizer**: a Boolean value used to indicate whether to execute the **finalize_cb** callback asynchronously. The value **true** means to execute the callback asynchronously. In this case, thread safety must be ensured. The value **false** means to execute the callback synchronously.

- **finalize_hint**: (optional) pointer to the callback context, which will be passed to the callback.

- **native_binding_size**: (optional) size of the native instance wrapped.

- **result**: (optional) pointer to the ArkTS object reference.

**Return value**

- **napi_ok**: The operation is successful.

- **napi_invalid_arg**: The **env**, **js_object**, or **native_object** parameter is null.

- **napi_object_expected**: The **js_object** parameter is not an ArkTs object or function.

- **napi_pending_exception**: An uncaught exception or an exception occurs during the execution.

#### **napi_finalize** description

```cpp
typedef void (*napi_finalize)(napi_env env,
                              void* finalize_data,
                              void* finalize_hint);
```

**Description**

Called when the lifecycle of a Node-API object ends.

**Parameters**

- **env**: environment, in which the API is invoked.

- **finalize_data**: pointer to the user data to be cleared.

- **finalize_hint**: context hint, which is used to assist the clear process.

**Return value**

- **void**: no return value.

<!--no_check-->
