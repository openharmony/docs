# Node-API

<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--Designer: @shilei123-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->
<!-- md-trans-meta sourceCommit=05e80b422c197d16c763041b53c92c6e9f303841 translatedAt=2026-08-18T15:26:16.884Z pushedAt=2026-08-19T02:34:43.132Z -->

## Introduction

Node-API provides APIs to encapsulate JavaScript (JS) capabilities as native addons. It is independent of the underlying JS and is maintained as part of Node.js.

## Including Node-API Capabilities

To use Node-API, include the following header file:

```cpp
#include <napi/native_api.h>
```

Add the following dynamic link library to **CMakeLists.txt**:

```
libace_napi.z.so
```

## Supported Capabilities

Node-API eliminates the differences between underlying JavaScript engines and provides a set of stable APIs.

The Node-API component of OpenHarmony reimplements the Node-API interfaces and connects to engines such as ArkJS at the underlying layer. Currently, it supports some interfaces in the Node-API standard library and provides extended capabilities. For details, see [Node-API Component Extension APIs](#node-api-component-extension-apis).

## Symbols Exported from the Node-API Library

The usage and behavior of the APIs exported from the Node-API native library are based on [Node.js](https://nodejs.org/docs/latest-v18.x/api/n-api.html). Some APIs differ. For details, see [Differences Between the Exported Symbols and the Symbols in the Native Library](#differences-between-the-exported-symbols-and-the-symbols-in-the-native-library).

> **NOTE**
> When using NAPI APIs, ensure that the environment, objects, and values are valid and comply with the specifications. Invalid use or use across lifecycles may cause failures, crashes, or undefined behavior. For common issues during development, see [Node-API FAQ](../../napi/use-napi-faqs.md#node-api-faqs).

|Symbol Type|Symbol|Description|Start API Version|
| --- | --- | --- | --- |
|FUNC|napi_module_register|Registers a native module.|10|
|FUNC|napi_get_last_error_info|Obtains the napi_extended_error_info struct, which contains the latest error information.|10|
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
|FUNC|napi_create_typedarray|Creates a js `TypedArray` from an existing `ArrayBuffer`.|10|
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
|FUNC|napi_get_global|Obtains the global object.|10|
|FUNC|napi_get_null|Obtains the null object.|10|
|FUNC|napi_get_undefined|Obtains the undefined object.|10|
|FUNC|napi_coerce_to_bool|Forcibly converts a JS value to a JS Boolean value.|10|
|FUNC|napi_coerce_to_number|Forcibly converts a JS value to a JS number.|10|
|FUNC|napi_coerce_to_object|Forcibly converts a JS value to a JS object.|10|
|FUNC|napi_coerce_to_string|Forcibly converts a JS value to a JS string.|10|
|FUNC|napi_typeof|Obtains the JS type of a JS value.|10|
|FUNC|napi_instanceof|Checks whether an object is an instance of the specified constructor.|10|
|FUNC|napi_is_array|Checks whether a JS value is an array.|10|
|FUNC|napi_is_arraybuffer|Checks whether a JS value is an ArrayBuffer.|10|
|FUNC|napi_is_typedarray|Checks whether a JS value is a TypedArray.|10|
|FUNC|napi_is_dataview|Checks whether a JS value is a DataView.|10|
|FUNC|napi_is_date|Checks whether a JS value is a JS Date object.|10|
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
|FUNC|napi_create_date|Creates a JS Date object from C double data.|10|
|FUNC|napi_get_date_value|Obtains the C double equivalent of the given JS Date.|10|
|FUNC|napi_create_bigint_int64|Creates a JS BigInt from C int64 data.|10|
|FUNC|napi_create_bigint_uint64|Creates a JS BigInt from C uint64 data.|10|
|FUNC|napi_create_bigint_words|Creates a single JS BigInt from a C uint64 array.|10|
|FUNC|napi_get_value_bigint_int64|Obtains the C int64 equivalent of the given JS BigInt.|10|
|FUNC|napi_get_value_bigint_uint64|Obtains the C uint64 equivalent of the given JS BigInt.|10|
|FUNC|napi_get_value_bigint_words|Obtains information from the given JS BigInt, including the sign bit, 64-bit little-endian array, and number of elements in the array.|10|
|FUNC|napi_create_buffer|Creates a JS Buffer instance of the specified size.|10|
|FUNC|napi_create_buffer_copy|Creates a JS Buffer instance of the specified size, and initializes it with data copied from the passed-in buffer.|10|
|FUNC|napi_create_external_buffer|Creates a JS Buffer instance of the specified size, and initializes it with the given data. The Buffer instance created can include extra.|10|
|FUNC|napi_get_buffer_info|Obtains the underlying data of Buffer and its length.|10|
|FUNC|napi_is_buffer|Checks whether the given JS value is a Buffer object.|10|
|FUNC|napi_object_freeze|Freezes the given object.|10|
|FUNC|napi_object_seal|Seals the given object.|10|
|FUNC|napi_get_all_property_names|Obtains an array containing the names of all the available properties of this object.|10|
|FUNC|napi_detach_arraybuffer|Detaches the underlying data of the given ArrayBuffer.|10|
|FUNC|napi_is_detached_arraybuffer|Checks whether the given ArrayBuffer has been detached.|10|
|FUNC|napi_run_script|Runs a given object as JS code. This API is currently an empty implementation. You can use the system extension API `napi_run_script_path` to improve security.|10|
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

- **code**: In OpenHarmony, the value type can be string or number. However, in the standard library interface, the value type can only be string.

**Return value**

- If the **code** type is incorrect, the OpenHarmony interface returns napi_invalid_arg, whereas the standard library interface returns napi_string_expected.

- The OpenHarmony export interface allows the **code** property to fail without error, whereas the standard library interface evaluates the setting. If the setting fails, it returns **napi_generic_failure**.

- The error type created in OpenHarmony is Error, whereas that created in the standard library is TypeError.

### napi_create_range_error

**Parameters**

- **code**: In OpenHarmony, the value type can be string or number. However, in the standard library interface, the value type can only be string.

**Return value**

- If the **code** type is incorrect, the OpenHarmony interface returns napi_invalid_arg, whereas the standard library interface returns napi_string_expected.

- The OpenHarmony export interface allows the **code** property to fail without error, whereas the standard library interface evaluates the setting. If the setting fails, it returns **napi_generic_failure**.

- The error type created in OpenHarmony is Error, whereas that created in the standard library is RangeError.

### napi_create_reference

**Parameters**

- **value**: The OpenHarmony API does not restrict the value type. The standard library supports only object, function, and symbol types.

### napi_delete_reference

**NOTE**

- In OpenHarmony, if the **napi_finalize** callback is registered when a strong reference is created, calling this API will trigger the **napi_finalize** callback.

### napi_create_symbol

**Return value**

- The exported symbol returns **napi_invalid_arg** if **description** is not empty and is not a string.

### napi_create_typedarray

**Return value**

- The exported symbol returns **napi_arraybuffer_expected** if **arraybuffer** is not empty and is not an ArrayBuffer object.

### napi_create_dataview

**Return value**

- The exported symbol returns **napi_arraybuffer_expected** if **arraybuffer** is not empty and is not an ArrayBuffer object.

- If the sum of **byte_offset** and **byte_length** is greater than the size of **arraybuffer**, the export API throws a **RangeError** exception and returns **napi_pending_exception**.

### napi_get_typedarray_info

**Parameters**

- **object**: The exported symbol supports TypedArray or Sendable TypedArray ([Int8Array](../apis-arkts/arkts-apis-arkts-collections-Int8Array.md), [Uint8Array](../apis-arkts/arkts-apis-arkts-collections-Uint8Array.md), [Int16Array](../apis-arkts/arkts-apis-arkts-collections-Int16Array.md), [Uint16Array](../apis-arkts/arkts-apis-arkts-collections-Uint16Array.md), [Int32Array](../apis-arkts/arkts-apis-arkts-collections-Int32Array.md), [Uint32Array](../apis-arkts/arkts-apis-arkts-collections-Uint32Array.md), [Uint8ClampedArray](../apis-arkts/arkts-apis-arkts-collections-Uint8ClampedArray.md), and [Float32Array](../apis-arkts/arkts-apis-arkts-collections-Float32Array.md)).

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

- **value**: The exported symbol also supports Sendable TypedArray ([Int8Array](../apis-arkts/arkts-apis-arkts-collections-Int8Array.md), [Uint8Array](../apis-arkts/arkts-apis-arkts-collections-Uint8Array.md), [Int16Array](../apis-arkts/arkts-apis-arkts-collections-Int16Array.md), [Uint16Array](../apis-arkts/arkts-apis-arkts-collections-Uint16Array.md), [Int32Array](../apis-arkts/arkts-apis-arkts-collections-Int32Array.md), [Uint32Array](../apis-arkts/arkts-apis-arkts-collections-Uint32Array.md), [Uint8ClampedArray](../apis-arkts/arkts-apis-arkts-collections-Uint8ClampedArray.md) and [Float32Array](../apis-arkts/arkts-apis-arkts-collections-Float32Array.md)).

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

- The exported interface does not verify the type of the **async_resource_name** parameter. It is recommended that you pass in a String object to describe the asynchronous work object. A parameter of the string type is displayed in the trace information, while null or undefined is not displayed. Other types will cause a crash.

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

- If **arraybuffer** is not an object, the exported symbol returns **napi_object_expected**. If **arraybuffer** is an object but not an ArrayBuffer object, it returns **napi_invalid_arg**.

### napi_add_env_cleanup_hook

**NOTE**

- If data is registered with **env**, OpenHarmony prints only error logs.

### napi_add_finalizer

**Return value**

- If **js_object** is not an object, the exported symbol returns **napi_object_expected**.

**NOTE**

- When a strong reference is deleted, OpenHarmony immediately triggers a callback, whereas the standard library does so during object destruction.

- If a callback throws an exception, OpenHarmony will cause a JSCrash, but the standard library will not trigger a crash.

- OpenHarmony creates a strong reference when the result is non-empty, whereas the standard library opts for a weak reference in such cases.

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

## Node-API Component Extension APIs

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

**Since:** 10

### napi_event_mode

```cpp
typedef enum {
    napi_event_mode_default = 0, // Run the underlying event loop while blocking the current thread, and exit the event loop only when there is no task in the loop.
    napi_event_mode_nowait = 1, // Run the underlying event loop without blocking the current thread. Process a task and exit the event loop after the task is complete. If there is no task in the event loop, exit the event loop immediately.
} napi_event_mode;
```

**Description**
Enumerates the modes for running the underlying event loop.

**Since**: 12

### napi_queue_async_work_with_qos

```cpp
napi_status napi_queue_async_work_with_qos(napi_env env,
                                           napi_async_work work,
                                           napi_qos_t qos);
```

**Description**

Adds an async work object to the queue so that it can be scheduled for execution based on the QoS priority passed in.

**Since:** 10

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

**Since:** 10

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

**Since**: 11

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

**Since**: 11

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

**Since**: 11

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

**Since**: 11

**Parameters**

- **env**: environment, in which the API is invoked.

- **js_object**: JS object to convert.

- **detach_cb**: callback to be invoked to perform cleanup operations when the object is detached during serialization.

- [in] attach_cb: callback for binding, generally invoked during deserialization.

- **native_object**: parameters to be passed to the callbacks. This object cannot be empty.

- **hint**: pointer to the additional information to be passed to the callbacks.

**Return value**

**napi_ok** if the operation is successful.

### napi_create_ark_runtime

```cpp
napi_status napi_create_ark_runtime(napi_env *env)
```

**Description**

Creates a runtime environment. A process allows up to 64 instances, and the total number of child threads, including those created by [Worker](../../arkts-utils/worker-introduction.md), cannot exceed 80.

**Since**: 12

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

**Since**: 12

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

**Since**: 12

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

**Since**: 12

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

**Since**: 12

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

**Since**: 12

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

**Since**: 12

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

**Since**: 12

**Parameters**

- **env**: environment, in which the API is invoked.

- **buffer**: pointer to the buffer that contains the serialized data to delete. If the serialized data is no longer required, you can use this API to delete the data and release the memory occupied.

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

**Since**: 12

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

**Since**: 12

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

**Since**: 12

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

**Since**: 12

**Parameters**

- **env**: environment, in which the API is invoked.

- **property_count**: number of properties of the class. This parameter is of the size_t type.

- **properties**: pointer to the descriptors of the properties. This parameter of the const napi_property_descriptor* type.

- **result**: pointer to the sendable class created. This parameter is of the napi_value type.

**Return value**

**napi_ok** if the operation is successful.

### napi_create_sendable_array

```cpp
napi_status napi_create_sendable_array(napi_env env, napi_value* result)
```

**Description**

Creates a sendable array.

**Since**: 12

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

**Since**: 12

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

**Since**: 12

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

**Since**: 12

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

**Since**: 12

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

**Since**: 12

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

**Since**: 12

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

Removes and obtains the native instance wrapped by an ArkTS object. After removal, the callback is automatically triggered later. Avoid duplicate release.

**Since**: 12

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

Wraps a native instance of the specified size into an ArkTS object. During runtime, the instance size is counted and accumulated. When the accumulated size reaches the GC triggering threshold, the garbage collection process is started. You can specify whether to execute the registered callback asynchronously (if asynchronous, it must be thread-safe).

**Since**: 18

**Parameters**

- **env**: environment, in which the API is invoked.

- **js_object**: ArkTS object.

- **native_object**: pointer to the native instance to be wrapped in the ArkTS object.

- **finalize_cb**: (optional) callback to be called when the ArkTS object is destroyed. For details, see [napi_finalize](#napi_finalize).

- **async_finalizer**: a Boolean value used to indicate whether to execute the **finalize_cb** callback asynchronously. The value **true** means to execute the callback asynchronously. In this case, thread safety must be ensured. The value **false** means to execute the callback synchronously.

- **finalize_hint**: (optional) pointer to the callback context, which will be passed to the callback.

- **native_binding_size**: (optional) size of the bound native instance. During runtime, the size is counted and accumulated. When the accumulated size reaches the GC triggering threshold, the garbage collection process is started.

- **result**: (optional) pointer to the ArkTS object reference.

**Return value**

- **napi_ok**: The operation is successful.

- **napi_invalid_arg**: The **env**, **js_object**, or **native_object** parameter is null.

- **napi_object_expected**: The **js_object** parameter is not an ArkTS object or function.

- **napi_pending_exception**: An uncaught exception or an exception occurs during the execution.

### napi_create_ark_context

```cpp
napi_status napi_create_ark_context(napi_env env, napi_env* newEnv);
```

**Description**

Creates a new runtime context environment.
Note the following when using this API:

1. Only new context environments created through the initial context environment are supported. It is prohibited to create new context environments using the context environment created by this API.

2. Currently, this API cannot be called on ArkTS threads that are not the main thread.

3. Before calling this API, ensure that the current context environment is normal. Otherwise, the API call fails.

4. The context environment created by this API can only load some native.so files of ArkUI. Loading application-specific native .so files and common basic library native so files is not supported.

5. The multi-context runtime environment does not support the sendable feature.

6. The runtime context environment created through **napi_create_ark_context** does not support module capabilities such as console and timer.

**Since**: 20

**Parameters**

- **env**: environment, in which the API is invoked.

- newEnv: pointer to the new runtime context environment.

**Return value**

**napi_ok** if the operation is successful.

### napi_switch_ark_context

```cpp
napi_status napi_switch_ark_context(napi_env env)
```

**Description**

Switches to the specified runtime context environment. Note the following when using this API:

1. Currently, this API cannot be called on ArkTS threads that are not the main thread.

2. Before calling this API, ensure that the current context environment is normal. Otherwise, the API call fails.

**Since**: 20

**Parameters**

- env: specified runtime context environment.

**Return value**

**napi_ok** if the operation is successful.

### napi_destroy_ark_context

```cpp
napi_status napi_destroy_ark_context(napi_env env)
```

**Description**

Destroys a context environment created by **napi_create_ark_context**. Note the following when using this API:

1. Currently, this API cannot be called on ArkTS threads that are not the main thread.

2. This API can only be used to destroy runtime context environments created by calling **napi_create_ark_context**.

3. You cannot use this API to destroy a context environment that is currently in use.

**Since**: 20

**Parameters**

- env: runtime context to be destroyed.

**Return value**

**napi_ok** if the operation is successful.

### napi_open_critical_scope

```cpp
napi_status napi_open_critical_scope(napi_env env, napi_critical_scope* scope);
```

**Description**

Opens a critical scope. Note the following when using this API:

1. A critical scope cannot be opened repeatedly. It can be opened again only after the current scope is closed.

2. In the critical scope, non-critical APIs cannot be called.

**Since**: 21

**Parameters**

- **env**: environment, in which the API is invoked.

- **scope**: pointer to a **napi_critical_scope**, indicating the opened critical scope.

**Return value**

**napi_ok** if the operation is successful.

### napi_close_critical_scope

```cpp
napi_status napi_close_critical_scope(napi_env env, napi_critical_scope scope);
```

**Description**

Closes a critical scope. Note the following when using this API:

1. A critical scope cannot be closed repeatedly. Ensure that the scope has been opened and is not closed.

2. After the critical scope is closed, do not use the critical API or its return result. Otherwise, the program may crash or data may be damaged.

**Since**: 21

**Parameters**

- **env**: environment, in which the API is invoked.

- **scope**: critical scope to be closed.

**Return value**

**napi_ok** if the operation is successful.

### napi_get_buffer_string_utf16_in_critical_scope

```cpp
napi_status napi_get_buffer_string_utf16_in_critical_scope(napi_env env,
                                                           napi_value value,
                                                           const char16_t** buffer,
                                                           size_t* length);
```

**Description**

Obtains the UTF-16 encoding memory buffer data of an ArkTS string. Note the following when using this API:

1. To obtain the memory buffer of an ArkTS string stored in UTF-16-encoding format, use **napi_get_buffer_string_utf16_in_critical_scope**. Otherwise, an error will be returned.

**Since**: 21

**Parameters**

- **env**: environment, in which the API is invoked.

- **value**: ArkTS string object.

- **buffer**: pointer to the UTF-16-encoded memory buffer data.

- **length**: pointer to the length of the string.

**Return value**

**napi_ok** if the operation is successful.

### napi_create_strong_reference

```cpp
napi_status napi_create_strong_reference(napi_env env, napi_value value, napi_strong_ref* result);
```

**Description**

Creates a strong reference to an ArkTS object.

**Since**: 21

**Parameters**

- **env**: environment, in which the API is invoked.

- **value**: ArkTS object.

- **result**: pointer to the strong reference.

**Return value**

**napi_ok** if the operation is successful.

### napi_delete_strong_reference

```cpp
napi_status napi_delete_strong_reference(napi_env env, napi_value value, napi_strong_ref ref);
```

**Description**

Deletes a strong reference. Note the following when using this API:

1. A strong reference cannot be deleted repeatedly.

**Since**: 21

**Parameters**

- **env**: environment, in which the API is invoked.

- **value**: ArkTS object.

- **ref**: strong reference to be deleted.

**Return value**

**napi_ok** if the operation is successful.

### napi_get_strong_reference_value

```c
napi_status napi_get_strong_reference_value(napi_env env, napi_strong_ref ref, napi_value* result)
```

**Description**

Obtains the ArkTS object value associated with a strong reference. Note the following when using this API:

1. Do not use a deleted strong reference to obtain the ArkTS object value. Otherwise, unexpected errors may occur.

**Since**: 21

**Parameters**

- **env**: environment, in which the API is invoked.

- **ref**: strong reference.

- **result**: pointer to the ArkTS object value.

**Return value**

**napi_ok** if the operation is successful.

### **napi_finalize**

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

### **napi_finalize_callback**

```cpp
typedef void (*napi_finalize_callback)(void* finalize_data,
                                       void* finalize_hint);
```

**Description**

Called when the lifecycle of an ArkTS string object created by calling **napi_create_external_string_utf16** or **napi_create_external_string_ascii** ends.

**Since**: 22

**Parameters**

- **finalize_data**: pointer to the user data to be cleared.

- **finalize_hint**: context hint, which is used to assist the clear process.

**Return value**

- **void**: no return value.

### napi_create_external_string_utf16

```cpp
napi_status napi_create_external_string_utf16(napi_env env,
                                              const char16_t* str,
                                              size_t length,
                                              napi_finalize_callback finalize_callback,
                                              void* finalize_hint,
                                              napi_value* result);
```

**Description**

Creates an ArkTS string from an external UTF-16-encoded string. Note the following when using this API:

1. The input string must be in UTF-16 encoding format. Otherwise, the string content may be abnormal.

2. The input string must remain valid throughout the lifetime of the ArkTS string object. Otherwise, unexpected behavior may occur.

3. If the **finalize_callback callback** function is provided, it will be called when the ArkTS string object is destroyed. The **finalize_hint** parameter can be used to pass context information to the callback function.

4. If the input **length** parameter is set to **NAPI_AUTO_LENGTH**, the API automatically locates the '\0' terminator internally to calculate the actual string length.

**Since**: 22

**Parameters**

- **env**: environment, in which the API is invoked.

- **str**: pointer to the external string.

- **length**: string length.

- **finalize_callback**: (optional) callback function called when the string object is destroyed. For details, see [napi_finalize_callback](#napi_finalize_callback).

- **finalize_hint**: (optional) pointer to the callback context, which will be passed to the callback.

- **result**: pointer to the ArkTS string object.

**Return value**

**napi_ok** if the operation is successful.

### napi_create_external_string_ascii

```cpp
napi_status napi_create_external_string_ascii(napi_env env,
                                              const char* str,
                                              size_t length,
                                              napi_finalize_callback finalize_callback,
                                              void* finalize_hint,
                                              napi_value* result);
```

**Description**

Creates an ArkTS string from ASCII-encoded external string. Note the following when using this API:

1. The input string must be in ASCII encoding format. Otherwise, the string content may be abnormal.

2. The input string must remain valid throughout the lifetime of the ArkTS string object. Otherwise, unexpected behavior may occur.

3. If the **finalize_callback callback** function is provided, it will be called when the ArkTS string object is destroyed. The **finalize_hint** parameter can be used to pass context information to the callback function.

4. If the input **length** parameter is set to **NAPI_AUTO_LENGTH**, the API automatically locates the '\0' terminator internally to calculate the actual string length.

5. The input string must not contain the null character '\0' within the specified length range. Otherwise, unexpected behavior may occur.

**Since**: 22

**Parameters**

- **env**: environment, in which the API is invoked.

- **str**: pointer to the external string.

- **length**: string length.

- **finalize_callback**: (optional) callback function called when the string object is destroyed. For details, see [napi_finalize_callback](#napi_finalize_callback).

- **finalize_hint**: (optional) pointer to the callback context, which will be passed to the callback.

- **result**: pointer to the ArkTS string object.

**Return value**

**napi_ok** if the operation is successful.

### napi_create_strong_sendable_reference

```cpp
napi_status napi_create_strong_sendable_reference(napi_env env,
                                                  napi_value value,
                                                  napi_sendable_ref* result);
```

**Description**

Creates a Sendable strong reference to a Sendable ArkTS object. Note the following when using this API:

1. **napi_sendable_ref** can be created only for [Sendable objects](../../arkts-utils/arkts-sendable.md#sendable-data-types).

2. **napi_sendable_ref** can be used across ArkTS threads. When performing multithreaded operations, the caller must manage the release timing to avoid issues related to using after release.

3. Within the same process, a maximum of 51200 **napi_sendable_ref** instances can coexist.

4. The caller should ensure that the input **env** parameter is the ArkTS thread environment object of the current API. Otherwise, [multithreading safety issues](https://developer.huawei.com/consumer/en/doc/best-practices/bpta-stability-ark-runtime-detection#section19357830121120) may occur.

**Since**: 22

**Parameters**

- **env**: environment, in which the API is invoked.

- **value**: Sendable ArkTS object to be referenced.

- **result**: created Sendable strong reference.

**Return value**

**napi_ok** if the operation is successful.

### napi_delete_strong_sendable_reference

```cpp
napi_status napi_delete_strong_sendable_reference(napi_env env, napi_sendable_ref ref);
```

**Description**

Deletes a Sendable strong reference. Note the following when using this API:

1. Do not forcibly cast other reference types (such as **napi_ref** or **napi_strong_ref**) to **napi_sendable_ref** for use with this API. **napi_delete_strong_sendable_reference** accepts only **napi_sendable_ref** created by calling **napi_create_strong_sendable_reference**.

2. The caller should ensure that the input **env** parameter is the ArkTS thread environment object of the current API. Otherwise, [multithreading safety issues](https://developer.huawei.com/consumer/en/doc/best-practices/bpta-stability-ark-runtime-detection#section19357830121120) may occur.

**Since**: 22

**Parameters**

- **env**: environment, in which the API is invoked.

- **ref**: reference to be deleted.

**Return value**

**napi_ok** if the operation is successful.

### napi_get_strong_sendable_reference_value

```cpp
napi_status napi_get_strong_sendable_reference_value(napi_env env,
                                                     napi_sendable_ref ref,
                                                     napi_value* result);
```

**Description**

Obtains the ArkTS object value associated with a Sendable strong reference. Note the following when using this API:

1. Do not forcibly cast other reference types (such as **napi_ref** or **napi_strong_ref**) to **napi_sendable_ref** for use with this API. **napi_get_strong_sendable_reference_value** accepts only **napi_sendable_ref** created by calling **napi_create_strong_sendable_reference**.

2. The caller should ensure that the input **env** parameter is the ArkTS thread environment object of the current API. Otherwise, [multithreading safety issues](https://developer.huawei.com/consumer/en/doc/best-practices/bpta-stability-ark-runtime-detection#section19357830121120) may occur.

**Since**: 22

**Parameters**

- **env**: environment, in which the API is invoked.

- **ref**: Sendable strong reference.

- **result**: Sendable ArkTS object obtained from **ref**.

**Return value**

**napi_ok** if the operation is successful.

### napi_throw_business_error

```cpp
napi_status napi_throw_business_error(napi_env env,
                                      int32_t errorCode,
                                      const char* msg);
```

**Description**

Throws an ArkTS Error with text information, specifying the error code as int32_t and the error message as string. Note the following when using this API:

1. The input parameters **env** and **msg** cannot be **nullptr**. Otherwise, **napi_invalid_arg** is returned.

2. If an ArkTS error exists in the current context, **napi_pending_exception** is returned when the API is called.

**Since**: 23

**Parameters**

- **env**: environment, in which the API is invoked.

- **errorCode**: error code of the int32_t type, which is used to set the error object.

- **msg**: C string of the text that is to be associated with the error.

**Return value**

**napi_ok** if the operation is successful.

### napi_create_callsite_info

```cpp
napi_status napi_create_callsite_info(napi_env env, napi_callsite_info* result);
```

**Description**

Creates a handle to the call site information, which is used to cache property access information. An independent handle must be created for each call site. A handle can be reused across multiple calls but cannot be used across threads. When the handle is no longer needed, call **napi_delete_callsite_info** to release it.

**Since**: 24

**Parameters**

- **env**: environment, in which the API is invoked.

- **result**: pointer to **napi_callsite_info**, which is used to receive the created call site information handle.

**Return value**

**napi_ok** if the operation is successful.

### napi_delete_callsite_info

```cpp
napi_status napi_delete_callsite_info(napi_env env, napi_callsite_info info);
```

**Description**

Deletes the handle to the call site information to release the associated cache resources.

**Since**: 24

**Parameters**

- **env**: environment, in which the API is invoked.

- **info**: handle to the call site information to be deleted.

**Return value**

**napi_ok** if the operation is successful.

### napi_get_property_with_callsite_info

```cpp
napi_status napi_get_property_with_callsite_info(napi_env env,
                                                 napi_value object,
                                                 napi_value key,
                                                 napi_callsite_info info,
                                                 napi_value* result,
                                                 bool* hit);
```

**Description**

Quickly obtains the property value of an object using the call site information. The **info** parameter can be set to **NULL**. In this case, the behavior is the same as that of **napi_get_property**.

**Since**: 24

**Parameters**

- **env**: environment, in which the API is invoked.

- **object**: object whose property is to be obtained.

- **key**: key name of the property to be obtained.

- **info**: handle to the call site information. It can be **NULL**.

- **result**: pointer to napi_value, which is used to receive the property value.

- **hit**: whether the write cache is hit. The value **true** indicates that the write cache is hit (fast path), and **false** indicates the opposite. It can be **nullptr**.

**Return value**

**napi_ok** if the operation is successful.

### napi_set_property_with_callsite_info

```cpp
napi_status napi_set_property_with_callsite_info(napi_env env,
                                                 napi_value object,
                                                 napi_value key,
                                                 napi_value value,
                                                 napi_callsite_info info,
                                                 bool* hit);
```

**Description**

Quickly sets the property value of an object using the call site information. The **info** parameter can be set to **NULL**. In this case, the behavior is the same as that of **napi_set_property**.

**Since**: 24

**Parameters**

- **env**: environment, in which the API is invoked.

- **object**: object whose property is to be set.

- **key**: key name of the property to be set.

- **value**: property value to be set.

- **info**: handle to the call site information. It can be **NULL**.

- **hit**: whether the write cache is hit. The value **true** indicates that the write cache is hit (fast path), and **false** indicates the opposite. It can be **nullptr**.

**Return value**

**napi_ok** if the operation is successful.

<!--no_check-->