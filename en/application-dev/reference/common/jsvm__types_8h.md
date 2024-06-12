# jsvm_types.h


## Overview

Provides JSVM-API type definitions.

Provides developers with independent, standard, and complete JavaScript engine capabilities through APIs, including managing the engine lifecycle, compiling and running JavaScript code, implementing cross-language invoking of JavaScript and C++, and taking snapshots.

Library: libjsvm.so

System capability: SystemCapability.ArkCompiler.JSVM

**Since**: 11

Related module: [JSVM](_j_s_v_m.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| struct&nbsp;&nbsp;[JSVM_CallbackStruct](_j_s_v_m___callback_struct.md) | Callback function pointers and data of native functions provided by users. These functions are exposed to JavaScript through the JSVM-API interface. | 
| struct&nbsp;&nbsp;[JSVM_InitOptions](_j_s_v_m___init_options.md) | Initialization option, which is used to initialize the JavaScript virtual machine. | 
| struct&nbsp;&nbsp;[JSVM_CreateVMOptions](_j_s_v_m___create_v_m_options.md) | Options for creating a JavaScript virtual machine. | 
| struct&nbsp;&nbsp;[JSVM_VMInfo](_j_s_v_m___v_m_info.md) | JavaScript VM information. | 
| struct&nbsp;&nbsp;[JSVM_PropertyDescriptor](_j_s_v_m___property_descriptor.md) | Attribute descriptor. | 
| struct&nbsp;&nbsp;[JSVM_ExtendedErrorInfo](_j_s_v_m___extended_error_info.md) | Extended exception information. | 
| struct&nbsp;&nbsp;[JSVM_TypeTag](_j_s_v_m___type_tag.md) | Type token, stored as a 128-bit value of two unsigned 64-bit integers. As a UUID, JavaScript objects can be "tagged" through it to ensure that their types remain unchanged. | 


### Types

| Name| Description| 
| -------- | -------- |
|  typedef uint16_t **char16_t** |  | 
| typedef struct JSVM_VM__ \* [JSVM_VM](_j_s_v_m.md#jsvm_vm) | Indicates a JavaScript VM instance. | 
| typedef struct JSVM_VMScope__ \* [JSVM_VMScope](_j_s_v_m.md#jsvm_vmscope) | Indicates the scope of the JavaScript virtual machine. | 
| typedef struct JSVM_EnvScope__ \* [JSVM_EnvScope](_j_s_v_m.md#jsvm_envscope) | Represents the environment used to control the attachment to the current virtual machine instance. The environment is available to the virtual machine instance of the thread only after the thread enters the JSVM_EnvScope of the environment through OH_JSVM_OpenEnvScope. | 
| typedef struct JSVM_Script__ \* [JSVM_Script](_j_s_v_m.md#jsvm_script) | Indicates a piece of JavaScript code. | 
| typedef struct JSVM_Env__ \* [JSVM_Env](_j_s_v_m.md#jsvm_env) | Indicates the context environment of a specific VM state. It needs to be transferred as a parameter when the native function is called and transferred to any subsequent JSVM-API nested invoking. | 
| typedef struct JSVM_Value__ \* [JSVM_Value](_j_s_v_m.md#jsvm_value) | Indicates the JavaScript value. | 
| typedef struct JSVM_Ref__ \* [JSVM_Ref](_j_s_v_m.md#jsvm_ref) | Represents a reference to a JavaScript value. | 
| typedef struct JSVM_HandleScope__ \* [JSVM_HandleScope](_j_s_v_m.md#jsvm_handlescope) | Indicates the scope of a JavaScript value. It is used to control and modify the lifecycle of an object created in a specific scope. Typically, JSVM-API values are created in the context of JSVM_HandleScope. When the native method is called from JavaScript, the default JSVM_HandleScope exists. If the user does not explicitly create a new JSVM_HandleScope, the JSVM-API value is created in the default JSVM_HandleScope. For any code call other than native method execution (for example, during libuv callback calls), the module needs to create a scope before calling any function that may cause JavaScript value creation. JSVM_HandleScope is created using OH_JSVM_OpenHandleScope and destroyed using OH_JSVM_CloseHandleScope. Closing the scope represents indicating to the GC that all JSVM_Values created during the lifecycle of the JSVM_HandleScope scope will no longer be referenced from the stack frame of the current heap. | 
| typedef struct JSVM_EscapableHandleScope__ \* [JSVM_EscapableHandleScope](_j_s_v_m.md#jsvm_escapablehandlescope) | Indicates a special type of handle scope, which is used to return the value created in a specific handle scope to the parent scope. | 
| typedef struct JSVM_CallbackInfo__ \* [JSVM_CallbackInfo](_j_s_v_m.md#jsvm_callbackinfo) | Represents the opaque data type passed to the callback function. It can be used to obtain additional information about the context in which the function is called. | 
| typedef struct JSVM_Deferred__ \* [JSVM_Deferred](_j_s_v_m.md#jsvm_deferred) | Promise delay object. | 
| typedef [JSVM_CallbackStruct](_j_s_v_m___callback_struct.md) \* [JSVM_Callback](_j_s_v_m.md#jsvm_callback) | Function pointer type of native functions provided by users. These functions are exposed to JavaScript through the JSVM-API interface. | 
| typedef void(JSVM_CDECL \* [JSVM_Finalize](_j_s_v_m.md#jsvm_finalize)) ([JSVM_Env](_j_s_v_m.md#jsvm_env) env, void \*finalizeData, void \*finalizeHint) | Function pointer type. When a native object or data is associated with a JS object, this pointer is transferred. This function is called when the associated JS object is reclaimed by the GC to execute the native cleanup action. | 


### Enums

| Name| Description| 
| -------- | -------- |
| [JSVM_PropertyAttributes](_j_s_v_m.md#jsvm_propertyattributes) {<br>[JSVM_DEFAULT](_j_s_v_m.md) = 0, [JSVM_WRITABLE](_j_s_v_m.md) = 1 &lt;&lt; 0, [JSVM_ENUMERABLE](_j_s_v_m.md) = 1 &lt;&lt; 1, [JSVM_CONFIGURABLE](_j_s_v_m.md) = 1 &lt;&lt; 2,<br>[JSVM_STATIC](_j_s_v_m.md) = 1 &lt;&lt; 10, [JSVM_DEFAULT_METHOD](_j_s_v_m.md) = JSVM_WRITABLE \| JSVM_CONFIGURABLE, [JSVM_DEFAULT_JSPROPERTY](_j_s_v_m.md) = JSVM_WRITABLE \| JSVM_ENUMERABLE \| JSVM_CONFIGURABLE<br>} | Controls the behavior of JavaScript object attributes. | 
| [JSVM_ValueType](_j_s_v_m.md#jsvm_valuetype) {<br>[JSVM_UNDEFINED](_j_s_v_m.md), [JSVM_NULL](_j_s_v_m.md), [JSVM_BOOLEAN](_j_s_v_m.md), [JSVM_NUMBER](_j_s_v_m.md),<br>[JSVM_STRING](_j_s_v_m.md), [JSVM_SYMBOL](_j_s_v_m.md), [JSVM_OBJECT](_j_s_v_m.md), [JSVM_FUNCTION](_j_s_v_m.md),<br>[JSVM_EXTERNAL](_j_s_v_m.md), [JSVM_BIGINT](_j_s_v_m.md)<br>} | Describes the JSVM_Value type. | 
| [JSVM_TypedarrayType](_j_s_v_m.md#jsvm_typedarraytype) {<br>[JSVM_INT8_ARRAY](_j_s_v_m.md), [JSVM_UINT8_ARRAY](_j_s_v_m.md), [JSVM_UINT8_CLAMPED_ARRAY](_j_s_v_m.md), [JSVM_INT16_ARRAY](_j_s_v_m.md),<br>[JSVM_UINT16_ARRAY](_j_s_v_m.md), [JSVM_INT32_ARRAY](_j_s_v_m.md), [JSVM_UINT32_ARRAY](_j_s_v_m.md), [JSVM_FLOAT32_ARRAY](_j_s_v_m.md),<br>[JSVM_FLOAT64_ARRAY](_j_s_v_m.md), [JSVM_BIGINT64_ARRAY](_j_s_v_m.md), [JSVM_BIGUINT64_ARRAY](_j_s_v_m.md)<br>} | Type of a TypedArray. | 
| [JSVM_Status](_j_s_v_m.md#jsvm_status) {<br>[JSVM_OK](_j_s_v_m.md), [JSVM_INVALID_ARG](_j_s_v_m.md), [JSVM_OBJECT_EXPECTED](_j_s_v_m.md), [JSVM_STRING_EXPECTED](_j_s_v_m.md),<br>[JSVM_NAME_EXPECTED](_j_s_v_m.md), [JSVM_FUNCTION_EXPECTED](_j_s_v_m.md), [JSVM_NUMBER_EXPECTED](_j_s_v_m.md), [JSVM_BOOLEAN_EXPECTED](_j_s_v_m.md),<br>[JSVM_ARRAY_EXPECTED](_j_s_v_m.md), [JSVM_GENERIC_FAILURE](_j_s_v_m.md), [JSVM_PENDING_EXCEPTION](_j_s_v_m.md), [JSVM_CANCELLED](_j_s_v_m.md),<br>[JSVM_ESCAPE_CALLED_TWICE](_j_s_v_m.md), [JSVM_HANDLE_SCOPE_MISMATCH](_j_s_v_m.md), [JSVM_CALLBACK_SCOPE_MISMATCH](_j_s_v_m.md), [JSVM_QUEUE_FULL](_j_s_v_m.md),<br>[JSVM_CLOSING](_j_s_v_m.md), [JSVM_BIGINT_EXPECTED](_j_s_v_m.md), [JSVM_DATE_EXPECTED](_j_s_v_m.md), [JSVM_ARRAYBUFFER_EXPECTED](_j_s_v_m.md),<br>[JSVM_DETACHABLE_ARRAYBUFFER_EXPECTED](_j_s_v_m.md), [JSVM_WOULD_DEADLOCK](_j_s_v_m.md), [JSVM_NO_EXTERNAL_BUFFERS_ALLOWED](_j_s_v_m.md), [JSVM_CANNOT_RUN_JS](_j_s_v_m.md)<br>} | Complete status code indicating whether the JSVM-API invoking is successful or fails. | 
| [JSVM_KeyCollectionMode](_j_s_v_m.md#jsvm_keycollectionmode) { [JSVM_KEY_INCLUDE_PROTOTYPES](_j_s_v_m.md), [JSVM_KEY_OWN_ONLY](_j_s_v_m.md) } | Limits the range of attributes to be searched for. | 
| [JSVM_KeyFilter](_j_s_v_m.md#jsvm_keyfilter) {<br>[JSVM_KEY_ALL_PROPERTIES](_j_s_v_m.md) = 0, [JSVM_KEY_WRITABLE](_j_s_v_m.md) = 1, [JSVM_KEY_ENUMERABLE](_j_s_v_m.md) = 1 &lt;&lt; 1, [JSVM_KEY_CONFIGURABLE](_j_s_v_m.md) = 1 &lt;&lt; 2,<br>[JSVM_KEY_SKIP_STRINGS](_j_s_v_m.md) = 1 &lt;&lt; 3, [JSVM_KEY_SKIP_SYMBOLS](_j_s_v_m.md) = 1 &lt;&lt; 4<br>} | Attribute filter. You can use or to construct a composite filter. | 
| [JSVM_KeyConversion](_j_s_v_m.md#jsvm_keyconversion) { [JSVM_KEY_KEEP_NUMBERS](_j_s_v_m.md), [JSVM_KEY_NUMBERS_TO_STRINGS](_j_s_v_m.md) } | Key conversion option. | 
| [JSVM_MemoryPressureLevel](_j_s_v_m.md#jsvm_memorypressurelevel) { [JSVM_MEMORY_PRESSURE_LEVEL_NONE](_j_s_v_m.md), [JSVM_MEMORY_PRESSURE_LEVEL_MODERATE](_j_s_v_m.md), [JSVM_MEMORY_PRESSURE_LEVEL_CRITICAL](_j_s_v_m.md) } | Memory pressure level. | 
