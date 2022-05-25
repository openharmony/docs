# Node_API



## Introduction



Node-API is an API used to encapsulate JavaScript capabilities as native plug-ins. It is independent of the underlying JavaScript and is maintained as part of Node.js.

## Supported Capabilities



Node-API eliminates the differences between underlying JavaScript engines and provides a set of stable interfaces.

The NAPI component re-implements the Node-API and connects to underlying engines such as ArkJs. Currently, some interfaces in the Node-API standard library are supported.

**List of Extended Symbols of NAPI**

|Type|Symbol|Description|
| --- | --- | --- |
|FUNC|napi_run_script_path|Runs a JavaScript file.|

**List of Symbols Exported from the Standard Library**

|Type|Symbol|Description|
| --- | --- | --- |
|FUNC|napi_module_register|
|FUNC|napi_get_last_error_info|
|FUNC|napi_throw|
|FUNC|napi_throw_error|
|FUNC|napi_throw_type_error|
|FUNC|napi_throw_range_error|
|FUNC|napi_is_error|
|FUNC|napi_create_error|
|FUNC|napi_create_type_error|
|FUNC|napi_create_range_error|
|FUNC|napi_get_and_clear_last_exception|
|FUNC|napi_is_exception_pending|
|FUNC|napi_fatal_error|
|FUNC|napi_open_handle_scope|
|FUNC|napi_close_handle_scope|
|FUNC|napi_open_escapable_handle_scope|
|FUNC|napi_close_escapable_handle_scope|
|FUNC|napi_escape_handle|
|FUNC|napi_create_reference|
|FUNC|napi_delete_reference|
|FUNC|napi_reference_ref|
|FUNC|napi_reference_unref|
|FUNC|napi_get_reference_value|
|FUNC|napi_create_array|
|FUNC|napi_create_array_with_length|
|FUNC|napi_create_arraybuffer|
|FUNC|napi_create_external|
|FUNC|napi_create_external_arraybuffer|
|FUNC|napi_create_object|
|FUNC|napi_create_symbol|
|FUNC|napi_create_typedarray|
|FUNC|napi_create_dataview|
|FUNC|napi_create_int32|
|FUNC|napi_create_uint32|
|FUNC|napi_create_int64|
|FUNC|napi_create_double|
|FUNC|napi_create_string_latin1|
|FUNC|napi_create_string_utf8|
|FUNC|napi_get_array_length|
|FUNC|napi_get_arraybuffer_info|
|FUNC|napi_get_prototype|
|FUNC|napi_get_typedarray_info|
|FUNC|napi_get_dataview_info|
|FUNC|napi_get_value_bool|
|FUNC|napi_get_value_double|
|FUNC|napi_get_value_external|
|FUNC|napi_get_value_int32|
|FUNC|napi_get_value_int64|
|FUNC|napi_get_value_string_latin1|
|FUNC|napi_get_value_string_utf8|
|FUNC|napi_get_value_uint32|
|FUNC|napi_get_boolean|
|FUNC|napi_get_global|
|FUNC|napi_get_null|
|FUNC|napi_get_undefined|
|FUNC|napi_coerce_to_bool|
|FUNC|napi_coerce_to_number|
|FUNC|napi_coerce_to_object|
|FUNC|napi_coerce_to_string|
|FUNC|napi_typeof|
|FUNC|napi_instanceof|
|FUNC|napi_is_array|
|FUNC|napi_is_arraybuffer|
|FUNC|napi_is_typedarray|
|FUNC|napi_is_dataview|
|FUNC|napi_is_date|
|FUNC|napi_strict_equals|
|FUNC|napi_get_property_names|
|FUNC|napi_set_property|
|FUNC|napi_get_property|
|FUNC|napi_has_property|
|FUNC|napi_delete_property|
|FUNC|napi_has_own_property|
|FUNC|napi_set_named_property|
|FUNC|napi_get_named_property|
|FUNC|napi_has_named_property|
|FUNC|napi_set_element|
|FUNC|napi_get_element|
|FUNC|napi_has_element|
|FUNC|napi_delete_element|
|FUNC|napi_define_properties|
|FUNC|napi_call_function|
|FUNC|napi_create_function|
|FUNC|napi_get_cb_info|
|FUNC|napi_get_new_target|
|FUNC|napi_new_instance|
|FUNC|napi_define_class|
|FUNC|napi_wrap|
|FUNC|napi_unwrap|
|FUNC|napi_remove_wrap|
|FUNC|napi_create_async_work|
|FUNC|napi_delete_async_work|
|FUNC|napi_queue_async_work|
|FUNC|napi_cancel_async_work|
|FUNC|napi_get_node_version|
|FUNC|napi_get_version|
|FUNC|napi_create_promise|
|FUNC|napi_resolve_deferred|
|FUNC|napi_reject_deferred|
|FUNC|napi_is_promise|
|FUNC|napi_run_script|
|FUNC|napi_get_uv_event_loop|
