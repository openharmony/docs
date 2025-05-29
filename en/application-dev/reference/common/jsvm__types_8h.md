# jsvm_types.h


## Overview

JSVM-API type definitions.

Through the APIs, independent, standard, and complete JavaScript engine capabilities are provided, including managing the engine lifecycle, compiling and running JS code, implementing JS/C++ cross-language invoking, and taking snapshots.

**Library**: libjsvm.so

**System capability**: SystemCapability.ArkCompiler.JSVM

**Since**: 11

**Related module**: [JSVM](_j_s_v_m.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| struct&nbsp;&nbsp;[JSVM_CallbackStruct](_j_s_v_m___callback_struct.md) | Pointer to and data of the native callbacks provided by the user. These functions are exposed to JavaScript via JSVM-API. | 
| struct&nbsp;&nbsp;[JSVM_HeapStatistics](_j_s_v_m___heap_statistics.md) | Heap statistics struct, which is used to store statistics about JavaScript heap memory usage. | 
| struct&nbsp;&nbsp;[JSVM_InitOptions](_j_s_v_m___init_options.md) | Options for initializing a JavaScript VM. | 
| struct&nbsp;&nbsp;[JSVM_CreateVMOptions](_j_s_v_m___create_v_m_options.md) | Options for creating a JavaScript VM. | 
| struct&nbsp;&nbsp;[JSVM_VMInfo](_j_s_v_m___v_m_info.md) | JavaScript VM information. | 
| struct&nbsp;&nbsp;[JSVM_PropertyDescriptor](_j_s_v_m___property_descriptor.md) | Property descriptor. | 
| struct&nbsp;&nbsp;[JSVM_ExtendedErrorInfo](_j_s_v_m___extended_error_info.md) | Extended error information. | 
| struct&nbsp;&nbsp;[JSVM_TypeTag](_j_s_v_m___type_tag.md) | Type tag, stored as a 128-bit value of two unsigned 64-bit integers. This tag can be used as a UUID, so that JavaScript objects can be tagged, to ensure that their types remain unchanged. | 
| struct&nbsp;&nbsp;[JSVM_PropertyHandlerConfigurationStruct](_j_s_v_m___property_handler_configuration_struct.md) | Struct for triggering the corresponding function callback in the struct when the getter, setter, deleter, or enumerator of an object is executed. | 
| struct&nbsp;&nbsp;[JSVM_ScriptOrigin](_j_s_v_m___script_origin.md) | Source code information.  | 


### Types

| Name| Description| 
| -------- | -------- |
|  typedef uint16_t **char16_t** |  | 
| typedef struct JSVM_VM__ \* [JSVM_VM](_j_s_v_m.md#jsvm_vm) | JavaScript VM instance. | 
| typedef struct JSVM_VMScope__ \* [JSVM_VMScope](_j_s_v_m.md#jsvm_vmscope) | JavaScript VM scope. | 
| typedef struct JSVM_EnvScope__ \* [JSVM_EnvScope](_j_s_v_m.md#jsvm_envscope) | Environment scope of the current VM instance. The environment is available to the VM instance of the thread only after the thread enters JSVM_EnvScope of the environment through OH_JSVM_OpenEnvScope. | 
| typedef struct JSVM_Script__ \* [JSVM_Script](_j_s_v_m.md#jsvm_script) | JavaScript code. | 
| typedef struct JSVM_Env__ \* [JSVM_Env](_j_s_v_m.md#jsvm_env) | Context of a specific VM state. It needs to be passed as a parameter when the native function is called and passed to any subsequent JSVM-API nested invoking. | 
| typedef struct JSVM_CpuProfiler__ \* [JSVM_CpuProfiler](_j_s_v_m.md#jsvm_cpuprofiler) | JavaScript CPU profiler. | 
| typedef struct JSVM_Value__ \* [JSVM_Value](_j_s_v_m.md#jsvm_value) | JavaScript value. | 
| typedef struct JSVM_Ref__ \* [JSVM_Ref](_j_s_v_m.md#jsvm_ref) | Reference to the JavaScript value. | 
| typedef struct JSVM_HandleScope__ \* [JSVM_HandleScope](_j_s_v_m.md#jsvm_handlescope) | Scope of the JavaScript value. It is used to control and modify the lifecycle of an object created in a specific scope. Typically, the JSVM-API value is created in the context of JSVM_HandleScope. When the native method is called from JavaScript, the default JSVM_HandleScope exists. If the user does not explicitly create a new JSVM_HandleScope, the JSVM-API value is created in the default JSVM_HandleScope. For any code call other than native method execution (for example, libuv callback), the module needs to create a scope before calling any function that may cause JavaScript value creation. JSVM_HandleScope is created using OH_JSVM_OpenHandleScope and destroyed using OH_JSVM_CloseHandleScope. Closing the scope represents indicating to the GC that all JSVM_Values created during the lifecycle of JSVM_HandleScope will no longer be referenced from the stack frame of the current heap. | 
| typedef struct JSVM_EscapableHandleScope__ \* [JSVM_EscapableHandleScope](_j_s_v_m.md#jsvm_escapablehandlescope) | A special type of handle scope, which is used to return the value created in a specific handle scope to the parent scope. | 
| typedef struct JSVM_CallbackInfo__ \* [JSVM_CallbackInfo](_j_s_v_m.md#jsvm_callbackinfo) | An opaque data type passed to the callback. It can be used to obtain additional information about the context in which the function is called. | 
| typedef struct JSVM_Deferred__ \* [JSVM_Deferred](_j_s_v_m.md#jsvm_deferred) | Promise deferred object. | 
| typedef [JSVM_CallbackStruct](_j_s_v_m___callback_struct.md) \* [JSVM_Callback](_j_s_v_m.md#jsvm_callback) | Pointer types of the native functions provided by user. These functions are exposed to JavaScript via JSVM-API. | 
| typedef void(JSVM_CDECL \* [JSVM_Finalize](_j_s_v_m.md#jsvm_finalize)) ([JSVM_Env](_j_s_v_m.md#jsvm_env) env, void \*finalizeData, void \*finalizeHint) | Function pointer type. It is passed in when a native object or data is associated with a JavaScript object. This function is called when the associated JavaScript object is reclaimed by the GC to execute the native cleanup action. | 
| typedef bool(JSVM_CDECL \* [JSVM_OutputStream](_j_s_v_m.md#jsvm_outputstream)) (const char \*data, int size, void \*streamData) | Pointer to the callback of the ASCII output stream. **data** indicates the pointer to the output data. **size** indicates the size of the output data. **void** points to the end of the stream. **streamData** indicates the pointer passed to the API function together with the callback. The API function generates data to the output stream. If **true** is returned, the stream can continue to receive data. Otherwise, it aborts the stream. | 
| typedef [JSVM_PropertyHandlerConfigurationStruct](_j_s_v_m___property_handler_configuration_struct.md) \* [JSVM_PropertyHandlerCfg](_j_s_v_m.md#jsvm_propertyhandlercfg) | Pointer type of the struct that contains the property listening callback. | 


### Enums

| Name| Description| 
| -------- | -------- |
| [JSVM_PropertyAttributes](_j_s_v_m.md#jsvm_propertyattributes) {<br>[JSVM_DEFAULT](_j_s_v_m.md) = 0, [JSVM_WRITABLE](_j_s_v_m.md) = 1 &lt;&lt; 0, [JSVM_ENUMERABLE](_j_s_v_m.md) = 1 &lt;&lt; 1, [JSVM_CONFIGURABLE](_j_s_v_m.md) = 1 &lt;&lt; 2,<br>[JSVM_STATIC](_j_s_v_m.md) = 1 &lt;&lt; 10, [JSVM_DEFAULT_METHOD](_j_s_v_m.md) = JSVM_WRITABLE \| JSVM_CONFIGURABLE, [JSVM_DEFAULT_JSPROPERTY](_j_s_v_m.md) = JSVM_WRITABLE \| JSVM_ENUMERABLE \| JSVM_CONFIGURABLE<br>} | Control over the behavior of JavaScript object properties. | 
| [JSVM_ValueType](_j_s_v_m.md#jsvm_valuetype) {<br>[JSVM_UNDEFINED](_j_s_v_m.md), [JSVM_NULL](_j_s_v_m.md), [JSVM_BOOLEAN](_j_s_v_m.md), [JSVM_NUMBER](_j_s_v_m.md),<br>[JSVM_STRING](_j_s_v_m.md), [JSVM_SYMBOL](_j_s_v_m.md), [JSVM_OBJECT](_j_s_v_m.md), [JSVM_FUNCTION](_j_s_v_m.md),<br>[JSVM_EXTERNAL](_j_s_v_m.md), [JSVM_BIGINT](_j_s_v_m.md)<br>} | JSVM_Value type. | 
| [JSVM_TypedarrayType](_j_s_v_m.md#jsvm_typedarraytype) {<br>[JSVM_INT8_ARRAY](_j_s_v_m.md), [JSVM_UINT8_ARRAY](_j_s_v_m.md), [JSVM_UINT8_CLAMPED_ARRAY](_j_s_v_m.md), [JSVM_INT16_ARRAY](_j_s_v_m.md),<br>[JSVM_UINT16_ARRAY](_j_s_v_m.md), [JSVM_INT32_ARRAY](_j_s_v_m.md), [JSVM_UINT32_ARRAY](_j_s_v_m.md), [JSVM_FLOAT32_ARRAY](_j_s_v_m.md),<br>[JSVM_FLOAT64_ARRAY](_j_s_v_m.md), [JSVM_BIGINT64_ARRAY](_j_s_v_m.md), [JSVM_BIGUINT64_ARRAY](_j_s_v_m.md)<br>} | TypedArray type. | 
| [JSVM_Status](_j_s_v_m.md#jsvm_status) {<br>[JSVM_OK](_j_s_v_m.md), [JSVM_INVALID_ARG](_j_s_v_m.md), [JSVM_OBJECT_EXPECTED](_j_s_v_m.md), [JSVM_STRING_EXPECTED](_j_s_v_m.md),<br>[JSVM_NAME_EXPECTED](_j_s_v_m.md), [JSVM_FUNCTION_EXPECTED](_j_s_v_m.md), [JSVM_NUMBER_EXPECTED](_j_s_v_m.md), [JSVM_BOOLEAN_EXPECTED](_j_s_v_m.md),<br>[JSVM_ARRAY_EXPECTED](_j_s_v_m.md), [JSVM_GENERIC_FAILURE](_j_s_v_m.md), [JSVM_PENDING_EXCEPTION](_j_s_v_m.md), [JSVM_CANCELLED](_j_s_v_m.md),<br>[JSVM_ESCAPE_CALLED_TWICE](_j_s_v_m.md), [JSVM_HANDLE_SCOPE_MISMATCH](_j_s_v_m.md), [JSVM_CALLBACK_SCOPE_MISMATCH](_j_s_v_m.md), [JSVM_QUEUE_FULL](_j_s_v_m.md),<br>[JSVM_CLOSING](_j_s_v_m.md), [JSVM_BIGINT_EXPECTED](_j_s_v_m.md), [JSVM_DATE_EXPECTED](_j_s_v_m.md), [JSVM_ARRAYBUFFER_EXPECTED](_j_s_v_m.md),<br>[JSVM_DETACHABLE_ARRAYBUFFER_EXPECTED](_j_s_v_m.md), [JSVM_WOULD_DEADLOCK](_j_s_v_m.md), [JSVM_NO_EXTERNAL_BUFFERS_ALLOWED](_j_s_v_m.md), [JSVM_CANNOT_RUN_JS](_j_s_v_m.md)<br>} | Complete status code indicating whether the JSVM-API call is successful or fails. | 
| [JSVM_KeyCollectionMode](_j_s_v_m.md#jsvm_keycollectionmode) { [JSVM_KEY_INCLUDE_PROTOTYPES](_j_s_v_m.md), [JSVM_KEY_OWN_ONLY](_j_s_v_m.md) } | Limited range of properties to be searched for. | 
| [JSVM_KeyFilter](_j_s_v_m.md#jsvm_keyfilter) {<br>[JSVM_KEY_ALL_PROPERTIES](_j_s_v_m.md) = 0, [JSVM_KEY_WRITABLE](_j_s_v_m.md) = 1, [JSVM_KEY_ENUMERABLE](_j_s_v_m.md) = 1 &lt;&lt; 1, [JSVM_KEY_CONFIGURABLE](_j_s_v_m.md) = 1 &lt;&lt; 2,<br>[JSVM_KEY_SKIP_STRINGS](_j_s_v_m.md) = 1 &lt;&lt; 3, [JSVM_KEY_SKIP_SYMBOLS](_j_s_v_m.md) = 1 &lt;&lt; 4<br>} | Property filter. You can use OR to construct a composite filter. | 
| [JSVM_KeyConversion](_j_s_v_m.md#jsvm_keyconversion) { [JSVM_KEY_KEEP_NUMBERS](_j_s_v_m.md), [JSVM_KEY_NUMBERS_TO_STRINGS](_j_s_v_m.md) } | Key conversion option. | 
| [JSVM_MemoryPressureLevel](_j_s_v_m.md#jsvm_memorypressurelevel) { [JSVM_MEMORY_PRESSURE_LEVEL_NONE](_j_s_v_m.md), [JSVM_MEMORY_PRESSURE_LEVEL_MODERATE](_j_s_v_m.md), [JSVM_MEMORY_PRESSURE_LEVEL_CRITICAL](_j_s_v_m.md) } | Memory pressure level. | 
| [JSVM_RegExpFlags](_j_s_v_m.md#jsvm_regexpflags) {<br>[JSVM_REGEXP_NONE](_j_s_v_m.md) = 0, [JSVM_REGEXP_GLOBAL](_j_s_v_m.md) = 1 &lt;&lt; 0, [JSVM_REGEXP_IGNORE_CASE](_j_s_v_m.md) = 1 &lt;&lt; 1, [JSVM_REGEXP_MULTILINE](_j_s_v_m.md) = 1 &lt;&lt; 2,<br>[JSVM_REGEXP_STICKY](_j_s_v_m.md) = 1 &lt;&lt; 3, [JSVM_REGEXP_UNICODE](_j_s_v_m.md) = 1 &lt;&lt; 4, [JSVM_REGEXP_DOT_ALL](_j_s_v_m.md) = 1 &lt;&lt; 5, [JSVM_REGEXP_LINEAR](_j_s_v_m.md) = 1 &lt;&lt; 6,<br>[JSVM_REGEXP_HAS_INDICES](_j_s_v_m.md) = 1 &lt;&lt; 7, [JSVM_REGEXP_UNICODE_SETS](_j_s_v_m.md) = 1 &lt;&lt; 8<br>} | Regular expression flags. They can be used to enable a set of flags. | 
| [JSVM_InitializedFlag](_j_s_v_m.md#jsvm_initializedflag) { [JSVM_ZERO_INITIALIZED](_j_s_v_m.md), [JSVM_UNINITIALIZED](_j_s_v_m.md) } | Initialization flag. | 
| [JSVM_WasmOptLevel](_j_s_v_m.md#jsvm_wasmoptlevel) { [JSVM_WASM_OPT_BASELINE](_j_s_v_m.md) = 10, [JSVM_WASM_OPT_HIGH](_j_s_v_m.md) = 20 } | WebAssembly function optimization level. | 
| [JSVM_CacheType](_j_s_v_m.md#jsvm_cachetype) { [JSVM_CACHE_TYPE_JS](_j_s_v_m.md), [JSVM_CACHE_TYPE_WASM](_j_s_v_m.md) } | Cache type. | 
