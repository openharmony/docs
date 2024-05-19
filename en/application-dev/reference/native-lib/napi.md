# Node-API

## Introduction

Node-API provides APIs to encapsulate JavaScript (JS) capabilities as native addons. It is independent of the underlying JS and is maintained as part of Node.js.

## Supported Capabilities

Node-API insulates addons from changes in the underlying JS engine and allows the modules compiled for one major version to run on later major versions without recompilation.

The OpenHarmony Node-API component optimizes the Node-API implementation and provides interaction with underlying engines such as ArkJS. Currently, the OpenHarmony Node-API component does not support all Node-API APIs.

## Symbols Exported from the Node-API Library

The usage and behavior of the APIs exported from the Node-API standard library are the same as those of Node.js. For details about the API declaration and parameter constraints, see [Node-API](https://nodejs.org/docs/latest-v8.x/api/n-api.html) documentation.

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
|FUNC|napi_open_escapable_handle_scope|Opens an escapable handle scope from which the declared values can be returned to the outer scope.|10|
|FUNC|napi_close_escapable_handle_scope|Closes the escapable handle scope passed in.|10|
|FUNC|napi_escape_handle|Promotes the handle to the input JS object so that it is valid for the lifespan of its outer scope.|10|
|FUNC|napi_create_reference|Creates a reference for an **Object** to extend its lifespan. The caller needs to manage the reference lifespan.|10|
|FUNC|napi_delete_reference|Deletes the reference passed in.|10|
|FUNC|napi_reference_ref|Increments the reference count for the reference passed in and returns the count.|10|
|FUNC|napi_reference_unref|Decrements the reference count for the reference passed in and returns the count.|10|
|FUNC|napi_get_reference_value|Obtains the JS **Object** associated with the reference.|10|
|FUNC|napi_create_array|Creates a JS array.|10|
|FUNC|napi_create_array_with_length|Creates a JS array of the specified length.|10|
|FUNC|napi_create_arraybuffer|Creates a JS ArrayBuffer of the specified size.|10|
|FUNC|napi_create_external|Allocates a JS value with external data.|10|
|FUNC|napi_create_external_arraybuffer|Allocates a JS **ArrayBuffer** with external data.|10|
|FUNC|napi_create_object|Creates a default JS **Object**.|10|
|FUNC|napi_create_symbol|Creates a JS **Symbol**.|10|
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
|FUNC|napi_get_arraybuffer_info|Obtains the underlying data buffer of **ArrayBuffer** and its length.|10|
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
|FUNC|napi_is_arraybuffer|Checks whether a JS value is a `ArrayBuffer`.|10|
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
|FUNC|napi_unwrap|Obtains the native instance that was previously wrapped in a JS object.|10|
|FUNC|napi_remove_wrap|Obtains the native instance that was previously wrapped in a JS object and removes the wrapping.|10|
|FUNC|napi_create_async_work|Creates a work object that executes logic asynchronously.|10|
|FUNC|napi_delete_async_work|Releases an asynchronous work object.|10|
|FUNC|napi_queue_async_work|Adds an asynchronous work object to the queue so that it can be scheduled for execution.|10|
|FUNC|napi_cancel_async_work|Cancels the queued asynchronous work if it has not been started.|10|
|FUNC|napi_async_init|Creates an asynchronous context. The capabilities related to **async_hook** are not supported currently.|11|
|FUNC|napi_make_callback|Allows a JS function to be called in the asynchronous context. The capabilities related to **async_hook** are not supported currently.|11|
|FUNC|napi_async_destroy|Destroys the previously created asynchronous context. The capabilities related to **async_hook** are not supported currently.|11|
|FUNC|napi_open_callback_scope|Opens a callback scope. The capabilities related to **async_hook** are not supported currently.|11|
|FUNC|napi_close_callback_scope|Closes the callback scope. The capabilities related to **async_hook** are not supported currently.|11|
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
|FUNC|napi_ref_threadsafe_function|Indicates that the event loop running on the main thread should not exit until the thread-safe function is destroyed.|10|
|FUNC|napi_unref_threadsafe_function|Indicates that the event loop running on the main thread may exit before the thread-safe function is destroyed.|10|
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
|FUNC|napi_detach_arraybuffer|Detaches the underlying data of the given **ArrayBuffer**.|10|
|FUNC|napi_is_detached_arraybuffer|Checks whether the given **ArrayBuffer** has been detached.|10|
|FUNC|napi_set_instance_data|Associates data with the currently running environment.|11|
|FUNC|napi_get_instance_data|Retrieves the data that was previously associated with the currently running environment.|11|
|FUNC|napi_add_env_cleanup_hook|Registers a clean-up hook for releasing resources when the environment exits.|11|
|FUNC|napi_remove_env_cleanup_hook|Unregisters the clean-up hook.|11|
|FUNC|napi_add_async_cleanup_hook|Registers an asynchronous clean-up hook for releasing resources when the environment exits.|11|
|FUNC|napi_remove_async_cleanup_hook|Unregisters the asynchronous clean-up hook.|11|
|FUNC|node_api_get_module_file_name|Obtains the absolute path of the location, from which the addon is loaded.|11|
|FUNC|napi_add_finalizer|Adds a **napi_finalize** callback, which will be called when the JS object in **js_Object** is garbage-collected.|11|

## Symbols Not Exported from the Node-API Library

|Symbol Type|Symbol|Description|
| --- | --- | --- |
|FUNC|napi_run_script|Runs an object as JS code.|
|FUNC|napi_adjust_external_memory|Adjusts the external memory held by a JS object.|
|FUNC|napi_fatal_exception|Throws **UncaughtException** to JS.|

## Node-API Extended Symbols

|Symbol Type|Symbol|Description|Start API Version|
| --- | --- | --- | --- |
|FUNC|napi_queue_async_work_with_qos|Adds asynchronously working objects to the queue and schedules them based on the QoS priority.|10|
|FUNC|napi_run_script_path|Runs an ABC file.|10|
|FUNC|napi_load_module|Loads an .abc file as a module. This API returns the namespace of the module.|11|
|FUNC|napi_create_object_with_properties|Creates a JS object using the given **napi_property_descriptor**. The key of the descriptor must be a string and cannot be converted into a number.|11|
|FUNC|napi_create_object_with_named_properties|Creates a JS object using the given **napi_value** and key. The key must be a string and cannot be converted into a number.|11|
|FUNC|napi_coerce_to_native_binding_object|Forcibly binds a JS object and a native object.|11|
